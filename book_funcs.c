#include "headers.h"

void apply_book(struct member *m)
{
	FILE *bk;
	struct book_list b;
	int i;
	long int bk_id;
	if((m)->books_applied==3)
	{
		printf("\nYour limit for number of books has reached. Please return one of the books to apply for more");
		printf("\nBook ID of the Library books currently in your possession");
		for(i=0;i<3;i++) printf("\n%ld",(m)->applied_books[i]);
		return;
	}
	printf("\nEnter the ID number of the book you want to apply for: ");
	scanf("%ld",&bk_id);
	bk=fopen("Book_list.txt","r+");
	if((bk))
	{
		fseek(bk, 0, SEEK_END);
		if (ftell(bk) == 0)
		{	
			printf("\nThe book list is empty. Please request the library incharge to buy books immediately");
			return;
		}
	}
	fclose(bk);
	bk=fopen("Book_list.txt","r+");
	if(bk_id==1) fread(&b,sizeof(struct book_list),1,bk);
	else
	{
		fseek(bk,((sizeof(struct book_list))*(bk_id+1)),SEEK_SET);
		fread(&b,sizeof(struct book_list),1,bk);
	}
	if((b.book_id!=bk_id)||(b.status==0))
	{
		printf("\nThe book you requested for doesn't exist or has been deleted. Sorry for the inconvenience");	
		return;
	}
	if(b.availability==0)
	{
		printf("\nAll copies of the requested book \"%s\" have been issued. Better luck next time. :)",b.name);
		return;
	}
	i=0;
	while((i<3)&&((m)->applied_books[i]!=0)) i++;
	(m)->applied_books[i]=bk_id;
	b.availability--;
	(m)->books_applied++;
	due_date(&((m)->return_dates[i]));
	printf("\n%s has applied for the book \"%s\" which has to be returned on %d-%d-%d",m->name,b.name,m->return_dates[i].dd,m->return_dates[i].mm,m->return_dates[i].yy);
	printf("\nThe books in possession are");
	for(i=0;i<3;i++) printf("\n%ld",m->applied_books[i]);
	printf("\n%s has %d library books in his possession now",m->name,m->books_applied);
	printf("\n%d copies of the book are left in the library now",b.availability);
	if(bk_id==1) fwrite(&b,sizeof(struct book_list),1,bk);
	else
	{
		while(bk) if(b.book_id==bk_id) break;
		fwrite(&b,sizeof(struct book_list),1,bk);
	}
	fclose(bk);
}

void return_book(struct member *m, long int bk_id)
{
	FILE *bk;
	struct book_list b;
	int bk_days,fine=0,i=0;
	while(i<3&&(((m)->applied_books[i])!=bk_id)) i++;
	if(i==3)
	{
		printf("\nThe said book hasn't been applied for");
		return;
	}
	bk=fopen("Book_list.txt","r+");
	if(bk_id==1) fread(&b,sizeof(struct book_list),1,bk);
	else
	{

		while(bk)
		{
			fread(&b,sizeof(struct book_list),1,bk);
			if(b.book_id==bk_id) break;
		}
	}	
	b.availability++;
	bk_days=difference((m)->return_dates[i]);
	(m)->applied_books[i]=(long int)0;
	m->books_applied--;
	if(bk_days>15)
	{
		fine=bk_days-15;
		(m)->account+=fine;
		printf("\nA fine of Rs. %d is to be levied for late submission", fine);
		printf("\nTotal dues of the member amount to %d",(m)->account);
	}
	printf("\n\"%s\" has been returned to the library",b.name);
	fclose(bk);
	bk=fopen("Book_list.txt","r+");
	if(bk_id==1) fwrite(&b,sizeof(struct book_list),1,bk);
	else
	{
		while(bk)
		{
			fread(&b,sizeof(struct book_list),1,bk);
			if(b.book_id==bk_id) break;
		}
		fwrite(&b,sizeof(struct book_list),1,bk);
	}
	fclose(bk);
}

void renew_book(struct member *m, long int bk_id)
{
	int bk_days,fine=0,i=0;
	while((i<3)&&(((m)->applied_books[i]!=bk_id)))	i++;
	if(i==3)
	{
		printf("\nThe book hasn't been applied for");
		return;
	}
	bk_days=difference((m)->return_dates[i]); 
	if(bk_days>15)
	{
		fine=bk_days-15;
		(m)->account+=fine;
		printf("\nA fine of Rs. %d is to be levied for late submission", fine);
		printf("\nTotal dues of the member amount to %d",(m)->account);
	}
	due_date(&((m)->return_dates[i])); 
	printf("\nThe book has been renewed\nThe revised return date is %d-%d-%d",m->return_dates[i].dd,m->return_dates[i].mm,m->return_dates[i].yy);
}
