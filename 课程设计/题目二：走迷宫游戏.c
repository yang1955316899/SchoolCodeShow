//头文件
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//全局变量定义
#define Road 0
#define Wall 1
#define Start 2
#define End 3
#define Esc 4
#define Up 0
#define Down 1
#define Left 2
#define Right 3
#define Search 5
#define Len 27
int List_x[] = {-1,1,0,0},List_y[] = {0,0,-1,1},map[Len + 2][Len + 2],v[Len + 2][Len + 2],Use = 1;

//欢迎界面，同时初始化窗口
void Welcome()
{
	system("mode con:cols=54 lines=27&&title Maze Design:杨建文");
	//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) {25, 0});//隐藏光标函数，通过调用Windows API对窗口进行定义
	printf("\
                     	|\n\
                 __\\--__|_\n\
  II=======OOOOO[/ ★02 ___|\n\
           _____\\______|/-----.\n\
         /____________________|\n\
          \\◎◎◎◎◎◎◎◎⊙/\n\
            ~~~~~~~~~~~~~~~~\n");
	//Sleep(3000);
	system("cls");
}

//通过调用WindoesAPI，实现光标跳转到对应的区域
void Goto(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//随机生成地图函数
void Create(int x, int y)
{
	int c[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
	int i, j, t;
	for (i = 0; i < 4; i++)
		{
			j = rand() % 4;
			t = c[i][0];
			c[i][0] = c[j][0];
			c[j][0] = t;
			t = c[i][1];
			c[i][1] = c[j][1];
			c[j][1] = t;
		}
	map[x][y] = Road;
	for (i = 0; i < 4; i++)
		if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == Wall)
			{
				map[x + c[i][0]][y + c[i][1]] = Road;
				Create(x + 2 * c[i][0], y + 2 * c[i][1]);
			}
}

int Get_key()
{
	char c;
	while (c = getch())
		{
			if (c == 27)
				return Esc;
			c = getch();
			if (c == 119)
				return Up;
			if (c == 115)
				return Down;
			if (c == 97)
				return Left;
			if (c == 100)
				return Right;
		}
	return 0;
}

void Print(int x, int y)
{
	Goto(2 * y - 2, x - 1);
	switch (map[x][y])
		{
			case Start:
				printf("入");
				break;
			case End:
				printf("出");
				break;
			case Wall:
				printf("▇");
				break;
			case Road:
				printf(" ");
				break;
			case Search:
				printf("★");
				break;
		}
}

void Game()
{
	int x = 2, y = 1,c;
	while (1)
		{
			Goto(2 * y - 2, x - 1);
			printf("●\b\b");
			if (map[x][y] == End)
				{
					printf("\n\n到达终点，按任意键结束");
					getch();
					break;
				}
			c = Get_key();
			if (c == Esc)break;
			if (map[x + List_x[c]][y + List_y[c]] != Wall)
				{
					x += List_x[c];
					y += List_y[c];
					Print(x, y);
				}
		}
}

void Edit()
{
	int x,y;
	system("cls");
	Use = 2;
	printf("请输入要更改的坐标：");
	scanf("%d %d",&x,&y);
	map[x][y] = map[x][y]?0:1;
}

int DFS(int x,int y)
{
	v[x][y] = 1;
	for (int i = 0; i < 4; i++)
		{
			int tem_x = x + List_x[i],tem_y = y + List_y[i];
			if(tem_x >= 2 && tem_x <= Len && tem_y >= 2 && v[tem_x][tem_y] == 0 && map[tem_x][tem_y] == Road)
				{
					map[x][y] = Search;
					if(tem_x == Len - 1 && tem_y == Len - 1)return 0;
					if(!DFS(tem_x,tem_y))return 0;
				}
		}
	map[x][y] = Road;
}

void Url_Change(char Local[100])
{
	int temp,next;
	for ( temp = 0; temp < strlen(Local); temp++)
		{
			if (Local[temp] == '\\')/*我去太坑了，这里也要用转义字符*/
				{
					for (next = strlen(Local) + 1; next > (temp + 1); next--)
						Local[next] = Local[next - 1];
					Local[temp + 1] = '\\';
					temp++;
				}
		}
}
void Map_Out()
{
	FILE *Data;
	char Local[100],Work_name[13] = {"\\\\Map.txt"};
	system("cls");
	if(!Use)
		{
			printf("\t请输入导出的地址: ___\b\b\b");
			scanf("%s",Local);
			Url_Change(Local);
			strcat(Local,Work_name);
			Data = fopen(Local,"w");
			fprintf(Data,"%d\n",Len);
			for (int x = 1; x <= Len; x++)
				{
					for (int y = 1; y <= Len; y++)
						fprintf(Data,"%d ",map[x][y]);
					fprintf(Data,"\n");
				}

			fclose(Data);
			printf("\t成功将数据导出到%s\n\t文件名叫Map.txt\n",Local);
		}
	else printf("\t无地图数据！\n");
	printf("\t将在1.5秒后回到菜单！");
	Sleep(1500);
}

int Map_In()
{
	FILE *Data;
	int tem_Len;
	char Local[100],Work_name[13] = {"\\\\Map.txt"};
	system("cls");
	printf("\t请输入导入的地址: ___\b\b\b");
	scanf("%s",Local);
	Url_Change(Local);
	strcat(Local,Work_name);
	Data = fopen(Local,"r");/*打开指定文件*/
	fscanf(Data,"%d\n",&tem_Len);
	if(tem_Len == Len)
		{
			for (int x = 1; x <= Len; x++)
				{
					for (int y = 1; y <= Len; y++)
						fscanf(Data,"%d ",&map[x][y]);
					fscanf(Data,"\n");
				}
			printf("\t成功将数据从%s导出到程序！\n",Local);
			Use = 0;
		}
	else printf("\t地图格式错误！请重新输入！\n");
	fclose(Data);
	printf("\t将在1.5秒后回到菜单！");
	Sleep(1500);
	return 0;
}
void Mode(int flag) //flag = 1 时
{
	system("cls");
	srand((unsigned)time(NULL));
	for (int x = 0; x <= Len + 1; x++) for (int y = 0; y <= Len + 1; y++) if (x == 0 || x == Len + 1 || y == 0 || y == Len + 1) map[x][y] = Road;
			else if(flag) map[x][y] = Wall;
	if(flag)
		{
			Create(2 * (rand() % (Len / 2) + 1), 2 * (rand() % (Len / 2) + 1));
			Use = 0;
		}
	map[2][1] = Start;
	map[Len - 1][Len] = End;
	for (int x = 1; x <= Len; x++) for (int y = 1; y <= Len; y++) Print(x,y);
	Game();
}

int Direction()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t|---------------MENU------------|\n");
	printf("\t|\t 0. 退出系统\t\t|\n");
	printf("\t|\t 1. 使用自定义地图\t|\n");
	printf("\t|\t 2. 使用随机地图\t|\n");
	printf("\t|\t 3. 编辑地图\t\t|\n");
	printf("\t|\t 4. DFS\t\t\t|\n");
	printf("\t|\t 5. 地图存盘\t\t|\n");
	printf("\t|\t 6. 地图读盘\t\t|\n");
	printf("\t|\t 7. 程序设计人员名单\t|\n");
	printf("\t|-------------------------------|\n\n");
	printf("\t请输入您想进入的功能的序号(0-7): ___\b\b\b");
	switch (getch())
		{
			case '0':
				system("cls");
				printf("\t\t确认退出系统？(y/n) ___\b\b\b");
				if(_getch() == 121)
					{
						system("cls");
						printf("\t感谢您的使用！程序将在1.5秒后退出！");
						Sleep(1500);
						exit(0);
					}
				else
					break;
			case '1':
				if(Use)
					{
						printf("\n\t地图为空！请编辑地图或者随机生成地图！");
						Sleep(1500);
					}
				else
					Mode(0);
				break;
			case '2':
				Mode(1);
				break;
			case '3':
				Edit();
				break;
			case '4':
				memset(v,0,sizeof(v));
				if(Use)
					{
						system("cls");
						printf("\t未存储地图，是否生成地图？(y/n) ___\b\b\b");
						if(getch() == 'y')
							{
								system("cls");
								for (int x = 0; x <= Len + 1; x++) for (int y = 0; y <= Len + 1; y++) if (x == 0 || x == Len + 1 || y == 0 || y == Len + 1) map[x][y] = Road;
										else  map[x][y] = Wall;
								Create(2 * (rand() % (Len / 2) + 1), 2 * (rand() % (Len / 2) + 1));
								map[2][1] = Start;
								map[Len - 1][Len] = End;
								DFS(2,2);
								Mode(0);
								Use = 0;
							}
					}
				else
					{
						DFS(2,2);
						Mode(0);
					}
				break;
			case '5':
				Map_Out();
				break;
			case '6':
				Map_In();
				break;
			case '7':
				system("cls && start https://github.com/yang1955316899");
				printf("\t计算机科学与技术1904班\n\t杨建文 学号：2019013528\n\t按任意键返回！\n");
				if(getch()) break;
			default:
				printf("\n\t输入有误，请重新输入！");
				Sleep(1000);
				break;
		}
    return 0;
}

int main()
{
	Welcome();
	while (1) Direction();
	return 0;
}
