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
struct student menbers[MENBERS];	//�洢����ѧ�����ݵĽṹ�� 
struct student ex[MENBERS];		//�洢����ѧ�����ݵĽṹ�� 
struct student fi[MENBERS];		//�洢����ѧ�����ݵĽṹ�� 
struct student nm[MENBERS];		//�洢һ��ѧ�����ݵĽṹ�� 
struct student fl[MENBERS];		//�洢������ѧ�����ݵĽṹ�� 
int count=0;	//��¼������������ 
void prtstar(int a){	//��ӡ *�ŵĺ��� 
	int i;
	for(i=0;i<a;i++)
	printf("*");
}	
void prtspace(int a){	//��ӡ' '�ַ��ĺ��� 
	int i;
	for(i=0;i<a;i++)
	printf(" ");
}; 
void menu(void);	//�˵����� 
void scandate(void);	//�������� 
void printdate(void);	//��ӡ���� 
void rank(void);	//����ѧ���ɼ� 
void search_score(void);	//�������ֲ�ѯ���� 
void scandate_flie(void);	//ɨ��txt�ڵ����� 
void print_flie(void);		//��txt���ݴ����ṹ�� 
void analyze(void);		//����ѧ���ɼ� 
void change_stu(void){
	scandate_flie();
	int i;
	int a;
	char ch;
	printf("   ����\t�Ա�\tѧ��\t\t����\t��ѧ\tӢ��\t�ܷ�\n"); 
	for (i=0;i<count;i++)
	printf("%d. %s\t%s\t%s\t%d\t%d\t%d\t%d\n"
	,i+1,menbers[i].name,menbers[i].sex,menbers[i].std_nmb,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score
	,menbers[i].ch_score+menbers[i].mt_score+menbers[i].en_score);
	do{
		puts("������Ҫ�޸�ѧ������ţ�");
		scanf("%d",&a);
		getchar();
		puts("������ѧ������:"); 
		gets(menbers[a-1].name);
		puts("������ѧ���Ա�:"); 
		gets(menbers[a-1].sex);
		puts("������ѧ��ѧ��:"); 
		gets(menbers[a-1].std_nmb);
		puts("���������ĳɼ�:");
		scanf("%d",&menbers[a-1].ch_score);
		puts("��������ѧ�ɼ�:");
		scanf("%d",&menbers[a-1].mt_score);
		puts("������Ӣ��ɼ�:");
		scanf("%d",&menbers[a-1].en_score);
		menbers[a-1].sum_score=menbers[a-1].ch_score+menbers[a-1].mt_score+menbers[a-1].en_score;
		printf("�Ƿ�����޸�ѧ����Ϣ(y/n)\n");
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
	printf("*\t��ӭʹ��ѧ���ɼ�����ϵͳ\t*\n");
	printf("*\t\t\tPOWER BY Yuan.Sn*\n");
	prtstar(41);
	putchar('\n');
	printf("*             1.����ѧ����Ϣ            *\n");
	printf("*             2.��ӡѧ���ɼ�            *\n");
	printf("*             3.���ݳɼ�����            *\n");
	printf("*             4.��ѯѧ���ɼ�            *\n");
	printf("*             5.����ѧ���ɼ�            *\n");
	printf("*             6.�޸�ѧ����Ϣ            *\n");
	printf("*             0.exit                    *\n");
	prtstar(41);
	printf("\n");
}
void scandate_flie(void){	//ɨ��txt�ڵ����� 
	FILE *fp;
	int i;
	fp=fopen("date.txt","r+");
	fscanf(fp,"%d\n",&count);
	for(i=0;i<count;i++)
	fscanf(fp,"%s %s %s %d %d %d %d\n",menbers[i].name,menbers[i].sex,menbers[i].std_nmb,&menbers[i].ch_score,&menbers[i].mt_score,&menbers[i].en_score,&menbers[i].sum_score); 
	fclose(fp);
} 
void print_flie(void){	//���ṹ���������ȡ��txt 
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
	puts("������ѧ������:"); 
	gets(menbers[count].name);
	puts("������ѧ���Ա�:"); 
	gets(menbers[count].sex);
	puts("������ѧ��ѧ��:"); 
	gets(menbers[count].std_nmb);
	puts("���������ĳɼ�:");
	scanf("%d",&menbers[count].ch_score);
	puts("��������ѧ�ɼ�:");
	scanf("%d",&menbers[count].mt_score);
	puts("������Ӣ��ɼ�:");
	scanf("%d",&menbers[count].en_score);
	menbers[count].sum_score=menbers[count].ch_score+menbers[count].mt_score+menbers[count].en_score;
	count++;
	print_flie();
	puts("�Ƿ�Ҫ�������루y/n):");
	getchar();
	choose=_getch();
	}while(choose=='y');
}
void printdate(void){
	int i;
	printf("����\t�Ա�\tѧ��\t\t����\t��ѧ\tӢ��\t�ܷ�\n"); 
	for (i=0;i<count;i++)
	printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
	,menbers[i].name,menbers[i].sex,menbers[i].std_nmb,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score
	,menbers[i].ch_score+menbers[i].mt_score+menbers[i].en_score);
}
void rank(){	//����ѧ���ܳɼ� 
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
void search_score(void){	//�������ֲ�ѯ���� 
	system("cls");
	char name[20];
	int i;
	printf("��������Ҫ��ѯѧ�������֣�\n");
	scanf("%s",&name);
	for(i=0;i<count;i++){
		if((strcmp(name,menbers[i].name))==0){
			printf("%s�����ĳɼ�Ϊ��%d����ѧ�ɼ�Ϊ��%d��Ӣ��ɼ�Ϊ��%d",menbers[i].name,menbers[i].ch_score,menbers[i].mt_score,menbers[i].en_score);
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
		printf("1.��ӡ�ɼ�����ѧ�� 2.��ӡ�ɼ�����ѧ�� 3.��ӡ�ɼ�һ��ѧ�� 4.��ӡ������ѧ��\n");
		ch=_getch();
	switch(ch){
		case '1':
			system("cls");
			for(i=0;i<count_ex;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,ex[i].name,ex[i].sex,menbers[i].std_nmb,ex[i].ch_score,ex[i].mt_score,ex[i].en_score
			,ex[i].sum_score);
			printf("(���ο��Թ���%d�˲ο�������Ĺ���%d��)",count,count_ex);
			getchar();
			system("cls");
			break;
		case '2':
			system("cls");
			for(i=0;i<count_fi;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,fi[i].name,fi[i].sex,menbers[i].std_nmb,fi[i].ch_score,fi[i].mt_score,fi[i].en_score
			,fi[i].sum_score);
			printf("(���ο��Թ���%d�˲ο������õĹ���%d��)",count,count_fi);
			getchar();
			system("cls");
			break;
		case '3':
			system("cls");
			for(i=0;i<count_nm;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,nm[i].name,nm[i].sex,menbers[i].std_nmb,nm[i].ch_score,nm[i].mt_score,nm[i].en_score
			,nm[i].sum_score);
			printf("(���ο��Թ���%d�˲ο���һ��Ĺ���%d��)",count,count_nm);
			getchar();
			system("cls");
			break;
		case '4':
			system("cls");
			for(i=0;i<count_nm;i++)
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n"
			,fl[i].name,fl[i].sex,menbers[i].std_nmb,fl[i].ch_score,fl[i].mt_score,fl[i].en_score
			,fl[i].sum_score);
			printf("(���ο��Թ���%d�˲ο���������Ĺ���%d��)",count,count_fl);
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
	printf("�Ƿ��������ѧ����Ϣ(y/n)\n");
	ch2=_getch();
	}
	while(ch2=='y');
}
	
 

