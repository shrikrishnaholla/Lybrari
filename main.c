#include "headers.h"

int main()
{
	int ch1,ch2,ch3=1;
	long int ids;
	printf("\nWelcome to Lybrari!!\nThis simple library management software is a part of our project to demonstrate the working of the make utility.\n\nMenu:\n****\nPlease select one of the following options\n");
	do
	{
		printf("1: Add/Delete a member\n2: Add/Remove a book from the library\n3: Book Transactions\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
				printf("\nSubmenu:\n*******\n1: Add a member\n2: Delete a member\n");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						insert_member();
						break;
					case 2:
						printf("\nEnter the ID of the member to be deleted: ");
						scanf("%ld",&ids);
						delete_member(ids);
						break;
					default: printf("\nWrong input!! Please enter options 1 or 2");
				}
				break;
			case 2:
				printf("\nSubmenu:\n*******\n1: Add a book\n2: Remove a book\n");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						addbook();
						break;
					case 2:
						printf("\nEnter the ID of the book to be deleted: ");
	                                        scanf("%ld",&ids);
						delbook(ids);
						break;
					default: printf("\nWrong input!! Please enter options 1 or 2");
				}
				break;
			case 3:
				book_trans();
				break;
			default: printf("\nWrong choice!! Enter a n option between 1 and 3");
		}
		printf("\nDo you want to continue? [1/0]: ");
		scanf("%d",&ch3);
	}while(ch3==1);
}
