/*In this project Adding new records, listing them, modifying them,
Search for contacts saved, and deleting the phonebook records, are the basic functions,
which make up the main menu of this Phonebook application.
A structure is used to carry information about a contact.
The phonebook is a very simple mini project in C that can help you understand the basic concepts of functions,
file handling, and data structure.
This application will teach you how to add, list, modify or edit, search, and delete data from the file.

The coding of the project is very short and simple.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citision_no[20];

    };
void menu();//This function is used to display the main menu.
void got();
void start();//This functions calls the menu function mentioned above.
void back();//This function is used to go back to start.
void addrecord();// It adds a new Phonebook record.
void listrecord();//This function is used to view list of added records in file.
void modifyrecord();//This function is used to modify added records.
void deleterecord();// It deletes record from file.
void searchrecord();// It searches for added record by name.
int main()//main function started//
{
    system("color 2f");
    start();
    return 0;
}
void back()//This function is used to go back to start.
{
    start();
}
void start()//This functions calls the menu function mentioned above.
{
    menu();
}
void menu()//This function is used to display the main menu.
{
    system("cls");
printf("\t\t*********WELCOME TO PHONEBOOK************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete");

switch(getch())
{
    case '1':
	addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': deleterecord();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter Any Key");
                getch();

menu();
}
}
        void addrecord()//this function is used to add a new phone book record//
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\nEnter Name: ");
        got(p.name);
        printf("\nEnter Address: ");
        got(p.address);
        printf("\nEnter Father Name: ");
        got(p.father_name);
        printf("\nEnter Mother Name: ");
        got(p.mother_name);
        printf("\nEnter Phone Number: ");
        scanf("%ld",&p.mble_no);
        printf("Enter Gender: ");
        got(p.sex);
        printf("\nEnter e-Mail: ");
         got(p.mail);
        printf("\nEnter Citizen Number: ");
        got(p.citision_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);//clear the output buffer of the stream
        printf("\nRecord Saved !!");

fclose(f);

    printf("\n\nEnter Any Key");

	 getch();
    system("cls");
    menu();
}
void listrecord()//This function is used to view list of added records in file.//
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nFile Opening Error In Listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)//reads data from a file and store it in buffer
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName: %s\nAdress: %s\nFather Name: %s\nMother Name: %s\nMobile Number: %ld\nGender: %s\nE-Mail: %s\nCitizen Number: %s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\nEnter Any Key");
 getch();//hold the screen,until user presss any key
    system("cls");
menu();
}
void searchrecord()//this function is used to searches for added record by name.//
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\nError In Opening\a\a\a\a");
    exit(1);

}
printf("\nEnter Name of the Person to Search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName: %s\nAddress: %s\nFather Name: %s\nMother Name: %s\nMobile Number: %ld\nGender: %s\nE-Mail: %s\nCitizen Number: %s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);
    }
        else
        printf("404 ! File Not Found !!");

}
 fclose(f);
  printf("\nEnter Any Key");

	 getch();
    system("cls");
menu();
}
void deleterecord()//this function is used to deletes record from file.//
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("\nCONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("File Opening Error");
		else

        {


		printf("\nEnter CONTACT'S NAME: ");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\nNO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\nEnter Any Key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()//This function is used to modify added records.//
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("\nCONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\nEnter Name: ");
                    got(s.name);
                    printf("\nEnter Address: ");
                    got(s.address);
                    printf("\nEnter Father Name: ");
                    got(s.father_name);
                    printf("\nEnter Mother Name: ");
                    got(s.mother_name);
                    printf("\nEnter Phone Number: ");
                    scanf("%ld",&s.mble_no);
                    printf("Enter Gender: ");
                    got(s.sex);
                    printf("\nEnter e-Mail: ");
                    got(s.mail);
                    printf("\nEnter Citizen Number: ");
                    got(s.citision_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\nYour Data is Modified");

            }
            else
            {
                    printf(" \nData Not Found");

            }
            fclose(f);
	}
	 printf("\nEnter Any Key");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
