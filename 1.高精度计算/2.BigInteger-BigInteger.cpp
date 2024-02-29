# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
using namespace std;
int JudgeBigger(vector<int> &A,vector<int> &B);
vector<int> Subtraction(vector<int> &A,vector<int> &B);
int main(){
    cout<<"//Subtraction//\n\n";
    string a,b;
    vector<int> A,B;
    cout<<"Enter big integer A(>=0):  ";
    cin>>a;//先用string读入大整数（暂存为字符串）
    cout<<"Enter big integer B(>=0):  ";
    cin>>b;
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//再放入vector，先放低位再放高位
    for(int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');
    vector<int> C;//求差结果数组
    if(JudgeBigger(A,B)==0){//A=B则直接打印0
        cout<<"\nResult:  A - B = 0"; cout<<endl; return 0;
    }
    if(JudgeBigger(A,B)==1){//A大则求A-B
        C=Subtraction(A,B); cout<<"\nResult:  A - B = ";
    }
    else{//B大则求-(B-A)
        C=Subtraction(B,A); cout<<"\nResult:  A - B = - ";//打印带负号的C
    }
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//从高位到低位打印
    cout<<endl;
}
/*判断A是否大于B*/
int JudgeBigger(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size()){//若A、B位数不同
        if(A.size()>B.size()) return 1;
        else return -1; }
    int i=A.size()-1;//若A、B位数相同
    do{
        if(A[i]!=B[i]){
            if(A[i]>B[i]) return 1;
            else return -1; }
        --i; } while(i>=0);
    return 0;
}
/*大整数-大整数*/
vector<int> Subtraction(vector<int> &A,vector<int> &B){//A是被减数（较大数），B是减数（较小数），保证结果C为正数
    vector<int> C; int t=0;//暂存A、B第i位的差（低位对齐），每轮循环开始前是第i-1位差的借位（0或1）
    for(int i=0;i<A.size();++i){//计算A与B的差（A位数>=B位数）
        t=A[i]-t;
        if(i<B.size()) t-=B[i];//若B还有位数
        C.push_back((t+10)%10);//用【加10再取余】求结果C第i位
        t= (t<0)? 1:0;//判断A[i]-B[i]-t{i-1}是否小于0求第i位到第i+1位的借位
    }
    while(C.size()>1&&C.back()==0) C.pop_back();//若最后C高位有0且总共不只1位（1位时保留0）须舍弃高位0
    return C;
}


