#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "kuwenjian.h"
#include "tanchishe.h"

int main()
{

    KZT_BT("贪吃蛇 C语言版 V1.0 老九学堂 Cjl");//更改控制台名称
    KZT_DX(125,35);                   //更改控制台大小
    KZT_YS(12,0);                     //更改控制台颜色
    TCS_JM();                         //界面显示函数
    TCS_PHB();                        //排行榜显示函数
    TCS_XZ();                         //用户选择函数 包含开始游戏等后续逻辑
    KZT_GB(0,29);
    return 0;
}
