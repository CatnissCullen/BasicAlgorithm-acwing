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
    cin>>a;//����string������������ݴ�Ϊ�ַ�����
    cout<<"Enter big integer B (>=0):  ";
    cin>>b;
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//�ٷ���vector���ȷŵ�λ�ٷŸ�λ
    for(int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');
    vector<int> C=Addition(A,B);//��ͽ������
    cout<<"\nResult:  A + B = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//�Ӹ�λ����λ��ӡ
    cout<<endl;
}
/*������+������*/
vector<int> Addition(vector<int> &A,vector<int> &B){
    vector<int> C; int t=0;//�ݴ�A��B��iλ�ĺͣ���λ���룩��ÿ��ѭ����ʼǰ�ǵ�i-1λ�͵Ľ�λ��0��1�� 
    for(int i=0;i<A.size()||i<B.size()||t!=0;++i){//������A��B�и���λ����ͬλ���ĺͣ�CҪô����ͬλ����Ҫô��󻹶�һλ���������t���н�λ����C��󻹶�һλ�ý�λ�������ж�t�Ƿ�Ϊ0���������push_back(0)������ӡʱ���λΪ0���� 
        if(i<A.size()) t+=A[i];//����ͬ�ڵ�iλ�������ֺ�
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);//�á�ȡ�ࡿ����C��iλ
        t/=10;//�á����������iλ����i+1λ�Ľ�λ
    }
    return C;
}
