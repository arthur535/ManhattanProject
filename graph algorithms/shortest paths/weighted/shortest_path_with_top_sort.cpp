unordered_map<Node*, std::optional<int>> dijkstra_in_DAG (const vector<Node*>& vertices, Node* source) {
    vector<Node*> topSorted = sorting(vertices);
    unordered_map<Node*, std::optional<int>> distances;
    if(topSorted.empty()){
        throw invalid_argument("Graph is not a DAG");
    }
    auto node_iterator = find(topSorted.begin(),topSorted.end(),source);
    for (auto it = find(topSorted.begin(),topSorted.end(),source); it != topSorted.end(); ++it) {
        distances[*it] = std::nullopt;
    }

    distances[*node_iterator] = 0;

    for ( ; node_iterator != topSorted.end(); ++node_iterator) {
        Node* u = *node_iterator;
        if (distances[u] != std::nullopt) {
            for (auto [adj, w] : u->adjacents) {
                if (!distances[adj] || distances[u].value() + w < distances[adj].value()) {
                    distances[adj] = distances[u].value() + w;
                }
            }
        }
    }

    return distances;
}
