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
}menbers[MENBERS];
int count=0;	//��¼������������ 
void prtstar(int a){	//��ӡ *�� 
	int i;
	for(i=0;i<a;i++)
	printf("*");
}	
void prtspace(int a){	//��ӡ' '�ַ�
	int i;
	for(i=0;i<a;i++)
	printf(" ");
}; 
void menu(void);	//�˵����� 
void scandate(void);	//�������� 
void printdate(void);	//��ӡ���� 
void rank(void);	//����ѧ���ɼ� 
void search_score(void){
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
	printf("*             5.������߳ɼ�            *\n");
	printf("*             6.������ͳɼ�            *\n");
	printf("*             0.�˳�����                *\n");
	prtstar(41);
	printf("\n");
}
void scandate(void){ 
	char choose;
	do{
	if(count>0){
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

