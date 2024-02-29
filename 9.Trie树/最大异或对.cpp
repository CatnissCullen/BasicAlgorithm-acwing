# include <iostream>
using namespace std;
# define M 3100100//最多结点总数（最大二进制位数31*最大整数个数100000）
int nodes[M][2];//行号为结点索引，列号表示数码'0'或'1'，元素值为行号结点的孩子结点索引
int idx;//结点索引从1起（根结点为0号，置空）
int Bry(int x,int i);
void InsertString(int x);
int main(){
    int n; int res=0; int x;
    cin>>n;
    while(n--){//一边插入当前x，一边查找x与前面数的最大异或，这样就不会查求到重复的最大异或
        scanf("%d",&x);
        InsertString(x);//插入当前x
        int k=30; int j=0;
        int t=0;
        while(k>=0){//i一定，在Trie中求nums[i]的最大异或
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

