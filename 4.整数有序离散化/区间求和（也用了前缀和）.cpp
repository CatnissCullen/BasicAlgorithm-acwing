# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;
int n,m;
vector<int> nums;
map<int,int> nums_c;
int index_l(int l);
int index_r(int r);
int main(){
    cin>>n>>m; nums.reserve(n);
    int* s=new int[n+1]();//ǰ׺�����飬s[i]=a0+a1+...+a(i-1)����ʼ��Ϊ0
    int x,c;
    while(n--){//����n��x��c
        scanf("%d%d", &x, &c);
        if(nums_c.find(x)!=nums_c.end()) nums_c[x]+=c;//���Ѷ����x
        else{//��δ�����x
            nums.push_back(x);//x��vector
            nums_c[x]=c;//x��map
        }
    }
    sort(nums.begin(),nums.end());//�����ظ�Ԫ�ص�vector����
    for(int k=0;k<=nums.size()-1;++k) s[k+1]=s[k]+nums_c[nums[k]];//��ǰ׺������
    int l,r,sum; int i,j;
    while(m--){//����m����ѯ
        sum=0;
        scanf("%d%d",&l,&r);
        i=index_l(l); j=index_r(r);//����vector�д��ڵ���l����СԪ���±��С�ڵ���r�����Ԫ���±�
        if(i!=-1&&j!=-1)//��[i,j]��nums�н��������󽻼����ֵ�ǰ׺�ͣ�ֱ����ӻᳬʱ��
            if(i<=j) sum=s[j+1]-s[i];//�н���[i,j]������ǰ׺��
        cout<<sum<<endl;
    }
}
int index_l(int l){//�Ҵ��ڵ��ڵ���СԪ���±�
    int mid,low,high;
    low=0, high=nums.size()-1;
    while(low<high){
        mid=(low+high)>>1;
        if(nums[mid]>=l) high=mid;
        else low=mid+1;
    }
    if(nums[low]>=l) return low;
    else return -1;//l>nums�����ֵ
}
int index_r(int r){//��С�ڵ��ڵ����Ԫ���±�
    int mid,low,high;
    low=0, high=nums.size()-1;
    while(low<high){
        mid=(low+high+1)>>1;
        if(nums[mid]<=r) low=mid;
        else high=mid-1;
    }
    if(nums[low]<=r) return low;
    else return -1;//r<nums����Сֵ
}
