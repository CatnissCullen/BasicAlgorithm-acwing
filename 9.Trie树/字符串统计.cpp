# include <iostream>
using namespace std;
# define N 100010
char str[N];
int childNodes[N][26];//以都是小写字母为例，N为最多结点数，每个结点的孩子结点（分支）最多有26个（条）
int endCnt[N];//以当前结点结尾的单词个数
int idx=1;//可变索引，值为未占用的最小索引，下标为0的点用作根结点或空结点
void InsertNodes(char* s);
int Query(char* s);
int main(){
    int n;
    cin>>n;
    while(n--){
        char op;
        scanf("%*c%c%*c%s",&op,str);
        if(op=='I') InsertNodes(str);
        else printf("%d\n",Query(str));
    }
}
void InsertNodes(char* s){//将一个字符串入树
    int k;//某字符在合法字符中的序号（将字符转化为childNodes列下标）
    int i,j;
    for(i=0,j=0; s[j] != '\0'; ++j){//i从根结点开始，为树中结点索引；j从当前字符串第一个字符开始，为字符串中字符索引
        k= s[j] - 'a';
        if(!childNodes[i][k]) childNodes[i][k]=idx++;//若无当前字符，创建字符结点
        i=childNodes[i][k];//更新i，指向新的字符结点
    }//i为当前字符串中最后一个字符对应的结点的索引
    ++endCnt[i];
}
int Query(char* s){//统计树中某字符串的个数：①沿着树支找到连续的所有字符 ②返回最后一个字符的endCnt
    int k;//某字符在合法字符中的序号（将字符转化为childNodes列下标）
    int i,j;
    for(i=0,j=0; s[j] != '\0'; ++j){//i从根结点开始，为树中结点索引；j从当前字符串第一个字符开始，为字符串中字符索引
        k= s[j] - 'a';
        if(!childNodes[i][k]) return 0;//若无当前字符，返回0个
        else i=childNodes[i][k];//否则更新i，指向新的字符结点
    }//i为当前字符串中最后一个字符对应的结点的索引
    return endCnt[i];//返回endCnt[i]个
}
