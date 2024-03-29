#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
char train_no[20];
char from[25];
char to[20];
int fac_fare;
int sac_fare;
};
typedef struct Train Train;
struct Passenger
{
 char p_name[20];
 char gender;
 char train_no[20];
 char mob_no[20];
 char add[30];
 char tclass;
 int age;
 int ticketno;
};
typedef struct Passenger Passenger;
int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
int* get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_booking(char*);
int cancel_ticket(int);
int cancel_train(char*);
Passenger* get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
int accept_ticket_no();
char* accept_train_no();
char* accept_mob_no();
void view_all_tickets(char*,int*);
#endif // RLYRES_H_INCLUDED
