#ifndef HEADERS_H
#define HEADERS_H 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Structure definitions
struct date
{
	int dd,mm,yy;
};


struct member
{
	long int id;
	char name[20];
	int account;
	int books_applied;
	long int applied_books[3];
	struct date return_dates[3];
	int status;
};

struct book_list
{
	char name[20];
	long int book_id;
	int no_of_copies;
	int availability;
	int status;
};


//function prototypes

void insert_member(void);
void delete_member(long int);

void addbook(void);
void delbook(long int);

int isleap(int);
void due_date(struct date *);
int difference(struct date);

void book_trans(void);

void apply_book(struct member *);
void return_book(struct member *, long int);
void renew_book(struct member *, long int);



#endif
