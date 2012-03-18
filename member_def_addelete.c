#include "headers.h"

void insert_member(void)
{
	FILE *ml;
	int i;
 	struct member m,temp;
	ml=fopen("Member_list.txt","a+");
	temp.id=(long int)0;
	while(!feof(ml)) fread(&temp,sizeof(struct member),1,ml);
	printf("\nEnter the name of the new member [First name only, no spaces]: ");
	scanf("%s",m.name);
	m.account=0;
	m.status=1;
	m.id=(temp.id)+1;
	for(i=0;i<3;i++) m.applied_books[i]=(long int)0;
	printf("\nNew member added successfully!!\nMember name is: %s\nMember's ID is %ld",m.name,m.id);
	fwrite(&m,sizeof(struct member),1,ml);
	fclose(ml);
}


void delete_member(long int ID)
{
	FILE *ml;
	struct member m;
	int ch;
	ml=fopen("Member_list.txt","r+");
	if(ID==1) fread(&m,sizeof(struct member),1,ml);
	else
	{
		fseek(ml,(sizeof(struct member)*(ID-1)),SEEK_SET);
		fread(&m,sizeof(struct member),1,ml);
	}
	if(m.status==0) printf("\nThis record has already been deleted");
	else
	{
		printf("\nAre you sure you want to terminate %s's membership? [1/0]: ",m.name);
		scanf("%d",&ch);
		if(ch==1)
		{
			m.name[0]='\0';
			printf("\nThe member's final dues amount to Rs.%d.",m.account);
			m.account=0;
			m.status=0;
			if(ID==1) fwrite(&m,sizeof(struct member),1,ml);
			else
			{
				fseek(ml,(sizeof(struct member)*(ID-1)),SEEK_SET);
				fwrite(&m,sizeof(struct member),1,ml);
			}
			printf("\nRecord successfully deleted");
		}
	}
	fclose(ml);
}

