#include <iostream>
using namespace std;
const int N = 100010;
unsigned long long A[N],B[N];
int n,m;
int main(){
    unsigned long long x;
    cin>>n>>m>>x;
    for(int k=0;k<n;++k) scanf("%llu",&A[k]);
    for(int k=0;k<m;++k) scanf("%llu",&B[k]);
    int i=0,j=m-1;
    while(i<n&&j>=0){
        if(A[i]+B[j]>x) j--;
        else if(A[i]+B[j]<x) i++;
        else {cout<<i<<" "<<j; return 0;}
    }
}
