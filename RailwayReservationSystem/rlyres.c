#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
int enterchoice()
{
int choice,i;
textcolor(14);
gotoxy(28,1);
printf("RAILWAY RESERVATION SYSTEM\n");
for(i=0;i<=74;i++)
    printf("-");
printf("\nSelect an option\n1- View Trains\n2- Book Tickets\n3- View Ticket\n4- Search Ticket No\n5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- Quit\n\nEnter choice:");
scanf("%d",&choice);
return choice;
}
void add_trains()
{
FILE *fp;
fp=fopen("D:\\c_project\\alltrains.dat","rb");
if(fp==NULL)
{
    Train alltrains[4]={{"123","BPL","GWA",2100,1500},{"546","BPL","DEL",3500,2240},{"345","HBJ","AGR",1560,1135},{"896","HBJ","MUM",4500,3360}};
    fp=fopen("D:\\c_project\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(Train),1,fp);
    //printf("File Saved successfully\n");
    fclose(fp);
}
else{
     //printf("File already present..!!");
     fclose(fp);
}
}
void view_trains()
{
    system("cls");
    FILE *fp=fopen("D:\\c_project\\alltrains.dat","rb");
    if(fp==NULL)
    {}
    int i;
    printf("TRAIN NO\tFROM\t\tTO \t FIRST AC FAIR \t SECOND AC FAIR\n");
    for(i=0;i<=74;i++)
       printf("-");
    Train s;
    while(fread(&s,sizeof(s),1,fp)==1)
    {
      printf("\n%s\t\t%s\t\t%s \t  %d \t \t %d",s.train_no,s.from,s.to,s.fac_fare,s.sac_fare);
    }
    textcolor(WHITE);
    printf("\n\n\nPress any key for main menu");
    textcolor(YELLOW);
    _getch();
    system("cls");
}
int check_train_no(char* tno)
{
FILE *fp=fopen("D:\\c_project\\alltrains.dat","rb");
if(fp==NULL)
{}
Train tr;
while(fread(&tr,sizeof(tr),1,fp)==1)
{
    if(strcmp(tr.train_no,tno)==0)
    {
        fclose(fp);
        return 1;
    }
}
fclose(fp);
return 0;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
     return 0;
    while(*p_mob!='\0')
    {
     if(isdigit(*p_mob)==0)
      return 0;
     p_mob++;
    }
    return 1;
}
Passenger* get_passenger_details()//Because,it return NULL when user cancel the booking.
{
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name :");
    static Passenger p;
    fflush(stdin);
    fgets(p.p_name,20,stdin);//append \n in the end.
    char *pos=strchr(p.p_name,'\n');
    *pos='\0';
    if(strcmp(p.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
    }
    printf("Enter your gender(M/F) :");
    int valid;
    do
    {
    valid=1;
    scanf(" %c",&p.gender);
    if(p.gender=='0')
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
         printf("\t\t\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
    }
    if(p.gender!='M'&&p.gender!='F')
    {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("Error! Gender should be M or F(in uppercase)");
      valid=0;
      _getch();
      gotoxy(25,2);
      printf(" \b");
      textcolor(14);
    }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number:");
    do
    {
    scanf(" %s",p.train_no);
    valid=1;
    if(strcmp(p.train_no,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        printf("\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
    }
    valid=check_train_no(p.train_no);
    if(valid==0)
    {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("ERROR!Invalid Train No");
      _getch();
      gotoxy(20,3);
      printf("\t\t\t\t\t\t\t");
      gotoxy(20,3);
      textcolor(14);
    }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(First AC-F Second AC-S):");
    do
    {
      scanf(" %c",&p.tclass);
      valid=1;
     if(p.tclass=='0')
     {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        printf("\t\t\t\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
     }
     if(p.tclass!='F'&&p.tclass!='S')
     {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("Error!Travelling class should be F or S(in uppercase)");
      valid=0;
      _getch();
      gotoxy(48,4);
      printf("     \b\b\b\b\b");
      textcolor(14);
     }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address:");
    fflush(stdin);
    fgets(p.add,20,stdin);
    char *pos1=strchr(p.add,'\n');
    *pos1='\0';
    if(strcmp(p.add,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        printf("\t\t\t\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
    }
    printf("Enter your age :");
    do
    {
    scanf("%d",&p.age);
    valid=1;
    if(p.age==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        printf("\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
    }
    if(p.age<0)
    {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("Invalid age..!!");
      valid=0;
      _getch();
      gotoxy(17,6);
      printf("   \b\b\b");
      textcolor(14);
    }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t");
    gotoxy(1,7);
    printf("Enter Mobile number:");
    do
    {
      fflush(stdin);
      fgets(p.mob_no,12,stdin);
      char *pos2=strchr(p.mob_no,'\n');
      if(pos2!=NULL)//Bahut Jaruri h nhi toh code crush kr jayega
      *pos2='\0';
      if(strcmp(p.mob_no,"0")==0)
      {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        printf("\t\t");
        _getch();
        system("cls");
        textcolor(14);
        return NULL;
      }
      valid=check_mob_no(p.mob_no);
      if(valid==0)
      {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("ERROR!Invalid Mobile number");
      _getch();
      gotoxy(21,7);
      printf("\t\t\t\t");
      gotoxy(21,7);
      textcolor(14);
      }
    }while(valid==0);
    return &p;
}
int get_booked_ticket_count(char *tno,char tclass)
{
FILE *fp=fopen("D:\\c_project\\allbooks.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,tno)==0 && pr.tclass==tclass)
        ++count;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
FILE *fp=fopen("D:\\c_project\\allbooks.dat","rb");
    if(fp==NULL)
     return 0;
    Passenger p;
    fseek(fp,-1*sizeof(p),SEEK_END);
    fread(&p,sizeof(p),1,fp);
    fclose(fp);
    return p.ticketno;
}
int book_ticket(Passenger p)
{
int ticket_no=get_booked_ticket_count(p.train_no,p.tclass);
if(ticket_no==2)
{
    textcolor(LIGHTRED);
    printf("All Seats full in train no %s in %c class!",p.train_no,p.tclass);
    return -1;
}
p.ticketno=last_ticket_no()+1;
FILE *fp=fopen("D:\\c_project\\allbooks.dat","ab+");
fwrite(&p,sizeof(p),1,fp);
fclose(fp);
return p.ticketno;
}
int accept_ticket_no()
{
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
printf("Enter ticket no:");
int valid,ticket_no;
    do
    {
    scanf("%d",&ticket_no);
    valid=1;
    if(ticket_no==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t");
        gotoxy(1,25);
        printf("Cancelling input...!!");
        textcolor(YELLOW);
        return 0;
    }
    if(ticket_no<0)
    {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("Error!Invalid Ticket number should be positive");
      valid=0;
      _getch();
      gotoxy(17,1);
      printf("\t\t\t\t");
      gotoxy(17,1);
      textcolor(14);
    }
    }while(valid==0);
}
void view_ticket(int tno)
{
FILE *fp=fopen("D:\\c_project\\allbooks.dat","rb");
if(fp==NULL)
{
        textcolor(LIGHTRED);
        printf("ERROR!Invalid Ticket no");
        return;
}
Passenger p;
int found=0;
while(fread(&p,sizeof(p),1,fp)==1)
{
   if(p.ticketno==tno)
        {
        printf("\nName     : %s\nGender   : %c\nTrain no : %s\nClass    : %c\nAddress  : %s\nAge      : %d\nMobile no: %s",p.p_name,p.gender,p.train_no,p.tclass,p.add,p.age,p.mob_no);
        found =1;
        textcolor(WHITE);
        printf("\nPress any key to go back to the main screen");
        break;
        }
}
if(!found)
{
    textcolor(2);
    printf("\nNo details of ticket no %d found!",tno);
}
fclose(fp);
}
void view_all_bookings()
{
FILE *fp=fopen("d:\\c_project\\allbooks.dat","rb");
if(fp==NULL)
{

}
Passenger pr;
int i;
printf("TRAIN NO  TICKET NO CLASS  NAME\t\t\tMOBILE\t    GENDER  AGE\n");
for(i=0;i<=74;i++)
       printf("-");
i=3;
while(fread(&pr,sizeof(pr),1,fp)==1)
    {
    printf("\n%s \t  %d\t    %c      %s",pr.train_no,pr.ticketno,pr.tclass,pr.p_name);
    gotoxy(49,i);
    printf("%s  %c       %d",pr.mob_no,pr.gender,pr.age);i++;
    }
fclose(fp);
}
int cancel_ticket(int tno)
{
 FILE *fp1=fopen("d:\\c_project\\allbooks.dat","rb+");
  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2=fopen("d:\\c_project\\temp.dat","wb+");
  Passenger pr;
  int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(pr.ticketno!=tno)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\c_project\\temp.dat");
    }
    else
    {
        remove("d:\\c_project\\allbooks.dat");
        rename("d:\\c_project\\temp.dat","d:\\c_project\\allbooks.dat");
    }
return found;
}
char* accept_train_no()
{
static char train_no[10];
int valid;
gotoxy(60,1);
textcolor(LIGHTGREEN);
printf("Press 0 to exit");
gotoxy(1,1);
textcolor(YELLOW);
printf("Enter train number:");
            do
            {
            scanf(" %s",train_no);
            if(strcmp(train_no,"0")==0)
             {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelling Input. . .!");
                textcolor(YELLOW);
                return NULL;
             }
            valid=check_train_no(train_no);
            if(valid==0)
             {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("Error! Invalid Train No");
             _getch();
             gotoxy(20,1);
             printf("\t\t\t\t\t\t");
             gotoxy(20,1);
             textcolor(YELLOW);
             }
            }while(valid==0);
  system("cls");
return train_no;
}
int cancel_train(char *ptrain_no)
{
  FILE *fp1=fopen("D:\\c_project\\allbooks.dat","rb+");
  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet.!!");
        return -1;
    }
  FILE *fp2=fopen("D:\\c_project\\temp.dat","wb+");
  Passenger pr;
  int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(strcmp(pr.train_no,ptrain_no)!=0)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("D:\\c_project\\temp.dat");
    }
    else
    {
        remove("D:\\c_project\\allbooks.dat");
        rename("D:\\c_project\\temp.dat","d:\\c_project\\c_books.dat");
    }
return found;
}
char* accept_mob_no()
{
static char mob_no[10];
int valid;
printf("Enter mobile number:");
            do
            {
            scanf(" %s",mob_no);
            if(strcmp(mob_no,"0")==0)
             {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelling Input. . .!");
                textcolor(YELLOW);
                return NULL;
             }
            valid=check_mob_no(mob_no);
            if(valid==0)
             {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("Error! Invalid Mobile No");
             _getch();
             gotoxy(20,1);
             printf("\t\t\t\t\t\t");
             gotoxy(20,1);
             textcolor(YELLOW);
             }
            }while(valid==0);
  system("cls");
return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
int count=0;
FILE *fp=fopen("d:\\c_project\\allbooks.dat","rb");
   if(fp==NULL)
    {
      return NULL;
    }
   Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticketno;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}
void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        _getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
_getch();
}
void view_booking(char *tno)
{
FILE *fp=fopen("D:\\c_project\\allbooks.dat","rb");
if(fp==NULL)
{
        textcolor(LIGHTRED);
        printf("ERROR!Invalid Ticket no");
        return;
}
Passenger p;
int found=0,i;
printf("TICKET NO   CLASS  NAME\t\t\tMOBILE\t    GENDER  AGE\n");
for(i=0;i<=74;i++)
       printf("-");
i=3;
while(fread(&p,sizeof(p),1,fp)==1)
    {
    if(strcmp(tno,p.train_no)==0)
    {
    printf("\n%d\t    %c\t   %s",p.ticketno,p.tclass,p.p_name);
    gotoxy(41,i);
    printf("%s  %c\t    %d",p.mob_no,p.gender,p.age);i++;
    found=1;
    }
    }
if(!found)
{
    textcolor(2);
    printf("\nNo details of ticket no %s found!",tno);
}
fclose(fp);
}
