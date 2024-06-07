#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define star *
#define NAMESIZE 10
#define STD_NMBSIZE 15
#define SEXSIZE 5
#define MENBERS 100
struct student{
	char name[NAMESIZE];
	char sex[SEXSIZE];
	char std_nmb[STD_NMBSIZE];
	int ch_score;
	int mt_score;
	int en_score;	
}menbers[MENBERS];
int count=0; //记录输入数据数量 
void prtstar(int a){	//打印 *号 
	int i;
	for(i=0;i<a;i++)
	printf("*");
}	
void prtspace(int a){	//打印' '字符
	int i;
	for(i=0;i<a;i++)
	printf(" ");
}; 
void menu(void); //菜单函数 
void scandate(void); //输入数据 
void printdate(void); //打印数据 
int sum_score(char *ch_score,char *mt_score,char *en_score); //求总成绩 
int main(){
	while(1){
	if(count>0){
		putchar('\n');
		putchar('\n');
		}	
	menu();
	char ch=_getch();
	switch (ch){
		case'1':scandate();
				break;
		case'2':printdate();
				break;	
		}		
	}	
	return 0;
}
void menu(void){
	prtstar(41);
	putchar('\n');
	printf("*\t欢迎使用学生成绩管理系统\t*\n");
	printf("*\t\t\tPOWER BY Yuan.Sn*\n");
	prtstar(41);
	putchar('\n');
	printf("*             1.输入学生信息            *\n");
	printf("*             2.打印学生成绩            *\n");
	printf("*             3.排序学生成绩            *\n");
	printf("*             4.计算成绩均值            *\n");
	printf("*             5.计算最高成绩            *\n");
	printf("*             6.计算最低成绩            *\n");
	prtstar(41);
	printf("\n");
}
void scandate(void){ 
	char choose;
	do{
	if(choose>0){
		prtstar(21);
		putchar('\n');
	}
	puts("请输入学生姓名:"); 
	gets(menbers[count].name);
	puts("请输入学生性别:"); 
	gets(menbers[count].sex);
	puts("请输入学生学号:"); 
	gets(menbers[count].std_nmb);
	puts("请输入语文成绩:");
	scanf("%d",&menbers[count].ch_score);
	puts("请输入数学成绩:");
	scanf("%d",&menbers[count].mt_score);
	puts("请输入英语成绩:");
	scanf("%d",&menbers[count].en_score);
	count++;
	puts("是否要继续输入（y/n):");
	getchar();
	choose=_getch();
	}while(choose=='y');
}
void printdate(void){
	int i;
	printf("姓名\t性别\t学号\t\t语文\t数学\t英语\t总分\n"); 
	for (i=0;i<count;i++)
	printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
	,menbers[i].name,menbers[i].sex,menbers[i].std_nmb,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score
	,menbers[i].ch_score+menbers[i].mt_score+menbers[i].en_score);
}

