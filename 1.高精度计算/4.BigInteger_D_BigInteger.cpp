# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;
vector<int> Division(vector<int> &A, int b,int &r);//rΪ����
int main(){
    cout<<"//Division//\n\n";
    string a; int b; int r;
    vector<int> A;
    cout<<"Enter big integer A (>=0):  ";
    cin>>a;//����string������������ݴ�Ϊ�ַ�����
    cout<<"Enter small integer b (>=0):  ";
    cin>>b;//С����ֱ�Ӷ���int
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');//�ٰѴ���������vector���ȷŵ�λ�ٷŸ�λ
    vector<int> C=Division(A, b,r);//��ͽ������
    cout<<"\nResult:  A div b = ";
    for(int i=C.size()-1;i>=0;--i) printf("%d",C[i]);//�Ӹ�λ����λ��ӡ
    cout<<" ...... "<<r;//��ӡ����
    cout<<endl;
}
/*������/С��������������*/
vector<int> Division(vector<int> &A, int b,int &r){
    vector<int> C;
    r=0;//������ʼ��Ϊ0���ݴ�ÿ��ѭ����������ÿ��ѭ����ʼǰ��i+1λ��õ�����
    for(int i=A.size()-1;i>=0;--i){//�����ӱ�����A���λ��ʼ����λ��
        r=r*10+A[i];//�ȼ��㱾��ѭ��������
        C.push_back(r/b);//�á�����������C�ĵ�iλ
        r%=b;//�á�ȡ�ࡿ�õ�iλ������
    }
    reverse(C.begin(),C.end());//���C���ã���شӵ�λ����λ�Ĵ洢����
    while(C.size()>1&&C.back()==0) C.pop_back();//�����C��λ��0���ܹ���ֻ1λ��1λʱ����0����������λ0
    return C;
}
