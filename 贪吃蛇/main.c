#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "kuwenjian.h"
#include "tanchishe.h"

int main()
{

    KZT_BT("̰���� C���԰� V1.0 �Ͼ�ѧ�� Cjl");//���Ŀ���̨����
    KZT_DX(125,35);                   //���Ŀ���̨��С
    KZT_YS(12,0);                     //���Ŀ���̨��ɫ
    TCS_JM();                         //������ʾ����
    TCS_PHB();                        //���а���ʾ����
    TCS_XZ();                         //�û�ѡ���� ������ʼ��Ϸ�Ⱥ����߼�
    KZT_GB(0,29);
    return 0;
}
