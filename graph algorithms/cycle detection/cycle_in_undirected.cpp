//function finds if there is a cycle in undirected graph or not
enum State { UNVISITED, INSTACK, VISITED };
bool has_cycle_undirected(const vector<Node*>& vertices) {
    unordered_map<Node*, State> visited;
    stack<Node*> s;
    for(int i = 0; i < vertices.size(); ++i){
        Node* u = vertices[i];
        if(!visited[u]){
            s.push(u);
            visited[u] = INSTACK;
            while(!s.empty()){
                Node* top = s.top();
                s.pop();
                visited[top] = VISITED;
                for(Node* adj : top->adjacents){
                    if(visited[adj] == INSTACK) {
                       return true;
                    }
                    if(visited[adj] == 0){
                        s.push(adj);
                        visited[adj] = INSTACK;
                    }
                }
            }
        }
    }
    return false;
}
