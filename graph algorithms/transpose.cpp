vector<unique_ptr<Node>> transpose (const vector<Node*>& vertices) {
    long n = vertices.size();
    vector<unique_ptr<Node>> transposed(n);
    for(int i = 0; i < n; ++i){
        transposed[i] = make_unique<Node>(i);
    }
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        Node* u = *it;
        for(Node* adj : u->adjacents){
            transposed[adj->val]->adjacents.insert(u);
        }
    }
    return transposed;
}
