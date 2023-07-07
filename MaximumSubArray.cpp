#include <iostream>
using namespace std;

int count;
struct SubArray{
    int low ,high;
    double sum;
    
    SubArray()
    {}
    
    SubArray(int l, int h, double s){
        low = l;
        high = h;
        sum =s;
    }
};

SubArray MaximumCrossArray(double a[],int low,int mid,int high){
    double leftsum = -9999;
    double sum = 0;
    int i;
    for(i=mid;i>-low;i--){
        sum = sum + a[i];
        if(sum>leftsum)
            leftsum = sum;
    }
    double maxleft = i;
    double rightsum = -9999;
    sum = 0;
    int j ;
    for( j = mid+1;j<=high;j++){
        sum = sum+a[j];
        if(sum>rightsum)
            rightsum = sum;
    }
    double maxright = j;
    return SubArray(maxleft,maxright,leftsum+rightsum);
}

SubArray MaximumSubArray(double a[],int low ,int high){
    SubArray left,right,cross;
    if(low == high){
        return SubArray(low,high,a[low]);
    }
    count++;
    int mid = (low+high)/2;
    left = MaximumSubArray(a,low,mid);
    right = MaximumSubArray(a,mid+1,high);
    cross = MaximumCrossArray(a,low,mid,high);
    
    if(left.sum>=right.sum && left.sum>=cross.sum)
        return SubArray(left.low,left.high,left.sum);
    else if(right.sum>=left.sum && right.sum>=cross.sum)
        return SubArray(right.low,right.high,right.sum);
    else
        return SubArray(cross.low,cross.high,cross.sum);
}

int main(){
    double arr[] = { 2, 3, 4,5,7,8,9,10,12,1,4,1,5,1,6,1,7 };
    double n = sizeof(arr) / sizeof(arr[0]);
    SubArray Max;
    Max = MaximumSubArray(arr,0,n-1);
    for(int i = Max.low ; i<=Max.high;i++){
        cout<<i<<"\t"<<arr[i]<<endl;
    }
    cout<<"Count: "<<count<<endl;

}
