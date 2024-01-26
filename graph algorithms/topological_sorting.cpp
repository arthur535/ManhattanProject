vector<Node*> sorting(const vector<Node*>& vertices) {
    long n = vertices.size();
    vector<Node*> result;
    vector<int> inDegree(n);
    set<Node*> seen;
    for(int i = 0; i < n; ++i){
        Node* u = vertices[i];
        for(auto [adj,w] : u->adjacents){
            inDegree[adj->val]++;
        }
    }
    queue<Node*> ZeroIndegree;
    for(int i = 0; i < n; ++i){
        if(inDegree[i] == 0) {
            ZeroIndegree.push(vertices[i]);
        }
    }
    if(ZeroIndegree.empty()){
        return {};
    }
    while(!ZeroIndegree.empty()){
        Node* u = ZeroIndegree.front();
        ZeroIndegree.pop();
        seen.insert(u);
        result.push_back(u);
        for(auto [adj,w] : u->adjacents){
            inDegree[adj->val]--;
            if(inDegree[adj->val] == 0) {
                ZeroIndegree.push(adj);
            }
        }
    }
    if (seen.size() == n) return result;
    return {};
}
