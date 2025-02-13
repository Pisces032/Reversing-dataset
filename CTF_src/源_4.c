//̰����dos��

//1----ǽ���
//2----�����
//3----ʳ���
//4----ǽ��

//--------ͷ�ļ�-----------
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h> //������ _kbhit()��_getch()����
#include <windows.h> 
#include <process.h>

//--------�궨��-----------
#define LEFT 0x4b 
#define RIGHT 0x4d 
#define DOWN 0x50 
#define UP 0x48 

//--------ȫ�ֱ���---------

typedef struct
{
	int flag;
	int sort;
}Data;

typedef struct
{
	int x, y;
}nextdata;

//direction=1;��
//direction=2;��
//direction=3;��
//direction=4;��
Data wall[20][20];
nextdata next;

int direction = 1;
int length = 0;
//----------����-----------
void InitData();
void DrawData();
void NextFoot();
int JudgeWall();
int JudgeFood();
int JudgeEatFood();
int JudgeInWall();
void JudgeDirection();
void RandFood();
void IncreatLeath();
void MoveFoot();

void main()
{
	_beginthread(JudgeDirection, 0, NULL);
	//printf("O\n");
	InitData();
	NextFoot();
	while (!JudgeWall())
	{
		if (JudgeFood())
		{
			RandFood();
		}
		DrawData();
		if (JudgeEatFood())
		{
			IncreatLeath();
		}
		else if (JudgeInWall())
		{
			MoveFoot();
		}
		else
		{
			break;
		}
		NextFoot();
		JudgeDirection();
		Sleep(300);
	}		//	getchar();
}   //vc6.0�±�������

void InitData()
{
	int i, j;
	//��ǽ����
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			wall[i][j].flag = 4;
			wall[i][j].sort = -1;
		}
	}
	//ǽ������
	for (i = 0, j = 0; i < 20; i++)
	{
		wall[i][j].flag = 1;
	}

	for (i = 0, j = 19; i < 20; i++)
	{
		wall[i][j].flag = 1;
	}

	for (i = 0, j = 0; j < 20; j++)
	{
		wall[i][j].flag = 1;
	}
	for (i = 19, j = 0; j < 20; j++)
	{
		wall[i][j].flag = 1;
	}
	//��ǽ������

	for (i = 10, j = 10; i <= 12; i++)
	{
		wall[i][j].flag = 2;
		wall[i][j].sort = ++length;
	}
}

void DrawData()
{
	int i, j;
	system("cls");
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (1 == wall[i][j].flag)//ǽ
			{
				printf("��");
			}
			else if (2 == wall[i][j].flag)
			{
				printf("��");
			}
			else if (3 == wall[i][j].flag)
			{
				printf("��");
			}
			else if (4 == wall[i][j].flag)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void NextFoot()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{

			if (1 == wall[i][j].sort)
			{
				pprintf("%d\n", direction);
				getchar();
				getchar();
				switch (direction)
				{
				case 1:next.x = i - 1; next.y = j; break;
				case 2:next.x = i + 1; next.y = j; break;
				case 3:next.x = i; next.y = j - 1; break;
				case 4:next.x = i; next.y = j + 1; break;
				}
				// printf("����:%d\n����(%d,%d)\n",direction,next.x,next.y);
			}

		}
	}

}

int JudgeWall()
{
	if (1 == wall[next.x][next.y].flag)
	{
		return 1;
	}
	return 0;
}

int JudgeFood()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (3 == wall[i][j].flag)
			{
				return 0;
			}
		}
	}
	return 1;
}

void RandFood()
{
	int i, j;
	srand((unsigned)time(NULL));
	do
	{
		i = rand() % 20;
		j = rand() % 20;
		Sleep(20);
	} while (1 == wall[i][j].flag || 2 == wall[i][j].flag);
	wall[i][j].flag = 3;
}

int JudgeEatFood()
{
	if (3 == wall[next.x][next.y].flag)
	{
		return 1;
	}
	return 0;
}

void IncreatLeath()
{
	int i, j;
	wall[next.x][next.y].flag = 2;
	wall[next.x][next.y].sort = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (2 == wall[i][j].flag)
			{
				wall[i][j].sort++;
			}
		}
	}
	length++;
}

int JudgeInWall()
{
	if (4 == wall[next.x][next.y].flag)
	{
		return 1;
	}
	return 0;
}

void MoveFoot()
{
	int i, j;
	wall[next.x][next.y].flag = 2;
	wall[next.x][next.y].sort = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (2 == wall[i][j].flag)
			{
				wall[i][j].sort++;
			}
			if (length + 1 == wall[i][j].sort)
			{
				wall[i][j].flag = 4;
				wall[i][j].sort = -1;
			}
		}
	}
}

void JudgeDirection()
{
	char unch;
	if (_kbhit() && (unch = _getch()))
	{
		switch (unch)
		{
		case DOWN:
			if (1 != direction)
			{
				direction = 2;
			}break;
		case UP:
			if (2 != direction)
			{
				direction = 1;
			}break;
		case LEFT:
			if (4 != direction)
			{
				direction = 3;
			}break;
		case RIGHT:
			if (3 != direction)
			{
				direction = 4;
			}break;
		}
	}
}