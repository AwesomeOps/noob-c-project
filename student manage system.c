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
int count=0; //��¼������������ 
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
void menu(void); //�˵����� 
void scandate(void); //�������� 
void printdate(void); //��ӡ���� 
int sum_score(char *ch_score,char *mt_score,char *en_score); //���ܳɼ� 
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
	printf("*\t��ӭʹ��ѧ���ɼ�����ϵͳ\t*\n");
	printf("*\t\t\tPOWER BY Yuan.Sn*\n");
	prtstar(41);
	putchar('\n');
	printf("*             1.����ѧ����Ϣ            *\n");
	printf("*             2.��ӡѧ���ɼ�            *\n");
	printf("*             3.����ѧ���ɼ�            *\n");
	printf("*             4.����ɼ���ֵ            *\n");
	printf("*             5.������߳ɼ�            *\n");
	printf("*             6.������ͳɼ�            *\n");
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
	count++;
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

