# include <stdio.h>
# include <iostream>
using namespace std;
# define N 1010
int n1,n2,m;
int a[N][N],d[N][N];//ȫ�ֱ����ڱ���ʱ�Զ���ʼ����d[i][j]��Ϊ0
void Insert(int x1,int y1,int x2,int y2,int c);//��a�ĸ�Ԫ��ǰ����cʱd�ı仯��d��ʼ�Ĺ���Ҳ��Insert���У�
int main(){
    cout<<"Size of matrix:  "; scanf("%d%d",&n1,&n2);
    cout<<"Number of insertions:  "; scanf("%d",&m);
    cout<<"Your matrix:\n";
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j){
            scanf("%d",&a[i][j]);//��������a
            Insert(i,j,i,j,a[i][j]);//d�ĳ�ʼ���죨Ԥ����
        }
    cout<<"Your sub-matrices & inserted lengths as "
          "'up-left_row-index up-left_col-index down-right_row-index down-right_col-index length':  \n";
    int x1,y1,x2,y2,c;
    while(m--){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c); Insert(x1,y1,x2,y2,c);//ͨ����Insert����������������ʵ�ֶ�aԪ�ز��볣���Ĵ���
    }
    cout<<"New matrix:\n";
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j) {
            d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];//�����ͨ����d��ǰ׺�ͽ�dԭ�ر任Ϊa
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
