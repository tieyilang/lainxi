#include <stdio.h>
int main()
{
    int nums[] = {8,4,2,1,23,344,12};
    int i,search;
    int sum = 0;
    double avg;
    printf("输出的数组元素：\n");
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
    printf("\n该数组的平均数为：%lf",avg);
    printf("\n请输入要查找的数字：");
    scanf("%d",&search);
    for(i=0;i<7;i++)
    {
        if(search == nums[i])
        {
            printf("有缘千里来相会！");
            break;
        }
    }
    if(i == 7)
    {
        printf("咫尺天涯");
    }
}
