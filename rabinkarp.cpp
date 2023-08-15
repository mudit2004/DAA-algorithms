/*#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class RabinKarp
{
  char Pattern[100];
  int m;
  int d;
  long int q;

public:

  RabinKarp(char p[])
  {
    strcpy(Pattern, p);
    m = strlen(Pattern);
    d = 10;
    q = 100000;
  }

  void match(char Text[])
  {
     int n=strlen(Text);
     long int h = long(pow(d, m-1)) % q;
     long int p=0, t=0;
     for (int i=0; i<m; i++)
     {
      p = (p*d+(Pattern[i]-'a'+1)) % q;
      t = (t*d+(Text[i]-'a'+1)) % q;
     }
     cout << "Pattern = "<<p<<endl<<endl;
     for (int s=0; s<=n-m; s++)
     {
       cout << "T"<<s <<"="<<t<<endl;
    if (p == t)
    {
      int flag = 1;
      for (int i=0; i<m; i++)
      {
        if (Pattern[i] != Text[s+i])
        {
         flag = 0;
       break;
        }
      }
      if (flag)
          cout << "Pattern matches with shift" << s << endl;
    }
    if (s<n-m)
      t = (((t - (Text[s]-'a'+1)*h)*d)+(Text[s+m]- 'a'+1)) % q;
     }
  }
};
int main()
{
  char p[100], t[500];
  char ch;
  cout << "Enter the pattern to match: ";
  cin >> p;
  RabinKarp rk(p);
  do
  {
     cout << "Enter the text to match: ";
     cin >> t;
     rk.match(t);
     cout << "Do you want search in another text (y/n) ? ";
     cin >> ch;
  }
  while (ch == 'y' || ch == 'Y');
  return 0;
}*/

#include <iostream>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define d 10
void RK(char T[], char P[], int q){
    int m = strlen(P);
    int n = strlen(T);
    int t = 0, p= 0, h, i, j;
    h = pow(d, m-1);
    h = h%q;
    for(i = 0; i <m; i++){
        t = (d*t+T[i]) % q;
        p = (d*p+P[i]) % q;
    }
    for(i = 0; i<= n-m; i++){
        if(p==t){
            for(j = 0; j <m; j++){
                if(T[i+j] != P[j])
                    break;
            }
            if(j==m)
                cout<<"Found at"<<i<<endl;
        }
        if(i < n-m){
            t = (d*(t-T[i]*h) + T[i+m]) % q;
            if(t < 0)
                t = t+q;
        }
    }
}
int main()
{
    char T[30], P[10];
    cout <<"enter T: ";
    cin >> T;
    cout <<"enter P: ";
    cin >> P;
    cout<<" T: "<<T<<endl;
    cout<<" P: "<<P<<endl;
    int q = 13;
    RK(T, P, q);
    return 0;
}
