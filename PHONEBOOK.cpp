#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct phonebook
{
	long int number;
	char name[15];
};
void savecontact()
{
	FILE *f;
	struct phonebook p;
	f=fopen("project","ab+");
	printf("\n *Enter name:");
	scanf("%s",p.name);
	printf("\n #Enter phone number: ");
	scanf("%ld",&p.number);
	fwrite(&p,sizeof(p),1,f);
	fflush(stdin);
	printf("\n Contact saved");
	fclose(f);
	printf("\nenter any key");
	getch();
	system("cls");
}
void viewcontact()
{
	struct phonebook p;
	FILE *f;
	f=fopen("project","rb");


	if(f==NULL)
	{
		printf("\n file not opened ");
		exit (1);
	}
	while(fread(&p,sizeof(p),1,f)==1)
	{
		printf("\n\n\nYOUR Contact are \n\n");
		printf("\nNAME =%s  \nPhone number=%ld",p.name,p.number);
		getch();
	}
	fclose(f);
	printf("\n press any key");
	getch();

}
void search()
{
	struct phonebook p;
	FILE *f;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
	{
		printf("\n File not opened");
		exit(1);
	}
	printf("\n ENter the name of person to search\n");
	scanf("%s",name);
	while(fread(&p,sizeof(p),1,f)==1)
	{
		if(strcmp(p.name,name)==0)
		{

			printf("\n\t details of  about :%s",name);
			printf("\n\n* Name :%s Contact:%ld",p.name,p.number);
		}
		else
		{
			printf(" \n FIle not found");
		}
	}
	fclose(f);
	printf("\n press any key");
	getch();
	system("cls");
}

void deletecontact()
{
	system("cls");
	struct phonebook p;
	FILE *f,*ft;
	int flag=0;
	char name[100];
	f=fopen("project","rb+");
	if(f==NULL)
	{
	printf(" \n\ncontact not found");
	}
	else
	{
		ft=fopen("temp","ab+");
		if(ft==NULL)
		{
		printf("\n file not opened");
		}
		printf("\n\n  Enter contacts name ;");
		scanf("%s",name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)>0)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			else if(strcmp((p.name),name)==0)
				flag=1;
				fclose(ft);
		}
		fclose(f);
		if(flag!=1)
		{
			printf("NO contacts are avilable to delete");
		}
		else
		{
			remove("project");
			rename("temp","project");
			printf("REcord deleted succesfully");
		}	
	}

	printf("\n press any key");
	getch();
}



int main()
{
	int choice;
//clrscr();
	do
	{
		system("cls");
		printf("\n\n\t#########################################################");
		printf("\n\n\t *****PHONE BOOK*****");
		printf("\n\n\t##################################################");
		printf("\n\n\t 1.Save new contact.");
		printf("\n\n\t 2.delete contact .");
		printf("\n\n\t 3.view all the contacts");
		printf("\n\n\t 4.Search contact");
		printf("\n\n\t 5.Exit");
		printf("\n\n\t Enter your choice from above (1-5):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				savecontact();
				break;
			case 2:
				deletecontact();
				break;
			case 3:
				viewcontact();
				break;
			case 4:
				search();
				break;
 		}
	}while(choice!=5);
	getch();
}


