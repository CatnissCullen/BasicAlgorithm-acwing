# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
using namespace std;
vector<int> Addition(vector<int> &A,vector<int> &B);
int main(){
	cout<<"//Addition//\n\n";
    string a,b;
    vector<int> A,B;
    cout<<"Enter big integer A (>=0):  ";
    cin>>a;//先用string读入大整数（暂存为字符串）
    cout<<"Enter big integer B (>=0):  ";
    cin>>b;
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//再放入vector，先放低位再放高位
    for(int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');
    vector<int> C=Addition(A,B);//求和结果数组
    cout<<"\nResult:  A + B = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//从高位到低位打印
    cout<<endl;
}
/*大整数+大整数*/
vector<int> Addition(vector<int> &A,vector<int> &B){
    vector<int> C; int t=0;//暂存A、B第i位的和（低位对齐），每轮循环开始前是第i-1位和的进位（0或1） 
    for(int i=0;i<A.size()||i<B.size()||t!=0;++i){//计算与A、B中更多位的数同位数的和（C要么与其同位数，要么最后还多一位）（若最后t还有进位，则C最后还多一位该进位（必须判断t是否为0，否则可能push_back(0)，最后打印时最高位为0）） 
        if(i<A.size()) t+=A[i];//先求同在第i位的两数字和
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);//用【取余】求结果C第i位
        t/=10;//用【整除】求第i位到第i+1位的进位
    }
    return C;
}
