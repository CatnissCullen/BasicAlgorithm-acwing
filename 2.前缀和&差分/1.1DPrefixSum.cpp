# include <stdio.h>
# include <iostream>
using namespace std;
# define N 100010
int n,m;
int a[N],S[N];//ȫ�ֱ����ڱ���ʱ�Զ���ʼ����S[i]��Ϊ0
int main(){
    cout<<"Size of array:  "; scanf("%d",&n);
    cout<<"Number of intervals:  "; scanf("%d",&m);
    cout<<"Your array:  ";
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);//��������a
//    S[0]=0;
    for(int i=1;i<=n;++i) S[i]=S[i-1]+a[i];//Ԥ������ǰ׺������
    cout<<"Your intervals as 'left_index right_index':  ";
    int l,r;
    while(m--){
        scanf("%d%d",&l,&r); printf("%d\n",S[r]-S[l-1]);//����ǰ׺��������a[l]��a[r]�ĺ�
    }
}
