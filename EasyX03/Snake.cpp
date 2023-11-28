#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BlockWidth 20
int direction = 0;//�����ߵķ���
int WAIT_TIME;
int score = 0;
int snake[100][2] =
{ {20,31},{20,32},{21,32},{21,33},{21,34},{21,35},{22,35},{23,35},{23,36} };//��ʼ���ߵ�λ��
int snakesize = 9;
int food[2] = { 0 };

void UI()//��ª���û�����
{
	int i = MessageBoxA(NULL, "Do you want to play the game?", "Gluttonous Snake", MB_YESNO);
	if (i == IDYES) 
	{
		int j = MessageBoxA(NULL, "Do you want to do something challenging?", "Gluttonous Snake", MB_YESNO);
		if (j == IDYES)
		{
			WAIT_TIME = 250;
		}
		else
		{
			WAIT_TIME = 500;
		}
		MessageBoxA(NULL, "Ready", "Gluttonous Snake", MB_OK);
	}
	else 
	{
		MessageBoxA(NULL, "Game over!", "Gluttonous Snake", MB_OK);/*����*/
		exit(0);
	}
}

void DrawBackground()//��ʼ����Ϸ����
{
	initgraph(800, 800, SHOWCONSOLE);//����������ʹ��������ڿ���̨��
	BeginBatchDraw();
	setbkcolor(RGB(189, 174, 173));
	cleardevice();
}

void DrawUnitBlock(int a, int b, int c)//��Ԫ��
{
	int left = a * BlockWidth;
	int top = b * BlockWidth;
	int right = left + BlockWidth;
	int bottom = top + BlockWidth;
	setlinecolor(c);
	setfillcolor(c);
	fillrectangle(left, top, right, bottom);
}

void BorderWall()//��ʼ��ǽ
{
	for (int i = 0; i <= 40; i++)
	{
		for (int j = 0; j <= 40; j++)
		{
			if (i == 0 || i == 39)
			{
				DrawUnitBlock(i, j, RGB(159, 163, 154));
			}
			else if (j == 0 || j == 39)
			{
				DrawUnitBlock(i, j, RGB(159, 163, 154));
			}
		}
	}
}

void InitFood()//�������ʳ��
{
	unsigned seed = time(0);
	srand(seed);
	food[0] = (rand() % (38 - 1 + 1)) + 1;
	food[1] = (rand() % (38 - 1 + 1)) + 1;
}

void InitSnake()//��ʼ����
{
	BorderWall();
	for (int i = 0; i < snakesize; i++)
	{
		int color = RGB(238, 162, 164);//����ɫ����(ĵ���ۺ�)����ɫ��Դ��http://zhongguose.com/
		DrawUnitBlock(snake[i][0], snake[i][1], color);
	}
	for (int i = 0; i < snakesize; i++)//��ӡ�ߵ�����
	{
		cout << "(" << snake[i][0] << "," << snake[i][1] << ")" ;
	}
	cout << endl;
}

void AutoMove()//�����Զ���ǰ
{
	setbkcolor(RGB(189, 174, 173));
	cleardevice();//���±���
	BorderWall();//ǽ
	DrawUnitBlock(food[0], food[1], RGB(33, 119, 184));//ʳ��
	for (int i = snakesize - 1; i > 0; i--)//������ͷ���������
	{
		snake[i][0] = snake[i - 1][0];
		snake[i][1] = snake[i - 1][1];
	}
	switch (direction)
	{
	case UP:
		snake[0][1]--;
		break;
	case DOWN:
		snake[0][1]++;
		break;
	case LEFT:
		snake[0][0]--;
		break;
	case RIGHT:
		snake[0][0]++;
		break;
	}
	for (int i = 0; i < snakesize; i++)
	{
		int color = RGB(238, 162, 164);//����(ĵ���ۺ�)����ɫ��Դ��http://zhongguose.com/
		DrawUnitBlock(snake[i][0], snake[i][1], color);
	}
	for (int i = 0; i < snakesize; i++)
	{
		cout << "(" << snake[i][0] << "," << snake[i][1] << ")";
	}
	cout << endl;
}

void BodyGrowth()
{
	if (snake[snakesize - 2][0] - snake[snakesize - 3][0] > 0 && snake[snakesize - 2][1] - snake[snakesize - 3][1] == 0)
	{
		snake[snakesize - 1][0] = snake[snakesize - 2][0] + 1;
		snake[snakesize - 1][1] = snake[snakesize - 2][1];
	}
	if (snake[snakesize - 2][0] - snake[snakesize - 3][0] < 0 && snake[snakesize - 2][1] - snake[snakesize - 3][1] == 0)
	{
		snake[snakesize - 1][0] = snake[snakesize - 2][0] - 1;
		snake[snakesize - 1][1] = snake[snakesize - 2][1];
	}
	if (snake[snakesize - 2][0] - snake[snakesize - 3][0] == 0 && snake[snakesize - 2][1] - snake[snakesize - 3][1] > 0)
	{
		snake[snakesize - 1][0] = snake[snakesize - 2][0];
		snake[snakesize - 1][1] = snake[snakesize - 2][1] - 1;
	}
	if (snake[snakesize - 2][0] - snake[snakesize - 3][0] == 0 && snake[snakesize - 2][1] - snake[snakesize - 3][1] < 0)
	{
		snake[snakesize - 1][0] = snake[snakesize - 2][0];
		snake[snakesize - 1][1] = snake[snakesize - 2][1] + 1;
	}
}

void JudgeFood()//�ж������ɵ�ʳ���Ƿ���������
{
	for (int i = 0; i < snakesize; i++)
	{
		if (snake[i][0] == food[0] && snake[i][1] == food[1])
		{
			InitFood();
			JudgeFood();
		}
	}
}

void EatFood()
{
	if (snake[0][0] == food[0] && snake[0][1] == food[1])
	{
		score++;
		snakesize++;
		void BodyGrowth();
		InitFood();
		JudgeFood();
	}
}

void Judge()
{
	for (int i = 1; i < snakesize; i++)
	{
		if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
		{
			MessageBoxA(NULL, "Game over!", "Gluttonous Snake", MB_OK);
			char buf[100];
			sprintf_s(buf, "%d", score);
			MessageBoxA(NULL, buf, "Your score is", MB_OK);
			exit(0);
		}
	}
	if (snake[0][0] == 0 || snake[0][0] == 39 || snake[0][1] == 0 || snake[0][1] == 39)
	{
		MessageBoxA(NULL, "Game over!", "Gluttonous Snake", MB_OK);
		char buf[100];
		sprintf_s(buf, "%d", score);
		MessageBoxA(NULL, buf, "Your score is", MB_OK);
		exit(0);
	}
	EatFood();
}

void MoveSnake()//�����ߵ��ƶ�
{
	while (1)
	{
		if (_kbhit())
		{
			char input;
			while (!_kbhit() == 0)//�����������˶�������������һ������Ϊ׼
				input = _getch();
			if (input == 'a')
			{
				if (direction == RIGHT)//�����޷���ͷ
					continue;
				direction = LEFT;
			}
			else if (input == 'd')
			{
				if (direction == LEFT)//�����޷���ͷ
					continue;
				direction = RIGHT;
			}
			else if (input == 'w')
			{
				if (direction == DOWN)//�����޷���ͷ
					continue;
				direction = UP;
			}
			else if (input == 's')
			{
				if (direction == UP)//�����޷���ͷ
					continue;
				direction = DOWN;
			}
			else if (input == 'q')//������Ϸ
			{
				cout << "                    ��Ϸ����" << endl;
				break;
			}
			for (int i = 0; i < snakesize; i++)
			{
				cout << "(" << snake[i][0] << "," << snake[i][1] << ")" ;
			}
			cout << endl;
		}
		Sleep(WAIT_TIME);
		AutoMove();
		FlushBatchDraw();
		Judge();
	}
}

void CloseGraph()//�رջ���
{
	_getch();
	closegraph();
}

int main()
{
	UI();
	DrawBackground();
	InitFood();
	InitSnake();
	MoveSnake();
	CloseGraph();
	return 0;
}