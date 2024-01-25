//function prints graph vertex values in depth-first-search order
void bfs(Node* src) {
  set<Node*> visited;
  queue<Node*> q;
  q.push(src);
  visited.insert(src);
  while(!q.empty()){
      Node* front = q.front();
      cout << front->val << " ";
      q.pop();
      for(auto& adjacent : front->adjacents){
          if(!visited.count(adjacent)){
              q.push(adjacent);
              visited.insert(adjacent);
          }
      }
  }
}
