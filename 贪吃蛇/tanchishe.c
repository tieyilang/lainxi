#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "tanchishe.h"

WJ wjph[11] = //������� ���Ÿ�  ��ʮ�����ڴ洢����� ���һ��������������ʱ����
{
    {"Cjl",666},
};
int wjs = 1;//����������������� �����������9


COORD tcs[27 * 25]; //��ʼ��̰���� ��������� ���Ϊ27*25

int tcscd = 6;         //���Ƴ���

COORD sp;  //�洢ʳ������
COORD wb;   //�����߱��滻��β�� ���ڲ��ϳ�ʳ��������
char sr;//��¼�û�����

void TCS_JM()
{
    int i,j;
    KZT_GB(ZBJ,0);                    //�ϱ߽�
    printf(FGX);
    for(i = 0;i < CD;i++)
    {
        KZT_GB( ZBJ , i + 1);         //��߽߱�
        printf("|");
        KZT_GB( XXL +ZBJ, i + 1);     //��ͼ����Ϣ���ֽ�
        printf("|");
        KZT_GB( ZBJ + KD -1 , i + 1); //�ұ߽߱�
        printf("|");
    }
    KZT_GB( XXL +ZBJ+9,1);
    printf("���а�");
    KZT_GB( XXL +ZBJ+3,2);
    printf("����   ����   ����");
    KZT_GB( XXL +ZBJ+1,12);           //���а�ֽ�
    printf("---------------------");
    KZT_GB( XXL +ZBJ+1,18);
    printf("---------------------");
    KZT_GB( XXL +ZBJ+2,14);
    printf("     ����:  Cjl    ");
    KZT_GB( XXL +ZBJ+6,16);
    printf("�Ͼ�ѧ��ѧ��");
    KZT_GB( XXL +ZBJ+7,20);
	printf(" ����ָ��");
    KZT_GB( XXL +ZBJ+2,22);
	printf("W S �� �����ƶ����");
    KZT_GB( XXL +ZBJ+4,24);
	printf("Enter  ȷ��ѡ��");
    KZT_GB(ZBJ, CD + 1);              //�±߽�
    printf(FGX);
}


void TCS_XZ()  //��ʼ����
{
    int i;
    int a = 0;
    char xz;                 //�û�������
    char xs[2][10] = {"��ʼ��Ϸ","�뿪��Ϸ"};   //
    KZT_GB( ZBJ+20,9);
    printf("��̰���� C���԰桷");
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
                printf("  ��������ĸ��ַ�  ");
                KZT_GB( XXL +ZBJ+4,24);
                printf(" Enter ȷ������");
                TCS_SR();//��������
                KZT_GB(0,28);   //����������
                getch();
                KZT_QP(ZBJ+1,1,25);  //����
                TCS_JM();  //���´�ӡ����
            }
            if(a == 1)
            {
                KZT_QP(ZBJ+1,1,25);  //����
                KZT_GB(ZBJ +22 ,11);
                printf("��Ϸ����,�ټ�");
                break;
            }
        }
    }

}

void TCS_PHB() //ˢ�����а�
{
    int i;
    for(i = 0;i < wjs;i++)
    {
        KZT_GB(ZBJ +XXL+4 ,3+i);
        printf("%-6d%-7s%-5d",i+1,wjph[i].name,wjph[i].fenshu);
    }
}

void TCS_SR()  //�����������(�����ַ�) ����ʾ����Ϸ��
{
    KZT_QP(ZBJ+1,1,25);  //����
    KZT_GB(ZBJ +22 ,11);
    printf("�����������ǳ�");
    KZT_GB(ZBJ +27,13);
    scanf("%4s",wjph[9].name);
    KZT_QP(ZBJ+1,1,25);  //����
    KZT_GB( XXL +ZBJ+5,14);
    printf("��ǰ���:%5s",wjph[9].name);
    KZT_GB( XXL +ZBJ+5,16);
    printf("��ҷ���:  %-5d",wjph[9].fenshu);
    KZT_QP(ZBJ+1,1,25);  //����
    KZT_GB( XXL +ZBJ+4,22);
    printf("W A S D ���Ʒ���");
    KZT_GB( XXL +ZBJ+4,24);
    printf("  Esc ��ͣ��Ϸ");

    wjph[9].fenshu = 0;//��ʼ������
    /* ��ʼ��̰���� Ҳ�������������¿�ʼ */
    tcs[0].X=35; tcs[0].Y=11;
    tcs[1].X=37; tcs[1].Y=11;
    tcs[2].X=39; tcs[2].Y=11;
    tcs[3].X=41; tcs[3].Y=11;
    tcs[4].X=43; tcs[4].Y=11;
    tcs[5].X=45; tcs[5].Y=11;
    tcscd = 6;         //���Ƴ���

    TCS_YX();//����̰���߿�ʼ��Ϸ
}

void TCS_YX() //̰������Ϸ����!
{
    int i,s;   //iѭ������  s�ٶ�
    int kz = 1;   //���ڿ��������while ������Ϊ0
    sr = 'D'; //Ĭ��������
    TCS_SP();  //��ʼ��ʳ��
    while(kz)
    {
        //    TCS_SP();
        //    getch();
        switch(wjph[9].fenshu)//�жϷ��������ٶ�
        {
        case 0://����
            s = 400; //�ٶȺ���
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
        while(sr == 87 || sr == 119)     //����
        {
            while(kbhit())//�����ѹ���̾�ִ�� ����while���Ը��õĿ��Ʒ��� �᲻�����if��̫�����޷�����
            {
                sr = getch();
            }
            if(sr == 27) ZT();//��ͣ�߼�
            if(sr == 'A' || sr == 'D' || sr == 'a' || sr == 'd') break;
            else sr = 'W';
            wb = tcs[0]; //��û������ǰ������β
            DDQP(); //���β��
            /* �ȸ��� */
            tcs[tcscd] = tcs[tcscd - 1]; //����ͷ��ֵ��ǰһλ ԭ���ı���
            tcs[tcscd].Y--;              //������ͷλ�� ����y--
            //�ж���������
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //�����˳�
            TCS_SZ();  //�ж�����
            for(i = 0 ;i < tcscd ;i++)//����λ��
            {
                tcs[i] = tcs[i+1];//��һλ��ֵ��ǰһλ
            }
            TCS_SZ();  //�ж�����
            TCS_XS();   //��ʾ��
            Sleep(s);
        }
        while(sr == 83 || sr == 115)     //����
        {
            while(kbhit())//�����ѹ���̾�ִ�� ����while���Ը��õĿ��Ʒ��� �᲻�����if��̫�����޷�����
            {
                sr = getch();
            }
            if(sr == 27) ZT();//��ͣ�߼�
            if(sr == 'A' || sr == 'D' || sr == 'a' || sr == 'd') break;
            else sr = 'S';
            wb = tcs[0]; //��û������ǰ������β
            DDQP(); //���β��
            tcs[tcscd] = tcs[tcscd - 1]; //����ͷ��ֵ��ǰһλ ԭ���ı���
            tcs[tcscd].Y++;              //������ͷλ�� ����y++
            //�ж���������
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //�����˳�
            TCS_SZ();  //�ж�����
            for(i = 0 ;i < tcscd ;i++)//����λ��
            {
                tcs[i] = tcs[i+1];//��һλ��ֵ��ǰһλ
            }
            TCS_SZ();  //�ж�����
            TCS_XS();   //��ʾ��
            Sleep(s);
        }
        while(sr == 65 || sr == 97)     //����
        {
            while(kbhit())//�����ѹ���̾�ִ�� ����while���Ը��õĿ��Ʒ��� �᲻�����if��̫�����޷�����
            {
                sr = getch();
            }
            if(sr == 27) ZT();//��ͣ�߼�
            if(sr == 'W' || sr == 'S' || sr == 'w' || sr == 's') break;
            else sr = 'A';
            wb = tcs[0]; //��û������ǰ������β
            DDQP(); //���β��
            tcs[tcscd] = tcs[tcscd - 1]; //����ͷ��ֵ��ǰһλ ԭ���ı���
            tcs[tcscd].X -= 2;              //������ͷλ�� ������x-�����ַ�
            //�ж���������
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //�����˳�
            for(i = 0 ;i < tcscd ;i++)//����λ��
            {
                tcs[i] = tcs[i+1];//��һλ��ֵ��ǰһλ ��ͷ��ԭ
            }
            TCS_SZ();  //�ж�����
            TCS_XS();   //��ʾ��
            Sleep(s);
        }
        while(sr == 68 || sr == 100)     //��YOU
        {
            while(kbhit())//�����ѹ���̾�ִ�� ����while���Ը��õĿ��Ʒ��� �᲻�����if��̫�����޷�����
            {
                sr = getch();
            }
            if(sr == 27) ZT();//��ͣ�߼�
            if(sr == 'W' || sr == 'S' || sr == 'w' || sr == 's') break;
            else  sr = 'D';
            wb = tcs[0]; //��û������ǰ������β
            DDQP(); //���β��
            tcs[tcscd] = tcs[tcscd - 1]; //����ͷ��ֵ��ǰһλ ԭ���ı���
            tcs[tcscd].X += 2;              //������ͷλ�� ������x+�����ַ�
            //�ж���������
            TCS_SW(tcs[tcscd] ,&kz);
            if(kz == 0) break;    //�����˳�
            for(i = 0 ;i < tcscd ;i++)//����λ��
            {
                tcs[i] = tcs[i+1];//��һλ��ֵ��ǰһλ ��ͷ��ԭ
            }
            TCS_SZ();  //�ж�����
            TCS_XS();   //��ʾ��
            Sleep(s);
        }
    }
}


void TCS_XS(void)  //��ʾ̰����
{
    int i;
    for(i = 0 ;i < tcscd ;i++)//��ʾѭ��
    {
        KZT_YS(11,0);
        KZT_GB(tcs[i].X,tcs[i].Y);
        if(i == (tcscd - 1))    printf("��"); //��ӡ��ͷ
        else printf("��");
        KZT_YS(12,0);
    }
}


void TCS_SW(COORD sw,int *kz)  //��ͷ���������ж����� int����ѭ��
{
    int i,k;
    COORD HEHE;//������ʱ����
    if(sw.X < 21 || sw.X > 73 || sw.Y < 1 || sw.Y > 25)
    {
        KZT_QP(ZBJ+1,1,25);  //����
        for(i = 0;i < 4;i++)
        {
            KZT_GB(ZBJ +15 ,12);
            printf("��Ϸ����!��̰��Ҳ���ܳ�Χǽ��!");
            if(i == 3)
            {
                KZT_GB(ZBJ +15 ,14);
                printf("        �����������   ",3-i);
                Sleep(1000);
            }
            else
            {
            KZT_GB(ZBJ +21 ,14);
            printf("%d������������           ",3-i);
            Sleep(1000);
            }
        }
        *kz = 0;
        TCS_PHB_GX();
        TCS_PHB();
    }
    for(k = 1;k < tcscd  ;k++)  //��һ��ʼ ��Ϊ���һλ���ϻᱻ�滻
    {
        if(sw.X == tcs[k].X && sw.Y == tcs[k].Y)
        {
            KZT_QP(ZBJ+1,1,25);  //����
            for(i = 0;i < 4;i++)
            {
                KZT_GB(ZBJ +15 ,12);
                printf("��Ϸ����!��̰��Ҳ���ܳ��Լ���!");
                if(i == 3)
                {
                    KZT_GB(ZBJ +15 ,14);
                    printf("        �����������   ",3-i);
                    Sleep(1000);
                }
                else
                {
                KZT_GB(ZBJ +21 ,14);
                printf("%d������������           ",3-i);
                Sleep(1000);
                }
            }
            *kz = 0;
            TCS_PHB_GX();
            TCS_PHB();
        }
    }
}

void TCS_PHB_GX(void)//�������а�
{
    if(wjph[9].fenshu != 0)  //�����������
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

void TCS_SP(void)   //ʳ��ˢ�º��� һ�����о�ˢ��
{
    int i;
    srand(time(NULL));
    sp.X = rand()%27 * 2 + 21;//52+21
    sp.Y = rand()%25 + 1;//24+1
    for(i = 0;i < tcscd ;i++)//�ж��Ƿ��ص�
    {
        while(sp.X == tcs[i].X && sp.Y == tcs[i].Y)
        {      /* �ص����������� */
            sp.X = rand()%27 * 2 + 21;//52+21  Ҫ�õ�һλ������˫�� ģһ��27 * 2
            sp.Y = rand()%25 + 1;//24+1
            i = -1;//����ѭ��
        }
    }
    /* ��ӡ */
    KZT_GB(sp.X,sp.Y);
    KZT_YS(10,0);
    printf("��");
    KZT_YS(12,0);
}

void TCS_SZ(void)  //�������� �ж��Ƿ�Ե�
{
    int i;
    if(tcs[tcscd - 1].X == sp.X && tcs[tcscd - 1].Y == sp.Y)
    {
        wjph[9].fenshu++;
        KZT_GB( XXL +ZBJ+5,16);
        printf("��ҷ���:  %-5d",wjph[9].fenshu);  //ˢ�·���
        tcscd++;
        for(i = tcscd - 1 ;i > 0;i--)//����λ��
        {
            tcs[i] = tcs[i-1];//ǰһλ��ֵ����һλ
        }
        tcs[0] = wb; //����һλ���Ƶ������ ��ԭ�ոյ�β��
        TCS_SP();//ˢ��ʳ��
    }
}

void DDQP(void)  //�������� ���β��
{
    KZT_GB(tcs[0].X,tcs[0].Y);
    printf("  ");
}

void ZT()  //��ͣ
{
        KZT_GB( XXL +ZBJ+4,21);
        printf("   ��Ϸ��ͣ��    ");
        KZT_GB( XXL +ZBJ+4,23);
        printf("  �����������   ");
        KZT_GB( XXL +ZBJ+7,20);
        printf("           ");
        KZT_GB( XXL +ZBJ+2,22);
        printf("                 ");
        KZT_GB( XXL +ZBJ+4,24);
        printf("                ");
        sr = getch();  //���Կ��Ʒ���
        KZT_GB( XXL +ZBJ+4,21);
        printf("                 ");
        KZT_GB( XXL +ZBJ+4,23);
        printf("                ");
        KZT_GB( XXL +ZBJ+7,20);
        printf(" ����ָ��");
        KZT_GB( XXL +ZBJ+4,22);
        printf("W A S D ���Ʒ���");
        KZT_GB( XXL +ZBJ+4,24);
        printf("  Esc ��ͣ��Ϸ");
}
