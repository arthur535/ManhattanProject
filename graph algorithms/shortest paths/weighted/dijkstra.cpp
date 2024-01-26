bool comp(pair<Node*,int> p1, pair<Node*,int> p2){
    return (p1.second > p2.second);
}

vector<vector<Node*>> dijkstra (const vector<Node*>& vertices, Node* source, Node* destination) {
    vector<Node*> path;
    vector<vector<Node*>> result;
    unordered_map<Node*, std::optional<int>> distances;
    unordered_map<Node*, Node*> parent;
    parent[source] = nullptr;
    for(Node* v : vertices){
        distances[v] = std::nullopt;
    }
    distances[source] = 0;
    priority_queue<pair<Node*, int>, vector<pair<Node*, int>>, decltype(&comp)> pq(&comp);

    pq.push({source,0});
    
    while(!pq.empty()) {
        auto [u, dist] = pq.top();
        pq.pop();
        for (auto [adj, w]  : u->adjacents) {
            if (!distances[adj] || distances[u].value() + w < distances[adj].value()) {
                distances[adj] = distances[u].value() + w;
                pq.push(make_pair(adj, distances[adj].value()));
                parent[adj] = u;
                if( adj == destination ) {
                    Node* curr = adj;
                    while(curr) {
                        path.push_back(curr);
                        curr = parent[curr];
                    }
                    std::reverse(path.begin(), path.end());
                    result = {{path}};
                    path.clear();
                }
            }
            else if (!distances[adj] || distances[u].value() + w == distances[adj].value()) {
                parent[adj] = u;
                if( adj == destination ) {
                    Node* curr = adj;
                    while(curr) {
                        path.push_back(curr);
                        curr = parent[curr];
                    }
                    std::reverse(path.begin(), path.end());
                    result.push_back(path);
                    path.clear();
                }
            }
        }
    }
    return result;
}
