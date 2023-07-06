#include<iostream>m,/, ≥
#include<iomanip>
#define MAX 20
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class SList
{
    private:
        Node *a;
        int size;
    public:
        SList();
        bool insertEnd(int);
        bool ElementAt(int,int&);
        int GetSize()    {    return size;        }
};
SList::SList()
{
    a = NULL;
    size = 0;
}
bool SList::insertEnd(int x)
{
    Node *n;
     n = new Node;
    if(n==NULL)
    {
        return false;
    }
    n->data = x;
    n->next = NULL;
    if(a==NULL)
    {
        a = n;
        size++;
        return true;
    }
    Node *t;
    t = a;
    while(t!=NULL)
    {
        if(t->next==NULL)
        {
            t->next = n;
            size++;
            return true;
        }
        t = t->next;
    }
    return false;
}
bool SList::ElementAt(int p, int &x)
{
    Node *t = a;
    int c=1;
    while(t!=NULL)
    {
        if(c==p)
        {
            x = t->data;
            return true;
        }
        
        t = t->next;
        c++;
    }
    return false;
}
struct Vertex
{
    SList AdjList;
    int Value;
    int Parent;
    int Distance;
};
class Graph
{
    Vertex *V;
    int size;
    void Relax(int, int, int [][MAX]);
    public:
        Graph(int);
        void AddEdge(int,int);
        bool BellmanFord(int [][MAX],int);
        void ShowGraph();
};
void Graph::Relax(int u, int v, int w[][MAX])
{
    if(V[v].Distance>V[u].Distance+w[u][v])
    {
        V[v].Distance = V[u].Distance+w[u][v];
        V[v].Parent = u;
    }
}
Graph::Graph(int n)
{
    size = n;
    V = new Vertex[n];
    for(int i=0;i<n;i++)
    {
        V[i].Value = i;
        V[i].Parent = -1;
        V[i].Distance = 9999;
    }
}
void Graph::ShowGraph()
{
    int mincost=0;
    cout<<"\n"<<"Vertex | "<<"Parent | "<<"Distance | ";
    cout<<"\n********************************************";
    for(int i=0;i<size;i++)
    {
        cout<<"\n";
        if(V[i].Parent==-1)
            cout<<setw(6)<<V[i].Value<<" | "<<"Source"<<" | "<<setw(8)<<V[i].Distance<<" | ";
        else
            cout<<setw(6)<<V[i].Value<<" | "<<setw(6)<<V[i].Parent<<" | "<<setw(8)<<V[i].Distance<<" | ";
        
    }
    cout<<"\n********************************************";
}
bool Graph::BellmanFord(int w[][MAX],int s)
{
    V[s].Distance=0;
    int u,v,p,i;
    for(i=0;i<size-1;i++)
    {
        for(u=0;u<size;u++)
        {
            for(int p=1;p<=V[u].AdjList.GetSize();p++)
            {
                if(V[u].AdjList.ElementAt(p,v))
                {
                    if(w[u][v]!=0)
                    {
                        Relax(u,v,w);
                    }
                    
                }
            }
        }
    }
    
    for(u=0;u<size;u++)
    {
        for(p=1;p<=V[u].AdjList.GetSize();p++)
        {
            if(V[u].AdjList.ElementAt(p,v))
            {
                if(V[v].Distance>V[u].Distance+w[u][v])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void Graph::AddEdge(int from, int to)
{
    V[from].AdjList.insertEnd(to);
}
int main()
{
    int n;
    //Test Input-1
    n=6;
    //Cost Matrix for the input graph
    int b[][MAX]={    {0,6,4,5,0,0},
                        {0,0,0,0,-1,8},
                        {0,-2,0,0,3,0},
                        {0,0,-2,0,0,-1},
                        {0,0,0,0,0,3},
                        {0,0,0,0,0,0} };

    Graph g(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]!=0)
            {
                g.AddEdge(i,j);
            }
        }
    }
    int s=0;
    bool res;
    res = g.BellmanFord(b,s);
    if(res)
    {
cout<<"\n\nSingle Source Shortest Path (Bellman-Ford Algorithm) Result:\n";
        g.ShowGraph();
    }
    else
    {
        cout<<"\nNegative Weight Cycle is Present. \nSo, Could Not find Shortest Path....";
    }
}
