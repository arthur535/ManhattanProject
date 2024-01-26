// unweighted graph vertex class
class Node {
public:
    Node(int val) : val(val){ }
    void add_edge(Node* adj){
        this->adjacents.insert(adj);
    }
public:
    set<Node*> adjacents;
    int val;
};

void add_edge(Node* first, Node* second, bool directed){
    first->add_edge(second);
    if(!directed) second->add_edge(first);
}

// wirghted graph vertex class
class Node {
public:
    Node(int val) : val(val){ }
    void add_edge(Node* adj, int w){
        this->adjacents.insert(make_pair(adj,w));
    }
public:
    set<pair<Node*,int>> adjacents;
    int val;
};

void add_edge(Node* first, Node* second, int w, bool directed) {
    first->add_edge(second, w);
    if(!directed) second->add_edge(first, w);
}

const bool undirected = false;
const bool directed = true;


// choose directed or undirected and start exploring 

int main() {
    const int n = 12;
    vector<Node*> vertices(n);
    for(int i = 0; i < n; ++i){
        vertices[i] = new Node(i);
    }
   // weighted
  
   // add_edge(vertices[0], vertices[1], 2, directed);
   // add_edge(vertices[0], vertices[2], 4, directed);
   // add_edge(vertices[1], vertices[4], 5, directed);
   // add_edge(vertices[1], vertices[3], 1, directed);
   // add_edge(vertices[2], vertices[4], 6, directed);
   // add_edge(vertices[2], vertices[5], 4, directed);
   // add_edge(vertices[3], vertices[7], 2, directed);
   // add_edge(vertices[0], vertices[5], 5, directed);
   // add_edge(vertices[4], vertices[6], 3, directed);
   // add_edge(vertices[5], vertices[6], 5, directed);
   // add_edge(vertices[6], vertices[8], 16, directed);
   // add_edge(vertices[7], vertices[8], 3, directed);
   // add_edge(vertices[9], vertices[6], 1, directed);
   // add_edge(vertices[8], vertices[9], 1, directed);
   // add_edge(vertices[9], vertices[3], -5, directed);

    // unweighted 
    add_edge(vertices[0], vertices[1], directed);
    add_edge(vertices[0], vertices[4], directed);
    add_edge(vertices[0], vertices[8], directed);
    add_edge(vertices[1], vertices[6], directed);
    add_edge(vertices[3], vertices[2], directed);
    add_edge(vertices[4], vertices[5], directed);
    add_edge(vertices[6], vertices[0], directed);
    add_edge(vertices[6], vertices[2], directed);
    add_edge(vertices[7], vertices[0], directed);
    add_edge(vertices[7], vertices[2], directed);
    add_edge(vertices[8], vertices[9], directed);
    add_edge(vertices[9], vertices[10], directed);
    add_edge(vertices[10], vertices[8], directed);
    add_edge(vertices[11], vertices[7], directed);
    add_edge(vertices[11], vertices[2], directed);
    
    // auto cyclics = Cycle::cyclic_nodes(vertices);
    // for(auto t:cyclics){
    //     cout << t->val << " ";
    // }
    // cout << endl;

}
