#ifndef TANCHISHE_H_INCLUDED
#define TANCHISHE_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#define ZBJ 20   //��߾�20
#define KD 78    //��Ϸ���78
#define CD 25    //��Ϸ����
#define XXL 55   //��ͼ�����ݷֽ���
#define FGX "------------------------------------------------------------------------------"//78��

typedef struct Wanjia_  //��ҽṹ��
{
    char name[5]; //�ǳ�
    int fenshu; //��ҷ���
}WJ;


void TCS_JM(void);  //��ʾ����

void TCS_PHB(void); //���а�

void TCS_PHB_GX(void);//�������а�

void TCS_XZ(void);  //���ѡ��ʼ��Ϸ����

void TCS_SR(void);  //�����������(�����ַ�) ����ʾ����Ϸ��

void TCS_YX(void);  //̰������Ϸ����!

void TCS_SW(COORD,int*);  //��ͷ���������ж����� int����ѭ��

void TCS_XS(void);   //��ʾ(��ӡ)̰����

void TCS_SP(void);   //ʳ��ˢ������ʾ����

void TCS_SZ(void);  //�������� �ж��Ƿ�Ե�

void DDQP(void);  //��������

void ZT(void);//��ͣ


#endif // TANCHISHE_H_INCLUDED
