#include <graphics.h>

int main()
{
        initgraph(640, 480);

        //������������
        char str[100];
        //���öԻ�����
        inputbox_getline("�������", "�����루�س�ȷ�ϣ�", str, 100);

        //��ʾ���������
        outtextxy(0, 0, str);

        getch();

        closegraph();
        return 0;
}
