#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct element{
		char name[20];
		char sb[5];
		int atm;
		float atms;
		char block;
		char atc[20];
		char prop[250];
	       }p,q;
int rw,cl;
FILE*fp;
void add();
void explor();
void print();
void mainscreen();
int main()
{
	int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

	system("cls");
	mainscreen();
	label1:




	printf("Enter the corresponding no\n");

	printf("1.Add new Element Information\n");

	printf("2.Explore\n");

	printf("3.Quit\n");

       //	cprintf("4.Delete the records");gotoxy(22,27);
       //	cprintf("5.Exit from the program");gotoxy(25,30);
	fflush(stdin);
	d=getch();
	switch(d)
	{
		case '1':
		      {
			add();
		       //	getch();
		       //	print();
		       //	getch();
			break;
		      }
		case '2':
		      {
			explor();
			break;

			}
		case '3':
		      {
			system("cls");
			mainscreen();
			printf("THANK U\n");

		       //	cprintf("SAVING UR SETTINGS"); gotoxy(30,28);
			printf("BYE...........");
			getch();
			exit(1);
			break;
			}
		default:
		       {
			system("cls");
			mainscreen();
			printf("Wrong choice\n");
            printf("Retype choice\n");
			goto label1;
			}

	}
	system("cls");
	mainscreen();
	goto label1;
	return 0;
}
void mainscreen()
{
	int i,j;
	system("cls");
	for(i=2,j=2;i<rw;j++)
	{
		if(j>15)
		j=2;

		printf("%c",'*');
		printf("%c",'*');
		i++;

	}
	for(i=2,j=2;i<cl;i++,j++)
	{
		if(j>15)
		j=2;
		printf("%c",'*');
		printf("%c",'*');

	}
	printf("Modern Periodic Table\n");
	printf("Digital\n");
	printf("-----------\n");
}
void add()
{
	char ch;
	label1:
	system("cls");
	mainscreen();
    printf("Enter the Information of Elements:\n");
       //	printf(" %d",l);
	printf("Name:\n");
	fflush(stdin);
	scanf("%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);

	printf("Symbol:\n");
	fflush(stdin);
	scanf("%[^\n]",p.sb);
	p.sb[0]=toupper(p.sb[0]);

	printf("Atomic No:\n ");
	fflush(stdin);
	scanf("%d",&p.atm);

	printf("Atomic Wt:\n");
    fflush(stdin);
	scanf("%f",&p.atms);


	printf("Atomic Config:\n");
    fflush(stdin);
	scanf("%[^\n]",p.atc);


	printf("Block:\n");
	fflush(stdin);
	scanf("%c",&p.block);
	p.block=toupper(p.block);
	if(p.block!='S'&&p.block!='P'&&p.block!='D'&&p.block!='F')
	p.block=' ';
	fflush(stdin);

    printf("Properties\n:");
 	scanf("%[^\n]",p.prop);
	p.prop[0]=toupper(p.prop[0]);
	 /*	gotoxy(9,30);
	cprintf("(In Short)");

	gotoxy(5,33);
	cprintf("Reff. Specialist no:");      */
	if((fp=fopen("data","ab+"))==NULL)
	{
		printf("Cannot open the file f1");
		getch();
		exit(1);
	}
	fwrite(&p,sizeof(p),1,fp);
	fclose(fp);
	printf("\n\n\n\t\tEnter 'y' for next record(y/n):");
	ch=getch();
	if(ch=='y')
	{
		goto label1;
	}

       //	getch();
}
void explor()
{
	char d,c;
	FILE *f;
	int given_atmic_no,a,i,tsz,n;
	float given_atmic_mass;
	int flag;
	char string[20];
	startofexplore:
	system("cls");
	mainscreen();
	label6:
	printf("Enter the corresponding no");
	printf("1.Search by 'NAME'\n");
	printf("2.Search by SYMBOL\n");
	printf("3.Search by ATOMIC NUMBER\n");
	printf("4.Search by ATOMIC WEIGHT\n");
	printf("5.Elements of Diff. Blocks\n");
	printf("6.Return to main menu\n");
	fflush(stdin);
	d=getch();
	switch(d)
       {
		case '1':
		{
			system("cls");
			mainscreen();
			printf("Enter the Name of Element:");
			fflush(stdin);
			scanf("%[^\n]",string);
			printf("%s",string);
			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.name,string)==0)
				{
					print();

					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls");
				mainscreen();
				printf("::No Element Available::");

			}

			fclose(fp);
			getch();
			break;
		}
		case '2':
		{
			system("cls");
			mainscreen();
			printf("Enter the symbol:");
			fflush(stdin);
			scanf("%[^\n]",string);
			printf("%s",string);
			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.sb,string)==0)
				{
					print();
					flag=0;


					break;
				 }

			}
			if(flag==1)
			{
				system("cls");
				mainscreen();
				printf("::No Element Available::");

			}

			fclose(fp);
			getch();
			break;
		}
		case '6':
		{
			return;
		}
		case '3':
		{
			system("cls");
			mainscreen();
			printf("Enter the Atomic No. Element:");
			fflush(stdin);
			scanf("%d",&given_atmic_no);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atm==given_atmic_no)
				{
					print();
					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls");
				mainscreen();
				printf("::No Element Available::");

			}

			fclose(fp);
			getch();
			break;
		}
		case '4':
		{
			system("cls");
			mainscreen();
			printf("Enter the Atomic mass of Element:");
			fflush(stdin);
			scanf("%f",&given_atmic_mass);
			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atms==given_atmic_mass)
				{
					print();
					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
				system("cls");
				mainscreen();
				printf("::No Element Available::");

			}

			fclose(fp);
			getch();
			break;
		}
		case '5':
		{

			system("cls");
			mainscreen();
			printf("Enter the Block:");
			fflush(stdin);
			scanf("%c",&c);
			c=toupper(c);
			if((f=fopen("temp","wb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the temp file 1");
			getch();
			exit(1);
			}


			if((fp=fopen("data","rb+"))==NULL)
			{
			system("cls");

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.block==c)
				{
					fwrite(&p,sizeof(p),1,f);
				 }

			}
			fclose(f);
			fclose(fp);

					 if((f=fopen("temp","rb+"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
					 fseek(f,0,SEEK_END);
					 tsz=ftell(f);
					 n=(int)(tsz/sizeof(p));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(f,i*sizeof(p),SEEK_SET);
						fread(&p,sizeof(p),1,f);
						fseek(f,a*sizeof(p),SEEK_SET);
						fread(&q,sizeof(p),1,f);
						if((p.atm-q.atm)>0)
							{
							fseek(f,i*sizeof(p),SEEK_SET);
							fwrite(&q,sizeof(p),1,f);
							fseek(f,a*sizeof(p),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(p),1,fp);
							}
						}
					}
					rewind(f);
			while(fread(&p,sizeof(p),1,f))
			{

					print();
					getch();


			}


				system("cls");
				mainscreen();
				printf("::No Element Available::");



			fclose(f);
			getch();
			break;
		}


		default:
		{
				system("cls");
				mainscreen();
				printf("Wrong choice");
				printf("Retype choice");
				goto label6;
		}
	}
	goto startofexplore;

}
void print()
{
	system("cls");
	mainscreen();
	printf("Name:\t");
    printf("%s\n",p.name);
	printf("Symbol:\t");
    printf("%s\n",p.sb);
    fflush(stdin);
	printf("Atomic No:\t ");
    printf("%d\n",p.atm);

	fflush(stdin);
	printf("Atomic Wt:\t ");
    printf("%f\n",p.atms);

	fflush(stdin);
	printf("Atomic Config:\t");
	printf("%s\n",p.atc);
	fflush(stdin);
	printf("Block:\t");
    printf("%c\n",p.block);
	printf("Properties:\t");
    printf("%s\n",p.prop);



	}
