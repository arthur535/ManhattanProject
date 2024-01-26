void dfs_for_kosaraju_1(Node* u, unordered_map<Node*, bool>& visited, stack<Node*>& onStack) {
    visited[u] = true;
    for(Node* adj : u->adjacents){
        if(!visited[adj]){
            dfs_for_kosaraju_1(adj, visited, onStack);
            
        }
    }
    onStack.push(u);
}

void dfs_for_kosaraju_2(Node* u, unordered_map<Node*, bool>& visited, vector<Node*>& tmp, vector<unique_ptr<Node>>& transposed) {
        visited[u] = true;
    tmp.push_back(u);
    for(Node* adj : transposed[u->val]->adjacents) {
        if(!visited[adj]){
            dfs_for_kosaraju_2(adj, visited, tmp, transposed);
        }
    }
}

vector<vector<Node*>> kosaraju(const vector<Node*>& vertices){
    vector<vector<Node*>> result;
    unordered_map<Node*, bool> visited;
    stack<Node*> onStack;
    vector<Node*> tmp;
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        Node* u = *it;
        if(!visited[u]){
            dfs_for_kosaraju_1(u, visited, onStack);
        }
    }
    
    auto transposed = transpose(vertices);
    visited.clear();
    
    while (!onStack.empty()) {
        Node* u = onStack.top();
        onStack.pop();
        if(!visited[u]){
            dfs_for_kosaraju_2(u, visited, tmp, transposed);
            result.push_back(tmp);
            tmp.clear();
        }
    }
    return result;
}
