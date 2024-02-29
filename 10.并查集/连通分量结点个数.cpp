# include <iostream>
using namespace std;
# define N 100010
int parent[N];//每个结点的父结点
int setSize[N];//每个根结点的集合的元素数（只更新根结点对应的元素数，其他结点的size其实是其孩子结点的个数）
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
void InitializeDSet(int n){//初始化
    for(int i=0;i<n;++i){
        parent[i]=i;//每个结点的父结点为自身（各自是自己集合的根结点）
        setSize[i]=1;//每个集合里只有一个元素（自己）
    }
}
int GetDSetNum(int x){//返回x所在集合编号（根结点值），用【路径压缩】优化
    if(parent[x]!=x) parent[x]=GetDSetNum(parent[x]);
    return parent[x];
}
void MergeDSets(int x,int y){//x、y分别为两集合编号（即根结点索引）
    parent[x]=y;//或parent[y]=x;
    setSize[y]+=setSize[x];//更新嫁接后的唯一根结点的元素数
}

作者：ccccaterina
链接：https://www.acwing.com/activity/content/code/content/5273754/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
