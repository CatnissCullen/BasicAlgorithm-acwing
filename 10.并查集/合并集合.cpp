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
void InitializeDSet(int n){//初始化
    for(int i=0;i<n;++i) parent[i]=i;//每个结点的父结点为自身（各自是自己集合的根结点）
}
int GetDSetNum(int x){//返回x所在集合编号（根结点值），用【路径压缩】优化
    if(parent[x]!=x) parent[x]=GetDSetNum(parent[x]);
    return parent[x];
}
void MergeDSets(int x,int y){//x、y分别为两集合编号（即根结点索引）
    parent[x]=y;//或parent[y]=x;
}

