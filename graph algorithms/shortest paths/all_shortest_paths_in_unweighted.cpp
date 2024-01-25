vector<vector<Node*>> allshortestpaths(Node* source, Node* destination) {
    vector<vector<Node*>> result;
    vector<Node*> path;
    unordered_map<Node*, Node*> parent;
    stack<Node*> st;
    unordered_map<Node*, bool> visited;
    parent[source] = nullptr;
    dfs(source, destination, parent, st, visited, path, result);
    return result;
}

void dfs(Node* source, Node* destination, unordered_map<Node*, Node*>& parent, stack<Node*>& st, unordered_map<Node*, bool>& visited, vector<Node*>& path, vector<vector<Node*>>& result) {
    static int time = 0;
    static int min_time = INT_MAX;
    time++;
    st.push(source);
    visited[source] = true;
    if(source == destination) {
        Node* u = source;
        if(time < min_time){
            min_time = time;
            while(u != nullptr){
                path.push_back(u);
                u = parent[u];
            }
            std::reverse(path.begin(), path.end());
            result = {{path}};
            path.clear();
        }
        else if(time == min_time){
            while(u != nullptr){
                path.push_back(u);
                u = parent[u];
            }
            std::reverse(path.begin(), path.end());
            result.push_back(path);
            path.clear();
        }
    }
    for(Node* adj : source->adjacents) {
        if(!visited[adj]) {
            parent[adj] = source;
            dfs(adj, destination, parent, st, visited, path, result);
            visited[adj] = false;
            time--;
        }
    }
}


