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
    cin>>a;//����string������������ݴ�Ϊ�ַ�����
    cout<<"Enter big integer B(>=0):  ";
    cin>>b;
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//�ٷ���vector���ȷŵ�λ�ٷŸ�λ
    for(int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');
    vector<int> C;//���������
    if(JudgeBigger(A,B)==0){//A=B��ֱ�Ӵ�ӡ0
        cout<<"\nResult:  A - B = 0"; cout<<endl; return 0;
    }
    if(JudgeBigger(A,B)==1){//A������A-B
        C=Subtraction(A,B); cout<<"\nResult:  A - B = ";
    }
    else{//B������-(B-A)
        C=Subtraction(B,A); cout<<"\nResult:  A - B = - ";//��ӡ�����ŵ�C
    }
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//�Ӹ�λ����λ��ӡ
    cout<<endl;
}
/*�ж�A�Ƿ����B*/
int JudgeBigger(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size()){//��A��Bλ����ͬ
        if(A.size()>B.size()) return 1;
        else return -1; }
    int i=A.size()-1;//��A��Bλ����ͬ
    do{
        if(A[i]!=B[i]){
            if(A[i]>B[i]) return 1;
            else return -1; }
        --i; } while(i>=0);
    return 0;
}
/*������-������*/
vector<int> Subtraction(vector<int> &A,vector<int> &B){//A�Ǳ��������ϴ�������B�Ǽ�������С��������֤���CΪ����
    vector<int> C; int t=0;//�ݴ�A��B��iλ�Ĳ��λ���룩��ÿ��ѭ����ʼǰ�ǵ�i-1λ��Ľ�λ��0��1��
    for(int i=0;i<A.size();++i){//����A��B�ĲAλ��>=Bλ����
        t=A[i]-t;
        if(i<B.size()) t-=B[i];//��B����λ��
        C.push_back((t+10)%10);//�á���10��ȡ�ࡿ����C��iλ
        t= (t<0)? 1:0;//�ж�A[i]-B[i]-t{i-1}�Ƿ�С��0���iλ����i+1λ�Ľ�λ
    }
    while(C.size()>1&&C.back()==0) C.pop_back();//�����C��λ��0���ܹ���ֻ1λ��1λʱ����0����������λ0
    return C;
}


