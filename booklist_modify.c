#include "headers.h"

void addbook(void)
{
	FILE *bk;
	struct book_list b,nb;
	printf("\nEnter the name of the book [In a single word, without spaces]: ");
	scanf("%s",nb.name);
	printf("\nEnter the number of copies bought: ");
	scanf("%d",&nb.no_of_copies);
	nb.availability=nb.no_of_copies;
	bk=fopen("Book_list.txt","a+");
	b.book_id=(long int)0;
	while(!feof(bk)) fread(&b,sizeof(struct book_list),1,bk);
	nb.book_id=b.book_id+1;
	nb.status=1;
	fwrite(&nb,sizeof(struct book_list),1,bk);
	printf("\nThe book \"%s\" has been added\nIt's ID no is %ld\nAt present, %d copies of this book are available",nb.name,nb.book_id,nb.availability);
	fclose(bk);
}

void delbook(long int b_id)
{
	FILE *bk;
	struct book_list b;
	bk=fopen("Book_list.txt","r+");
	if(bk==NULL) printf("\nNo book left to delete");
	else
	{
		while(!feof(bk)) fread(&b,sizeof(struct book_list),1,bk);
		if(b.book_id<b_id)
		{
			printf("\nThe specified book ID doesn't exist");
			return;
		}
		fclose(bk);
		bk=fopen("Book_list.txt","r+");
		if(b_id==1) fread(&b,sizeof(struct book_list),1,bk);
		else
		{
			fseek(bk,(sizeof(struct book_list)*(b_id-1)),SEEK_SET);
			fread(&b,sizeof(struct book_list),1,bk);
		}
		if(b.status==0) printf("\nThe book has already been deleted");
		else
		{
			printf("\nThe book \"%s\" has been deleted",b.name);
			b.name[0]='\0';
			b.no_of_copies=0;
			b.availability=0;
			b.status=0;
		}
		fclose(bk);
		bk=fopen("Book_list.txt","r+");
		if(b_id==1) fwrite(&b,sizeof(struct book_list),1,bk);
		else
		{
			fseek(bk,(sizeof(struct book_list)*(b_id-1)),SEEK_SET);
			fwrite(&b,sizeof(struct book_list),1,bk);
		}
	}
}

