#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<dos.h>
static int i=3;

void wlcm_page(void);
void login_page(void);
void login();
void admin(void);
void new_mgr(void);
void manager(void);
void new_employee(void);
void new_vehicle(void);
//void driver(void);

int main()
{
	wlcm_page();
	login_page();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void wlcm_page()
{
	system("cls");
	gotoxy(35,2);
	printf("Welcome");
	gotoxy(25,4);
	printf("Oil Transport Record keeper");
	gotoxy(10,7);
	printf("Prepared BY :");
	gotoxy(10,8);
	printf("Diwas Dhakal");
	gotoxy(10,9);
	printf("Alisha Luitel");
	gotoxy(10,10);
	printf("Sadikshya Koirala");
	gotoxy(30,13);
	printf("Press Any Key To Continue");
	getch();
}

void login_page()
{
	char username[10],password[10];
	system("cls");
	gotoxy(20,3);
	printf("***************Login**************");
	gotoxy(15,6);
	printf("Username :");
	gotoxy(15,7);
	printf("Password :");
	gotoxy(27,6);
	scanf("%s",username);
	gotoxy(27,7);
	scanf("%s",password);
	login(username,password);
}

void login(char name[10],char pass[10])
{
	while(i>=1)
	{
		system("cls");
		if(strcmp(name,"admin")==0)
		{
			if(strcmp(pass,"admin")==0)
			{	
				admin();
			}
			else
			{
				gotoxy(35,5);
				printf("!!! Wrong Password !!! \a\a");
				gotoxy(35,6);
				printf("!! %d tries left !!",i);
				gotoxy(30,8);
				printf("This page will be redirected to login page");
				i--;
				sleep(1);
				login_page();
			}
		}
		else if(strcmp(name,"manager")==0)
		{
			if(strcmp(pass,"mgr1")==0)
			{	
				manager();
			}
			else
			{
				gotoxy(35,5);
				printf("!!! Wrong Password !!! \a\a");
				gotoxy(35,6);
				printf("!! %d tries left !!",i);
				gotoxy(30,8);
				printf("This page will be redirected to login page");
				i--;
				sleep(1);
				login_page();
			}
		}
		else if(strcmp(name,"driver")==0)
		{
			if(strcmp(pass,"driver1")==0)
			{	
				//driver();
			}
			else
			{
				gotoxy(35,5);
				printf("!!! Wrong Password !!! \a\a");
				gotoxy(35,6);
				printf("!! %d tries left !!",i);
				gotoxy(30,8);
				printf("This page will be redirected to login page");
				i--;
				sleep(1);
				login_page();
			}
		}
		else
		{
			gotoxy(35,5);
			printf("!!! Wrong username !!! \a\a");
			gotoxy(30,6);
			printf("!! %d tries left !!",i);
			gotoxy(30,8);
			printf("This page will be redirected to login page");
			i--;
			sleep(1);
			login_page();
		}
	}
	system("cls");
	gotoxy(35,6);
	printf("!! NO tries left !!");
	gotoxy(30,8);
	printf("The program will be terminated \a !!!");
	sleep(3);
	exit(1);
}

void admin()
{
	int choice;
	system("cls");
	gotoxy(25,3);
	printf("*****Welcome Administrator*****");
	gotoxy(15,6);
	printf("1. Show Tanker Details");
	gotoxy(15,7);
	printf("2. Show Driver Details");
	gotoxy(15,8);
	printf("3. Create New Manager ");
	gotoxy(15,9);
	printf("4. Login Page ");
	gotoxy(15,10);
	printf("0. Exit");
	gotoxy(15,12);
	printf("Choice :");
	gotoxy(25,12);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:
			printf("Tank");
			//show_tank_detail();
		case 2:
			printf("Driver");
			//show_driver_detail();
		case 3:
			new_mgr();
		case 4:
			i=3;
			login_page();
		case 0:
			exit(1);
		default:
			gotoxy(15,3);
			printf("!!! Wrong Choice !!!\a\a");
			gotoxy(12,4);
			printf("Try Again");
			admin();
	}	
}

void new_mgr()
{
	char fname[10],lname[10],username[10],password[10];
	system("cls");
	gotoxy(15,3);
	printf("New Manager Registration");
	gotoxy(7,6);
	printf("First Name :");
	gotoxy(7,7);
	printf("Last Name :");
	gotoxy(7,8);
	printf("Username : ");
	gotoxy(7,9);
	printf("Password : ");
	gotoxy(25,6);
	scanf("%s",fname);
	gotoxy(25,7);
	scanf("%s",lname);
	gotoxy(25,8);
	scanf("%s",username);
	gotoxy(25,9);
	scanf("%s",password);
	sleep(2);
	system("cls");
	gotoxy(25,4);
	printf("Manager Scuessfully saved");
	gotoxy(20,5);
	printf("This will go back to admin main page");
	sleep(1);
	admin();
}

void manager()
{
	int choice;
	system("cls");
	gotoxy(10,3);
	printf("***********Welcome Manager******************");
	gotoxy(12,5);
	printf("1. Add New Employee");
	gotoxy(12,6);
	printf("2. Add New Vehicle");
	gotoxy(12,7);
	printf("3. Add and Modify Vehicle data");
	gotoxy(12,8);
	printf("5. Login");
	gotoxy(12,9);
	printf("0. Exit");
	gotoxy(15,11);
	printf("Choice : ");
	gotoxy(25,11);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:
			new_employee();
		case 2:
			new_vehicle();
			break;
		case 3:
			//veh_data();
			printf("Add and modify Vehicle data");
			break;
		case 4:
			//mod_emp();
			printf("Modify Employee Data");
			break;
		case 5:
			i=3;
			login_page();
		case 0:
			exit(0);
		default:
			system("cls");
			gotoxy(25,3);
			printf("!!! Wrong Choice !!!\a");
			gotoxy(20,5);
			printf("The program will go back to Manager Menu");
			sleep(1);
			manager();
	}
}

void new_employee()
{
	char fname[10],lname[10],licence_no[10],username[10],pass[10];
	int contact_no[10];
	system("cls");
	printf("\t\t*****New Driver Registration*********");
	gotoxy(20,3);
	printf("First Name :");
	gotoxy(20,4);
	printf("Last Name :");
	gotoxy(20,5);
	printf("License no :");
	gotoxy(20,6);
	printf("Contact No :");
	gotoxy(15,8);
	printf("******** Login Section********");
	gotoxy(20,9);
	printf("Username :");
	gotoxy(20,10);
	printf("Password :");
	gotoxy(35,3);
	scanf("%s",fname);
	gotoxy(35,4);
	scanf("%s",lname);
	gotoxy(35,5);
	scanf("%s",licence_no);
	gotoxy(35,6);
	scanf("%d",contact_no);
	gotoxy(35,9);
	scanf("%s",username);
	gotoxy(35,10);
	scanf("%s",pass);
	system("cls");
	gotoxy(15,3);
	printf("*********** Saving ***********");
	sleep(3);
	system("cls");
	gotoxy(15,3);
	printf("New Employee data has been added");
	gotoxy(10,5);
	printf("The Page will be redirected to managers Menu");
	sleep(1);
	manager();
}

void new_vehicle()
{
	char tank_no[12],eng_no[12];
	int year[4],cap;
	l:
	system("cls");
	printf("\n\t***************** New Vehicle Entry ************************");
	gotoxy(15,4);
	printf("Tanker No : ");
	gotoxy(15,5);
	printf("Engine No : ");
	gotoxy(15,6);
	printf("Manufacturing Year :");
	gotoxy(15,7);
	printf("Capacity :");
	gotoxy(40,7);
	printf("(12/20)");
	gotoxy(30,4);
	scanf("%s",tank_no);
	gotoxy(30,5);
	scanf("%s",eng_no);
	gotoxy(40,6);
	scanf("%d",&year);
	gotoxy(28,7);
	scanf("%d",&cap);
	if(cap==20||cap==12)
	{
		system("cls");
		printf("\n\t\t The data is being saved...");
		sleep(2);
		system("cls");
		printf("\n\t\t\tThe data is saved\n");
		printf("\n\t\tThe page will be redirected to the manager menu");
		sleep(2);
		manager();
	}
	else
	{
		system("cls");
		printf("\n\t\t\tWrong Choice !!!\a");
		printf("\n\n\t\tPlease try again\n");
		sleep(1);
		goto l;
	}
}

void veh_data()
{
	int choice;
	l:
	system("cls");
	printf("\n\n\t\t\t\t Please Select the choice \n");
	gotoxy(15,5);
	printf("1. Add data ");
	gotoxy(15,6);
	printf("2. Modify data");
	gotoxy(15,7);
	printf("3. Delete data");
	gotoxy(15,8);
	printf("4. Return to menu");
	gotoxy(15,9);
	printf("0. Exit");
	gotoxy(15,12);
	printf("Choice :");
	gotoxy(25,12);
	scanf("%d");
	switch(choice)
	{
		case 1:
			//add_veh_data();
			printf("add veh data");
			break;
		case 2:
			//mod_veh_data();
			printf("mod Veh data");
			break;
		case 3:
			//del_veh_data();
			printf("Del Veh Data");
			break;
		case 4:
			manager();
		case 0:
			exit(0);
		default:
			system("cls");
			printf("\n\t\t\t!!! Wrong Choice !!!\n");
			printf("\t\tThe page will be redirected to the menu");
			goto l;		
	}
}
