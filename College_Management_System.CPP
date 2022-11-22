#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	char roll[10];
	char name[20];
	char branch[4];
	char gender[2];
	char residency[10];
	struct student *next;
};
struct student *start=NULL;
struct branch
{
	int cse;
	int ece;
	int aero;
	int eee;
	int mech;
};
struct branch s;
struct hostel
{
	int boys_vacancy;
	int girls_vacancy;
};
struct hostel hosteller;
void create();
void display();
int main()
{
	int choice;
	s.cse=180;
	s.ece=180;
	s.aero=120;
	s.eee=120;
	s.mech=120;
	hosteller.boys_vacancy=180;
	hosteller.girls_vacancy=180;
	while(1)
	{
		clrscr();
		printf("\t****ADMISSION MANAGEMENT SYSTEM****\n");
		printf("*********************************");
		printf("\n\tBranch\tNo.of vacancies\n");
		printf("\tCSE-\t%d\n",s.cse);
		printf("\tAero-\t%d\n",s.aero);
		printf("\tECE-\t%d\n",s.ece);
		printf("\tEEE-\t%d\n",s.eee);
		printf("\tMECH-\t%d\n",s.mech);
		printf("*********************************");
		printf("\n\tHostel\tNo.of vacancies\n");
		printf("\tBoys\t%d\n",hosteller.boys_vacancy);
		printf("\tGirls\t%d\n",hosteller.girls_vacancy);
		printf("*********************************\n");
		printf("1.To enroll a student\n");
		printf("2.To display all students\n");
		printf("3.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
				break;
			case 2:display();
				break;
			default:exit(0);
		}
	}
}
void create()
{
	char b[4],r[10];
	struct student *temp,*p;
	temp=(struct student*)malloc(sizeof(struct student));
	p=(struct student*)malloc(sizeof(struct student));
	clrscr();
	printf("enter your roll number:");
	scanf("%s",temp->roll);
	printf("enter your name:");
	scanf("%s",temp->name);
	printf("enter branch:");
	scanf("%s",&b);
	if(strcmp(b,"CSE")==0)
	{
		if(s.cse==0)
		{
			printf("OOPS!No seats left :(");
			getch();
			return;
		}
		else
		{
			strcpy(temp->branch,b);
			s.cse=s.cse-1;
		}
	}
	else if(strcmp(b,"ECE")==0)
	{
		if(s.ece==0)
		{
			printf("OOPS!No seats left :(");
			getch();
			return;
		}
		else
		{
			strcpy(temp->branch,b);
			s.ece=s.ece-1;
		}
	}
	else if(strcmp(b,"AERO")==0)
	{
		if(s.aero==0)
		{
			printf("OOPS!No seats left :(");
			getch();
			return;
		}
		else
		{
			strcpy(temp->branch,b);
			s.aero=s.aero-1;
		}
	}
	else if(strcmp(b,"EEE")==0)
	{
		if(s.eee==0)
		{
			printf("OOPS!No seats left :(");
			getch();
			return;
		}
		else
		{
			strcpy(temp->branch,b);
			s.eee=s.eee-1;
		}
	}
	else
	{
		if(s.mech==0)
		{
			printf("OOPS!No seats left :(");
			getch();
			return;
		}
		else
		{
			strcpy(temp->branch,b);
			s.mech=s.mech-1;
		}
	}
	printf("enter gender(M/F):");
	scanf("%s",temp->gender);
	printf("Hosteller/local:");
	scanf("%s",&r);
	if(strcmp(r,"Hosteller")==0)
	{
		if(strcmp(temp->gender,"M")==0)
		{
			if(hosteller.boys_vacancy==0)
			{
				printf("OOPS!No vacancies in hostel :(");
				getch();
				return;
			}
			else
			{
				strcpy(temp->residency,r);
				hosteller.boys_vacancy-=1;
			}
		}
		else
		{
			if(hosteller.girls_vacancy==0)
			{
				printf("OOPS!No vacancies in hostel :(");
				getch();
				return;
			}
			else
			{
				strcpy(temp->residency,r);
				hosteller.girls_vacancy-=1;
			}
		}
	}
	else
	{
		strcpy(temp->residency,r);
	}
	if(start==NULL)
	{
		temp->next=NULL;
		start=temp;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		temp->next=NULL;
		p->next=temp;
	}
}
void display()
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	p=start;
	clrscr();
	printf("\n\t**********STUDENT DETAILS**********\n");
	printf("Roll\tName\tGender\tBranch\tResidency\n");
	while(p!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\n",p->roll,p->name,p->gender,p->branch,p->residency);
		p=p->next;
	}
	getch();
}