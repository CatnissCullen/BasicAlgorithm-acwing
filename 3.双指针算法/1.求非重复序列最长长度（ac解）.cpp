#include <iostream>
//用辅助数组时刻记录每个元素在当前区间中的个数，让j可以接着上一轮的位置接着往下走而不走回头路
using namespace std;
const int N = 100010;
int n;
int nums[N], s[N];//s[k]记录当前[j,i]区间内k的个数，s的长度是nums中元素的值域（若N过大应该用map或哈希表存储s[k]）
int main()
{
    scanf("%d", &n);
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ ){
        scanf("%d",&nums[i]);
        s[nums[i]]++ ;
        while (s[nums[i]]>1){//由于每次循环结束后都保证[j,i]内无重复元素，
            s[nums[j]]--; ++j;//因此新一轮循环新增的重复元素必是i++后的nums[i]，于是check只用检查s[nums[i]]是否不只1，是则新增元素重复
        }//当nums[i]被重复时才更新j（更新[j,i]，截掉重复的一段），否则j不动！
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
