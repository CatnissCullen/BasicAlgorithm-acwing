#include <iostream>
#include "queue"
#include "algorithm"
#include "unordered_map"
using namespace std;
string m="12345678x";
string a;
pair<int,int> d[4]={{0,1},{1,0},{0,-1},{-1,0}};
queue<string> q1;//状态队列
queue<pair<int,int>> q2;//x的位置队列
queue<int> q3;//步数队列
unordered_map<string,bool> rec;//记录某状态是否已经出现
int r,c;
int main(){
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j){
            char t; scanf("%c%*c",&t);
            a+=t;
            if(t=='x') r=i, c=j;
        }
    if(a==m){
        cout<<0; return 0;
    }
    //bfs
    rec[a]=true, q1.push(a), q2.emplace(r,c), q3.push(0);
    while(!q1.empty()){
        string t=q1.front(); q1.pop();
        int rt=q2.front().first, ct=q2.front().second; q2.pop();
        int lt=q3.front(); q3.pop();
        for(auto& dd:d){
            int rtt=rt+dd.first, ctt=ct+dd.second;
            if(0<=rtt&&rtt<3&&0<=ctt&&ctt<3){
                string tt=t; swap(tt[rtt*3+ctt],tt[rt*3+ct]);
                if(rec.find(tt)!=rec.end()) continue;
                if(tt==m){
                     cout<<lt+1; return 0;
                }
                rec[tt]=true, q1.push(tt), q2.emplace(rtt,ctt), q3.push(lt+1);
            }
        }
    }
    cout<<-1;
}

