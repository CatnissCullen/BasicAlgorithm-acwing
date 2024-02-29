# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
# include <map>
# include <vector>
# define INF 0x3f3f3f3f
using namespace std;
int n,m,s,d;
int num[500];
int g[500][500];
int l[500];//���·����
int tol[500];//����Ԯ�����·�����ܾ�Ԯ��
int p[500];//����Ԯ�����·����ǰ��
int cnt[500];//���·����
int flg[500];//Dijsktra�㷨�ı������
vector<int> path;//���·���õ�ջ
int main(){
    memset(g,0x3f,sizeof g);
    memset(l,0x3f,sizeof l);
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;++i) cin>>num[i];
    for(int i=1;i<=m;++i){
        int x,y,w;
        cin>>x>>y>>w;
        g[x][y]=g[y][x]=w;
    }
    for(int i=0;i<n;++i) g[i][i]=0;
    
    cnt[s]=1; l[s]=0; p[s]=s; tol[s]=num[s];
    for(int i=0;i<n;++i){
        int t=-1;
        for(int j=0;j<n;++j){
            if(!flg[j]&&(t==-1||l[j]<l[t])) t=j;
        }
        for(int j=0;j<n;++j){
            if(l[j]>l[t]+g[t][j]){//·����Ҫ���£���·������Ϊt��·����
                cnt[j]=cnt[t]; l[j]=l[t]+g[t][j];
                p[j]=t;
                tol[j]=tol[t]+num[j];
            }
            else if(j!=t&&l[j]==l[t]+g[t][j]){//·���ظ��Ҳ���������·��������t��·���������ȽϾ�Ԯ�����ж��Ƿ����·���;�Ԯ��
                cnt[j]+=cnt[t]; 
                if(tol[j]<tol[t]+num[j]){
                    p[j]=t;
                    tol[j]=tol[t]+num[j]; 
                }
            }
        }
        flg[t]=1;
    }
    
    int i=d; 
    while(1){
        path.push_back(i); 
        if(p[i]==i) break;
        else{
            i=p[i]; 
        }
    }
    cout<<cnt[d]<<" "<<tol[d]<<endl;
    cout<<path.back(); path.pop_back();
    while(path.size()){
        cout<<" "<<path.back();
        path.pop_back();
    }
    cout<<endl;
}
