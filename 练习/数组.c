#include <stdio.h>
int main()
{
    int nums[] = {8,4,2,1,23,344,12};
    int i,search;
    int sum = 0;
    double avg;
    printf("���������Ԫ�أ�\n");
    for(i=0;i<7;i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n********************");
    for(i=0;i<7;i++)
    {
        sum += nums[i];
    }
    avg = sum / 7.0;
    printf("\n�������ƽ����Ϊ��%lf",avg);
    printf("\n������Ҫ���ҵ����֣�");
    scanf("%d",&search);
    for(i=0;i<7;i++)
    {
        if(search == nums[i])
        {
            printf("��Եǧ������ᣡ");
            break;
        }
    }
    if(i == 7)
    {
        printf("�������");
    }
}
