#include <iostream>
#include <list>
#include <vector>
#include <queue>

using std::list;
using std::cout;
using std::queue;
using std::vector;
using std::string;
using std::ostream;

template<class D>
class TNode{
public:
    D data;
    unsigned idx;

    friend ostream& operator<< (ostream & out, const TNode<D> &n){
       out << n.idx << ":\t[" << n.data << "]";
       return out;
   	}

    TNode(unsigned, D);
    ~TNode();
};

template<class D>
TNode<D>::TNode(unsigned idx, D data){
    this->idx = idx;
    this->data = data;
}

template<class D>
TNode<D>::~TNode(){

}

template<class N>
class TGraph{
private:
    list<N*> *adjacents;    // pointer to array of adjacent;
    N **nodes;              // 
    int n;

public:
    TGraph(int);
    ~TGraph();

    void addNode(N*);
    void addEdge(int, int);

    void printNodes();
    void printEdges();

    void bfs(int);
};

template<class N>
TGraph<N>::TGraph(int n){
    this->n = n;
    this->adjacents = new list<N *>[n];
    this->nodes = new N*[n];
}

template<class N>
TGraph<N>::~TGraph(){
    delete []nodes;
}

template<class N>
void TGraph<N>::addNode(N* node){
    nodes[node->idx] = node;
}

template<class N>
void TGraph<N>::addEdge(int is, int it){
    if(is >= 0 and it >= 0){
        adjacents[is].push_back(nodes[it]);
    }
}

template<class N>
void TGraph<N>::printNodes(){
    for(int i=0; i<n; i++){
        cout << *nodes[i] << "\n";
    }
}

template<class N>
void TGraph<N>::printEdges(){
    typename list<N*>::iterator it;
    for(int i=0; i<n; i++){
        cout << nodes[i]->data << ":\n";
        for(it=adjacents[i].begin(); it!=adjacents[i].end(); it++){
            cout << "\t" << (*it)->data << "\n";
        }
    }
}

template<class N>
void TGraph<N>::bfs(int is){
    if(is < 0){
        return;
    }

    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    // queue
    list<int> queue;

    visited[is] = true;
    queue.push_back(is);

    typename list<N*>::iterator it;
    int tmp;
    while (!queue.empty()){
        is = queue.front();
        cout << is << " ";
        queue.pop_front();

        for(it=adjacents[is].begin(); it!=adjacents[is].end(); it++){
            tmp = (*it)->idx;
            if(!visited[tmp]){
                visited[tmp] = true;
                queue.push_back(tmp);
            }
        }
    }
}

typedef TNode<string> Node;
typedef TGraph<Node> Graph;

int main(int argc, char const *argv[]){
    
    Graph *g = new Graph(11);

    g->addNode(new Node(0, "Home"));
    g->addNode(new Node(1, "Download"));
    g->addNode(new Node(2, "Interview"));
    g->addNode(new Node(3, "Artificial Intelligence"));
    g->addNode(new Node(4, "Deep Learning"));
    g->addNode(new Node(5, "Machine Learning"));
    g->addNode(new Node(6, "Algorithms"));
    g->addNode(new Node(7, "Data Structures"));
    g->addNode(new Node(8, "Algorithm Analysis"));
    g->addNode(new Node(9, "AED"));
    g->addNode(new Node(10, "EDA"));

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    g->addEdge(0, 6);
    g->addEdge(6, 7);
    g->addEdge(6, 8);
    g->addEdge(7, 9);
    g->addEdge(7, 10);

    g->printNodes();
    // g->printEdges();

    g->bfs(0);

    delete g;

    return 0;
}
