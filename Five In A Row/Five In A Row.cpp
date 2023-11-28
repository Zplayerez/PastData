#define _CRT_SECURE_NO_WARNINGS
#include<istream>
#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<easyx.h>
#include <mmsystem.h>
#include<Windows.h>
#pragma comment(lib,"winmm.lib")

#define N 15
#define block_width 40
#define margin 30
typedef int Board;
typedef int chessKind;
int clickRow, clickCol;
int tempColor = BLACK;
int chessBox[N][N];
int humanNum;
int aiNum;
int emptyNum;
int tempX = 0, tempY = 0;
int scoreMap[N][N] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
		{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
		{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
		{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
		{0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
		{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
		{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
		{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
		{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
		{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
Board height = (N - 1) * block_width + 2 * margin;
Board width = (N - 1) * block_width + 2 * margin;
HWND hwnd;

using namespace std;

void loginHome();
void BGM();
void login();
void setWindowStyle();
void loginInterface();
void gameInterface();
bool isInRect(ExMessage* msg, int x, int y, int w, int h);
void InitChess();
void drawBoard();
void selectColor();
void drawChess(int row, int col, chessKind color);
void changeColor();
void checkClick(ExMessage m);
void Click();
int ContLimit(int n);
void regretPlay();
void JudgeWin(int x, int y, int color);
void calculateScore();
void think();
void player();
void AI();

enum MenuOp
{
	Start,
	Rule,
	Author,
	Quit,
	Home
};
enum MenuOp menuState = Home;

bool isInRect(ExMessage* msg, int x, int y, int w, int h)
{
	if (msg->x > x && msg->x < x + w && msg->y > y && msg->y < y + h)
	{
		return true;
	}
	return false;
}

void BGM()
{
	mciSendString("open Music/带我远游.mp3 alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat", NULL, 0, NULL);
}

void loginHome()
{
	IMAGE img1;
	loadimage(&img1, "resource/02.jpg", getwidth(), getheight());
	putimage(0, 0, &img1);

	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	TCHAR s1[10];
	_stprintf(s1, _T("开始游戏"));
	settextstyle(35, 0, _T("楷体"));
	outtextxy(160, 150, s1);

	TCHAR s2[10];
	_stprintf(s2, _T("游戏规则"));
	settextstyle(35, 0, _T("楷体"));
	outtextxy(160, 250, s2);

	TCHAR s3[10];
	_stprintf(s3, _T("开发人员"));
	settextstyle(35, 0, _T("楷体"));
	outtextxy(160, 350, s3);

	TCHAR s4[10];
	_stprintf(s4, _T("结束游戏"));
	settextstyle(35, 0, _T("楷体"));
	outtextxy(160, 450, s4);
}

void setWindowStyle()
{
	system("title 用户登录");
	system("color f0");
	system("mode con cols=40 lines=8");
}

void login()
{

}

void loginInterface()
{
	initgraph(800, 620);
	cleardevice();
	loginHome();

	while (1)
	{
		ExMessage msg = getmessage(EM_MOUSE);
		MOUSEMSG Mouse = GetMouseMsg();

		while (Mouse.uMsg == WM_LBUTTONDOWN)
		{
			cout << "(" << msg.x << "," << msg.y << ")" << endl;
			if (isInRect(&msg, 160, 150, 145, 35))//开始游戏
			{
				menuState = Start;
				cout << menuState << endl;
			}
			else if (isInRect(&msg, 160, 250, 145, 35))//游戏规则
			{
				menuState = Rule;
				cout << menuState << endl;
			}
			else if (isInRect(&msg, 160, 350, 145, 35))//开发人员
			{
				menuState = Author;
				cout << menuState << endl;
			}
			else if (isInRect(&msg, 160, 450, 145, 35))//结束游戏
			{
				menuState = Quit;
				cout << menuState << endl;
			}

			if (menuState == Start)
			{
				mciSendString("close BGM", NULL, 0, NULL);
				cleardevice();
				return;
			}
			else if (menuState == Rule)
			{
				cleardevice();
				IMAGE img3;
				loadimage(&img3, "resource/03.jpg", getwidth(), getheight());
				putimage(0, 0, &img3);

				TCHAR s5[50];
				_stprintf(s5, ("1.黑方在天元放第一子。"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(RGB(244, 62, 6));
				outtextxy(225, 110, s5);

				TCHAR s6[50];
				_stprintf(s6, ("2.首先在横、竖、斜方向上成五"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(RGB(244, 62, 6));
				outtextxy(170, 210, s6);

				TCHAR s7[50];
				_stprintf(s7, ("（连续五个己方棋子）者为胜。"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(RGB(244, 62, 6));
				outtextxy(165, 310, s7);

				TCHAR s8[50];
				_stprintf(s8, ("3.超过五子以上不算赢也不算输。"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(RGB(244, 62, 6));
				outtextxy(165, 410, s8);

				TCHAR s9[10];
				_stprintf(s9, ("主页"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(WHITE);
				outtextxy(0, 0, s9);

				while (true)
				{
					ExMessage msg1 = getmessage(EM_MOUSE);
					MOUSEMSG Mouse1 = GetMouseMsg();

					if (Mouse1.uMsg == WM_LBUTTONDOWN)
					{
						if (isInRect(&msg1, 0, 0, 70, 35))
						{
							loginHome();
							menuState = Home;
							break;
						}
						cout << "(" << msg1.x << "," << msg1.y << ")" << endl;
					}
				}
			}
			else if (menuState == Author)
			{
				cleardevice();
				IMAGE img4;
				loadimage(&img4, "resource/04.jpg", getwidth(), getheight());
				putimage(0, 0, &img4);

				TCHAR s10[10];
				_stprintf(s10, ("主页"));
				settextstyle(35, 0, ("楷体"));
				settextcolor(WHITE);
				outtextxy(0, 0, s10);

				while (true)
				{
					ExMessage msg2 = getmessage(EM_MOUSE);
					MOUSEMSG Mouse2 = GetMouseMsg();

					if (Mouse2.uMsg == WM_LBUTTONDOWN)
					{
						if (isInRect(&msg2, 0, 0, 70, 35))
						{
							loginHome();
							menuState = Home;
							break;
						}
						cout << "(" << msg2.x << "," << msg2.y << ")" << endl;
					}
				}
			}
			else if (menuState == Quit)
			{
				exit(0);
			}
			break;
		}
	}
}

void gameInterface()
{

	IMAGE img2;
	loadimage(&img2, "resource/01.jpg",getwidth(),getheight());
	putimage(0,0,&img2);

	drawBoard();

}

void InitChess()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			chessBox[i][j] = -1;
		}
	}
}

void drawBoard()
{
	/*initgraph(800, 620);
	setbkcolor(RGB(255, 205, 150));
	cleardevice();*/
	setlinecolor(BLACK);
	for (int i = 0; i < N; i++)
	{
		line(29, 29 + i * block_width, 589, 29 + i * block_width);
	}
	for (int j = 0; j < N; j++)
	{
		line(29 + j * block_width, 29, 29 + j * block_width, 589);
	}
	setfillcolor(BLACK);
	fillcircle(149, 149, 5);
	fillcircle(149, 469, 5);
	fillcircle(469, 149, 5);
	fillcircle(469, 469, 5);
	fillcircle(309, 309, 5);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	for (int i = 0; i < N; i++)
	{
		static int x = 1;
		TCHAR s[5];
		_stprintf(s, "%d", x++);
		settextstyle(20, 0, "Consolas");
		outtextxy(25 + i * block_width, 5, s);
	}
	for (int j = 0; j < N; j++)
	{
		static TCHAR c = 'A';
		settextstyle(20, 0, "Consolas");
		outtextxy(12, 20 + j * block_width, c++);
	}

	TCHAR s10[8];
	_stprintf(s10, ("认输"));
	settextstyle(35, 0, ("隶书"));
	settextcolor(WHITE);
	outtextxy(650, 300, s10);
}

void selectColor()
{
	int i = MessageBoxA(NULL, "你是否要选择先手？", "Gobang", MB_YESNO);
	if (i == IDYES)
	{
		return;
	}
	else 
	{
		AI();
		changeColor();
		return;
	}
}

void drawChess(int clickRow, int clickCol, chessKind color)
{
	setfillcolor(color);
	fillcircle(clickRow, clickCol, 15);
}

void changeColor()
{
	switch (tempColor)
	{
	case WHITE:
		tempColor = BLACK;
		break;
	case BLACK:
		tempColor = WHITE;
		break;
	}
}

void checkClick(ExMessage m)
{
	int col = (m.x + 1 - margin) / block_width;
	int row = (m.y + 1 - margin) / block_width;

	int leftTopX1 = margin + col * block_width - 1;
	int leftTopY1 = margin + row * block_width - 1;

	int leftTopX2 = block_width + leftTopX1;
	int leftTopY2 = leftTopY1;

	int leftTopX3 = leftTopX1;
	int leftTopY3 = block_width + leftTopY1;

	int leftTopX4 = block_width + leftTopX1;
	int leftTopY4 = block_width + leftTopY1;

	double checkBoard = block_width * 0.45;
	
	if (double(pow(pow(m.x - leftTopX1, 2) + pow(m.y - leftTopY1, 2), 0.5)) <= checkBoard)
	{
		clickRow = leftTopX1;
		clickCol = leftTopY1;
	}
	if (double(pow(pow(m.x - leftTopX2, 2) + pow(m.y - leftTopY2, 2), 0.5)) <= checkBoard)
	{
		clickRow = leftTopX2;
		clickCol = leftTopY2;
	}
	if (double(pow(pow(m.x - leftTopX3, 2) + pow(m.y - leftTopY3, 2), 0.5)) <= checkBoard)
	{
		clickRow = leftTopX3;
		clickCol = leftTopY3;
	}
	if (double(pow(pow(m.x - leftTopX4, 2) + pow(m.y - leftTopY4, 2), 0.5)) <= checkBoard)
	{
		clickRow = leftTopX4;
		clickCol = leftTopY4;
	}
}

void Click()
{
	hwnd = GetHWnd();
	while (1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		MOUSEMSG Mouse = GetMouseMsg();
		checkClick(m);
		if (Mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (chessBox[(clickRow + 1 - margin) / block_width][(clickCol + 1 - margin) / block_width] != -1 && (clickRow + 1 - margin) / block_width <= 14 && (clickCol + 1 - margin) / block_width <= 14)
			{
				MessageBox(hwnd, "此处已有棋子,请重新选择下棋点", "五子棋", MB_OK);
				continue;
			}
			if (isInRect(&m, 650, 300, 70, 30))
			{
				MessageBox(hwnd, "这就认输了？菜！", "五子棋", MB_OK);
				closegraph();
				exit(0);
			}

			if ((clickRow + 1 - margin) / block_width <= 14 && (clickCol + 1 - margin) / block_width <= 14)
			{
				srand((unsigned)time(NULL));
				int waitTime = (rand() % (1000 - 750 + 1)) + 750;
				player();
				changeColor();
				Sleep(waitTime);
				AI();
				changeColor();
			}
		}
	}
}

int ContLimit(int n)
{
	if (n > 14)
	{
		return 14;
	}
	if (n < 0)
	{
		return 0;
	}
	else return n;
}

void regretPlay()//待续
{

}

void JudgeWin(int x, int y, int color)
{
	int i = 0;
	int j = 0;
	int tempx = 0;
	int tempy = 0;
	int Cont_i = 0;
	//cout << '(' << ContLimit(x - 4) << ',' << ContLimit(x + 4) << ')' << endl;
	//cout << '(' << ContLimit(y - 4) << ',' << ContLimit(y + 4) << ')' << endl;
	for (i = ContLimit(x - 4); i <= ContLimit(x + 4); i++)
	{
		j = y;
		if (chessBox[i][j] != color)
		{
			Cont_i = 0;
		}
		else if (chessBox[i][j] == color)
		{
			Cont_i += 1;
			//cout << "Cont_i1: " << Cont_i << endl;
		}
		if (Cont_i >= 5)
		{
			if (color==WHITE)
			{
				MessageBox(hwnd, "游戏结束 白棋获胜", "五子棋", MB_OK);
			}
			if (color == BLACK)
			{
				MessageBox(hwnd, "游戏结束 黑棋获胜", "五子棋", MB_OK);
			}
			exit(0);
		}
	}
	
	Cont_i = 0;
	for (j = ContLimit(y - 4); j <= ContLimit(y + 4); j++)
	{
		i = x;
		if (chessBox[i][j] != color)
		{
			Cont_i = 0;
		}
		else if (chessBox[i][j] == color)
		{
			Cont_i += 1;
			//cout << "Cont_i2: " << Cont_i << endl;
		}
		if (Cont_i >= 5)
		{
			if (color == WHITE)
			{
				MessageBox(hwnd, "游戏结束 白棋获胜", "五子棋", MB_OK);
			}
			if (color == BLACK)
			{
				MessageBox(hwnd, "游戏结束 黑棋获胜", "五子棋", MB_OK);
			}
			exit(0);
		}
	}
	
	Cont_i = 0;
	tempx = x;
	tempy = y;
	while (tempx - 1 >= 0 && tempy - 1 >= 0 && x - tempx < 4 && y - tempy < 4)
	{
		tempx--;
		tempy--;
	}
	for (i = tempx, j = tempy; i <= ContLimit(x + 4) && j <= (y + 4); i++, j++)
	{
		if (chessBox[i][j] != color)
		{
			Cont_i = 0;
		}
		else if (chessBox[i][j] == color)
		{
			Cont_i += 1;
			//cout << "Cont_i3: " << Cont_i << endl;
		}
		if (Cont_i >= 5)
		{
			if (color == WHITE)
			{
				MessageBox(hwnd, "游戏结束 白棋获胜", "五子棋", MB_OK);
			}
			if (color == BLACK)
			{
				MessageBox(hwnd, "游戏结束 黑棋获胜", "五子棋", MB_OK);
			}
			exit(0);
		}
	}
	
	Cont_i = 0;
	tempx = x;
	tempy = y;
	while (tempx - 1 >= 0 && tempy + 1 <= 14 && x - tempx < 4 && tempy - y < 4)
	{
		tempx--;
		tempy++;
	}
	for (i = tempx, j = tempy; i <= ContLimit(x + 4) && j >= (y - 4); i++, j--)
	{
		if (chessBox[i][j] != color)
		{
			Cont_i = 0;
		}
		else if (chessBox[i][j] == color)
		{
			Cont_i += 1;
			//cout << "Cont_i4: " << Cont_i << endl;
		}
		if (Cont_i >= 5)
		{
			if (color == WHITE)
			{
				MessageBox(hwnd, "游戏结束 白棋获胜", "五子棋", MB_OK);
			}
			if (color == BLACK)
			{
				MessageBox(hwnd, "游戏结束 黑棋获胜", "五子棋", MB_OK);
			}
			exit(0);
		}
	}
	
}

void calculateScore()
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (chessBox[row][col] == -1)
			{
				for (int y = -1; y <= 1; y++)
				{
					for (int x = -1; x <= 1; x++)
					{
						humanNum = 0;
						aiNum = 0;
						emptyNum = 0;

						if (!(y == 0 && x == 0))
						{
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row + i * y;
								int curCol = col + i * x;
								if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == BLACK)
								{
									humanNum++;
								}
								else if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == -1)
								{
									emptyNum++;
									break;
								}
								else
									break;
							}
							
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row - i * y;
								int curCol = col - i * x;
								if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == BLACK)
								{
									humanNum++;
								}
								else if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == -1)
								{
									emptyNum++;
									break;
								}
								else
									break;
							}

							if (humanNum == 1)
							{
								scoreMap[row][col] += 10;
							}
							else if (humanNum == 2)
							{
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 30;
								}
								else if (emptyNum == 2)
								{
									scoreMap[row][col] += 40;
								}
							}
							else if (humanNum == 3)
								{
									if (emptyNum == 1)
									{
										scoreMap[row][col] += 60;
									}
									else if (emptyNum == 2)
									{
										scoreMap[row][col] += 7500;
									}
								}
							else if (humanNum == 4)
								{
									scoreMap[row][col] += 20000;
								}

							emptyNum = 0;

							for (int i = 1; i <= 4; i++)
									{
										int curRow = row + i * y;
										int curCol = col + i * x;
										if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == WHITE)
										{
											aiNum++;
										}
										else if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == -1)
										{
											emptyNum++;
											break;
										}
										else
											break;
									}

							for (int i = 1; i <= 4; i++)
									{
										int curRow = row - i * y;
										int curCol = col - i * x;
										if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == WHITE)
										{
											aiNum++;
										}
										else if (curRow >= 0 && curRow < N && curCol >= 0 && curCol < N && chessBox[curRow][curCol] == -1)
										{
											emptyNum++;
											break;
										}
										else
											break;
									}

							if (aiNum == 0)
									{
										scoreMap[row][col] += 5;
									}
							if (aiNum == 1)
									{
										scoreMap[row][col] += 10;
									}
							else if (aiNum == 2)
							{
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 25;
								}
								else if (emptyNum == 2)
									scoreMap[row][col] += 50;
							}
							else if (aiNum == 3)
										{
											if (emptyNum == 1)
											{
												scoreMap[row][col] += 55;
											}
											else if (emptyNum == 2)
											{
												scoreMap[row][col] += 10000;
											}
										}
							else if (aiNum == 4)
							{
								scoreMap[row][col] += 30000;
							}
						}
					}
				}
			}
		}
	}
}

void think()
{
	calculateScore();

	int maxScore = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			// 前提是这个坐标是空的
			if (chessBox[row][col] == -1) {
				if (scoreMap[row][col] > maxScore)          // 找最大的数和坐标
				{
					maxScore = scoreMap[row][col];
					tempX = row;
					tempY = col;
				}
			}
		}
	}
	cout << "score:" << maxScore << endl;
}

void player()
{
	chessBox[(clickRow + 1 - margin) / block_width][(clickCol + 1 - margin) / block_width] = tempColor;
	PlaySound("下棋音效.wav", NULL, SND_FILENAME | SND_ASYNC);
	drawChess(clickRow, clickCol, tempColor);
	JudgeWin((clickRow + 1 - margin) / block_width, (clickCol + 1 - margin) / block_width, chessBox[(clickRow + 1 - margin) / block_width][(clickCol + 1 - margin) / block_width]);
}

void AI()
{
	calculateScore();
	think();
	chessBox[tempX][tempY] = tempColor;
	PlaySound("下棋音效.wav", NULL, SND_FILENAME | SND_ASYNC);
	drawChess(tempX * block_width + margin - 1, tempY * block_width + margin - 1, tempColor);
	JudgeWin(tempX, tempY, chessBox[tempX][tempY]);
}

void main()
{
	BGM();
	//setWindowStyle();
	InitChess();
	loginInterface();
	gameInterface();
	selectColor();
	Click();
	_getch();
	closegraph();
}