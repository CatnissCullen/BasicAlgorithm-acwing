# include <stdio.h>
# include <iostream>
using namespace std;
# define N 1010
int n1,n2,m;
int a[N][N],S[N][N];//ȫ�ֱ����ڱ���ʱ�Զ���ʼ����S[i][j]��Ϊ0
int main(){
    cout<<"Size of matrix:  "; scanf("%d%d",&n1,&n2);
    cout<<"Number of sub-matrices:  "; scanf("%d",&m);
    cout<<"Your matrix:\n";
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            scanf("%d",&a[i][j]);//�������a
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];//Ԥ������ǰ׺�;���
    int x1,y1,x2,y2;
    cout<<"Your sub-matrices as 'up-left_row-index up-left_col-index down-right_row-index down-right_col-index':  ";
    while(m--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2); printf("%d\n",S[x2][y2]-S[x2][y1-1]-S[x1-1][y2]+S[x1-1][y1-1]);//����ǰ׺���������Ӿ���ĺ�
    }
}
