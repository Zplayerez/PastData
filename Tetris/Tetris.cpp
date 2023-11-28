#define _CRT_SECURE_NO_WARNINGS
#include<istream>
#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<Process.h>

#define BlockWidth 20
#define BLOCK_COUNT 4
#define X 19
#define Y 29

using namespace std;

int	ttime;
int	itime;
bool moveFlag;
int score = 0;
int Type, Rotate;
int color[7] =
{
	{RGB(240,161,168)},{RGB(192,142,175)},{RGB(99, 187, 208)},{RGB(154,190,175)},{RGB(208,222,170)},{RGB(18,170,156)},{RGB(192,196,195)}
};
int x = 10, y = 1;
int LandedBlock[20][30] = { 0 };
int LandFlag = 0;
int Blocks[7][4][4][2] =
{
	//"T"型方块
	{{{0, 0}, {-1, 0}, {0, -1}, {1, 0}},
	 {{0, 0}, {0, -1}, {1, 0}, {0, 1}},
	 {{0, 0}, {1, 0}, {0, 1}, {-1, 0}},
	 {{0, 0}, {0, 1}, {-1, 0}, {0, -1}}},
	 //反"Z"型方块
	{{{0, 0}, {-1, 0}, {0, -1}, {1, -1}},
	 {{0, 0}, {0, -1}, {1, 0}, {1, 1}},
	 {{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	 {{0, 0}, {0, 1}, {-1, 0}, {-1, -1}}},
	 //"Z"型方块
	{{{0, 0}, {-1, -1}, {0, -1}, {1, 0}},
	 {{0, 0}, {1, -1}, {1, 0}, {0, 1}},
	 {{0, 0}, {1, 1}, {0, 1}, {-1, 0}},
	 {{0, 0}, {-1, 1}, {-1, 0}, {0, -1}}},
	 //"一"字型方块
	{{{0, 0}, {-2, 0}, {-1, 0}, {1, 0}},
	 {{0, 0}, {0, -2}, {0, -1}, {0, 1}},
	 {{0, 0}, {2, 0}, {1, 0}, {-1, 0}},
	 {{0, 0}, {0, 2}, {0, 1}, {0, -1}}},
	 //"田"字型方块
    {{{0, 0}, {-1, 0}, {-1, -1}, {0, -1}},
  	 {{0, 0}, {0, -1}, {1, -1}, {1, 0}},
	 {{0, 0}, {1, 0}, {1, 1}, {0, 1}},
	 {{0, 0}, {0, 1}, {-1, 1}, {-1, 0}}},
	//"L"型方块
    {{{0, 0}, {-1, 0}, {1, 0}, {1, -1}},
     {{0, 0}, {0, -1}, {0, 1}, {1, 1}},
     {{0, 0},{1, 0}, {-1, 0}, {-1, 1}},
     {{0, 0}, {0, 1}, {0, -1}, {-1, -1}}},
 //反"L"型方块
    {{{0, 0}, {-1, 0}, {1, 0}, {1, 1}},
     {{0, 0}, {0, -1}, {0, 1}, {-1, 1}},
     {{0, 0}, {1, 0}, {-1, 0}, {-1, -1}},
     {{0, 0}, {0, 1}, {0, -1}, {1, -1}}},
};

void UI();
void DrawBackground();
void DrawUnitBlock(int x, int y, int color);
void GenBlock();
void DrawTetrisBlock();
void MoveBlock();
void MoveBlock();
int CanGoLeft(int Type, int Rotate, int x, int y);
int CanGoRight(int Type, int Rotate, int x, int y);
int CanFall(int Type, int Rotate, int x, int y);
int CanRotate(int Type, int Rotate, int x, int y);
void LandBlock(int x, int y);
void Print();
void Judge();
void CloseGraph();
int IsOccupiedCompletely(int y);
void RemoveRow();
void TetrisKeyHandle();
void TetrisInit();
void InitGraph();


void UI()
{
	int i = MessageBoxA(NULL, "Do you want to play Tetris?", "Tetris", MB_YESNO);
	if (i == IDYES)
	{
		MessageBoxA(NULL, "Ready", "Tetris", MB_OK);
	}
	else
	{
		MessageBoxA(NULL, "Game over!", "Tetris", MB_OK);
		exit(0);
	}
}

void InitGraph()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			LandedBlock[i][j] = RGB(189, 174, 173);
		}
	};
}

void DrawBackground()//初始化游戏背景
{
	initgraph(600, 600, SHOWCONSOLE);//第三个参数使焦点持续在控制台上
	BeginBatchDraw();
	setbkcolor(RGB(189, 174, 173));
	cleardevice();
}

void DrawUnitBlock(int x, int y, int color)//单元格
{
	int left = x * BlockWidth;
	int top = y * BlockWidth;
	int right = left + BlockWidth;
	int bottom = top + BlockWidth;
	setlinecolor(WHITE);
	setfillcolor(color);
	fillrectangle(left, top, right, bottom);
}

void GenBlock()
{
	time_t t;
	time(&t);
	srand((unsigned int)t);
	Type = rand() % 7;
	Rotate = rand() % 4;
}

void DrawTetrisBlock()
{
	for (int i = 0; i < 4; i++)
	{
		DrawUnitBlock(Blocks[Type][Rotate][i][0] + x, Blocks[Type][Rotate][i][1] + y, color[Type]);
	}
}

void DrawTetrisBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		DrawUnitBlock(Blocks[Type][Rotate][i][0] + x, Blocks[Type][Rotate][i][1] + y, color[Type]);
	}
}

void TetrisInit()
{
	setbkcolor(RGB(189, 174, 173));
	cleardevice();
	rectangle(399, 0, 599, 599);
	rectangle(399, 299, 599, 299);
	rectangle(0, 0, 399, 39);
	DrawTetrisBlock(25, 7);
	TCHAR s[5];
	_stprintf(s, _T("%d"), score);
	settextstyle(80, 0, _T("Consolas"));
	outtextxy(484, 404, s);
}

void TetrisKeyHandle()
{
	if (_kbhit())
	{
		char input;
		input = _getch();
		if (input == 'a' || input == 'A')
		{
			x--;
		}
		else if (input == 'd' || input == 'D')
		{
			x++;
		}
		else if (input == 'w' || input == 'W')
		{
			if (CanRotate(Type, Rotate, x, y) == 0)
			{
				Rotate++;
				if (Rotate > 3)
				{
					Rotate = 0;
				}
			}
		}
		else if (input == 's' || input == 'S')
		{
			y++;
		}
		else if (input == 'q' || input == 'Q')
		{
			system("pause");
			//exit(0);
		}
		Judge();
	}
}

void MoveBlock()
{
	ttime = GetTickCount();
	while (1)
	{
		TetrisInit();
		DrawTetrisBlock();
		itime = GetTickCount();
		if ((itime - 200) > ttime)
		{
			moveFlag = TRUE;
			ttime = GetTickCount();
		}
		if (moveFlag)
		{
			moveFlag = FALSE;
			y++;
			Judge();
			Print();
			FlushBatchDraw();
		}
		if (_kbhit())
		{
			TetrisKeyHandle();
		}
	}
}

int CanGoLeft(int Type, int Rotate, int x, int y) 
{
    int WillBeX, WillBeY;
	for (int i = 0; i < BLOCK_COUNT; i++)
    {
        WillBeX = x + Blocks[Type][Rotate][i][0];
		WillBeY = y + Blocks[Type][Rotate][i][1];
		if (WillBeX < 0)
		{
			return -1;
		}
    }
    return 0;
}

int CanGoRight(int Type, int Rotate, int x, int y)
{
	int WillBeX, WillBeY;
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		WillBeX = x + Blocks[Type][Rotate][i][0];
		WillBeY = y + Blocks[Type][Rotate][i][1];
		if (WillBeX > X)
		{
			return -1;
		}
	}
	return 0;
}

int CanFall(int Type, int Rotate, int x, int y)
{
	int WillBeX, WillBeY;
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		WillBeX = x + Blocks[Type][Rotate][i][0];
		WillBeY = y + Blocks[Type][Rotate][i][1];
		if (WillBeY > Y)
		{
			return -1;
		}
		if (LandedBlock[WillBeX][WillBeY] != RGB(189, 174, 173))
		{
			return -1;
		}
	}
}

int CanRotate(int Type, int Rotate, int x, int y)
{
	for (int i = 0; i < BlockWidth; i++)
	{
		if (LandedBlock[x + Blocks[Type][Rotate][i][0]][y + Blocks[Type][Rotate][i][1]] != RGB(189, 174, 173))
		{
			return -1;
		}
	}
	return 0;
}

void LandBlock(int x, int y)
{
	int CoordX,CoordY;
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		CoordX = x + Blocks[Type][Rotate][i][0];
		CoordY = y + Blocks[Type][Rotate][i][1];
		LandedBlock[CoordX][CoordY] = color[Type];
		cout << '(' << CoordX << ',' << CoordY << ')';
	}
	cout << endl;
	LandFlag = 1;
}

void Print()
{
	for (int i = 0; i <= Y; i++)
	{
		for (int j = 0; j <= X; j++)
		{
			if (LandedBlock[j][i] != RGB(189, 174, 173))
			{
				DrawUnitBlock(j, i, LandedBlock[j][i]);
			};
		}
	}
}

int IsOccupiedCompletely(int y)
{
	for (int i = 0; i <= X; i++)
	{
		if (LandedBlock[i][y] == RGB(189, 174, 173))
		{
			return -1;
		}
	}
	return 0;
}

void RemoveRow()
{
	for (int i = Y; i > 0; i--)
	{
		if (IsOccupiedCompletely(i) == 0)
		{
			score+=10;
			for (int j = Y; j > 0; j--)
			{
				for (int k = 0; k <= X; k++)
				{
					LandedBlock[k][j] = LandedBlock[k][j - 1];
				}
				
			}
		}
	}
}

void Judge()
{
	for (int i = 0; i <= X; i++)
	{
		for (int j = 0; j <= Y; j++)
		{
			if (LandedBlock[i][j] != RGB(189, 174, 173) && j < 2)
			{
				MessageBoxA(NULL, "Game over!", "Tetris", MB_OK);
				char buf[100];
				sprintf_s(buf, "%d", score);
				MessageBoxA(NULL, buf, "Your score is", MB_OK);
				exit(0);
			}
		}
	}
	if (CanGoLeft(Type, Rotate, x, y) == -1)
	{
		x++;
	}
	if (CanGoRight(Type, Rotate, x, y) == -1)
	{
		x--;
	}
	if (CanFall(Type, Rotate, x, y) == -1)
	{
		y--;
		LandBlock(x, y);
		x = 10, y = 1;
		GenBlock();
	}
	RemoveRow();
}

void CloseGraph()
{
    _getch();
    closegraph();
}

void main()
{
	UI();
	InitGraph();
	GenBlock();
	DrawBackground();
	FlushBatchDraw();
	DrawTetrisBlock();
	FlushBatchDraw();
	MoveBlock();
	EndBatchDraw();
    CloseGraph();
}