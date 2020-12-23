#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
int school_num, man, woman;
int No_5[6] = {0, 7, 5, 3, 2, 1}, No_3[4] = {0, 5, 3, 2};
char number_3[20] = {"三人项"};
struct pro
{
	char name[100];
	char type[20];
	char sex[3];
	int snum[6];
} project[21];
struct school
{
	char name[100];
} school[21];

int Initialization()
{
	system("cls");
	printf("输入学校数目:");
	while (1)
	{
		scanf("%d", &school_num);
		if (school_num < 1 || school_num > 20)
			printf("输入数据有误，请重新输入:");
		else
			break;
	}
	printf("请输入学校的名称（按回车键隔开）\n");
	for (int i = 1; i <= school_num; i++)
		scanf("%s", school[i].name);
	printf("请输入男女项目个数（空格键隔开）：");
	while (1)
	{
		scanf("%d %d", &man, &woman);
		if (school_num < 1 || school_num > 20)
			printf("输入数据有误，请重新输入:");
		else
			break;
	}
	printf("请输入项目名称\t男/女项目\t三人项/五人项\t\n");
	for (int i = 1; i <= man + woman; i++)
	{
		scanf("%s", project[i].name);
		scanf("%s", project[i].sex);
		scanf("%s", project[i].type);
	}
}
int Print(char mode)
{
	if (mode == 's')
		for (int tem = 1; tem <= school_num; tem++)
			printf("%d.%s\n", tem, school[tem].name);
	else if (mode == 'p')
		for (int tem = 1; tem <= man + woman; tem++)
			printf("%d.%s\n", tem, project[tem].name);
}
int Input()
{
	system("cls");
	int tem;
	Print('p');
	printf("请输入要录入的项目的序号：");
	scanf("%d", &tem);
	system("cls");
	Print('s');
	printf("按排名输入学校编号（空格键隔开）\n");
	if (!strcmp(project[tem].type, number_3))
	{
		printf("这是一个三人项目\n");
		for (int number = 1; number <= 3; number++)
			scanf("%d", &project[tem].snum[number]);
	}
	else
	{
		printf("这是一个五人项目\n");
		for (int number = 1; number <= 5; number++)
			scanf("%d", &project[tem].snum[number]);
	}
}
int School_Total()
{
	int school_number, sum = 0;
	system("cls");
	Print('s');
	printf("请输入你要查看的学校的序号：___\b\b\b");
	scanf("%d", &school_number);
	for (int tem = 1; tem <= woman + man; tem++)
	{
		if (!strcmp(project[tem].type, number_3))
		{
			for (int num = 1; num <= 3; num++)
				if (project[tem].snum[num] == school_number)
				{
					sum += No_3[num];
					printf("%s在%s比赛中荣获第%d名，积分+%d\n", school[school_number].name, project[tem].name, num, No_3[num]);
				}
		}
		else
			for (int num = 1; num <= 5; num++)
				if (project[tem].snum[num] == school_number)
				{
					sum += No_5[num];
					printf("%s在%s比赛中荣获第%d名，积分+%d\n", school[school_number].name, project[tem].name, num, No_5[num]);
				}
	}
	printf("总积分为：%d\n按任意键返回", sum);
	if (getch())
		return 0;
}
int Project()
{
	system("cls");
	int Project_tem;
	Print('p');
	printf("请输入你要查看的项目：\n");
	scanf("%d", &Project_tem);
	for (int tem = 1; tem <= (!strcmp(project[Project_tem].type, number_3) ? 3 : 5); tem++)
		printf("%s项目中荣获第%d名的是%s\n", project[Project_tem].name, tem, school[project[Project_tem].snum[tem]].name);
	printf("按任意键返回");
	if (getch())
		return 0;
}
int Url_Change(char Local[100])
{
	int temp, next;
	for (temp = 0; temp < strlen(Local); temp++)
		if (Local[temp] == '\\') /*我去太坑了，这里也要用转义字符*/
		{
			for (next = strlen(Local) + 1; next > (temp + 1); next--)
				Local[next] = Local[next - 1];
			Local[temp + 1] = '\\';
			temp++;
		}
}
int Data_Out()
{
	FILE *Data;
	char Local[100], Work_name[13] = {"\\\\Data.txt"};
	system("cls");
	printf("\t请输入导出的地址: ___\b\b\b");
	scanf("%s", Local);
	Url_Change(Local);
	strcat(Local, Work_name);
	Data = fopen(Local, "w");
	fprintf(Data, "参加学校有：\n");
	for (int tem = 1; tem <= school_num; tem++)
		fprintf(Data, "%d.%s\n", tem, school[tem].name);
	fprintf(Data, "比赛项目、排名情况\n");
	for (int tem = 1; tem <= man + woman; tem++)
	{
		fprintf(Data, "%d.%s\t", tem, project[tem].name);
		if (!strcmp(project[tem].type, number_3))
			fprintf(Data, "1.%s—5分 2.%s—3分 3.%s—2分\n", school[project[tem].snum[1]].name, school[project[tem].snum[2]].name, school[project[tem].snum[3]].name);
		else
			fprintf(Data, "1.%s—7分 2.%s—5分 3.%s—3分 4.%s—2分 5.%s—1分\n", school[project[tem].snum[1]].name, school[project[tem].snum[2]].name, school[project[tem].snum[3]].name, school[project[tem].snum[4]].name, school[project[tem].snum[5]].name);
	}
	fclose(Data);
	printf("\t成功将数据导出到%s\n\t文件名叫Data.txt\n", Local);
	printf("\t将在1.5秒后回到菜单！");
	Sleep(1500);
}

int Rank()
{
	system("cls");
	int Score[21], v[21];
	for (int sch = 1; sch <= school_num; sch++)
	{
		int sum = 0;
		for (int tem = 1; tem <= woman + man; tem++)
			if (!strcmp(project[tem].type, number_3))
			{
				for (int num = 1; num <= 3; num++)
					if (project[tem].snum[num] == sch)
						sum += No_3[num];
			}
			else
				for (int num = 1; num <= 5; num++)
					if (project[tem].snum[num] == sch)
						sum += No_5[num];
		Score[sch] = sum;
	}

	for (int tem = 1; tem <= school_num; tem++)
	{
		int score_tem = -1, pos, num;
		for (num = 1; num < school_num; num++)
			if (Score[num] > score_tem && !v[num])
			{
				score_tem = Score[num];
				pos = num;
			}
		printf("第%d名是：%s,成绩为：%d\n", tem, school[tem].name, Score[tem]);
		v[num] = 1;
	}
	printf("按任意键返回");
	if (getch())
		return 0;
}
int Menu()
{
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t|---------------MENU------------|\n");
		printf("\t| 1.初始化程序\t\t\t|\n");
		printf("\t| 2.录入项目详情\t\t|\n");
		printf("\t| 3.查询某个学校总分\t\t|\n");
		printf("\t| 4.文件输出\t\t\t|\n");
		printf("\t| 5.查询某个项目成绩\t\t|\n");
		printf("\t| 6.学校排名\t\t\t|\n");
		printf("\t| 7.制作人员名单\t\t|\n");
		printf("\t| 8.退出系统\t\t\t|\n");
		printf("\t|-------------------------------|\n\n");
		printf("\t选择您需要的操作(选择序号):___\b\b\b");
		switch (getch())
		{
		case '1':
			Initialization();
			break;
		case '2':
			Input();
			break;
		case '3':
			School_Total(1, 0);
			break;
		case '4':
			Data_Out();
			break;
		case '5':
			Project();
			break;
		case '6':
			Rank();
			break;
		case '7':
			system("cls");
			printf("\t\t\t\t\t计算机科学与技术1904班\n");
			printf("\t\t\t\t\t1.刘云飞\n");
			printf("\t\t\t\t\t学号:2019014587\n");
			printf("\t\t\t\t\t按任意键返回主菜单！\n");
			if (_getch())
				return 0;
			break;
		case '8':
			system("cls");
			printf("\t\t确认退出系统？(y/n) ___\b\b\b");
			if (_getch() == 121)
			{
				system("cls");
				printf("\t感谢您的使用！程序将在1.5秒后退出！");
				Sleep(1500);
				exit(0);
			}
			else
				break;
		default:
			printf("\n\t\t\t\t\t输入有误，请重新输入！");
			Sleep(1000);
			return 0;
		}
	}
}
int main()
{
	while (1)
		Menu();
}
/*测试数据
1
8
合肥市第一中学
合肥市第二中学
合肥市第三中学
合肥市第四中学
合肥市第五中学
合肥市第六中学
合肥市第七中学
合肥市第八中学
6 4
赛艇	男项目	三人项
自行车	男项目	三人项
游泳	男项目	三人项
拳击	男项目	三人项
排球	男项目	五人项
皮划艇	男项目	五人项
马术	女项目	五人项
篮球	女项目	五人项
足球	女项目	五人项
体操	女项目	五人项
2
1
1 2 3
2
2
1 2 3
2
3
1 2 3
3
1

4
D:
5
1

6

7

8
y
*/



