# include <iostream>
using namespace std;
# define N 100010
int parent[N];
void InitializeDSet(int n);
int GetDSetNum(int x);
void MergeDSets(int x,int y);
int main(){
    int n,m;
    cin>>n>>m;
    InitializeDSet(n);
    while(m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M') MergeDSets(GetDSetNum(a), GetDSetNum(b));
        else{
            if(GetDSetNum(a)==GetDSetNum(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
void InitializeDSet(int n){//��ʼ��
    for(int i=0;i<n;++i) parent[i]=i;//ÿ�����ĸ����Ϊ�����������Լ����ϵĸ���㣩
}
int GetDSetNum(int x){//����x���ڼ��ϱ�ţ������ֵ�����á�·��ѹ�����Ż�
    if(parent[x]!=x) parent[x]=GetDSetNum(parent[x]);
    return parent[x];
}
void MergeDSets(int x,int y){//x��y�ֱ�Ϊ�����ϱ�ţ��������������
    parent[x]=y;//��parent[y]=x;
}

