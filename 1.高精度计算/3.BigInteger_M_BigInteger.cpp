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
    cin>>a;//����string������������ݴ�Ϊ�ַ�����
    cout<<"Enter small integer b (>=0):  ";
    cin>>b;//С����ֱ�Ӷ���int
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//�ٰѴ���������vector���ȷŵ�λ�ٷŸ�λ
    if(b==0){//��b=0��ֱ�ӷ���0 
    	cout<<"\nResult:  A mul b = 0"; cout<<endl; return 0;
	}
	vector<int> C= Multiplication(A, b);//��ͽ������
    cout<<"\nResult:  A mul b = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//�Ӹ�λ����λ��ӡ
    cout<<endl;
}
/*������*С����*/
vector<int> Multiplication(vector<int> &A, int b){
    vector<int> C; int t=0;//�ݴ�A��iλ��b�Ļ���ÿ��ѭ����ʼǰ�ǵ�i-1λ���Ľ�λ
    for(int i=0;i<A.size()||t!=0;++i){//����A��λ�ֱ���b�Ļ���A�����Ժ�t����>0����Ҫ��ʣ�µĽ�λ��ɸ�λ���֣�
        if(i<A.size())t+=A[i]*b;//��A���У������iλA��b�Ļ�
        C.push_back(t%10);//�á�ȡ�ࡿ����C��iλ
        t/=10;//�á����������iλ����i+1λ�Ľ�λ����ֻ��0��1��
    }
    return C;
}
