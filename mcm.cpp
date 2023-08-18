#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
long int count1=0;
float count2 = 0;
int MatrixChainDP(int p[], int n, int **s){
	int m[n][n];
	int i, j, k, L, q;
	for(i = 1; i < n; i++)
		m[i][i] = 0;
	for(L=2; L < n; L++){
		for(i = 1; i < n-L+1; i++){
			j = i + L -1;
			m[i][j] = INT_MAX; 	
			for(k = i; k <= j-1 ; k++){
		 		count1++;
				q = m[i][k] +  m[k+1][j] + p[i-1]*p[k]*	p[j];
				if( q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;		
				}	
			}  	
		}
	}
	return m[1][n-1];
}
int MatrixChainDC(int p[], int i, int j){
	if(i == j)
		 return 0;
	int q, min = INT_MAX, k;
	for(k = i; k <= j-1; k++){
		count2++;
		q = MatrixChainDC(p, i, k) + MatrixChainDC(p,k+1, j)+ p[i-1]*p[k]*p[j];
  		if(q < min)
  			min = q;
	}	
	return min; 		 
}
void PrintOptPar(int **s, int i, int j){
	if(i == j)
		 cout<<"A"<<i;
	else{
		cout<<"(";
		PrintOptPar(s, i, s[i][j]);
		PrintOptPar(s, s[i][j] + 1, j);		  
		cout<<")";		  	  	  	  
    }				   	   	  	 	    
}
int main(){
	int n, i;
	long int res;
	cout <<"Enter no.of matrix + 1(p val req): ";
	cin >> n;
	int p[n];
	cout <<"Enter "<<n <<"values for p:"<<endl;
	for(i = 0; i < n; i++){
		cin >>p[i];
	}
	cout <<"P values: "<<endl;
	for(i = 0; i < n; i++){
		cout<< p[i]<<" ";
	}
	cout << endl;
	int **s;
	s = new int*[n];
	for(i = 0; i < n; i++)
		s[i] = new int[n];
	res = MatrixChainDP(p, n, s);
	cout<<"Dynamic Prog: "<<endl;
	cout<<"Min Scalar Multiplications: "<<res<<endl;
	cout<<"Count: "<<count1<<endl;
	res = MatrixChainDC(p, 1, n-1);
	cout<<"Div & Conq : "<<endl;
	cout<<"Min Scalar Multiplications: "<<res<<endl;
	cout<<"Count: "<<count2<<endl;
	cout<<"Optimal Paranthesis:" <<endl;
	PrintOptPar(s, 1, n-1);
	return 0;
}
