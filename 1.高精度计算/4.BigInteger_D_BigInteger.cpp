# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;
vector<int> Division(vector<int> &A, int b,int &r);//r为余数
int main(){
    cout<<"//Division//\n\n";
    string a; int b; int r;
    vector<int> A;
    cout<<"Enter big integer A (>=0):  ";
    cin>>a;//先用string读入大整数（暂存为字符串）
    cout<<"Enter small integer b (>=0):  ";
    cin>>b;//小整数直接读入int
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//再把大整数放入vector，先放低位再放高位
    vector<int> C=Division(A, b,r);//求和结果数组
    cout<<"\nResult:  A div b = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//从高位到低位打印
    cout<<" ...... "<<r;//打印余数
    cout<<endl;
}
/*大整数/小整数，传回余数*/
vector<int> Division(vector<int> &A, int b,int &r){
    vector<int> C;
    r=0;//余数初始化为0，暂存每轮循环被除数，每轮循环开始前是i+1位算得的余数
    for(int i=A.size()-1;i>=0;--i){//除法从被除数A最高位开始往低位算
        r=r*10+A[i];//先计算本轮循环被除数
        C.push_back(r/b);//用【整数】得商C的第i位
        r%=b;//用【取余】得第i位的余数
    }
    reverse(C.begin(),C.end());//最后将C倒置（变回从低位到高位的存储规则）
    while(C.size()>1&&C.back()==0) C.pop_back();//若最后C高位有0且总共不只1位（1位时保留0）须舍弃高位0
    return C;
}
