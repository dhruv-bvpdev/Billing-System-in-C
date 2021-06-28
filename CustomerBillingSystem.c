#include<stdio.h>
#include<windows.h>
#include<direct.h>
#include<stdlib.h>
#include<time.h> 
#include<dos.h>
#include<conio.h>
#include<unistd.h>

struct customer {
  char name[15], address[30], city[15], cust_id[20], date[20];
  int phn;
}cust;

struct billing {
  char a[20], cust_id[20], date[20],bill_id[20];
  int price, gst, qty, total, total2,total3;
}blng;

struct payment {
  char noc[20],ti[20];
  int ar;
}pay;

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void box(int, int, int, int);
void box(int a, int b, int c, int d) 
{
  int i, j;
  for (i = a; i < c; i++) 
  {
	gotoxy(i, b);
	printf("\xcd");
	gotoxy(i, d);
	printf("\xcd");
  }

  for (j = b; j < d; j++) 
  {
	gotoxy(a, j);
	printf("\xba");
	gotoxy(c, j);
	printf("\xba");
  }
  gotoxy(a, b);
  printf("\xc9");
  gotoxy(c, b);
  printf("\xbb");
  gotoxy(a, d);
  printf("\xc8");
  gotoxy(c, d);
  printf("\xbc");
}

int main() 
{
  FILE * fptr, * fptr1;

  int f=0,e=0,gst1, discount = 0, total1 = 0, total3 = 0;
  int i, n, b, d, ar, ra = 0, ba = 0;
  char ch, ch1, temp_id[20], temp_date[20];
	char name[10]="admin";
	char password[10]="1234";
	char sname[10];
	char spassword[10];
	system("cls");
	box(18, 10, 60, 12);
	gotoxy(20, 10);
	
	printf("\n       CUSTOMER BILLING SYSTEM       \n");
	Sleep(2000);
	LOGIN_FUNCTION :

	system("cls");
    system("color 40");
    box(18,10,50,15);
	gotoxy(20,11);
	printf("Enter username  ");
	scanf("%s",sname);
	gotoxy(20,12);
	printf("Enter password  ");
	scanf("%s",spassword);
	f=strcmp(name,sname);
	e=strcmp(password,spassword);
    if(f==0)
	{
		if(e==0)
		{
			gotoxy(20,13);
			printf("Successfully logged");
		}
		else
		{
			gotoxy(20,22);
			printf("Incorrect password");
			Sleep(1000);
			goto LOGIN_FUNCTION;
		}
    }
   else
    {
		gotoxy(20,22);
		printf("Incorrect username or password");
		Sleep(1000);
		goto LOGIN_FUNCTION;
    }
	Sleep(700);
	system("cls");

    CLIENT_FUNCTION :
  
  box(18, 8, 60, 20);
  gotoxy(23, 11);
  printf("   CUSTOMER BILLING SYSTEM:\n\n");
  gotoxy(23, 12);
  printf("===============================\n");
  gotoxy(23, 13);
  printf("1:  Create NEW customer bill\n");
  gotoxy(23, 14);
  printf("2:  Create EXISTING customer bill\n");
  gotoxy(23, 15);
  printf("3:  Details on Basis\n");
  gotoxy(23, 16);
  printf("4:  EXIT\n");
  gotoxy(23, 17);
  printf("================================");
  do 
  {
	gotoxy(20, 18);
	printf("select what do you want to do?");
	ch = getche();
  } while (ch <= '0' || ch > '4');

  switch (ch) {
  case '1':
	system("cls");
	//fptr = fopen("cust.txt", "r+");
    fptr = fopen("cust.txt", "a+");
	box(18,8,60,20);
	gotoxy(20,11);
	printf("enter customer id :  ");
	scanf("%s", &temp_id);
	fptr1 = fopen("cust.txt", "r+");
	while (fread( &cust, sizeof(cust), 1, fptr1) > 0) 
	{
	  if (strcmp(cust.cust_id, temp_id) == 0) 
	  {
		gotoxy(20,18);
		printf("Customer found");
		Sleep(1000);
		fclose(fptr1);
		system("cls");
		goto MAIN_FUNCTION;
	  }
	}

    strcpy(cust.cust_id,temp_id);

	gotoxy(20,12);
	printf("enter customer name :  ");
	scanf("%s", &cust.name);
	gotoxy(20,13);
	printf("enter customer phone no.  ");
	scanf("%d", &cust.phn);
	gotoxy(20,14);
	printf("enter customer address :  ");
	scanf("%s", &cust.address);
	gotoxy(20,15);
    fwrite( & cust, sizeof(cust), 1, fptr);

	fclose(fptr);
    fclose(fptr1);
	system("cls");
	goto MAIN_FUNCTION;

    case '2':
	system("cls");
	box(18, 8, 60, 20);
	fptr = fopen("cust.txt", "r+");
	gotoxy(20, 14);
	printf("enter customer id:");
    fflush(stdin);
	scanf("%s", &temp_id);

	while (fread( & cust, sizeof(cust), 1, fptr) > 0); 
	{
	  if (strcmp(cust.cust_id, temp_id) == 0) 
	  {
		gotoxy(20,19);
		printf("Customer found");
		Sleep(1000);
		system("cls");
		goto MAIN_FUNCTION;
        fclose(fptr);
	  }
	}
    break;
	

    case '3':
	system("cls");
	box(18, 8, 60, 20);
	gotoxy(22, 12);
	printf("on the basis of  ::");
	gotoxy(22, 13);
	printf("1:  Customer ID");
	gotoxy(22, 14);
	printf("2:  Bill ID ");
	gotoxy(22, 15);
	printf("3:  Customer information");
	gotoxy(22, 16);
	printf("4:  Main interface");
	do 
    {
	  gotoxy(20, 18);
	  printf("select what do you want to do?\n");
	  ch1 = getche();
	} while (ch1 <= '0' || ch1 > '3');

    switch (ch1) 
    {
	case '1':
	  system("cls");
	  box(13, 8, 65, 20);
	  gotoxy(20, 13);
	  printf("Enter Customer ID:");
	  scanf("%s", temp_id);
	  fptr1 = fopen("cbs.txt", "r+");
	  while (fread( & blng, sizeof(blng), 1, fptr1) > 0) {
		if (strcmp(blng.cust_id, temp_id) == 0) {
		  system("cls");
		  gotoxy(20, 8);
		  printf("bills are:");
		  fptr1 = fopen("cbs.txt", "r+");
		  while (fread( & blng, sizeof(blng), 1, fptr1) > 0) {
			if (strcmp(temp_id, blng.cust_id)== 0) {
			box(13, 8, 65, 20);
			gotoxy(20, 9);
			printf("       Customer Billing System       \n");
			gotoxy(20, 10);
			printf("________________________________________\n");
			gotoxy(20, 11);
			printf("       Item_name  ==  %s", blng.a);
			gotoxy(20, 12);
			printf("       Price      ==  %d", blng.price);
			gotoxy(20, 13);
			printf("       Qty        ==  %d", blng.qty);
			gotoxy(20, 14);
			printf("       GST        ==  %d", blng.gst);
			gotoxy(20, 15);
			printf("       Total      ==  %d", blng.total3);
			gotoxy(20, 16);
			printf("_________________________________________\n");
			gotoxy(20, 17);
			printf(" Amount  %d", blng.total3);
			getch();
		  }
		 }
		}
	  }
      fclose(fptr1);
	  fclose(fptr1);
	  ch1 = getche();
	  system("cls");
	  goto CLIENT_FUNCTION ;

      case '2':
	  system("cls");
	  box(13, 8, 65, 20);
	  gotoxy(20, 13);
	  printf("Enter Bill ID:");
	  scanf("%s", temp_date);
	  fptr1 = fopen("cbs.txt", "r+");
	  while (fread( & blng, sizeof(blng), 1, fptr1) > 0) {
		if (strcmp(blng.bill_id, temp_date) == 0) {
		  system("cls");
		  gotoxy(20, 8);
		  printf("bills are:");
			box(13, 8, 65, 20);
			gotoxy(20, 9);
			printf("       Customer Billing System       \n");
			gotoxy(20, 10);
			printf("________________________________________\n");
			gotoxy(20, 11);
			printf("       Item_name  ==  %s", blng.a);
			gotoxy(20, 12);
			printf("       Price      ==  %d", blng.price);
			gotoxy(20, 13);
			printf("       Qty        ==  %d", blng.qty);
			gotoxy(20, 14);
			printf("       GST        ==  %d", blng.gst);
			gotoxy(20, 15);
			printf("       Total      ==  %d", blng.total3);
			gotoxy(20, 16);
			printf("_________________________________________\n");
			gotoxy(20, 17);
			printf(" Amount  %d", blng.total3);
			getch();
		  }
		}
		fclose(fptr1);
	  ch1 = getche();
	  system("cls");
	  goto CLIENT_FUNCTION ;

      case '3':
	system("cls");
	box(18,8,60,20);
	gotoxy(20,11);
    fflush(stdin);
	fptr1 = fopen("cust.txt", "r+");
	printf("enter customer id :  ");
	fflush(stdin);
	scanf("%s", &temp_id);
	//fptr1 = fopen("cust.txt", "r+");

	while (fread(&cust, sizeof(cust), 1, fptr1) >0) {
	  if (strcmp(cust.cust_id, temp_id) == 0) {
	box(18,8,60,20);
	gotoxy(9,10);
	printf("customer information  ::");
	gotoxy(20,12);
	printf(" Customer name :  %s ",cust.name);
	gotoxy(20,13);
	printf("Customer phone no. :  %d ",cust.phn);
	gotoxy(20,14);
	printf("Customer address :  %s ",cust.address);
	gotoxy(20,15);
    sleep(5);
	}
	}
	fclose(fptr1);
	//sleep(700);
	system("cls");
	goto CLIENT_FUNCTION;

    case '4':
	  system("cls");
	  Sleep(5);
	  //(BLACK);
	  gotoxy(25, 12);
	  printf("\nA PROJECT BY Dhruv and Saransh");
	  Sleep(1500);
	  system("cls");
	  goto CLIENT_FUNCTION ;

	}

   case '4' :
	  system("cls");
	  Sleep(700);
	  //(BLACK);
	  gotoxy(25, 12);
	  printf("\nA PROJECT BY Dhruv and Saransh");
	  Sleep(1500);
	  exit(1);

  }
   MAIN_FUNCTION:
  system("cls");
  box(5, 8, 70, 16);
  fptr = fopen("bill.txt", "w");
  fptr1 = fopen("cbs.txt", "a+");
  gotoxy(20, 9);
  strcpy(blng.cust_id, cust.cust_id);

  printf("Enter total no. of item = ");
  scanf("%d", & d);
  system("cls");
  box(5, 8, 70, 16);
  gotoxy(20, 9);
  printf("Bill ID (last bill id ) :  ");
  scanf("%s", & blng.bill_id);
  system("cls");
  box(5, 8, 70, 16);
  gotoxy(20, 9);
  printf("Date (dd/mm/yyy) :  ");
  scanf("%s", & blng.date);
  system("cls");
  blng.total3=0;
  int total4=0;
  for (b = 1; b <= d; b = b + 1) {
	box(5, 8, 70, 16);
	gotoxy(6, 9);
	printf("Bill ID : %s", blng.bill_id);
	gotoxy(20, 10);
	printf("\nEnter the name of item  =  ");
	scanf("%s", & blng.a);
	gotoxy(20, 11);
	printf("\nEnter the qty  =  ");
	scanf("%d", & blng.qty);
	gotoxy(20, 12);
	printf("\nEnter the price  =  ");
	scanf("%d", & blng.price);
	gotoxy(20, 13);
	printf("\nEnter gst percentage value  =  ");
	scanf("%d", & blng.gst);
    //blng.total3=0;
	//for (i = 0; i < d; i++) 
	//{
       //blng.total3=0;
	  total1 = blng.price * blng.qty;
	  gst1 = ((total1 * blng.gst)/100);
	  blng.total2 = total1 + gst1; 
      blng.total = blng.total2;
    blng.total3=0;
	blng.total3 = blng.total3 + blng.total;
	total4=total4+blng.total3;
	//}
	//blng.total = blng.total2;
    //blng.total3=0;
	//blng.total3 = blng.total3 + blng.total;

	fwrite( & blng, sizeof(blng), 1, fptr);
	fwrite( & blng, sizeof(blng), 1, fptr1);
	system("cls");
  }
  strcpy(cust.date, blng.date);
  //system("cls");
  fclose(fptr1);
  fclose(fptr);
  system("cls");
  fptr = fopen("bill.txt", "r+");
  
  while (fread( & blng, sizeof(blng), 1, fptr) > 0) {
	box(13, 8, 65, 20);
	gotoxy(20, 9);
	printf("       Customer Billing System       \n");
	gotoxy(20, 10);
	printf("________________________________________\n");
	gotoxy(20, 11);
	printf("       Item_name  ==  %s", blng.a);
	gotoxy(20, 12);
	printf("       Price      ==  %d", blng.price);
	gotoxy(20, 13);
	printf("       Qty        ==  %d", blng.qty);
	gotoxy(20, 14);
	printf("       GST        ==  %d", blng.gst);
	gotoxy(20, 15);
	printf("       Total      ==  %d", blng.total3);
	gotoxy(20, 16);
	printf("_________________________________________\n");
	gotoxy(20, 17);
	printf(" Amount  %d", blng.total3);
	getch();
  }
  fclose(fptr);
  remove("bill.txt");
  system("cls");
  box(13, 8, 65, 20);
  
  gotoxy(20, 9);
  printf("    SELECT MODE OF PAYMENT:\n");
  gotoxy(20, 10);
  printf("===============================\n");
  gotoxy(20, 11);
  printf("1:    CASH PAYMENT\n");
  gotoxy(20, 12);
  printf("2:    CARD PAYMENT\n");
  gotoxy(20, 13);
  printf("3:    ONLINE PAYMENT\n");
  
  gotoxy(20, 15);
  printf("========================\n");
  do {
	gotoxy(20, 16);
	printf("select what do you want to do?\n");
	ch = getche();
  } while (ch <= '0' || ch > '3');

  switch (ch) {
  case '1':
	system("cls");
	box(13, 8, 65, 20);
	gotoxy(20, 13);
	printf("Total BILL  ==  %d\n", total4);
	gotoxy(20, 14);
	printf("AMOUNT RECIEVED  == ");
	scanf("%d", & ar);
	ra = ar - total4;
	ba = blng.total3 - ar;
	gotoxy(20, 16);
	if (ar >= total4) {
	  printf("Return amount  == %d\n", ra);
	} else {
	  printf("Balance amount  == %d\n", ba);
	}
	getch();
      Sleep(700);
	system("cls");
	fptr1 = fopen("pay.txt", "a+");
	gotoxy(20, 18);
	printf("      Thankyou! Do visit again...!\n");
	Sleep(700);
	system("cls");
	goto CLIENT_FUNCTION ;

    case '2':
	system("cls");
	box(13, 8, 65, 20);
	gotoxy(20, 13);
	printf("Total BILL  ==  %d\n", total4);
	gotoxy(20, 14);
	printf("Enter name on card == ");
	scanf("%s", & pay.noc);
	gotoxy(20, 15);
	printf("Enter Transaction id == ");
	scanf("%s", & pay.ti);
	gotoxy(20, 16);
	printf("Enter amount recieved == ");
	scanf("%d", & pay.ar);
	system("cls");
	Sleep(700);
	gotoxy(20, 18);
	printf("      Thankyou! Do visit again...!\n");
	gotoxy(20, 23);
	printf("PRESS (ENTER) for exit");
	ch = getche();
	system("cls");
	goto CLIENT_FUNCTION ;

    case '3':
	system("cls");
	box(13, 8, 65, 20);
	//(BLACK);
	gotoxy(20, 13);
	printf("Total BILL  ==  %d\n", total4);
	gotoxy(20, 14);
	printf("select mode of payment\n");
	gotoxy(20, 15);
	printf("1. PAYTM\n");
	gotoxy(20, 16);
	printf("2. UPI PAYMENT\n");
	gotoxy(20, 17);
	printf("3. ANY OTHER\n");
	do {
	  gotoxy(20, 18);
	  printf("select what do you want to do?\n");
	  ch1 = getche();
	} while (ch1 <= '0' || ch1 > '3');

	switch (ch1)
 {
		case '1':
	  	system("cls");
	  	box(13, 8, 65, 20);
	  	//(BLACK);
	  	gotoxy(20, 13);
	  	printf("Total BILL  ==  %d\n", total4);
	  	gotoxy(20, 14);
	  	printf("present number displayed in customer phone\n");
	  	gotoxy(20, 15);
	  	printf("----------------9999819773--------------\n");
	  	gotoxy(20, 16);
	  	printf("Enter Transaction id == ");
	  	scanf("%s", & pay.ti);
	  	gotoxy(20, 17);
	  	printf("AMOUNT RECIEVED  == ");
	  	scanf("%d", & pay.ar);
	  	system("cls");
	  	Sleep(700);
	  	gotoxy(20, 18);
	  	printf("      Thankyou! Do visit again...!\n");
	  	gotoxy(20, 23);
	  	printf("\nPRESS (ENTER) for exit");
	  	ch1 = getche();
	  	system("cls");
	  	goto CLIENT_FUNCTION ;
	
case '2':
	  system("cls");
	  box(13, 8, 65, 20);
	  gotoxy(20, 13);
	  printf("Total BILL  ==  %d\n", total4);
	  gotoxy(18, 14);
	  printf("Enter id displayed on screen to  customer's phone\n");
	  gotoxy(20, 15);
	  printf("            dhruv1_@_9999819773          \n");
	  gotoxy(20, 16);
	  printf("Enter Transaction id == ");
	  scanf("%s", & pay.ti);
	  gotoxy(20, 17);
	  printf("AMOUNT RECIEVED  == ");
	  scanf("%d", & pay.ar);
	  system("cls");
	  gotoxy(20, 18);
	  printf("      Thankyou! Do visit again...!\n");
	  gotoxy(20, 23);
	  printf("PRESS (ENTER) for exit\n");
	  ch1 = getche();
	  system("cls");
	  goto CLIENT_FUNCTION ;

      case '3':
	  system("cls");
	  box(13, 22, 65, 25);
	  gotoxy(20, 13);
	  printf("Total BILL  ==  %d\n", total4);
	  gotoxy(20, 14);
	  printf("present number displayed in customer phone\n");
	  gotoxy(20, 15);
	  printf("                      \n");
	  gotoxy(20, 16);
	  printf("Enter Transaction id == ");
	  scanf("%s", & pay.ti);
	  gotoxy(20, 17);
	  printf("AMOUNT RECIEVED  == ");
	  scanf("%d", & pay.ar);
	  fwrite( & pay, sizeof(pay), 1, fptr);
	  fclose(fptr1);
	  system("cls");
	  Sleep(700);
	  gotoxy(20, 18);
	  printf("      Thankyou! Do visit again...!\n");
	  gotoxy(20, 23);
	  printf("\nPRESS (ENTER) for exit");
	  ch1 = getche();
	  system("cls");
	  goto CLIENT_FUNCTION ;
	}
	getch();
  }
  return 0;
}