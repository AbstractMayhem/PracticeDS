#include <iostream>

using namespace std;

struct NodeType{
int info;
struct NodeType *next;
 NodeType(int val){info=val;next=NULL;}
~NodeType(){}
};

typedef struct NodeType Node;

class Graph{
public:
 Graph(int);
 void insertGraph(int V1,int V2);//Enter the two vertices which have edge between them edge would be V1->V2(Directed)
 void deleteEdge(int V1,int V2);
 void printGraph();
~Graph();
protected:
int nov;//Number Of Vertices
Node **graph;//Pointer to Agjacency Graph List
};

Graph::Graph(int V){
nov=V;
graph=new Node*[V];
}

//Time Complexity of Insertion O(1)
void Graph::insertGraph(int V1,int V2){
Node *newNode=new Node(V2);
if(graph[V1]!=NULL){newNode->next=graph[V1];graph[V1]=newNode;}
else{graph[V1]=newNode;}
}

//Worst Time Complexity in Deletion O(V) where V is number of Vertices
void Graph::deleteEdge(int V1,int V2){
//Check if Edge Exists
Node *ptr=graph[V1];
Node *prevNode=NULL;
Node *deleteNode=NULL;
while(ptr!=NULL && ptr->info!=V2){prevNode=ptr; ptr=ptr->next;}
if(ptr!=NULL && ptr->info == V2){deleteNode=ptr; if(prevNode==NULL)graph[V1]=NULL; else prevNode->next=ptr->next; delete deleteNode;}
else { cout << "Edge "<<V1<<" "<<V2<<" does not exists!!!."<<endl; }
}

void Graph::printGraph(){
for(int i=0;i<nov;++i){
cout<<i<<"--->";
Node *ptr=graph[i];
while(ptr!=NULL){
cout<<ptr->info<<",";
ptr=ptr->next;
}
cout<<endl;
}
}

Graph::~Graph(){
Node *deleteNode=NULL;
for(int i=0;i<nov;++i){
Node *ptr=graph[i];
while(ptr!=NULL){deleteNode=ptr;ptr=ptr->next;delete deleteNode;}
}
delete[] graph;
}

int main(int argc,char *argv[]){
Graph g(20);
g.insertGraph(1,2);
g.insertGraph(3,4);
g.insertGraph(5,6);
g.insertGraph(3,7);
g.printGraph();
g.deleteEdge(5,6);
g.printGraph();
return 0;
}
