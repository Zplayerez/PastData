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
            printf("第%d次，请猜一个魔法数字：", i);
            scanf_s("%d", &j);
            if (j == x)
            {
                printf("正确\n你好聪明！");
                break;
            }
            else {
                printf("错误！");
                if (j > x)printf("猜大了！\n");
                else printf("猜小了！");
            }
        }
        printf("魔法数字是%d\n要继续玩吗？\nY/N，y/n\n", x);
        scanf_s(" %c", &m);
        while (m != 'y' && m != 'Y' && m != 'n' && m != 'N')
        {
            printf("错误，输入Y/y,N/n\n");
            scanf_s(" %c", &m);
        }

    } while (m != 'n' && m != 'N');

}