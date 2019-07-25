#include <stdio.h>
#include <stdlib.h>
#include"rlyres.h"
#include"conio2.h"
int main()
{
    add_trains();
    Passenger *ptr;
    int ticket_no,result,ptrain_no,pmob_no,pticket_no,train_no;
    while(1){
    int choice=enterchoice();
    if(choice==9)
        exit(0);
    switch(choice)
     {
    case 1:
    view_trains();
    break;
    case 2:
    system("cls");
    ptr=get_passenger_details();
    system("cls");
    if(ptr!=NULL)
    {
     int booktno=book_ticket(*ptr);
     if(booktno!=-1)
     {
     textcolor(2);
     printf("Ticket Successfully booked! \nTicket no : %d",booktno);
     }
     else
     {
        textcolor(4);
        printf("\nBooking Failed!");
     }
     _getch();
     system("cls");
    }
    break;
    case 3:
    system("cls");
    ticket_no=accept_ticket_no();
    if(ticket_no!=0)
    view_ticket(ticket_no);
    _getch();
    system("cls");
    break;
    case 4:
    system("cls");
    pmob_no=accept_mob_no();
     if(pmob_no!=NULL)
      {
       pticket_no=get_ticket_no(pmob_no);
       view_all_tickets(pmob_no,pticket_no);
      }
    system("cls");
    break;
    case 5:
    system("cls");
    view_all_bookings();
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    _getch();
    system("cls");
    break;
    case 6:
    system("cls");
      train_no=accept_train_no();
      if(train_no!=NULL)
      {
          int t=check_train_no(train_no);
          if(t==1)
          view_booking(train_no);
      }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    _getch();
    system("cls");
    break;
    case 7:
        system("cls");
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                {
                    result=cancel_ticket(ticket_no);
                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked against ticket no %d",ticket_no);

                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Ticket no %d successfully cancelled!",ticket_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");
             }
            _getch();
     system("cls");
    break;
    case 8:
        system("cls");
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            {
                result=cancel_train(ptrain_no);
                if(result==0)
                  {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked in train no %s",ptrain_no);
                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no %s successfully cancelled!",ptrain_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");
            }
            _getch();
        system("cls");
    break;
    default:
        textcolor(LIGHTRED);
        printf("Please input correct option.!!");
        _getch();
        system("cls");
      }
    }
    return 0;
}
