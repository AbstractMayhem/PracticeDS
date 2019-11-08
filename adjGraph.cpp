#include <iostream>
#include <climits>

using namespace std;

class Graph{
public:
Graph(int n);// Here n take the number of Vertices
void insertEdge(int V1,int V2,int W);
void printGraph();
//int minDistance(int dist[],bool sptSet[]);
void dijkastraAlgo(int srcVertex);
~Graph();
private:
int nov;
int **adjMat;
};

Graph::Graph(int n){
nov=n;
adjMat=new int*[nov];
for(int i=0;i<nov;++i)
adjMat[i]=new int[nov];
//Initialisation
for(int i=0;i<nov;++i)
for(int j=0;j<nov;++j)
adjMat[i][j]=999;//INT_MAX;
}

Graph::~Graph(){
for(int i=0;i<nov;++i)
delete adjMat[i];
delete[] adjMat;
}

void Graph::insertEdge(int V1,int V2,int W){
if(V1 < nov && V2 < nov)
adjMat[V1][V2]=W;
else
cout<<"Either of "<<V1<<" or "<<V2<<" is greater than "<<nov<<endl;
}

void Graph::printGraph(){
for(int i=0;i<nov;++i)
{
for(int j=0;j<nov;++j)
cout<<adjMat[i][j]<<"\t";
cout<<endl;
}
}
/*
int Graph::minDistance(int dist[],bool sptSet[]){
 int min=999;
 int u;
 for(int v=0;v<nov;++v)
 if(sptSet[v]==false && dist[v] <= min)
 {
 min=dist[v];
 u=v;
 }
 return u;
}
*/
void Graph::dijkastraAlgo(int srcVertex){

bool sptSet[nov];//Shortest Path Tree Set 
int dist[nov];   //Distance or Cost on each Edge in graph

//Initialization of sptSet and distance matrix
for(int i=0;i<nov;++i){sptSet[i]=false;dist[i]=999;}

//Assign distance value zero to src vertex
dist[srcVertex]=0;

/*
 * This while Loop will exit untill all vertex are visited in shortest path set:
 *  a.Picking a Vertex u which has minimum distance value and is not in sptSet.
 *  b.Include u to sptSet.
 *  c.Update distance value of all adjacent vertices of u.To update the distance      values,iterate through all adjacent vertices.For every adjacent vertex v,       if sum of distance value of u (from source) and weight of edge u-v,is less      than the distance value of v,then update the distance value of v.
*/
for(int i=0;i<nov;++i)
{
	int u;//stores vertex pos with minimum distance
	//Find vertex with Minimum distance 

	int min=999;
	for(int v=0;v<nov;++v)
	if(sptSet[v]==false && dist[v] <= min)
	{
	min=dist[v];
	u=v;
	}

//	u=minDistance(dist,sptSet);
	
	//Mark u vertex as visited 
	sptSet[u]=true;

	//Process  adjacent Vertices of U and update their distance values
	for(int v=0;v<nov;++v)
	{
       if(!sptSet[v] && adjMat[u][v]!=999 && (dist[u]+adjMat[u][v] < dist[v]))
		dist[v]=dist[u]+adjMat[u][v];  
	}
}

cout<<endl;
//Print Distance and SptSet
for(int i=0;i<nov;++i)
cout<<dist[i]<<",";
cout<<endl;
for(int i=0;i<nov;++i)
cout<<sptSet[i]<<",";
}

int main(int argc,char *argv[])
{
Graph g(3);
g.insertEdge(0,1,1);
g.insertEdge(1,0,1);
g.insertEdge(1,2,2);
g.insertEdge(2,1,2);
g.insertEdge(0,2,3);
g.insertEdge(2,0,3);

/*
Graph g(4);
g.insertEdge(0,1,10);
g.insertEdge(0,2,3);
g.insertEdge(0,3,2);
g.insertEdge(2,3,6);
g.insertEdge(1,3,7);
*/

/*
Graph g(6);
g.insertEdge(0,1,4);
g.insertEdge(0,5,3);
g.insertEdge(1,0,4);
g.insertEdge(1,2,8);
g.insertEdge(1,5,11);
g.insertEdge(2,3,7);
g.insertEdge(2,4,14);
g.insertEdge(2,1,8);
g.insertEdge(3,4,2);
g.insertEdge(3,2,7);
g.insertEdge(4,3,2);
g.insertEdge(4,2,14);
g.insertEdge(4,5,5);
g.insertEdge(5,0,3);
g.insertEdge(5,1,11);
g.insertEdge(5,4,5);
*/
/*
Graph g(9);
g.insertEdge(0,1,4);
g.insertEdge(0,7,8);
g.insertEdge(1,0,4);
g.insertEdge(1,2,8);
g.insertEdge(1,7,11);
g.insertEdge(2,1,8);
g.insertEdge(2,3,7);
g.insertEdge(2,5,4);
g.insertEdge(2,8,2);
g.insertEdge(3,2,7);
g.insertEdge(3,4,9);
g.insertEdge(3,5,14);
g.insertEdge(4,3,9);
g.insertEdge(4,5,10);
g.insertEdge(5,2,4);
g.insertEdge(5,3,14);
g.insertEdge(5,4,10);
g.insertEdge(5,6,2);
g.insertEdge(6,5,2);
g.insertEdge(6,7,1);
g.insertEdge(6,8,6);
g.insertEdge(7,0,8);
g.insertEdge(7,1,11);
g.insertEdge(7,6,1);
g.insertEdge(7,8,7);
g.insertEdge(8,2,2);
g.insertEdge(8,6,6);
g.insertEdge(8,7,7);
*/
g.printGraph();
g.dijkastraAlgo(1);

}
