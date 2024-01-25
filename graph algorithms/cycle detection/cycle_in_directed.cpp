//function finds if there is a cycle in directed graph or not
bool has_cycle_directed(const vector<Node*>& vertices) {
    unordered_map<Node*, bool> visited;
    unordered_set<Node*> inStack;
    for(int i = 0; i < vertices.size(); ++i){
        Node* u = vertices[i];
        if(!visited[u]) {
            if(helper_dfs_for_directed_cycle(u, visited, inStack)) return true;
        }
    }
    return false;
}

bool helper_dfs_for_directed_cycle(Node* u, unordered_map<Node*, bool>& visited, unordered_set<Node*>& inStack) {
    visited[u] = true;
    inStack.insert(u);
    for(Node* neighbor : u->adjacents) {
        cout << u->val << "  " << neighbor->val << endl;
        if (inStack.count(neighbor)) {
            return true;
        }
        if (!visited[neighbor] && helper_dfs_for_directed_cycle(neighbor, visited, inStack)) {
           return true;
        }
    }
    inStack.erase(u);
    return false;
}
