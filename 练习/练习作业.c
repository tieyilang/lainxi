#include <stdio.h>
int main()
{
    int num1,num2,num;
    char ch;
    printf("\n 请输入两个数字：");
    scanf("%d %d",&num1,&num2);
    printf("\n 请输入运算符号：");
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
    printf("\n 得到的值为：%d",num);
}
