# include <iostream>//�����ʵ�֣�����ʱ����Ϊj���ߵ��߹���λ�ã��ܲ����ᳬ��n����˱�����ac��һ��ʱ�̼�¼ÿ��Ԫ���ڵ�ǰ�����еĸ�������j���Խ�����һ�ֵ�λ�ý��������߶����߻�ͷ· 
using namespace std;
# define N 100010
int nums[N];
bool check(int i,int j);
int main(){//�ý����������ظ������Ҷ˵�ı���Ҳ�������в����ظ���Ԫ�أ����ÿ��check��nums[i]�Ƚϼ��ɣ�ֱ�����ظ������ӳ����
    int n; int maxLen=0,st=0; int j;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",&nums[i]);
        j=st;
        while(j<i&&nums[j]!=nums[i])//��check��j��ÿ��ѭ���е���㣬������i��ǰ���һ���ظ�������һλ
            //��iǰ�ƣ�ÿ��nums[j]��nums[i]�Ƚϲ�����j����㣬�Ա�֤j��i֮��û�м������ظ�����
            ++j;
        if(j!=i) st=j+1;//��[st,i]�����ظ����У�����i�ظ���Ԫ�أ�����st�������ظ�Ԫ�ص���һλ
        else if(i-st+1>maxLen) maxLen=i-st+1;//�������Ƿ����maxLenΪ(i-st)
    }
    cout<<maxLen;
}

