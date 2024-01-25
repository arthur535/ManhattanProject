//function returns vertices in a graph and the ones from which there are paths to cycles
enum State { UNVISITED, INSTACK, VISITED };
vector<Node*> cyclic_nodes(const vector<Node*>& vertices) {
    vector<Node*> result;
    unordered_map<Node*,State> state;
    for(Node* v: vertices) {
        if (dfs_helper(vertices, v, state)) {
           result.push_back(v);
        }
    }
    return result;
}

bool dfs_helper(const vector<Node*>& vertices, Node* u, unordered_map<Node*,State>& state) {
    if (state[u] == INSTACK) {
       return true;
    }
    if (state[u] == VISITED) {
        return false;
    }
    state[u] = INSTACK;
    for(Node* adj : u->adjacents) {
        if (dfs_helper(vertices, adj, state)) {
            return true;
        }
    }
    state[u] = VISITED;
    return false;
}
