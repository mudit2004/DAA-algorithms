#include<iostream>
#include<iomanip>
#define MAX 20
#define INF 99999
#define NIL -1
using namespace std;
void FloydWharshal(int Cost[][MAX],int D[][MAX],int P[][MAX],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		D[i][j] = Cost[i][j];
		if(D[i][j]==0 || D[i][j]==INF)
			P[i][j] = NIL;
		else
		    P[i][j] = i;
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
			if(D[i][k]+D[k][j] < D[i][j] )
				{
			    D[i][j] = D[i][k]+D[k][j];
			    P[i][j] = P[k][j];
			    }
			}
		}
	}
  
}
int main()
{
 int n;
 int i,j;
	
 //Test Input-1
 n=5;
 //Cost Matrix for the input graph
 int Cost[][MAX]={ {0,0,0,0,0,0},
      {0,0,3,8,INF,-4},
      {0,INF,0,INF,1,7},
      {0,INF,4,0,INF,INF},
      {0,2,INF,-5,0,INF},
      {0,INF,INF,INF,6,0} };
      
 int Dist[MAX][MAX];
 int Parent[MAX][MAX];
 FloydWharshal(Cost,Dist,Parent,n);
 cout<<"\n\nDistance Matrix: ";
 for(i=1;i<=n;i++)
 {
  cout<<"\n";
  for(j=1;j<=n;j++)
  {
   if(Dist[i][j]==INF)
    cout<<"INF\t\t";
   else
    cout<<Dist[i][j]<<"\t\t";
  }  
 }
 cout<<"\n\nParent Matrix: ";
 for(i=1;i<=n;i++)
 {
  cout<<"\n";
  for(j=1;j<=n;j++)
  {
   if(Parent[i][j]==NIL)
    cout<<"NIL\t\t";
   else
    cout<<Parent[i][j]<<"\t\t";
  }  
 }
	
}
