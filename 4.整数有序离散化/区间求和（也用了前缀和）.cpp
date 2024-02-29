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
    int* s=new int[n+1]();//前缀和数组，s[i]=a0+a1+...+a(i-1)，初始化为0
    int x,c;
    while(n--){//存入n对x和c
        scanf("%d%d", &x, &c);
        if(nums_c.find(x)!=nums_c.end()) nums_c[x]+=c;//若已读入过x
        else{//若未读入过x
            nums.push_back(x);//x入vector
            nums_c[x]=c;//x入map
        }
    }
    sort(nums.begin(),nums.end());//对无重复元素的vector排序
    for(int k=0;k<=nums.size()-1;++k) s[k+1]=s[k]+nums_c[nums[k]];//求前缀和数组
    int l,r,sum; int i,j;
    while(m--){//处理m个查询
        sum=0;
        scanf("%d%d",&l,&r);
        i=index_l(l); j=index_r(r);//求在vector中大于等于l的最小元素下标和小于等于r的最大元素下标
        if(i!=-1&&j!=-1)//若[i,j]与nums有交集，则求交集部分的前缀和（直接相加会超时）
            if(i<=j) sum=s[j+1]-s[i];//有交集[i,j]，则求前缀和
        cout<<sum<<endl;
    }
}
int index_l(int l){//找大于等于的最小元素下标
    int mid,low,high;
    low=0, high=nums.size()-1;
    while(low<high){
        mid=(low+high)>>1;
        if(nums[mid]>=l) high=mid;
        else low=mid+1;
    }
    if(nums[low]>=l) return low;
    else return -1;//l>nums中最大值
}
int index_r(int r){//找小于等于的最大元素下标
    int mid,low,high;
    low=0, high=nums.size()-1;
    while(low<high){
        mid=(low+high+1)>>1;
        if(nums[mid]<=r) low=mid;
        else high=mid-1;
    }
    if(nums[low]<=r) return low;
    else return -1;//r<nums中最小值
}
