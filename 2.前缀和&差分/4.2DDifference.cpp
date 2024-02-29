# include <stdio.h>
# include <iostream>
using namespace std;
# define N 1010
int n1,n2,m;
int a[N][N],d[N][N];//全局变量在编译时自动初始化，d[i][j]均为0
void Insert(int x1,int y1,int x2,int y2,int c);//在a的各元素前插入c时d的变化（d初始的构造也用Insert进行）
int main(){
    cout<<"Size of matrix:  "; scanf("%d%d",&n1,&n2);
    cout<<"Number of insertions:  "; scanf("%d",&m);
    cout<<"Your matrix:\n";
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j){
            scanf("%d",&a[i][j]);//读入数组a
            Insert(i,j,i,j,a[i][j]);//d的初始构造（预处理）
        }
    cout<<"Your sub-matrices & inserted lengths as "
          "'up-left_row-index up-left_col-index down-right_row-index down-right_col-index length':  \n";
    int x1,y1,x2,y2,c;
    while(m--){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c); Insert(x1,y1,x2,y2,c);//通过用Insert函数处理查分数组间接实现对a元素插入常数的处理
    }
    cout<<"New matrix:\n";
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j) {
            d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];//最后再通过求d的前缀和将d原地变换为a
            printf("%d ",d[i][j]);
        }
        cout<<endl;
    }
}
void Insert(int x1,int y1,int x2,int y2,int c){
    d[x1][y1]+=c;
    d[x2+1][y1]-=c;
    d[x1][y2+1]-=c;
    d[x2+1][y2+1]+=c;
}
