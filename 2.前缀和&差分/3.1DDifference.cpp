# include <stdio.h>
# include <iostream>
using namespace std;
# define N 100010
int n,m;
int a[N],d[N];//全局变量在编译时自动初始化，d[i]均为0
void Insert(int l,int r,int c);//在a的各元素前插入c时d的变化（d初始的构造也用Insert进行）
int main(){
    cout<<"Size of array:  "; scanf("%d",&n);
    cout<<"Number of insertions:  "; scanf("%d",&m);
    cout<<"Your array:  ";
    for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);//读入数组a
		Insert(i,i,a[i]);//d的初始构造（预处理）
	}
    cout<<"Your intervals & inserted lengths as 'left_index right_index length':  \n";
    int l,r,c;
    while(m--){
        scanf("%d%d%d",&l,&r,&c); Insert(l,r,c);//通过用Insert函数处理查分数组间接实现对a元素插入常数的处理
    }
    cout<<"New array:  ";
    for(int i=1;i<=n;++i){
        d[i]+=d[i-1]; printf("%d ",d[i]);//最后再通过求d的前缀和将d原地变换为a
    }
}
void Insert(int l,int r,int c){
    d[l]+=c; d[r+1]-=c;
}
