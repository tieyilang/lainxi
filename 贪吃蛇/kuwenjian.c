#include <stdio.h>
#include <windows.h>
#include "kuwenjian.h"


void KZT_BT(char *kzt)//���Ŀ���̨����
{
    SetConsoleTitle(kzt);//windows�����ú��� ���ַ�������
}

void KZT_YS(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //��ȡ��ǰ���ھ��
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
}

void KZT_GB(int x, int y)
{
    COORD cursorPosition;   //��������
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //����x��y����
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
	//���ÿ���̨���ڵĻ�������С
	COORD size = {width, height};
	SetConsoleScreenBufferSize(handle, size);
	//���ÿ���̨���ڴ�С,��������ǻ�������С-1
	SMALL_RECT rect = {0, 0, width-1, height-1};
	SetConsoleWindowInfo(handle, 1, &rect);
}
