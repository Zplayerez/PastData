#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int x, i, j;
    char m;
    do
    {

        srand(time(NULL));
        x = rand() % 100 + 1;
        for (i = 1; i <= 10; i = i + 1)
        {
            printf("��%d�Σ����һ��ħ�����֣�", i);
            scanf_s("%d", &j);
            if (j == x)
            {
                printf("��ȷ\n��ô�����");
                break;
            }
            else {
                printf("����");
                if (j > x)printf("�´��ˣ�\n");
                else printf("��С�ˣ�");
            }
        }
        printf("ħ��������%d\nҪ��������\nY/N��y/n\n", x);
        scanf_s(" %c", &m);
        while (m != 'y' && m != 'Y' && m != 'n' && m != 'N')
        {
            printf("��������Y/y,N/n\n");
            scanf_s(" %c", &m);
        }

    } while (m != 'n' && m != 'N');

}