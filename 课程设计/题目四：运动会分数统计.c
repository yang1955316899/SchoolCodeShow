#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
int school_num, man, woman;
int No_5[6] = {0, 7, 5, 3, 2, 1}, No_3[4] = {0, 5, 3, 2};
char number_3[20] = {"������"};
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
	printf("����ѧУ��Ŀ:");
	while (1)
	{
		scanf("%d", &school_num);
		if (school_num < 1 || school_num > 20)
			printf("����������������������:");
		else
			break;
	}
	printf("������ѧУ�����ƣ����س���������\n");
	for (int i = 1; i <= school_num; i++)
		scanf("%s", school[i].name);
	printf("��������Ů��Ŀ�������ո����������");
	while (1)
	{
		scanf("%d %d", &man, &woman);
		if (school_num < 1 || school_num > 20)
			printf("����������������������:");
		else
			break;
	}
	printf("��������Ŀ����\t��/Ů��Ŀ\t������/������\t\n");
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
	printf("������Ҫ¼�����Ŀ����ţ�");
	scanf("%d", &tem);
	system("cls");
	Print('s');
	printf("����������ѧУ��ţ��ո��������\n");
	if (!strcmp(project[tem].type, number_3))
	{
		printf("����һ��������Ŀ\n");
		for (int number = 1; number <= 3; number++)
			scanf("%d", &project[tem].snum[number]);
	}
	else
	{
		printf("����һ��������Ŀ\n");
		for (int number = 1; number <= 5; number++)
			scanf("%d", &project[tem].snum[number]);
	}
}
int School_Total()
{
	int school_number, sum = 0;
	system("cls");
	Print('s');
	printf("��������Ҫ�鿴��ѧУ����ţ�___\b\b\b");
	scanf("%d", &school_number);
	for (int tem = 1; tem <= woman + man; tem++)
	{
		if (!strcmp(project[tem].type, number_3))
		{
			for (int num = 1; num <= 3; num++)
				if (project[tem].snum[num] == school_number)
				{
					sum += No_3[num];
					printf("%s��%s�������ٻ��%d��������+%d\n", school[school_number].name, project[tem].name, num, No_3[num]);
				}
		}
		else
			for (int num = 1; num <= 5; num++)
				if (project[tem].snum[num] == school_number)
				{
					sum += No_5[num];
					printf("%s��%s�������ٻ��%d��������+%d\n", school[school_number].name, project[tem].name, num, No_5[num]);
				}
	}
	printf("�ܻ���Ϊ��%d\n�����������", sum);
	if (getch())
		return 0;
}
int Project()
{
	system("cls");
	int Project_tem;
	Print('p');
	printf("��������Ҫ�鿴����Ŀ��\n");
	scanf("%d", &Project_tem);
	for (int tem = 1; tem <= (!strcmp(project[Project_tem].type, number_3) ? 3 : 5); tem++)
		printf("%s��Ŀ���ٻ��%d������%s\n", project[Project_tem].name, tem, school[project[Project_tem].snum[tem]].name);
	printf("�����������");
	if (getch())
		return 0;
}
int Url_Change(char Local[100])
{
	int temp, next;
	for (temp = 0; temp < strlen(Local); temp++)
		if (Local[temp] == '\\') /*��ȥ̫���ˣ�����ҲҪ��ת���ַ�*/
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
	printf("\t�����뵼���ĵ�ַ: ___\b\b\b");
	scanf("%s", Local);
	Url_Change(Local);
	strcat(Local, Work_name);
	Data = fopen(Local, "w");
	fprintf(Data, "�μ�ѧУ�У�\n");
	for (int tem = 1; tem <= school_num; tem++)
		fprintf(Data, "%d.%s\n", tem, school[tem].name);
	fprintf(Data, "������Ŀ���������\n");
	for (int tem = 1; tem <= man + woman; tem++)
	{
		fprintf(Data, "%d.%s\t", tem, project[tem].name);
		if (!strcmp(project[tem].type, number_3))
			fprintf(Data, "1.%s��5�� 2.%s��3�� 3.%s��2��\n", school[project[tem].snum[1]].name, school[project[tem].snum[2]].name, school[project[tem].snum[3]].name);
		else
			fprintf(Data, "1.%s��7�� 2.%s��5�� 3.%s��3�� 4.%s��2�� 5.%s��1��\n", school[project[tem].snum[1]].name, school[project[tem].snum[2]].name, school[project[tem].snum[3]].name, school[project[tem].snum[4]].name, school[project[tem].snum[5]].name);
	}
	fclose(Data);
	printf("\t�ɹ������ݵ�����%s\n\t�ļ�����Data.txt\n", Local);
	printf("\t����1.5���ص��˵���");
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
		printf("��%d���ǣ�%s,�ɼ�Ϊ��%d\n", tem, school[tem].name, Score[tem]);
		v[num] = 1;
	}
	printf("�����������");
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
		printf("\t| 1.��ʼ������\t\t\t|\n");
		printf("\t| 2.¼����Ŀ����\t\t|\n");
		printf("\t| 3.��ѯĳ��ѧУ�ܷ�\t\t|\n");
		printf("\t| 4.�ļ����\t\t\t|\n");
		printf("\t| 5.��ѯĳ����Ŀ�ɼ�\t\t|\n");
		printf("\t| 6.ѧУ����\t\t\t|\n");
		printf("\t| 7.������Ա����\t\t|\n");
		printf("\t| 8.�˳�ϵͳ\t\t\t|\n");
		printf("\t|-------------------------------|\n\n");
		printf("\tѡ������Ҫ�Ĳ���(ѡ�����):___\b\b\b");
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
			printf("\t\t\t\t\t�������ѧ�뼼��1904��\n");
			printf("\t\t\t\t\t1.���Ʒ�\n");
			printf("\t\t\t\t\tѧ��:2019014587\n");
			printf("\t\t\t\t\t��������������˵���\n");
			if (_getch())
				return 0;
			break;
		case '8':
			system("cls");
			printf("\t\tȷ���˳�ϵͳ��(y/n) ___\b\b\b");
			if (_getch() == 121)
			{
				system("cls");
				printf("\t��л����ʹ�ã�������1.5����˳���");
				Sleep(1500);
				exit(0);
			}
			else
				break;
		default:
			printf("\n\t\t\t\t\t�����������������룡");
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
/*��������
1
8
�Ϸ��е�һ��ѧ
�Ϸ��еڶ���ѧ
�Ϸ��е�����ѧ
�Ϸ��е�����ѧ
�Ϸ��е�����ѧ
�Ϸ��е�����ѧ
�Ϸ��е�����ѧ
�Ϸ��еڰ���ѧ
6 4
��ͧ	����Ŀ	������
���г�	����Ŀ	������
��Ӿ	����Ŀ	������
ȭ��	����Ŀ	������
����	����Ŀ	������
Ƥ��ͧ	����Ŀ	������
����	Ů��Ŀ	������
����	Ů��Ŀ	������
����	Ů��Ŀ	������
���	Ů��Ŀ	������
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



