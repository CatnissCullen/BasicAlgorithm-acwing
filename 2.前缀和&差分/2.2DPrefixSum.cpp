# include <stdio.h>
# include <iostream>
using namespace std;
# define N 1010
int n1,n2,m;
int a[N][N],S[N][N];//全局变量在编译时自动初始化，S[i][j]均为0
int main(){
    cout<<"Size of matrix:  "; scanf("%d%d",&n1,&n2);
    cout<<"Number of sub-matrices:  "; scanf("%d",&m);
    cout<<"Your matrix:\n";
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            scanf("%d",&a[i][j]);//读入矩阵a
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];//预处理：求前缀和矩阵
    int x1,y1,x2,y2;
    cout<<"Your sub-matrices as 'up-left_row-index up-left_col-index down-right_row-index down-right_col-index':  ";
    while(m--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2); printf("%d\n",S[x2][y2]-S[x2][y1-1]-S[x1-1][y2]+S[x1-1][y1-1]);//利用前缀和数组求子矩阵的和
    }
}
