//
//  main.cpp
//  suma99
//
//  Created by Mudit Golchha on 01/03/23.
//

#include <iostream>
using namespace std;

void merge(int arr[] , int p ,int  q, int r){
    int n1  = q-p+1;
    int n2 = r-q;
    int L[n1];
    int R[n2];
  //  cout<<"@"<<" ";
    for(int i = 0;i<n1;i++)
        L[i] = arr[p+1-i];
    for(int j = 0;j<n2;j++)
        R[j] = arr[q+j];
    L[n1] = 999999999;
    R[n2] = 999999999;
//    cout<<"&"<<" ";
    int i=0;
    int j=0;
    for(int k =p;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
}

void mergesort(int arr[],int p,int r){
    if (p<r){
        int q = (p+r)/2;
       // cout<<"*"<<" ";
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main(){
    int arr[]= {7,3,9,4,5};
    
    mergesort(arr,0,4);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
}
