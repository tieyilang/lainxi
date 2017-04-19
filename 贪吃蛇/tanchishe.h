#ifndef TANCHISHE_H_INCLUDED
#define TANCHISHE_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#define ZBJ 20   //左边距20
#define KD 78    //游戏宽度78
#define CD 25    //游戏长度
#define XXL 55   //地图与数据分界线
#define FGX "------------------------------------------------------------------------------"//78格

typedef struct Wanjia_  //玩家结构体
{
    char name[5]; //昵称
    int fenshu; //玩家分数
}WJ;


void TCS_JM(void);  //显示界面

void TCS_PHB(void); //排行榜

void TCS_PHB_GX(void);//更新排行榜

void TCS_XZ(void);  //玩家选择开始游戏函数

void TCS_SR(void);  //玩家输入名称(限制字符) 并显示在游戏里

void TCS_YX(void);  //贪吃蛇游戏函数!

void TCS_SW(COORD,int*);  //用头部的坐标判定死亡 int控制循环

void TCS_XS(void);   //显示(打印)贪吃蛇

void TCS_SP(void);   //食物刷新与显示函数

void TCS_SZ(void);  //生长函数 判断是否吃到

void DDQP(void);  //定点清屏

void ZT(void);//暂停


#endif // TANCHISHE_H_INCLUDED
