vector<Node*> shortestpath(Node* u, Node* v){
    vector<Node*> result;
    unordered_map<Node*, bool> visited;
    unordered_map<Node*, Node*> parent;
    parent[u] = nullptr;
    bfs(u, v, visited, parent, result);
    return result;
}

void bfs(Node* u, Node* v, unordered_map<Node*, bool>& visited, unordered_map<Node*, Node*>& parent, vector<Node*>& result){
    queue<Node*> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        for(Node* adj : front->adjacents){
            
            if(!visited[adj]){
                q.push(adj);
                visited[adj] = true;
                parent[adj] = front;
                
                if(adj == v){
                    while (adj != nullptr) {
                        result.push_back(adj);
                        adj = parent[adj];
                    }
                    reverse(result.begin(), result.end());
                    return;
                }
            }
        }
    }
}
