vector<vector<Node*>> tarjan(const vector<Node*>& vertices){
    long n = vertices.size();
    vector<Node*> tmp;
    vector<vector<Node*>> result;
    unordered_map<Node*, int> disc;
    unordered_map<Node*, int> low_link;
    unordered_map<Node*, bool> inStack;
    stack<Node*> st;
    
    for(Node* u : vertices){
        if (!disc[u]){
            dfs_for_tarjan(u, disc, low_link, st, inStack, tmp, result);
        }
    }
    return result;
}
void dfs_for_tarjan(Node* u, unordered_map<Node*, int>& disc, unordered_map<Node*, int>& low_link, stack<Node*>& st,  unordered_map<Node*, bool>& inStack, vector<Node*>& tmp, vector<vector<Node*>>& result) {
    
    static int time = 1;
    
    disc[u] = low_link[u] = time;
    time++;
    st.push(u);
    inStack[u] = true;
    
    for(Node* adj : u->adjacents){
        if(disc[adj] == 0) {
            dfs_for_tarjan(adj, disc, low_link, st, inStack, tmp, result);
            low_link[u] = std::min(low_link[u], low_link[adj]);
        }
        else if(inStack[adj]){
            low_link[u] = std::min(low_link[u], low_link[adj]);
        }
    }
    if(low_link[u] == disc[u]){
        while(st.top() != u){
            tmp.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
        }
        tmp.push_back(st.top());
        result.push_back(tmp);
        tmp.clear();
        inStack[st.top()] = false;
        st.pop();
    }
}

