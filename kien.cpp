#include <iostream>
using namespace std;

long getMax(long a,long b){
    return a>b?a:b;
}
long maxSquare(long *a,int start,int endx,int maxx){
    if(endx<start){
        return 0;
    }
    if(start == endx){
        return a[start];
    }
    int minIndex=start;
    for(int i=start;i<=endx;i++){
        if(a[i]<a[minIndex]){
            minIndex=i;
        }
    }
    long local_max=a[minIndex]*(endx-start+1);
    long lf=maxSquare(a,start,minIndex-1,maxx);
    long rg=maxSquare(a,minIndex+1,endx,maxx);
    maxx=getMax(lf,local_max);
    maxx=getMax(rg,maxx);
    return maxx;
}
int main() {
    long n;
    cin>>n;
    long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxSquare(a,0,n-1,0);
    return 0;
}
