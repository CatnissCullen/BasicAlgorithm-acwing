# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool cmp(const vector<int> a,const vector<int> b);
int n;
int main(){
    vector<vector<int>> intervals, merged;
    cin>>n; intervals.resize(n);
    for(int k=0;k<n;++k){
        intervals[k].resize(2);
        scanf("%d%d",&intervals[k][0],&intervals[k][1]);
    }//�������䵽intervals
    sort(intervals.begin(),intervals.end(),cmp);//��������˵��С��������
    int st_current=intervals[0][0], ed_current=intervals[0][1];
    for(int i=1;i<intervals.size();++i){
        if(intervals[i][0]<=ed_current&&intervals[i][1]>=ed_current){
            //���2��[st_current,ed_current]�Ҷ˵����
            ed_current=intervals[i][1];
            continue;}
        if(intervals[i][0]>ed_current){
            //���3��[st_current,ed_current]�Ȳ��䣬���������Merged
            //�ٸ���[st_current,ed_current]
            merged.push_back({st_current,ed_current});
            st_current=intervals[i][0]; ed_current=intervals[i][1];}
    }
    merged.push_back({st_current,ed_current});
    cout<<merged.size();
}
bool cmp(const vector<int> a,const vector<int> b){return a[0]<b[0];}
