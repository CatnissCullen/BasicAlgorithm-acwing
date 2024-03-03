#include <iostream>
using namespace std;
const int N = 100010;
long long a[N],b[N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i) scanf("%lld",&a[i]);
    for(int i=0;i<m;++i) scanf("%lld",&b[i]);
    int i=0,j=0;
    while(i<n){
        while(j<m&&b[j]!=a[i]) ++j;
        if(j==m){ cout<<"No"; return 0; }
        else ++i,++j; //b[j]==a[i]£¬Ôòi¡¢j¶¼Ç°ÒÆ
    }
    --i,--j;
    if(a[i]==b[j]) cout<<"Yes";
    else cout<<"No";
}
