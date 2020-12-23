/*头文件*/
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

/*全局变量定义*/
struct Use_Log
{
	char name[9];
	int id_number;
	char sex[3];
	char classes[100];
	int start_time;
	int end_time ;
};
#define N 100//N代表可以存储上下机记录最大存储条数
struct Use_Log Log[N + 1];//定义N+1个，最后一个用于临时存储信息
int Use_number,mon,day,hor,min,sec,temp,Useing[N] = {0},Used[N] = {0};

/*辅助模块*/
/*时间转换模块*/
void Time_Printf(int sum_sec)
{
    char mon_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year = 1970;
    sec = sum_sec % 60;
    min = sum_sec / 60 % 60;
    hor =(sum_sec / 3600 + 8) % 24;
    long sum_day =(sum_sec / 3600 + 8) / 24 + 1;
    while(sum_day >= 365)
    {      
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            sum_day -= 366;
        }
        else
        {
            sum_day -= 365;
        }
        year++;
    }
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//判断闰年以确定二月的天数
    {
       mon_arr[1] = 29;
    }
    for(mon = 1;mon < 13;mon++)//判断月份
    {
        if(sum_day > mon_arr[mon - 1])
        {
            sum_day -= mon_arr[mon - 1];
        }
        else
        {
            day = sum_day;
            break;
        }
    }
}
/*文件地址转换模块*/
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
/*欢迎界面*/
void Welcome()
{
	int sec = 3;
	for(;sec > 0;sec--)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t   ▇▇▇▇    ▇▇▇▇    ▇▇▇▇    ▇▇▇▇\n");
		printf("\t\t\t\t ◢▇▇▇▇◣◢▇▇▇▇◣◢▇▇▇▇◣◢▇▇▇▇◣\n");
		printf("\t\t\t\t ▇欢迎使用▇▇计科四班▇▇1.杨建文▇▇2.徐思坤▇\n");
		printf("\t\t\t\t ◥▇▇▇▇◤◥▇▇▇▇◤◥▇▇▇▇◤◥▇▇▇▇◤\n");
		printf("\t\t\t\t   ▇▇▇▇    ▇▇▇▇    ▇▇▇▇    ▇▇▇▇\n");
		printf("\t\t\t\t系统将在%d秒后进入",sec);
		Sleep(1000);
	}
}
/*菜单*/
void Menu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t|-----------------------MENU--------------------|\n");
	printf("\t\t\t\t|\t 0. 退出系统\t\t\t\t|\n");
	printf("\t\t\t\t|\t 1. 开始使用电脑记录\t\t\t|\n");
	printf("\t\t\t\t|\t 2. 结束使用电脑记录\t\t\t|\n");
	printf("\t\t\t\t|\t 3. 查找记录\t\t\t\t|\n");
	printf("\t\t\t\t|\t 4. 删除记录\t\t\t\t|\n");
	printf("\t\t\t\t|\t 5. 导出记录\t\t\t\t|\n");
	printf("\t\t\t\t|\t 6. 导入记录\t\t\t\t|\n");
	printf("\t\t\t\t|\t 7. 机器使用情况明细\t\t\t|\n");
	printf("\t\t\t\t|\t 8. 程序设计人员名单\t\t\t|\n");
	printf("\t\t\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\t\t\t请输入您想进入的功能的序号(0-8): ___\b\b\b");
}

/*自定义模块*/
/*查看使用情况模块*/
void User(int Use_End_list,int *Number,int mode)//mode控制是否输出统计
{
	system("cls");
	int scan;
	printf("序号\t姓名\t\t学号\t性别\t班级\t\t上机时间\n");
	for (scan = 0; scan < Use_number; scan++)//检测下机状态
	{
		if(Useing[scan] - Used[scan] == 1)
		{
			Number[Use_End_list] = scan;//将未下机人的编号计入数组
			Time_Printf(Log[scan].start_time);
			printf("%d\t%s\t\t%d\t%s\t%s\t%d月%d日%d点%d分%d秒\n",Use_End_list + 1,Log[scan].name,Log[scan].id_number,Log[scan].sex,Log[scan].classes,mon,day,hor,min,sec);
			Sleep(10);
			Use_End_list++;
		}
	}
	if (mode)
	{
		printf("以上是正在使用机器情况，按任意键返回！");
		if(_getch());
	}
}
/*删除记录模块*/
void Delete_Log()
{
	int Use_End_list = 0,temp,Number[N] ={0};int Delete_number;
	User(Use_End_list,Number,0);
	printf("请输想要删除的序号:___\b\b\b");
	scanf("%d",&Delete_number);
	printf("确认删除%c%c同学的记录吗？（y/n） ___\b\b\b",Log[Number[Delete_number - 1]].name[0],Log[Number[Delete_number - 1]].name[1]);
	if(_getch() == 121)
	{
		for (temp = Delete_number; temp < Use_number; temp++)
		{
			Log[Delete_number] = Log[Delete_number + 1];
			Useing[Delete_number] = Useing[Delete_number + 1];
			Used[Delete_number] = Used[Delete_number + 1];
		}
		Useing[Delete_number + 1] = Used[Delete_number + 1] = 0;
		Use_number--;
		printf("\n成功删除！将在1秒后返回主菜单！");
		Sleep(1000);
	}
	else
	{
		printf("\n已经取消删除，将在1秒后返回菜单！\n");
		Sleep(1000);
	}
}
/*按条件搜索模块*/
void Search()
{
	system("cls");
	int mode,times = 0;
	printf("1.按姓名查找2.按学号查找3.按班级查找4.按性别查找\n请输入查找方式前面的序号: ___\b\b\b");
	mode = _getch();
	system("cls");
	switch (mode)
	{
		case 49:
		{
			printf("请输入需要查找的姓名： ___\b\b\b");
			scanf("%s",Log[N + 1].name);
			printf("序号\t姓名\t\t学号\t性别\t班级\t\t上机时间\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if((strcmp(Log[temp].name,Log[N + 1].name)) == 0)
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d月%d日%d点%d分%d秒\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%s同学一共出现%d次\n",Log[N + 1].name,times);
			printf("按任意键回到主菜单！");
			if (_getch())
				break;
		}
		case 50:
		{
			printf("请输入需要查找的学号： ___\b\b\b");
			scanf("%d",&Log[N + 1].id_number);
			printf("序号\t姓名\t\t学号\t性别\t班级\t\t上机时间\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if (Log[temp].id_number == Log[N + 1].id_number)
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d月%d日%d点%d分%d秒\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("学号为：%d一共出现%d次\n",Log[N + 1].id_number,times);
			printf("按任意键回到主菜单！");
			if (_getch())
				break;
		}
		case 51:
		{
			printf("请输入需要查找的班级： ___\b\b\b");
			scanf("%s",Log[N + 1].classes);
			printf("序号\t姓名\t\t学号\t性别\t班级\t\t上机时间\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if(!(strcmp(Log[temp].classes,Log[N + 1].classes)))
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d月%d日%d点%d分%d秒\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%s班一共出现%d次\n",Log[N + 1].classes,times);
			printf("按任意键回到主菜单！");
			if (_getch())
				break;
		}
		case 52:
		{
			printf("请输入需要查找的性别： ___\b\b\b");
			scanf("%s",Log[N + 1].sex);
			printf("序号\t姓名\t\t学号\t性别\t班级\t\t上机时间\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if(!(strcmp(Log[temp].sex,Log[N + 1].sex)))
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d月%d日%d点%d分%d秒\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%s性一共出现%d次\n",Log[N + 1].sex,times);
			printf("按任意键回到主菜单！");
			if (_getch())
				break;
		}
		default:
		{
			printf("输入错误，将在1秒后返回主菜单！");
			Sleep(1000);
			break;
		}
	}
}
/*从文件导入模块*/
void To_Data()
{
	FILE *Data;
	char Local[100],Work_name[13] = {"\\\\Data.txt"};
	system("cls");
	printf("请输入导入的地址: ___\b\b\b");
	scanf("%s",Local);
	Url_Change(Local);
	strcat(Local,Work_name);
	Data = fopen(Local,"r");/*打开指定文件*/
	Use_number = 0;//对文件初始化
	for (temp = 0; temp < N; temp++)
	{
		Useing[temp] = 0;
		Used[temp] = 0;
	}
	char line[N][100];
	while(!feof(Data))
	{
		fgets(line[Use_number],100,Data);//按行读取，存入二维数组中
		if(strlen(line[Use_number])>10)//有些行只含一个回车 当然不能作为一个结构体读取
		{
			sscanf(line[Use_number],"%s %d %s %s %d %d\n",Log[Use_number].name,&Log[Use_number].id_number,Log[Use_number].sex,Log[Use_number].classes,&Log[Use_number].start_time,&Log[Use_number].end_time);
			if (Log[Use_number].start_time != 0)//对正在使用列表进行赋值
				Useing[Use_number] = 1;
			if (Log[Use_number].end_time != 0)//对以下机列表进行赋值
				Used[Use_number] = 1;
			Use_number++;
		}
	}
	fclose(Data);
	printf("成功将数据从%s导出到程序！\n将在2秒后回到菜单！",Local);
	Sleep(2000);
}
/*导出为文件模块*/
void To_File()
{
	FILE *Data;
	char Local[100],Work_name[13] = {"\\\\Data.txt"};
	system("cls");
	printf("请输入导出的地址: ___\b\b\b");
	scanf("%s",Local);
	Url_Change(Local);
	strcat(Local,Work_name);
	Data = fopen(Local,"w");
	for (temp = 0; temp < Use_number; temp++)
		fprintf(Data,"%s %d %s %s %d %d\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,Log[temp].start_time,Log[temp].end_time);
	fclose(Data);
	printf("成功将数据导出到%s，文件名叫Data.txt\n将在2秒后回到菜单！",Local);
	Sleep(2000);
}
/*下机模块*/
void End_Use()
{
	int Use_End_list = 0,Number[N] ={0},End_number;
	User(Use_End_list,Number,0);
	printf("请输入需要下机的序号： ___\b\b\b");
	scanf("%d",&End_number);
	printf("确认让%c%c同学下机吗？（y/n） ___\b\b\b",Log[Number[End_number - 1]].name[0],Log[Number[End_number - 1]].name[1]);
	if(_getch() == 121)
	{
		Log[Number[End_number - 1]].end_time = time(NULL);
		printf("%c%c同学下机成功！费用为%.0f元 \n将在3秒后返回菜单！\n",Log[Number[End_number - 1]].name[0],Log[Number[End_number - 1]].name[1],ceil(((float)Log[Number[End_number - 1]].end_time - (float)Log[Number[End_number - 1]].start_time)/3600.0));
		Used[Number[End_number - 1]] = 1;
		Sleep(3000);
	}
	else
	{
		printf("已经取消下机，将在1秒后返回菜单！\n");
		Sleep(1000);
	}
}
/*上机模块*/
void Start_Use()
{
    int people_number;
    system("cls");
    printf("请输入你要录入的人数： ___\b\b\b");
    scanf("%d",&people_number);
    printf("请输入姓名\t\t学号\t性别\t班级\n");//这里可以循环读入
    for(;people_number > 0;people_number--)
    {
		scanf("%s",Log[Use_number].name);
		scanf("%d",&Log[Use_number].id_number);
		scanf("%s",Log[Use_number].sex);
		scanf("%s",Log[Use_number].classes);
		Log[Use_number].start_time = time(NULL);
		Useing[Use_number] = 1;
		Use_number++;       
    }
    printf("录入成功,将在1秒后返回主菜单！");
    Sleep(1000);
}
/*功能跳转模块*/
int Go_To_Action(int menu)
{
	switch (menu)
	{
		case 48:
		{
			system("cls");
			printf("\t\t\t\t\t确认退出系统？(y/n) ___\b\b\b");
			if(_getch() == 121)
			{
				system("cls");
				printf("\t\t\t\t\t感谢您的使用！程序将在1.5秒后退出！");
				Sleep(1500);
				exit(0);
			}
			else
				break;	
		}
		case 49:Start_Use();break;
		case 50:End_Use();break;
		case 51:Search();break;
		case 52:Delete_Log();break;
		case 53:To_File();break;
		case 54:To_Data();break;
		case 55:
		{
			int Use_End_list = 0,Number[N] ={0};
			User(Use_End_list,Number,1);
			break;
		}
		case 56:
		{
			system("cls");
			printf("        .... ...............                    ....... ............    \n\
    ......,@@@@@@@@@@\\].....                ............................     \n\
    ...,@@@@@@@@@@@@@@@@@@`.................,]/@@@@@@@@@@@@@@@@@@@@@@]]`........        ....................     \n\
    ..@@@@@@@@@@@@@@@@@@@@@@`........]/@@@@@@/[[*..................,[[@@@@@@\\`.....     .....,]/@@@@\\]......        \n\
....=@@@@@@@@@@@@@@@@@@@@@@@@@`.]@@@@@@[`...                            ...[@@@@@].......]@@@@@@@@@@@@@@@\\`.....    \n\
.../@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[........                            .......,\\@@@\\`./@@@@@@@@@@@@@@@@@@@@@`..    \n\
..=@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`...                                            ..,\\@@@@@@@@@@@@@@@@@@@@@@@@@@^.....\n\
../@@@@@@@@@@@@@@@@@@@@@@@@@@`......                                            .....,@@@@@@@@@@@@@@@@@@@@@@@@@\\....\n\
..@@@@@@@@@@@@@@@@@@@@@@@@@`..                                                      .. .\\@@@@@@@@@@@@@@@@@@@@@@@^...\n\
..@@@@@@@@@@@@@@@@@@@@@@@`..   .                                                     .. ..\\@@@@@@@@@@@@@@@@@@@@@@...\n\
.=@@@@@@@@@@@@@@@@@@@@@^                                                                . .,@@@@@@@@@@@@@@@@@@@@@^..\n\
..@@@@@@@@@@@@@@@@@@@@..                                                                .....\\@@@@@@@@@@@@@@@@@@@^..\n\
..\\@@@@@@@@@@@@@@@@@/...                                                                    ..@@@@@@@@@@@@@@@@@@@^..\n\
...@@@@@@@@@@@@@@@@^....                                                                    ...@@@@@@@@@@@@@@@@@@^..\n\
 ...@@@@@@@@@@@@@@`.                                                                        . ..@@@@@@@@@@@@@@@@@...\n\
. ...@@@@@@@@@@@@`..                  ,]`                                                   . ...@@@@@@@@@@@@@@@^...\n\
    ..\\@@@@@@@@@`...         \\@@`=@@@@@@@@@@@^                          @@@@@@@@@@@@@@@         ..\\@@@@@@@@@@@@/... \n\
    ....[@@@@@@^....           \\^  ,/@@@@@]`                            @@]]]]/@\\]]]]@@         ...@@@@@@@@@@@`..   \n\
        ...\\@@@.            @@@\\,@@/` =@^ ,\\@@`                         @@[[[[\\@/[[[[@@         ...=@@@@@@@[....    \n\
        ....@@`.              \\/  @@@@@@@@@@^                           @@@@@@@@@@@@@@@         ....\\@@/`...        \n\
        ...@@^..              @]  @@@@@@@@@@^                                =@^                  ..,@@@`...        \n\
        ..=@^. .             =@/  @@]]]]]]/@^                          @@@@@@@@@@@@@@@@^          ...=@@\\...        \n\
        ..@@..               @@^  @@[[[[[[\\@^                              /@@`      /@`            ..@@@...        \n\
        ./@`..              ,@@ =@@@@@@@@@@@@@                        =@@@@/`   @@@@@@/             ..=@@^..        \n\
       .,@^.                 [`                                                                      .=@@@..        \n\
       ./@..                                                                                        . .@@@..        \n\
    ...,@^..                                                                                        ...@@@^.        \n\
    ...@@^..                                                                                        ...@@@^.        \n\
.....,@@@...                    ...                                                                 ...=@@^.        \n\
...,/@@@@...                    ...                                                                 ...=@@^.        \n\
../@@@@@/...                                                                                        ...=@@@`....    \n\
/@@@@@@@^...                                                                                        ...=@@@@\\...    \n\
@@@@@@@@@...                                                                                        ...=@@@@@@`.    \n\
@@@@@@@@@...                                                                                        ...=@@@@@@@`..  \n\
@@@@@@@@@^..                                                                                        ...@@@@@@@@@^...\n\
@@@@@@@@@@..                                                                                        ..=@@@@@@@@@@^..\n\
@@@@@@@@@@@.....                                                                                    ..@@@@@@@@@@@@^.\n\
@@@@@@@@@@@@`...                                                                                    ./@@@@@@@@@@@@@^\n\
@@@@@@@@@@@@@^......                                              .....                         ..../@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@`....                                              .... .                        .../@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@`......                                  ..                                ......@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@\\....                                .                                   ..../@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@\\.........                                                    .........,@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@\\`.....                                                    ......,/@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@]`.........  ..                            .............,]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\\]......                               .... ..,]]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@]`..............................]]/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@]]]]]]]]]]]]]]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			printf("\t\t\t\t\t计算机科学与技术1904班\n");
			printf("\t\t\t\t\t1.杨建文\n");
			printf("\t\t\t\t\t学号:2019013528\n");
			printf("\t\t\t\t\t2.徐思坤\n");
			printf("\t\t\t\t\t学号:2019013462\n");
			printf("\t\t\t\t\t按任意键返回主菜单！\n");
			if(_getch()) return 0;
		}
		default:
		{
            printf("\n\t\t\t\t\t输入有误，请重新输入！");
			Sleep(1000);
			return 0;
		}
	}
}
/*主函数*/
int main()
{
    Welcome();
    while (true)
    {
        Menu();
        Go_To_Action(_getch());
    }
	system("pause");
	return 0;
}
/*测试数据
杨耀武 4112655 男 软件科学与技术1901
张标 4112681 男 软件科学与技术1901
左浩然 4112690 男 软件科学与技术1901
黄越常 4112650 男 软件科学与技术1901
许明强 4112678 男 软件科学与技术1901
杨维 4112672 男 软件科学与技术1901
秦世杰 4112661 男 软件科学与技术1901
何高辉 4112648 男 软件科学与技术1901
霍建国 4112651 男 软件科学与技术1901
石景阳 4112662 男 软件科学与技术1901
汪浩洋 4112719 男 软件科学与技术1902
黄梦姣 4112700 女 软件科学与技术1902
陈霜霜 4112693 女 软件科学与技术1902
徐淑铭 4112727 女 软件科学与技术1902
时英豪 4112712 男 软件科学与技术1902
水有越 4112714 女 软件科学与技术1902
黄子豪 4112709 男 软件科学与技术1902
吴晨宇 4112716 男 软件科学与技术1902
周强 4112739 男 软件科学与技术1902
徐浪 4112726 男 软件科学与技术1902
徐刚 4112725 男 软件科学与技术1902
沈浩 4112711 男 软件科学与技术1902
房辉 4112695 男 软件科学与技术1902
乔杰 4112710 男 软件科学与技术1902
黄旭阳 4112701 男 软件科学与技术1902
吴延越 4112717 男 软件科学与技术1902
洪棋 4112698 男 软件科学与技术1902
钟晨光 4112737 男 软件科学与技术1902
黄申奥 4112707 男 软件科学与技术1902
丁帅 4112694 男 软件科学与技术1902
杨梦婷 4112722 女 软件科学与技术1902
张宇航 4112735 男 软件科学与技术1902
黄永升 4112708 男 软件科学与技术1902
张洋 4112734 男 软件科学与技术1902
江凌峰 4112702 男 软件科学与技术1902
杨瑶楠 4112705 男 软件科学与技术1902
韩冬 4112697 男 软件科学与技术1902
黄典辉 4112699 男 软件科学与技术1902
杨康乐 4112721 男 软件科学与技术1902
杨嘉明 4112720 男 软件科学与技术1902
陈晨 4112691 男 软件科学与技术1902
杨志宇 4112723 男 软件科学与技术1902
郜志伟 4112696 男 软件科学与技术1902
陶贤红 4112718 女 软件科学与技术1902
孙正鹏 4112740 男 软件科学与技术1902
张航 4112732 男 软件科学与技术1902
尹爱迪 411271 男 软件科学与技术1902
吴远乐 4112724 男 软件科学与技术1902
范仁豪 4111086 男 软件科学与技术1903
程世森 4111574 男 软件科学与技术1903
张涛涛 4112107 男 软件科学与技术1903
束维维 4111104 男 软件科学与技术1903
傅宇 4110464 男 软件科学与技术1903
徐晓龙 4110453 男 软件科学与技术1903
胡迅 4111532 男 软件科学与技术1903
顾成彬 4110549 男 软件科学与技术1903
甘淑芳 4111128 女 软件科学与技术1903
袁富贵 4111114 男 软件科学与技术1903
杨佳龙 4111535 男 软件科学与技术1903
凡其超 4110434 男 软件科学与技术1903
吕毅 4111139 男 软件科学与技术1903
童仁江 4110479 男 软件科学与技术1903
杨铭漳 4111702 男 软件科学与技术1903
牛栏瑾 4111691 男 软件科学与技术1903
吕清卓 4110443 男 软件科学与技术1903
宋慧慧 4110943 女 软件科学与技术1903
黄伟 4110772 男 软件科学与技术1903
黄宇阳 4110471 男 软件科学与技术1903
何志鹏 4110551 男 软件科学与技术1903
孙志浩 4111570 男 软件科学与技术1903
曹毓 4112972 女 软件科学与技术1904
常帅 4113474 男 软件科学与技术1904
陈明 4112162 男 软件科学与技术1904
戴晓雨 4112203 男 软件科学与技术1904
段登昌 4113985 男 软件科学与技术1904
方涛 4114094 男 软件科学与技术1904
郭翰玥 4114186 女 软件科学与技术1904
郭泽旭 4113483 男 软件科学与技术1904
郝浩男 4113950 男 软件科学与技术1904
何古月 4112166 男 软件科学与技术1904
何英健 4115009 男 软件科学与技术1904
季龙 4112208 男 软件科学与技术1904
冀凤腾 4114573 女 软件科学与技术1904
杨可妮 4112072 女 软件科学与技术1904
杨镇宇 4114102 男 软件科学与技术1904
黄昊 4114073 男 软件科学与技术1904
黄乐 411161 男 软件科学与技术1904
黄启鹏 4112619 男 软件科学与技术1904
黄思梦 4112766 女 软件科学与技术1904
黄云越 4114587 女 软件科学与技术1904
罗猛 4115078 男 软件科学与技术1904
马庆阳 4115081 男 软件科学与技术1904
马滢滢 4114969 女 软件科学与技术1904
聂保建 4112081 男 软件科学与技术1904
杨靖 4114201 女 软件科学与技术1904
杨亮 4113966 男 软件科学与技术1904
吴易锴 4112229 男 软件科学与技术1904
夏忠宇 4112190 男 软件科学与技术1904
许志杰 4115343 男 软件科学与技术1904
杨建建 4113528 男 软件科学与技术1904
*/