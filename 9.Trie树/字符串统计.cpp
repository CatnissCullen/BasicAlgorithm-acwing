# include <iostream>
using namespace std;
# define N 100010
char str[N];
int childNodes[N][26];//�Զ���Сд��ĸΪ����NΪ���������ÿ�����ĺ��ӽ�㣨��֧�������26��������
int endCnt[N];//�Ե�ǰ����β�ĵ��ʸ���
int idx=1;//�ɱ�������ֵΪδռ�õ���С�������±�Ϊ0�ĵ�����������ս��
void InsertNodes(char* s);
int Query(char* s);
int main(){
    int n;
    cin>>n;
    while(n--){
        char op;
        scanf("%*c%c%*c%s",&op,str);
        if(op=='I') InsertNodes(str);
        else printf("%d\n",Query(str));
    }
}
void InsertNodes(char* s){//��һ���ַ�������
    int k;//ĳ�ַ��ںϷ��ַ��е���ţ����ַ�ת��ΪchildNodes���±꣩
    int i,j;
    for(i=0,j=0; s[j] != '\0'; ++j){//i�Ӹ���㿪ʼ��Ϊ���н��������j�ӵ�ǰ�ַ�����һ���ַ���ʼ��Ϊ�ַ������ַ�����
        k= s[j] - 'a';
        if(!childNodes[i][k]) childNodes[i][k]=idx++;//���޵�ǰ�ַ��������ַ����
        i=childNodes[i][k];//����i��ָ���µ��ַ����
    }//iΪ��ǰ�ַ��������һ���ַ���Ӧ�Ľ�������
    ++endCnt[i];
}
int Query(char* s){//ͳ������ĳ�ַ����ĸ�������������֧�ҵ������������ַ� �ڷ������һ���ַ���endCnt
    int k;//ĳ�ַ��ںϷ��ַ��е���ţ����ַ�ת��ΪchildNodes���±꣩
    int i,j;
    for(i=0,j=0; s[j] != '\0'; ++j){//i�Ӹ���㿪ʼ��Ϊ���н��������j�ӵ�ǰ�ַ�����һ���ַ���ʼ��Ϊ�ַ������ַ�����
        k= s[j] - 'a';
        if(!childNodes[i][k]) return 0;//���޵�ǰ�ַ�������0��
        else i=childNodes[i][k];//�������i��ָ���µ��ַ����
    }//iΪ��ǰ�ַ��������һ���ַ���Ӧ�Ľ�������
    return endCnt[i];//����endCnt[i]��
}
