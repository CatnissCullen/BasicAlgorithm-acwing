# include <iostream>
using namespace std;
# define N 100010
int parent[N];//ÿ�����ĸ����
int setSize[N];//ÿ�������ļ��ϵ�Ԫ������ֻ���¸�����Ӧ��Ԫ��������������size��ʵ���亢�ӽ��ĸ�����
void InitializeDSet(int n);
int GetDSetNum(int x);
void MergeDSets(int x,int y);
int main(){
    int n,m;
    cin>>n>>m;
    InitializeDSet(n);
    while(m--){
        char op[5];
        int a,b;
        scanf("%s",op);
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            if(GetDSetNum(a)== GetDSetNum(b)) continue;
            MergeDSets(GetDSetNum(a), GetDSetNum(b));
        }
        else if(op[1]=='1'){
            scanf("%d%d",&a,&b);
            if(GetDSetNum(a)== GetDSetNum(b)) puts("Yes");
            else puts("No");
        }
        else{
            scanf("%d",&a);
            printf("%d\n", setSize[GetDSetNum(a)]);
        }
    }
}
void InitializeDSet(int n){//��ʼ��
    for(int i=0;i<n;++i){
        parent[i]=i;//ÿ�����ĸ����Ϊ�����������Լ����ϵĸ���㣩
        setSize[i]=1;//ÿ��������ֻ��һ��Ԫ�أ��Լ���
    }
}
int GetDSetNum(int x){//����x���ڼ��ϱ�ţ������ֵ�����á�·��ѹ�����Ż�
    if(parent[x]!=x) parent[x]=GetDSetNum(parent[x]);
    return parent[x];
}
void MergeDSets(int x,int y){//x��y�ֱ�Ϊ�����ϱ�ţ��������������
    parent[x]=y;//��parent[y]=x;
    setSize[y]+=setSize[x];//���¼޽Ӻ��Ψһ������Ԫ����
}

���ߣ�ccccaterina
���ӣ�https://www.acwing.com/activity/content/code/content/5273754/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
