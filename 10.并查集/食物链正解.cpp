#include <iostream>
using namespace std;
// 用并查集维护食物链集群间互吃关系，每两个结点间子吃父，跨结点关系由两点间路径长模3的余数决定，种类是否相等由两点各自
// 到当前集群根结点路径长模3的余数是否相等决定，这样使两集群相接的语句出现时也能正确合并互吃关系
int N, K;
int p[50010], d[50010];// p[i]=j：j吃i；d[i]=l：i到当前集群根结点的路径长为l

int find(int x){
    if (p[x]!=x){
        int t=find(p[x]);
        d[x]+=d[p[x]];// 因为每句话检查开始时都对两个结点调用find，所以可以在find中更新d
        p[x]=t;
    }
    return p[x];
}

int main(){
    cin>>N>>K;
    for(int i=1;i<=N;++i) p[i]=i;
    int cnt=0;
    while(K--){
        int x,a,b;
        cin>>x>>a>>b;
        //不用把判断真假和对真语句的操作分开，直接对x、a、b的数值分情况讨论
        if(a>N||b>N||a<=0||b<=0) ++cnt;
        else{
            int pa=find(a), pb=find(b);
            if(x==1){
                if (pa==pb&&(d[a]-d[b])%3) ++cnt;//1语句假（在同一集群中且d不相等）
                else if(pa!=pb){//1语句真且a、b当前在两个不同集群，则合并集群
                    p[pa]=pb;//设a根结点与b的相同
                    d[pa]=d[b]-d[a];//对齐a到b相对于根结点的层级（d[pa]有可能为负数！！）
                }
            }
            else{
                if(pa==pb&&(d[a]-d[b]-1)%3) ++cnt;//2语句假（在同一集群中且d之差模3余数不为1或-2，即该差-1模3余0，
                // 不能写成((d[a]-d[b])%3!=1)！会漏掉根结点吃余-2点的情况！！！！！可写成(((d[a]-d[b])%3+3)%3!=1)，等价
                // <(-3n)%3=0,(-3n+m)%3=-m!!>）
                else if(pa!=pb){//2语句真且a、b当前在两个不同集群，则合并集群
                    p[pa]=pb;//设a根结点与b的相同
                    d[pa]=d[b]+1-d[a];//对齐a到b相对于根结点的层级的下一级（d[pa]有可能为负数！！）
                }
            }
        }
    }
    cout<<cnt;

    return 0;
}

