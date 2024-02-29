# include <stdio.h>
# include <iostream>
using namespace std;
# define N 100010
int n,m;
int a[N],S[N];//全局变量在编译时自动初始化，S[i]均为0
int main(){
    cout<<"Size of array:  "; scanf("%d",&n);
    cout<<"Number of intervals:  "; scanf("%d",&m);
    cout<<"Your array:  ";
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);//读入数组a
//    S[0]=0;
    for(int i=1;i<=n;++i) S[i]=S[i-1]+a[i];//预处理：求前缀和数列
    cout<<"Your intervals as 'left_index right_index':  ";
    int l,r;
    while(m--){
        scanf("%d%d",&l,&r); printf("%d\n",S[r]-S[l-1]);//利用前缀和数组求a[l]到a[r]的和
    }
}
