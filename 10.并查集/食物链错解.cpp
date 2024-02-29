//（以下集群指当某句话提及的两个动物之前都未提及过时，他们属于一个新的食物链集群）  
//这种解法没有用到并查集模型，数组元素直接表示动物所属类（A、B、C），默认了每个集群第一个被提及的动物为A类，但实际上不一定，这样是错的！！
//其实题目说了每个动物“并不知道它到底是哪一种”就提示了不能这样做（不能给提及的动物划分绝对种类），只能记录互吃的相对关系
//【两种方法的区别在于，前者在集群内<类似一个地址空间>的互吃关系正确，但集群间<类似整个内存>不一定；后者在集群内和集群间的互吃关系都能正确维护】 
#include <iostream>
using namespace std;
//A、B、C是三种集合，每个食物链集群（有环图）是A、B、C三种动物的总集合 
int N,K;
int t[50010];// A=>-1, B=>-2, C=>-3
int cnt;
int main() {
    cin>>N>>K;
    int x,a,b;
    while(K--){
        cin>>x>>a>>b;
        //判断真假
        if(a>N||b>N||a<=0||b<=0||(x==2&&a==b)){
            ++cnt; continue;
        }
        int t1=t[a], t2=t[b];
        if(x==1){
            if(t1!=0&&t2!=0&&t1!=t2){ ++cnt; continue; }
        }
        else{
            if(t1!=0&&t2!=0&&!((t1==-1&&t2==-2)||(t1==-2&&t2==-3)||(t1==-3&&t2==-1)))
            { ++cnt; continue; }
        }
        //未提及
        if(!t1&&!t2){
            t[a]=-1;//某A类集合第一个
            if(x==1) t[b]=-1;//该A类集合第二个
            else t[b]=-2;//某B类集合第一个
            continue;
        }
        if(x==2){
            if(!t1){
                switch(t2){
                    case -1: t[a]=-3;break;
                    case -2: t[a]=-1;break;
                    case -3: t[a]=-2;break;
                    default: break;
                }
            }
            else if(!t2){
                switch(t1){
                    case -1: t[b]=-2;break;
                    case -2: t[b]=-3;break;
                    case -3: t[b]=-1;break;
                    default: break;
                }
            }
        }
        else{
            if(!t1) t[a]=t[b];
            else if(!t2) t[b]=t[a];
        }
    }
    cout<<cnt;
    return 0;
}

