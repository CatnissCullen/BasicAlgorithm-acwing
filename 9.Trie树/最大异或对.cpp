# include <iostream>
using namespace std;
# define M 3100100//�������������������λ��31*�����������100000��
int nodes[M][2];//�к�Ϊ����������кű�ʾ����'0'��'1'��Ԫ��ֵΪ�кŽ��ĺ��ӽ������
int idx;//���������1�𣨸����Ϊ0�ţ��ÿգ�
int Bry(int x,int i);
void InsertString(int x);
int main(){
    int n; int res=0; int x;
    cin>>n;
    while(n--){//һ�߲��뵱ǰx��һ�߲���x��ǰ�����������������Ͳ�������ظ���������
        scanf("%d",&x);
        InsertString(x);//���뵱ǰx
        int k=30; int j=0;
        int t=0;
        while(k>=0){//iһ������Trie����nums[i]��������
            if(nodes[j][!Bry(x,k)]!=0) t=t*2+!Bry(x, k), j=nodes[j][!Bry(x, k)];
            else t=t*2+Bry(x, k), j=nodes[j][Bry(x, k)];
            --k;
        }
        if((t^x)>res) res=t^x;
    }
    printf("%d\n",res);
}
int Bry(int x,int i){
    return (x>>i)&1;
}
void InsertString(int x){
    int i,j;
    for(i=0,j=30;j>=0;--j){
        if(nodes[i][Bry(x,j)]==0) nodes[i][Bry(x,j)]=++idx;
        i=nodes[i][Bry(x,j)];
    }
}

