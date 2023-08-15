#include<iostream>
#include<iomanip>
#include<vector>
#define N 5
using namespace std;
enum MyColor {W,G,B};
struct Vertex
{
vector<int> AdjList;
int Value;
MyColor Color;
int Parent;
int st;
int end;
};

class Graph
{
Vertex *V;
int size;
public:
Graph(int);
void AddEdge(int,int);
void DFS(vector<Vertex> &);
void DFS_Visit(int,int&,vector<Vertex> &);
void ShowGraph();
vector<Vertex> TopologicalOrder();
};

vector<Vertex> Graph::TopologicalOrder()
{
vector<Vertex> TopOrder;
DFS(TopOrder);
cout<<"\n\nGraph After DFS:";
ShowGraph();
return TopOrder;
}

Graph::Graph(int n)
{
size = n;
V = new Vertex[n];
for(int i=0;i<n;i++)
{
V[i].Value = i;
V[i].Color = W;
V[i].Parent = -1;
V[i].st = V[i].end = 0;
}
}

void Graph::ShowGraph()
{
cout<<"\n***************************************************";
cout<<"\nParent | Vertex Value | Color | Start | Finish";
cout<<"\n***************************************************";
for(int i=0;i<size;i++)
{
cout<<"\n";
if(V[i].Parent==-1)
cout<<setw(6)<<"NULL";
else
cout<<setw(6)<<V[i].Parent;
cout<<" | ";
cout<<setw(12)<<V[i].Value;
cout<<" | ";
cout<<setw(5)<<V[i].Color;
cout<<" | ";
cout<<setw(5)<<V[i].st;
cout<<" | ";
cout<<setw(6)<<V[i].end;
}
cout<<"\n***************************************************";
}

void Graph::DFS(vector<Vertex> &TopOrder)
{
int time=0;
for(int i=0;i<size;i++)
{
if(V[i].Color==W)
{
V[i].Parent = -1;
DFS_Visit(i,time,TopOrder);
}
}
}

void Graph::DFS_Visit(int i, int &time,vector<Vertex> &TopOrder)
{
int u;
V[i].Color = G;
V[i].st = ++time;
for(int p=0;p<V[i].AdjList.size();p++)
{
u = V[i].AdjList[p];
if(V[u].Color==W)
{
V[u].Parent = i;
DFS_Visit(u,time,TopOrder);
}
}
V[i].end = ++time;
V[i].Color = B;
TopOrder.insert(TopOrder.begin(),V[i]);
}

void Graph::AddEdge(int from, int to)
{
V[from].AdjList.push_back(to);
}

int main()
{
Graph g(N);
int b[][N] = { {0,1,1,1,0},
{0,0,1,1,0},
{0,0,0,0,1},
{0,0,0,0,1},
{0,0,0,0,0} };
for(int i=0;i<N;i++)
{
for(int j=0;j<N;j++)
{
if(b[i][j]!=0)
{
g.AddEdge(i,j);
}
}
}
vector<Vertex> TopOrder;
TopOrder = g.TopologicalOrder();
int topsize = TopOrder.size();
Vertex v;
cout<<"\n\nTopological Order of Vertices: ";
for(int i=0;i<topsize;i++)
{
v = TopOrder[i];
cout<<setw(5)<<v.Value;
}
cout<<"\n\n";
} 
