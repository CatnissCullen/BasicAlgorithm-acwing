# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool cmp(const vector<int> a,const vector<int> b);
int n;
int main(){
    vector<vector<int>> intervals;
    cin>>n;
    intervals.resize(n);
    for(int k=0;k<n;++k){
        intervals[k].resize(2);
        scanf("%d%d",&intervals[k][0],&intervals[k][1]);
    }
    sort(intervals.begin(),intervals.end(),cmp);
    int i=0;
    while(i<intervals.size()-1){
        if(intervals[i+1][1]<=intervals[i][1]){
            intervals.erase(intervals.begin()+i+1);//情况1：不变，移除下一区间
            continue;
        }
        if(intervals[i+1][0]<=intervals[i][1]&&intervals[i+1][1]>=intervals[i][1]){
            intervals[i][1]=intervals[i+1][1];
            intervals.erase(intervals.begin()+i+1);
            continue;
        }//情况2：右端点更新，移除下一区间
        if(intervals[i+1][0]>intervals[i][1]) ++i; //情况3：不变，归入答案，换成下一区间
    }
    cout<<intervals.size();
}
bool cmp(const vector<int> a,const vector<int> b){
    return a[0]<b[0];
}
