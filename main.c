#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct contact{
	char fname[35];
	char lname[35];
	char mobile_no[10];
	char tag[25];
};
void search_menu();
void add_contact();
void search();
int main(){
	int choice;
	while(1){
		printf("-------------------------------------------------------------\n");
		printf("-------------------------------------------------------------\n");
		printf("********WELCOME TO PHONEBOOK DIRECTORY********\n");
		printf("\t\t***MENU***\n");
		printf("1.ADD NEW");
		printf("\t2.TAGS");
		printf("\t3.MODIFY");
		printf("\t4.SEARCH\n");
		printf("5.DELETE");
		printf("\t6.VIEW");
		printf("\t7.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Add New contact now:\n");
				add_contact();
				break;
			case 4:
				search();
				break;
				
			//other cases to be added
	}
}
	return 0;
}
// A utility function to add new contact into the phone directory
void add_contact(){
	system("cls");
	FILE* fp;
	fp=fopen("project1","ab+");
	struct contact p;
	printf("Enter first name: ");
	scanf("%s",&p.fname);
	printf("Enter last name: ");
	scanf("%s",&p.lname);
	printf("Enter mobile number: ");
	scanf("%s",&p.mobile_no);
	printf("Enter TAG: ");
	scanf("%s",&p.tag);
	fwrite(&p,sizeof(p),1,fp);
	fflush(stdin);
	printf("Successfully saved the record\n");
	fclose(fp);
	system("cls");
}

//A utility function to search for a contact in the directory
void search(){
	FILE *fp;
	struct contact temp;
	char phone[10];
	int c,flag=0;
	fp=fopen("project1","rb");
	if(fp==NULL){
		printf("\nError in opening\n");
		exit(1);
	}
	printf("1.Search by name\n2.Search by Phone number\n");
	scanf("%d",&c);
	if(c==1){
	char fname[30],lname[30];		
	printf("Enter the name to be searched for:\n");
	printf("Enter first name: ");
	scanf("%s",&fname);
	printf("Enter last name: ");
	scanf("%s",&lname);	
	while(fread(&temp,sizeof(temp),1,fp)==1){
		
		if(strcmp(strlwr(temp.fname),strlwr(fname))==0&&strcmp(strlwr(temp.lname),strlwr(lname))==0){
			flag=1;
			printf("\nDetail information about %s",fname);
			printf("First name: %s\nLast name: %s\nMobile number: %s\n",temp.fname,temp.lname,temp.mobile_no);
				break;
			}
		}
		if(flag==0) printf("\nSearch not found\n");
		fclose(fp);
	}
	else if(c==2){
		printf("Enter phone number to search: ");
		scanf("%s",&phone);
		while(fread(&temp,sizeof(temp),1,fp)==1){
			if(strcmp(phone,temp.mobile_no)==0){
				flag=1;
				printf("\n\nDetail information about %s",phone);
				printf("\n\nFirst name: %s\nLast name: %s\nMobile number: %s\n",temp.fname,temp.lname,temp.mobile_no);
				break;
			}
		}
		if(flag==0) printf("\nSearch not found\n");
		fclose(fp);
	}
	else{
		printf("Wrong Choice!!\nPress any key to continue");
		getch();
		system("cls");
	}
}
