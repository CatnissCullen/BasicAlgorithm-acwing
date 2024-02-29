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
            intervals.erase(intervals.begin()+i+1);//���1�����䣬�Ƴ���һ����
            continue;
        }
        if(intervals[i+1][0]<=intervals[i][1]&&intervals[i+1][1]>=intervals[i][1]){
            intervals[i][1]=intervals[i+1][1];
            intervals.erase(intervals.begin()+i+1);
            continue;
        }//���2���Ҷ˵���£��Ƴ���һ����
        if(intervals[i+1][0]>intervals[i][1]) ++i; //���3�����䣬����𰸣�������һ����
    }
    cout<<intervals.size();
}
bool cmp(const vector<int> a,const vector<int> b){
    return a[0]<b[0];
}
