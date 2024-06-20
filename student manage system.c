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
	int sum_score;	
};
struct student menbers[MENBERS];	//存储所有学生数据的结构体 
struct student ex[MENBERS];		//存储优秀学生数据的结构体 
struct student fi[MENBERS];		//存储良好学生数据的结构体 
struct student nm[MENBERS];		//存储一般学生数据的结构体 
struct student fl[MENBERS];		//存储不及格学生数据的结构体 
int count=0;	//记录输入数据数量 
void prtstar(int a){	//打印 *号的函数 
	int i;
	for(i=0;i<a;i++)
	printf("*");
}	
void prtspace(int a){	//打印' '字符的函数 
	int i;
	for(i=0;i<a;i++)
	printf(" ");
}; 
void menu(void);	//菜单函数 
void scandate(void);	//输入数据 
void printdate(void);	//打印数据 
void rank(void);	//排序学生成绩 
void search_score(void);	//根据名字查询分数 
void scandate_flie(void);	//扫描txt内的数据 
void print_flie(void);		//将txt数据传到结构体 
void analyze(void);		//分析学生成绩 
void change_stu(void){
	scandate_flie();
	int i;
	int a;
	char ch;
	printf("   姓名\t性别\t学号\t\t语文\t数学\t英语\t总分\n"); 
	for (i=0;i<count;i++)
	printf("%d. %s\t%s\t%s\t%d\t%d\t%d\t%d\n"
	,i+1,menbers[i].name,menbers[i].sex,menbers[i].std_nmb,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score
	,menbers[i].ch_score+menbers[i].mt_score+menbers[i].en_score);
	do{
		puts("请输入要修改学生的序号：");
		scanf("%d",&a);
		getchar();
		puts("请输入学生姓名:"); 
		gets(menbers[a-1].name);
		puts("请输入学生性别:"); 
		gets(menbers[a-1].sex);
		puts("请输入学生学号:"); 
		gets(menbers[a-1].std_nmb);
		puts("请输入语文成绩:");
		scanf("%d",&menbers[a-1].ch_score);
		puts("请输入数学成绩:");
		scanf("%d",&menbers[a-1].mt_score);
		puts("请输入英语成绩:");
		scanf("%d",&menbers[a-1].en_score);
		menbers[a-1].sum_score=menbers[a-1].ch_score+menbers[a-1].mt_score+menbers[a-1].en_score;
		printf("是否继续修改学生信息(y/n)\n");
		ch=_getch();
	}
	while(ch=='y');
} 

int main(){
	scandate_flie();
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
		case'3':rank();
				break;
		case'4':search_score();
				break;
		case'5':analyze();
				break;
		case'6':change_stu();
				break;		
		case'0':
				printf("Bye Bye!\n");
				exit(0);
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
	printf("*             3.根据成绩排名            *\n");
	printf("*             4.查询学生成绩            *\n");
	printf("*             5.分析学生成绩            *\n");
	printf("*             6.修改学生信息            *\n");
	printf("*             0.exit                    *\n");
	prtstar(41);
	printf("\n");
}
void scandate_flie(void){	//扫描txt内的数据 
	FILE *fp;
	int i;
	fp=fopen("date.txt","r+");
	fscanf(fp,"%d\n",&count);
	for(i=0;i<count;i++)
	fscanf(fp,"%s %s %s %d %d %d %d\n",menbers[i].name,menbers[i].sex,menbers[i].std_nmb,&menbers[i].ch_score,&menbers[i].mt_score,&menbers[i].en_score,&menbers[i].sum_score); 
	fclose(fp);
} 
void print_flie(void){	//将结构体的数据提取到txt 
	FILE *fp;
	int i;
	fp=fopen("date.txt","w+");
	fprintf(fp,"%d\n",count);
	for(i=0;i<count;i++)
	fprintf(fp,"%s %s %s %d %d %d %d\n",menbers[i].name,menbers[i].sex,menbers[i].std_nmb,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score,menbers[i].sum_score);
	fclose(fp);
} 
void scandate(void){ 
	char choose;
	do{
	if(choose>0){
		prtstar(21);
		putchar('\n');
	}
	scandate_flie();
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
	menbers[count].sum_score=menbers[count].ch_score+menbers[count].mt_score+menbers[count].en_score;
	count++;
	print_flie();
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
void rank(){	//排序学生总成绩 
	int i,j;
	struct student change;
	for(i=0;i<count;i++)
		for(j=0;j<count-i;j++){
			if(menbers[i+1].sum_score>menbers[i].sum_score){
				change=menbers[i];
				menbers[i]=menbers[i+1];
				menbers[i+1]=change;
			}
		}
	printdate();
}
void search_score(void){	//根据名字查询分数 
	system("cls");
	char name[20];
	int i;
	printf("请输入需要查询学生的名字：\n");
	scanf("%s",&name);
	for(i=0;i<count;i++){
		if((strcmp(name,menbers[i].name))==0){
			printf("%s的语文成绩为：%d，数学成绩为：%d，英语成绩为：%d",menbers[i].name,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score);
		}	
	}
}
void analyze(void){
	int i; 
	char ch,ch2;
	print_flie();
	int count_ex=0;
	int count_fi=0;
	int count_nm=0;
	int count_fl=0;
	for(i=0;i<count;i++){
		if(menbers[i].sum_score>270){
			strcpy(ex[count_ex].name,menbers[i].name);
			strcpy(ex[count_ex].sex,menbers[i].sex);
			strcpy(ex[count_ex].std_nmb,menbers[i].std_nmb);
			ex[count_ex].ch_score=menbers[i].ch_score;
			ex[count_ex].mt_score=menbers[i].mt_score;
			ex[count_ex].en_score=menbers[i].en_score;
			ex[count_ex].sum_score=menbers[i].sum_score;
			count_ex++;
			continue;
		}
		if(menbers[i].sum_score>240){
			strcpy(fi[count_fi].name,menbers[i].name);
			strcpy(fi[count_fi].sex,menbers[i].sex);
			strcpy(fi[count_fi].std_nmb,menbers[i].std_nmb);
			fi[count_fi].ch_score=menbers[i].ch_score;
			fi[count_fi].mt_score=menbers[i].mt_score;
			fi[count_fi].en_score=menbers[i].en_score;
			fi[count_fi].sum_score=menbers[i].sum_score;
			count_fi++;
			continue;
		}
		if(menbers[i].sum_score>180){
			strcpy(nm[count_nm].name,menbers[i].name);
			strcpy(nm[count_nm].sex,menbers[i].sex);
			strcpy(nm[count_nm].std_nmb,menbers[i].std_nmb);
			nm[count_nm].ch_score=menbers[i].ch_score;
			nm[count_nm].mt_score=menbers[i].mt_score;
			nm[count_nm].en_score=menbers[i].en_score;
			nm[count_nm].sum_score=menbers[i].sum_score;
			count_nm++;
			continue;
		}
		if(menbers[i].sum_score<180){
			strcpy(fl[count_fl].name,menbers[i].name);
			strcpy(fl[count_fl].sex,menbers[i].sex);
			strcpy(fl[count_fl].std_nmb,menbers[i].std_nmb);
			fl[count_fl].ch_score=menbers[i].ch_score;
			fl[count_fl].mt_score=menbers[i].mt_score;
			fl[count_fl].en_score=menbers[i].en_score;
			fl[count_fl].sum_score=menbers[i].sum_score;
			count_fl++;
			continue;
		}		
	} 
	do{
		system("cls");
		printf("1.打印成绩优秀学生 2.打印成绩良好学生 3.打印成绩一般学生 4.打印不及格学生\n");
		ch=_getch();
	switch(ch){
		case '1':
			system("cls");
			for(i=0;i<count_ex;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,ex[i].name,ex[i].sex,menbers[i].std_nmb,ex[i].ch_score,ex[i].mt_score,ex[i].en_score
			,ex[i].sum_score);
			printf("(本次考试共有%d人参考，优秀的共有%d人)",count,count_ex);
			getchar();
			system("cls");
			break;
		case '2':
			system("cls");
			for(i=0;i<count_fi;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,fi[i].name,fi[i].sex,menbers[i].std_nmb,fi[i].ch_score,fi[i].mt_score,fi[i].en_score
			,fi[i].sum_score);
			printf("(本次考试共有%d人参考，良好的共有%d人)",count,count_fi);
			getchar();
			system("cls");
			break;
		case '3':
			system("cls");
			for(i=0;i<count_nm;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,nm[i].name,nm[i].sex,menbers[i].std_nmb,nm[i].ch_score,nm[i].mt_score,nm[i].en_score
			,nm[i].sum_score);
			printf("(本次考试共有%d人参考，一般的共有%d人)",count,count_nm);
			getchar();
			system("cls");
			break;
		case '4':
			system("cls");
			for(i=0;i<count_nm;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,fl[i].name,fl[i].sex,menbers[i].std_nmb,fl[i].ch_score,fl[i].mt_score,fl[i].en_score
			,fl[i].sum_score);
			printf("(本次考试共有%d人参考，不及格的共有%d人)",count,count_fl);
			getchar();
			system("cls");
			break;
		case '5':
			fp=fopen("analyze.txt","w+");
			fprintf(fp,"%d\n",count);
			for(i=0;i<count_ex;i++)
			fprintf(fp,"%s %s %s %d %d %d %d\n",ex[i].name,ex[i].sex,ex[i].std_nmb,ex[i].ch_score,ex[i].mt_score,ex[i].en_score,ex[i].sum_score);
			fclose(fp);
		case '0':
			exit(0);
	}
	printf("是否继续分析学生信息(y/n)\n");
	ch2=_getch();
	}
	while(ch2=='y');
}
	
 

