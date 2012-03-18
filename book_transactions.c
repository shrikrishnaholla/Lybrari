#include "headers.h"

void book_trans(void)
{
	FILE *ml;
	struct member mem;
	int ch;
	int choice=1;
	long int mem_id,bk_id;
	printf("\nEnter the member ID please: ");
	scanf("%ld",&mem_id);
	ml=fopen("Member_list.txt","r+");
	if(feof(ml))
	{
		printf("\nThe member list is empty. Books are but pieces of scrap without readers. So please add members to continue.");
		return;
	}
	if(mem_id==1) fread(&mem,sizeof(struct member),1,ml);
	else
	{
		while(!feof(ml))
		{
			fread(&mem,sizeof(struct member),1,ml);
			if(mem.id==mem_id) break;
		}
	}
	if(mem.status==0)
	{
		printf("\nSorry, but your account no longer exists. Join again to enjoy the previleges of this library");
		return;
	}	
	printf("\nWelcome %s",mem.name);
	do
	{
		printf("\n1: Apply for a book\n2: Return a book\n3: Renew a book\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				apply_book(&mem);
				break;
			case 2:
				printf("\nEnter the ID of the book to be returned: ");
				scanf("%ld",&bk_id);
				return_book(&mem,bk_id);
				break;
			case 3:
				printf("\nEnter the ID of the book to be renewed: ");
				scanf("%ld",&bk_id);
				renew_book(&mem,bk_id);
				break;
			default:
				printf("\nWrong option! Give a choice between 1 and 3");
		}
		printf("\nDo you want to make another operation? [1/0]: ");
		scanf("%d",&choice);
	}while(choice==1);
	if(mem_id==1) fwrite(&mem,sizeof(struct member),1,ml);
	else
	{
		fseek(ml,(sizeof(struct member)*(mem_id-1)),SEEK_SET);
		fwrite(&mem,sizeof(struct member),1,ml);
	}
	fclose(ml);
	printf("\nThank you");
}
