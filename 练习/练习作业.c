#include <stdio.h>
int main()
{
    int num1,num2,num;
    char ch;
    printf("\n �������������֣�");
    scanf("%d %d",&num1,&num2);
    printf("\n ������������ţ�");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch == '+')
    {
        num = num1 + num2;
    }
    if(ch == '-')
    {
        num = num1 - num2;
    }
    if(ch == '*')
    {
        num = num1 * num2;
    }
    if(ch == '/')
    {
        num = num1 / num2;
    }
    printf("\n �õ���ֵΪ��%d",num);
}
