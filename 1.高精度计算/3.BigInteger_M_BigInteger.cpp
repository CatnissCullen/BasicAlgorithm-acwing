# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
using namespace std;
vector<int> Multiplication(vector<int> &A,int b);
int main(){
    cout<<"//Multiplication//\n\n";
    string a; int b;
    vector<int> A;
    cout<<"Enter big integer A (>=0):  ";
    cin>>a;//先用string读入大整数（暂存为字符串）
    cout<<"Enter small integer b (>=0):  ";
    cin>>b;//小整数直接读入int
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//再把大整数放入vector，先放低位再放高位
    if(b==0){//若b=0，直接返回0 
    	cout<<"\nResult:  A mul b = 0"; cout<<endl; return 0;
	}
	vector<int> C= Multiplication(A, b);//求和结果数组
    cout<<"\nResult:  A mul b = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//从高位到低位打印
    cout<<endl;
}
/*大整数*小整数*/
vector<int> Multiplication(vector<int> &A, int b){
    vector<int> C; int t=0;//暂存A第i位和b的积，每轮循环开始前是第i-1位积的进位
    for(int i=0;i<A.size()||t!=0;++i){//计算A各位分别与b的积（A完了以后t可能>0，还要把剩下的进位拆成各位数字）
        if(i<A.size())t+=A[i]*b;//若A还有，先求第i位A与b的积
        C.push_back(t%10);//用【取余】求结果C第i位
        t/=10;//用【整除】求第i位到第i+1位的进位（不只是0或1）
    }
    return C;
}
