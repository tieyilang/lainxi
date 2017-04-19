#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "tanchishe.h"

WJ wjph[11] = //玩家排行 最多九个  第十个用于存储新玩家 最后一个用于排序做临时变量
{
    {"Cjl",666},
};
int wjs = 1;//控制输出的排行数量 后面限制最多9


COORD tcs[27 * 25]; //初始化贪吃蛇 肉体的坐标 最大为27*25

int tcscd = 6;         //控制长度

COORD sp;  //存储食物坐标
COORD wb;   //储存蛇被替换的尾巴 用于补上吃食物后的坐标
char sr;//记录用户输入

void TCS_JM()
{
    int i,j;
    KZT_GB(ZBJ,0);                    //上边界
    printf(FGX);
    for(i = 0;i < CD;i++)
    {
        KZT_GB( ZBJ , i + 1);         //左边边界
        printf("|");
        KZT_GB( XXL +ZBJ, i + 1);     //地图与信息栏分界
        printf("|");
        KZT_GB( ZBJ + KD -1 , i + 1); //右边边界
        printf("|");
    }
    KZT_GB( XXL +ZBJ+9,1);
    printf("排行榜");
    KZT_GB( XXL +ZBJ+3,2);
    printf("排名   姓名   分数");
    KZT_GB( XXL +ZBJ+1,12);           //排行榜分界
    printf("---------------------");
    KZT_GB( XXL +ZBJ+1,18);
    printf("---------------------");
    KZT_GB( XXL +ZBJ+2,14);
    printf("     作者:  Cjl    ");
    KZT_GB( XXL +ZBJ+6,16);
    printf("老九学堂学生");
    KZT_GB( XXL +ZBJ+7,20);
	printf(" 操作指南");
    KZT_GB( XXL +ZBJ+2,22);
	printf("W S 或 ↑↓移动光标");
    KZT_GB( XXL +ZBJ+4,24);
	printf("Enter  确认选择");
    KZT_GB(ZBJ, CD + 1);              //下边界
    printf(FGX);
}


void TCS_XZ()  //开始函数
{
    int i;
    int a = 0;
    char xz;                 //用户的输入
    char xs[2][10] = {"开始游戏","离开游戏"};   //
    KZT_GB( ZBJ+20,9);
    printf("《贪吃蛇 C语言版》");
    while(1)
    {
        for(i = 0;i < 2;i++)
        {
            if(a == i) KZT_YS(1,2);
            KZT_GB( ZBJ+25,11 + i);
            printf("%s",xs[i]);
            KZT_YS(12,0);
        }
        xz = getch();
        if(xz == 72 || xz == 119 || xz == 87)
        {
            a--;
            if(a < 0) a = 1;
        }
        if(xz == 80 || xz == 115 || xz == 83)
        {
            a++;
            if(a > 1) a = 0;
        }
        if(xz == 13)
        {
            if(a == 0)
            {
                KZT_GB( XXL +ZBJ+2,22);
                printf("  最多输入四个字符  ");
                KZT_GB( XXL +ZBJ+4,24);
                printf(" Enter 确认输入");
                TCS_SR();//输入名称
                KZT_GB(0,28);   //死亡后跳回
                getch();
                KZT_QP(ZBJ+1,1,25);  //清屏
                TCS_JM();  //重新打印界面
            }
            if(a == 1)
            {
                KZT_QP(ZBJ+1,1,25);  //清屏
                KZT_GB(ZBJ +22 ,11);
                printf("游戏结束,再见");
                break;
            }
        }
    }

}

void TCS_PHB() //刷新排行榜
{
    int i;
    for(i = 0;i < wjs;i++)
    {
        KZT_GB(ZBJ +XXL+4 ,3+i);
        printf("%-6d%-7s%-5d",i+1,wjph[i].name,wjph[i].fenshu);
    }
}

void TCS_SR()  //玩家输入名称(限制字符) 并显示在游戏里
{
    KZT_QP(ZBJ+1,1,25);  //清屏
    KZT_GB(ZBJ +22 ,11);
    printf("请输入您的昵称");
    KZT_GB(ZBJ +27,13);
    scanf("%4s",wjph[9].name);
    KZT_QP(ZBJ+1,1,25);  //清屏
    KZT_GB( XXL +ZBJ+5,14);
    printf("当前玩家:%5s",wjph[9].name);
    KZT_GB( XXL +ZBJ+5,16);
    printf("玩家分数:  %-5d",wjph[9].fenshu);
    KZT_QP(ZBJ+1,1,25);  //清屏
    KZT_GB( XXL +ZBJ+4,22);
    printf("W A S D 控制方向");
    KZT_GB( XXL +ZBJ+4,24);
    printf("  Esc 暂停游戏");

    wjph[9].fenshu = 0;//初始化分数
    /* 初始化贪吃蛇 也用于死亡后重新开始 */
    tcs[0].X=35; tcs[0].Y=11;
    tcs[1].X=37; tcs[1].Y=11;
    tcs[2].X=39; tcs[2].Y=11;
    tcs[3].X=41; tcs[3].Y=11;
    tcs[4].X=43; tcs[4].Y=11;
    tcs[5].X=45; tcs[5].Y=11;
    tcscd = 6;         //控制长度

    TCS_YX();//控制贪吃蛇开始游戏
}

void TCS_YX() //贪吃蛇游戏函数!
{
    int i,s;   //i循环变量  s速度
    int kz = 1;   //用于控制外面的while 死亡就为0
    sr = 'D'; //默认向右走
    TCS_SP();  //初始化食物
    while(kz)
    {
        //    TCS_SP();
        //    getch();
        switch(wjph[9].fenshu)//判断分数决定速度
        {
        case 0://分数
            s = 400; //速度毫秒
            break;
        case 10:
            s = 320;
            break;
        case 20:
            s = 240;
            break;
        case 40:
            s = 180;
            break;
        case 80:
            s = 120;
            break;
        }
        while(sr == 87 || sr == 119)     //向上
        {
            while(kbhit())//如果按压键盘就执行 发现while可以更好的控制方向 会不会出现if按太多下无法控制
            {
                sr = getch();
            }
            if(sr == 27) ZT();//暂停逻辑
            if(sr == 'A' || sr == 'D' || sr == 'a' || sr == 'd') break;
            else sr = 'W';
            wb = tcs[0]; //在没被覆盖前保存蛇尾
            DDQP(); //清除尾巴
            /* 先更新 */
            tcs[tcscd] = tcs[tcscd - 1]; //把蛇头赋值给前一位 原来的保留
            tcs[tcscd].Y--;              //更新蛇头位置 向上y--
            //判定死亡函数
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //死亡退出
            TCS_SZ();  //判定生长
            for(i = 0 ;i < tcscd ;i++)//更新位置
            {
                tcs[i] = tcs[i+1];//后一位赋值给前一位
            }
            TCS_SZ();  //判定生长
            TCS_XS();   //显示蛇
            Sleep(s);
        }
        while(sr == 83 || sr == 115)     //向下
        {
            while(kbhit())//如果按压键盘就执行 发现while可以更好的控制方向 会不会出现if按太多下无法控制
            {
                sr = getch();
            }
            if(sr == 27) ZT();//暂停逻辑
            if(sr == 'A' || sr == 'D' || sr == 'a' || sr == 'd') break;
            else sr = 'S';
            wb = tcs[0]; //在没被覆盖前保存蛇尾
            DDQP(); //清除尾巴
            tcs[tcscd] = tcs[tcscd - 1]; //把蛇头赋值给前一位 原来的保留
            tcs[tcscd].Y++;              //更新蛇头位置 向下y++
            //判定死亡函数
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //死亡退出
            TCS_SZ();  //判定生长
            for(i = 0 ;i < tcscd ;i++)//更新位置
            {
                tcs[i] = tcs[i+1];//后一位赋值给前一位
            }
            TCS_SZ();  //判定生长
            TCS_XS();   //显示蛇
            Sleep(s);
        }
        while(sr == 65 || sr == 97)     //向左
        {
            while(kbhit())//如果按压键盘就执行 发现while可以更好的控制方向 会不会出现if按太多下无法控制
            {
                sr = getch();
            }
            if(sr == 27) ZT();//暂停逻辑
            if(sr == 'W' || sr == 'S' || sr == 'w' || sr == 's') break;
            else sr = 'A';
            wb = tcs[0]; //在没被覆盖前保存蛇尾
            DDQP(); //清除尾巴
            tcs[tcscd] = tcs[tcscd - 1]; //把蛇头赋值给前一位 原来的保留
            tcs[tcscd].X -= 2;              //更新蛇头位置 向下左x-两个字符
            //判定死亡函数
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //死亡退出
            for(i = 0 ;i < tcscd ;i++)//更新位置
            {
                tcs[i] = tcs[i+1];//后一位赋值给前一位 蛇头复原
            }
            TCS_SZ();  //判定生长
            TCS_XS();   //显示蛇
            Sleep(s);
        }
        while(sr == 68 || sr == 100)     //向YOU
        {
            while(kbhit())//如果按压键盘就执行 发现while可以更好的控制方向 会不会出现if按太多下无法控制
            {
                sr = getch();
            }
            if(sr == 27) ZT();//暂停逻辑
            if(sr == 'W' || sr == 'S' || sr == 'w' || sr == 's') break;
            else  sr = 'D';
            wb = tcs[0]; //在没被覆盖前保存蛇尾
            DDQP(); //清除尾巴
            tcs[tcscd] = tcs[tcscd - 1]; //把蛇头赋值给前一位 原来的保留
            tcs[tcscd].X += 2;              //更新蛇头位置 向下左x+两个字符
            //判定死亡函数
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //死亡退出
            for(i = 0 ;i < tcscd ;i++)//更新位置
            {
                tcs[i] = tcs[i+1];//后一位赋值给前一位 蛇头复原
            }
            TCS_SZ();  //判定生长
            TCS_XS();   //显示蛇
            Sleep(s);
        }
    }
}


void TCS_XS(void)  //显示贪吃蛇
{
    int i;
    for(i = 0 ;i < tcscd ;i++)//显示循环
    {
        KZT_YS(11,0);
        KZT_GB(tcs[i].X,tcs[i].Y);
        if(i == (tcscd - 1))    printf("⊙"); //打印蛇头
        else printf("●");
        KZT_YS(12,0);
    }
}


void TCS_SW(COORD sw,int *kz)  //用头部的坐标判定死亡 int控制循环
{
    int i,k;
    COORD HEHE;//排序临时变量
    if(sw.X < 21 || sw.X > 73 || sw.Y < 1 || sw.Y > 25)
    {
        KZT_QP(ZBJ+1,1,25);  //清屏
        for(i = 0;i < 4;i++)
        {
            KZT_GB(ZBJ +15 ,12);
            printf("游戏结束!再贪吃也不能吃围墙啊!");
            if(i == 3)
            {
                KZT_GB(ZBJ +15 ,14);
                printf("        按任意键继续   ",3-i);
                Sleep(1000);
            }
            else
            {
            KZT_GB(ZBJ +21 ,14);
            printf("%d秒后按任意键继续           ",3-i);
            Sleep(1000);
            }
        }
        *kz = 0;
        TCS_PHB_GX();
        TCS_PHB();
    }
    for(k = 1;k < tcscd  ;k++)  //从一开始 因为最后一位马上会被替换
    {
        if(sw.X == tcs[k].X && sw.Y == tcs[k].Y)
        {
            KZT_QP(ZBJ+1,1,25);  //清屏
            for(i = 0;i < 4;i++)
            {
                KZT_GB(ZBJ +15 ,12);
                printf("游戏结束!再贪吃也不能吃自己啊!");
                if(i == 3)
                {
                    KZT_GB(ZBJ +15 ,14);
                    printf("        按任意键继续   ",3-i);
                    Sleep(1000);
                }
                else
                {
                KZT_GB(ZBJ +21 ,14);
                printf("%d秒后按任意键继续           ",3-i);
                Sleep(1000);
                }
            }
            *kz = 0;
            TCS_PHB_GX();
            TCS_PHB();
        }
    }
}

void TCS_PHB_GX(void)//更新排行榜
{
    if(wjph[9].fenshu != 0)  //大于零才排序
    {
        int i ,j;
        wjph[wjs] = wjph[9];
        wjs++;
        for(i = 0;i < wjs - 1;i++)
        {
            for(j = 0;j < wjs - i-1;j++)
            {
                if(wjph[j].fenshu < wjph[j + 1].fenshu)
                {
                    wjph[10] = wjph[j];
                    wjph[j] = wjph[j + 1];
                    wjph[j + 1] = wjph[10];
                }
            }
        }
        if(wjs > 9) wjs--;
    }
}

void TCS_SP(void)   //食物刷新函数 一旦运行就刷新
{
    int i;
    srand(time(NULL));
    sp.X = rand()%27 * 2 + 21;//52+21
    sp.Y = rand()%25 + 1;//24+1
    for(i = 0;i < tcscd ;i++)//判断是否重叠
    {
        while(sp.X == tcs[i].X && sp.Y == tcs[i].Y)
        {      /* 重叠就重新生成 */
            sp.X = rand()%27 * 2 + 21;//52+21  要让第一位必须是双数 模一个27 * 2
            sp.Y = rand()%25 + 1;//24+1
            i = -1;//重新循环
        }
    }
    /* 打印 */
    KZT_GB(sp.X,sp.Y);
    KZT_YS(10,0);
    printf("※");
    KZT_YS(12,0);
}

void TCS_SZ(void)  //生长函数 判断是否吃到
{
    int i;
    if(tcs[tcscd - 1].X == sp.X && tcs[tcscd - 1].Y == sp.Y)
    {
        wjph[9].fenshu++;
        KZT_GB( XXL +ZBJ+5,16);
        printf("玩家分数:  %-5d",wjph[9].fenshu);  //刷新分数
        tcscd++;
        for(i = tcscd - 1 ;i > 0;i--)//更新位置
        {
            tcs[i] = tcs[i-1];//前一位赋值给后一位
        }
        tcs[0] = wb; //当第一位复制到后面后 复原刚刚的尾巴
        TCS_SP();//刷新食物
    }
}

void DDQP(void)  //定点清屏 清除尾巴
{
    KZT_GB(tcs[0].X,tcs[0].Y);
    printf("  ");
}

void ZT()  //暂停
{
        KZT_GB( XXL +ZBJ+4,21);
        printf("   游戏暂停中    ");
        KZT_GB( XXL +ZBJ+4,23);
        printf("  按任意键继续   ");
        KZT_GB( XXL +ZBJ+7,20);
        printf("           ");
        KZT_GB( XXL +ZBJ+2,22);
        printf("                 ");
        KZT_GB( XXL +ZBJ+4,24);
        printf("                ");
        sr = getch();  //可以控制方向
        KZT_GB( XXL +ZBJ+4,21);
        printf("                 ");
        KZT_GB( XXL +ZBJ+4,23);
        printf("                ");
        KZT_GB( XXL +ZBJ+7,20);
        printf(" 操作指南");
        KZT_GB( XXL +ZBJ+4,22);
        printf("W A S D 控制方向");
        KZT_GB( XXL +ZBJ+4,24);
        printf("  Esc 暂停游戏");
}
