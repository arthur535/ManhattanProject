//function prints graph's vertex values in depth first search order 
void dfs(Node* src) {
  unordered_set<Node*> visited;
  stack<Node*> s;
  s.push(src);
  visited.insert(src);
  while(!s.empty()){
     Node* top = s.top();
     cout << top->val << " ";
     s.pop();
     for(auto& adjacent : top->adjacents){
        if(!visited.count(adjacent)){
           s.push(adjacent);
           visited.insert(adjacent);
        }
     }
  }
}
