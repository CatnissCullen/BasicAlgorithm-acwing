# include <stdio.h>
# include <iostream>
using namespace std;
# define N 100010
int n,m;
int a[N],d[N];//ȫ�ֱ����ڱ���ʱ�Զ���ʼ����d[i]��Ϊ0
void Insert(int l,int r,int c);//��a�ĸ�Ԫ��ǰ����cʱd�ı仯��d��ʼ�Ĺ���Ҳ��Insert���У�
int main(){
    cout<<"Size of array:  "; scanf("%d",&n);
    cout<<"Number of insertions:  "; scanf("%d",&m);
    cout<<"Your array:  ";
    for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);//��������a
		Insert(i,i,a[i]);//d�ĳ�ʼ���죨Ԥ����
	}
    cout<<"Your intervals & inserted lengths as 'left_index right_index length':  \n";
    int l,r,c;
    while(m--){
        scanf("%d%d%d",&l,&r,&c); Insert(l,r,c);//ͨ����Insert����������������ʵ�ֶ�aԪ�ز��볣���Ĵ���
    }
    cout<<"New array:  ";
    for(int i=1;i<=n;++i){
        d[i]+=d[i-1]; printf("%d ",d[i]);//�����ͨ����d��ǰ׺�ͽ�dԭ�ر任Ϊa
    }
}
void Insert(int l,int r,int c){
    d[l]+=c; d[r+1]-=c;
}
