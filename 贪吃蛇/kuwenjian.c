#include <stdio.h>
#include <windows.h>
#include "kuwenjian.h"


void KZT_BT(char *kzt)//更改控制台标题
{
    SetConsoleTitle(kzt);//windows的内置函数 把字符串传入
}

void KZT_YS(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //获取当前窗口句柄
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

void KZT_GB(int x, int y)
{
    COORD cursorPosition;   //光标的坐标
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //设置x、y坐标
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
}

void KZT_QP(int x,int y,int lis)
{
    int i ,j;
    for(i = 0;i < lis;i++)
    {
        KZT_GB(x,y+i);
        for(j = 0; j < 54;j++)
        {
            printf(" ");
        }
    }
}

void KZT_DX(int width, int height)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置控制台窗口的缓冲区大小
	COORD size = {width, height};
	SetConsoleScreenBufferSize(handle, size);
	//设置控制台窗口大小,最大坐标是缓冲区大小-1
	SMALL_RECT rect = {0, 0, width-1, height-1};
	SetConsoleWindowInfo(handle, 1, &rect);
}
