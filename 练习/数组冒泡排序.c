#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int i,j,temp;
    int nums[N] = {16,25,9,90,23};
    for(i=0;i<N - 1;i++)
    {
        for(j=0;j<N - i - 1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
        printf("排序的结果为：\n");
        for(i=0;i<N;i++)
        {
            printf("%d\t",nums[i]);
        }
}
