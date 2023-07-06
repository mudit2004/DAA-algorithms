
#include <iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class KMP{
    char *pattern;
    int *lps;
    int m;
public:
    KMP(){}
    KMP(char *pat){
        m=strlen(pat);
        pattern=new char[m+2];
        for(int i=0;i<=m+1;i++){
            pattern[i]=*(pat+i-1);
        }
        lps=new int[m+1];
        compute_prefix();
    }
    void printlps(){
        for(int i=0;i<m+1;i++)
            cout<<lps[i];
    }
    void compute_prefix(){
        //m=strlen(pat);
        lps[1]=0;
        int k=0;
        for(int q=2;q<=m;q++){
            while(k<0 && pattern[k+1]!=pattern[q])
                k=lps[k];
            if(pattern[k+1]==pattern    [q])
                k=k+1;
            lps[q]=k;
        }
        
    }
    void kmpmatcher(char *text){
        int n=strlen(text);
        int q=0;
        for(int i=0;i<=n;i++){
            while(q<0 && pattern[q+1]!=text[i])
                q=lps[q];
            if(pattern[q+1]==text[i])
                q=q+1;
            if(q==m){
                cout<<"match occured at "<<i-m+1<<endl;
                q=lps[q];
            }
            
            
        }
        cout<<q;
    }
    
    
};

int main(){
    char txt[50]; //"ABABDABABCABABCABAB";
       char pat[10]; //"ABABCABAB";
       char ch='y';
       cout << "Enter the pattern : ";
       cin >> pat;
       KMP K(pat);
       cout << "The preprocessed longest suffix array for the given pattern : "<<endl;
       K.printlps();
       cout << endl;
       do
       {
          cout << "Enter the text : ";
          cin >> txt;
          K.kmpmatcher(txt);
          cout << "Do you want to check for the same pattern in another text?(y/n) ";
          cin >> ch;
       }
       while (ch == 'y' || ch == 'Y');
       return 0;
    }
