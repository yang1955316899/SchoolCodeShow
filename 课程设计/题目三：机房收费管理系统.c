/*ͷ�ļ�*/
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

/*ȫ�ֱ�������*/
struct Use_Log
{
	char name[9];
	int id_number;
	char sex[3];
	char classes[100];
	int start_time;
	int end_time ;
};
#define N 100//N������Դ洢���»���¼���洢����
struct Use_Log Log[N + 1];//����N+1�������һ��������ʱ�洢��Ϣ
int Use_number,mon,day,hor,min,sec,temp,Useing[N] = {0},Used[N] = {0};

/*����ģ��*/
/*ʱ��ת��ģ��*/
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
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//�ж�������ȷ�����µ�����
    {
       mon_arr[1] = 29;
    }
    for(mon = 1;mon < 13;mon++)//�ж��·�
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
/*�ļ���ַת��ģ��*/
void Url_Change(char Local[100])
{
	int temp,next; 
	for ( temp = 0; temp < strlen(Local); temp++)
	{
		if (Local[temp] == '\\')/*��ȥ̫���ˣ�����ҲҪ��ת���ַ�*/
		{
			for (next = strlen(Local) + 1; next > (temp + 1); next--)
				Local[next] = Local[next - 1];
			Local[temp + 1] = '\\';
			temp++;
		}	
	}
}
/*��ӭ����*/
void Welcome()
{
	int sec = 3;
	for(;sec > 0;sec--)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t   �~�~�~�~    �~�~�~�~    �~�~�~�~    �~�~�~�~\n");
		printf("\t\t\t\t ���~�~�~�~�����~�~�~�~�����~�~�~�~�����~�~�~�~��\n");
		printf("\t\t\t\t �~��ӭʹ�è~�~�ƿ��İ�~�~1.��Ĩ~�~2.��˼���~\n");
		printf("\t\t\t\t ���~�~�~�~�����~�~�~�~�����~�~�~�~�����~�~�~�~��\n");
		printf("\t\t\t\t   �~�~�~�~    �~�~�~�~    �~�~�~�~    �~�~�~�~\n");
		printf("\t\t\t\tϵͳ����%d������",sec);
		Sleep(1000);
	}
}
/*�˵�*/
void Menu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t|-----------------------MENU--------------------|\n");
	printf("\t\t\t\t|\t 0. �˳�ϵͳ\t\t\t\t|\n");
	printf("\t\t\t\t|\t 1. ��ʼʹ�õ��Լ�¼\t\t\t|\n");
	printf("\t\t\t\t|\t 2. ����ʹ�õ��Լ�¼\t\t\t|\n");
	printf("\t\t\t\t|\t 3. ���Ҽ�¼\t\t\t\t|\n");
	printf("\t\t\t\t|\t 4. ɾ����¼\t\t\t\t|\n");
	printf("\t\t\t\t|\t 5. ������¼\t\t\t\t|\n");
	printf("\t\t\t\t|\t 6. �����¼\t\t\t\t|\n");
	printf("\t\t\t\t|\t 7. ����ʹ�������ϸ\t\t\t|\n");
	printf("\t\t\t\t|\t 8. ���������Ա����\t\t\t|\n");
	printf("\t\t\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\t\t\t�������������Ĺ��ܵ����(0-8): ___\b\b\b");
}

/*�Զ���ģ��*/
/*�鿴ʹ�����ģ��*/
void User(int Use_End_list,int *Number,int mode)//mode�����Ƿ����ͳ��
{
	system("cls");
	int scan;
	printf("���\t����\t\tѧ��\t�Ա�\t�༶\t\t�ϻ�ʱ��\n");
	for (scan = 0; scan < Use_number; scan++)//����»�״̬
	{
		if(Useing[scan] - Used[scan] == 1)
		{
			Number[Use_End_list] = scan;//��δ�»��˵ı�ż�������
			Time_Printf(Log[scan].start_time);
			printf("%d\t%s\t\t%d\t%s\t%s\t%d��%d��%d��%d��%d��\n",Use_End_list + 1,Log[scan].name,Log[scan].id_number,Log[scan].sex,Log[scan].classes,mon,day,hor,min,sec);
			Sleep(10);
			Use_End_list++;
		}
	}
	if (mode)
	{
		printf("����������ʹ�û������������������أ�");
		if(_getch());
	}
}
/*ɾ����¼ģ��*/
void Delete_Log()
{
	int Use_End_list = 0,temp,Number[N] ={0};int Delete_number;
	User(Use_End_list,Number,0);
	printf("������Ҫɾ�������:___\b\b\b");
	scanf("%d",&Delete_number);
	printf("ȷ��ɾ��%c%cͬѧ�ļ�¼�𣿣�y/n�� ___\b\b\b",Log[Number[Delete_number - 1]].name[0],Log[Number[Delete_number - 1]].name[1]);
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
		printf("\n�ɹ�ɾ��������1��󷵻����˵���");
		Sleep(1000);
	}
	else
	{
		printf("\n�Ѿ�ȡ��ɾ��������1��󷵻ز˵���\n");
		Sleep(1000);
	}
}
/*����������ģ��*/
void Search()
{
	system("cls");
	int mode,times = 0;
	printf("1.����������2.��ѧ�Ų���3.���༶����4.���Ա����\n��������ҷ�ʽǰ������: ___\b\b\b");
	mode = _getch();
	system("cls");
	switch (mode)
	{
		case 49:
		{
			printf("��������Ҫ���ҵ������� ___\b\b\b");
			scanf("%s",Log[N + 1].name);
			printf("���\t����\t\tѧ��\t�Ա�\t�༶\t\t�ϻ�ʱ��\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if((strcmp(Log[temp].name,Log[N + 1].name)) == 0)
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d��%d��%d��%d��%d��\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%sͬѧһ������%d��\n",Log[N + 1].name,times);
			printf("��������ص����˵���");
			if (_getch())
				break;
		}
		case 50:
		{
			printf("��������Ҫ���ҵ�ѧ�ţ� ___\b\b\b");
			scanf("%d",&Log[N + 1].id_number);
			printf("���\t����\t\tѧ��\t�Ա�\t�༶\t\t�ϻ�ʱ��\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if (Log[temp].id_number == Log[N + 1].id_number)
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d��%d��%d��%d��%d��\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("ѧ��Ϊ��%dһ������%d��\n",Log[N + 1].id_number,times);
			printf("��������ص����˵���");
			if (_getch())
				break;
		}
		case 51:
		{
			printf("��������Ҫ���ҵİ༶�� ___\b\b\b");
			scanf("%s",Log[N + 1].classes);
			printf("���\t����\t\tѧ��\t�Ա�\t�༶\t\t�ϻ�ʱ��\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if(!(strcmp(Log[temp].classes,Log[N + 1].classes)))
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d��%d��%d��%d��%d��\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%s��һ������%d��\n",Log[N + 1].classes,times);
			printf("��������ص����˵���");
			if (_getch())
				break;
		}
		case 52:
		{
			printf("��������Ҫ���ҵ��Ա� ___\b\b\b");
			scanf("%s",Log[N + 1].sex);
			printf("���\t����\t\tѧ��\t�Ա�\t�༶\t\t�ϻ�ʱ��\n");
			for (temp = 0; temp < Use_number; temp++)
			{
				if(!(strcmp(Log[temp].sex,Log[N + 1].sex)))
				{
					times++;
					Time_Printf(Log[temp].start_time);
					printf("%s\t\t%d\t%s\t%s\t%d��%d��%d��%d��%d��\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,mon,day,hor,min,sec);
				}
			}
			printf("%s��һ������%d��\n",Log[N + 1].sex,times);
			printf("��������ص����˵���");
			if (_getch())
				break;
		}
		default:
		{
			printf("������󣬽���1��󷵻����˵���");
			Sleep(1000);
			break;
		}
	}
}
/*���ļ�����ģ��*/
void To_Data()
{
	FILE *Data;
	char Local[100],Work_name[13] = {"\\\\Data.txt"};
	system("cls");
	printf("�����뵼��ĵ�ַ: ___\b\b\b");
	scanf("%s",Local);
	Url_Change(Local);
	strcat(Local,Work_name);
	Data = fopen(Local,"r");/*��ָ���ļ�*/
	Use_number = 0;//���ļ���ʼ��
	for (temp = 0; temp < N; temp++)
	{
		Useing[temp] = 0;
		Used[temp] = 0;
	}
	char line[N][100];
	while(!feof(Data))
	{
		fgets(line[Use_number],100,Data);//���ж�ȡ�������ά������
		if(strlen(line[Use_number])>10)//��Щ��ֻ��һ���س� ��Ȼ������Ϊһ���ṹ���ȡ
		{
			sscanf(line[Use_number],"%s %d %s %s %d %d\n",Log[Use_number].name,&Log[Use_number].id_number,Log[Use_number].sex,Log[Use_number].classes,&Log[Use_number].start_time,&Log[Use_number].end_time);
			if (Log[Use_number].start_time != 0)//������ʹ���б���и�ֵ
				Useing[Use_number] = 1;
			if (Log[Use_number].end_time != 0)//�����»��б���и�ֵ
				Used[Use_number] = 1;
			Use_number++;
		}
	}
	fclose(Data);
	printf("�ɹ������ݴ�%s����������\n����2���ص��˵���",Local);
	Sleep(2000);
}
/*����Ϊ�ļ�ģ��*/
void To_File()
{
	FILE *Data;
	char Local[100],Work_name[13] = {"\\\\Data.txt"};
	system("cls");
	printf("�����뵼���ĵ�ַ: ___\b\b\b");
	scanf("%s",Local);
	Url_Change(Local);
	strcat(Local,Work_name);
	Data = fopen(Local,"w");
	for (temp = 0; temp < Use_number; temp++)
		fprintf(Data,"%s %d %s %s %d %d\n",Log[temp].name,Log[temp].id_number,Log[temp].sex,Log[temp].classes,Log[temp].start_time,Log[temp].end_time);
	fclose(Data);
	printf("�ɹ������ݵ�����%s���ļ�����Data.txt\n����2���ص��˵���",Local);
	Sleep(2000);
}
/*�»�ģ��*/
void End_Use()
{
	int Use_End_list = 0,Number[N] ={0},End_number;
	User(Use_End_list,Number,0);
	printf("��������Ҫ�»�����ţ� ___\b\b\b");
	scanf("%d",&End_number);
	printf("ȷ����%c%cͬѧ�»��𣿣�y/n�� ___\b\b\b",Log[Number[End_number - 1]].name[0],Log[Number[End_number - 1]].name[1]);
	if(_getch() == 121)
	{
		Log[Number[End_number - 1]].end_time = time(NULL);
		printf("%c%cͬѧ�»��ɹ�������Ϊ%.0fԪ \n����3��󷵻ز˵���\n",Log[Number[End_number - 1]].name[0],Log[Number[End_number - 1]].name[1],ceil(((float)Log[Number[End_number - 1]].end_time - (float)Log[Number[End_number - 1]].start_time)/3600.0));
		Used[Number[End_number - 1]] = 1;
		Sleep(3000);
	}
	else
	{
		printf("�Ѿ�ȡ���»�������1��󷵻ز˵���\n");
		Sleep(1000);
	}
}
/*�ϻ�ģ��*/
void Start_Use()
{
    int people_number;
    system("cls");
    printf("��������Ҫ¼��������� ___\b\b\b");
    scanf("%d",&people_number);
    printf("����������\t\tѧ��\t�Ա�\t�༶\n");//�������ѭ������
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
    printf("¼��ɹ�,����1��󷵻����˵���");
    Sleep(1000);
}
/*������תģ��*/
int Go_To_Action(int menu)
{
	switch (menu)
	{
		case 48:
		{
			system("cls");
			printf("\t\t\t\t\tȷ���˳�ϵͳ��(y/n) ___\b\b\b");
			if(_getch() == 121)
			{
				system("cls");
				printf("\t\t\t\t\t��л����ʹ�ã�������1.5����˳���");
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
			printf("\t\t\t\t\t�������ѧ�뼼��1904��\n");
			printf("\t\t\t\t\t1.���\n");
			printf("\t\t\t\t\tѧ��:2019013528\n");
			printf("\t\t\t\t\t2.��˼��\n");
			printf("\t\t\t\t\tѧ��:2019013462\n");
			printf("\t\t\t\t\t��������������˵���\n");
			if(_getch()) return 0;
		}
		default:
		{
            printf("\n\t\t\t\t\t�����������������룡");
			Sleep(1000);
			return 0;
		}
	}
}
/*������*/
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
