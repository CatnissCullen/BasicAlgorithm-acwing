# include <iostream>//错解能实现，但超时，因为j会走到走过的位置，总步数会超过n，因此必须像ac解一样时刻记录每个元素在当前区间中的个数，让j可以接着上一轮的位置接着往下走而不走回头路 
using namespace std;
# define N 100010
int nums[N];
bool check(int i,int j);
int main(){//该解做法：非重复序列右端点的本质也是序列中不被重复的元素，因此每次check与nums[i]比较即可，直至非重复序列延长至最长
    int n; int maxLen=0,st=0; int j;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",&nums[i]);
        j=st;
        while(j<i&&nums[j]!=nums[i])//用check将j在每轮循环中的起点，更新至i以前最后一个重复序列下一位
            //随i前移，每个nums[j]与nums[i]比较并更新j的起点，以保证j、i之间没有检查过的重复序列
            ++j;
        if(j!=i) st=j+1;//若[st,i]内有重复序列（即与i重复的元素），将st更新至重复元素的下一位
        else if(i-st+1>maxLen) maxLen=i-st+1;//否则考虑是否更新maxLen为(i-st)
    }
    cout<<maxLen;
}

