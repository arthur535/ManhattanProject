//function returns all the paths from u to v
vector<vector<Node*>> allpaths(Node* u, Node* v) {
    vector<vector<Node*>> result;
    unordered_map<Node*, bool> visited;
    vector<Node*> tmp;
    dfs_helper(u, v, visited, tmp, result);
    return result;
}

void dfs_helper(Node* u, Node* v, unordered_map<Node*, bool>& visited, vector<Node*>& tmp, vector<vector<Node*>>& result) {
    if (!visited[u]){
        visited[u] = true;
        tmp.push_back(u);
        if (u == v){
           result.push_back(tmp);
        }
        for(Node* adj : u->adjacents) {
            if (!visited[adj]){
                dfs_helper(adj, v, visited, tmp, result);
                visited[adj] = false;
                tmp.pop_back();
            }
        }
    }
}
