#include <iostream>
//�ø�������ʱ�̼�¼ÿ��Ԫ���ڵ�ǰ�����еĸ�������j���Խ�����һ�ֵ�λ�ý��������߶����߻�ͷ·
using namespace std;
const int N = 100010;
int n;
int nums[N], s[N];//s[k]��¼��ǰ[j,i]������k�ĸ�����s�ĳ�����nums��Ԫ�ص�ֵ����N����Ӧ����map���ϣ��洢s[k]��
int main()
{
    scanf("%d", &n);
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ ){
        scanf("%d",&nums[i]);
        s[nums[i]]++ ;
        while (s[nums[i]]>1){//����ÿ��ѭ�������󶼱�֤[j,i]�����ظ�Ԫ�أ�
            s[nums[j]]--; ++j;//�����һ��ѭ���������ظ�Ԫ�ر���i++���nums[i]������checkֻ�ü��s[nums[i]]�Ƿ�ֻ1����������Ԫ���ظ�
        }//��nums[i]���ظ�ʱ�Ÿ���j������[j,i]���ص��ظ���һ�Σ�������j������
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
