#include <stdio.h>
int main()
{
    int num,i;
    printf("������һ�����֣�");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("%d + %d = %d",i,num-i,num);
        if(i%2 == 0)
            printf("\t");
        else
            printf("\n");
    }
}
