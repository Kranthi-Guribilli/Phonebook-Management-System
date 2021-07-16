#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct contact{
	char fname[35];
	char lname[35];
	char mobile_no[25];
	char tag[25];
};
void add_contact();
void search();
void delete_record();
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
			case 5:
				delete_record();
				break;
			default:
                system("cls");
                printf("\nEnter 1 to 6 only!");
                printf("\nEnter any key to continue!!\n");
                getch();
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
	printf("Enter Mobile number: ");
	scanf("%s",&p.mobile_no);
	printf("Enter tag: ");
	scanf("%s",&p.tag);
	fwrite(&p,sizeof(p),1,fp);
	fflush(stdin);
	printf("Successfully saved the record\n");
	fclose(fp);
	printf("Enter any key to continue.");
	getch();
    system("cls");
}

//A utility function to search for a contact in the directory
void search(){
	FILE *fp;
	struct contact temp;
	int c,flag=0;
	fp=fopen("project1","rb");
	if(fp==NULL){
		printf("\nError in opening\n");
		exit(1);
	}
	printf("\n***SEARCH MENU***\n");
	printf("1.Search by name\n2.Search by Phone number\n");
	printf("Enter your choice: ");
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
			printf("\nDetail information about %s\n",fname);
			printf("First name: %s\nLast name: %s\nMobile number: %s\nTag: %s\n",temp.fname,temp.lname,temp.mobile_no,temp.tag);
				break;
			}
		}
		if(flag==0) printf("\nSearch not found\n");
		fclose(fp);
	}
	else if(c==2){
		char phone[10];
		printf("Enter phone number to search: ");
		scanf("%s",&phone);
		while(fread(&temp,sizeof(temp),1,fp)==1){
			if(strcmp(phone,temp.mobile_no)==0){
				flag=1;
				printf("\n\nDetail information about %s",phone);
				printf("\n\nFirst name: %s\nLast name: %s\nMobile number: %s\nTag: %s\n",temp.fname,temp.lname,temp.mobile_no,temp.tag);
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
	printf("Enter any key:");
	getch();
	system("cls");
}
// A utility function to delete record
void delete_record(){
	struct contact c;
	FILE *f,*fp;
	int flag;
	f=fopen("project1","rb");
	if(f==NULL){
		printf("CONTACT'S DATA NOT ADDED YET");
	}
	else{
		fp=fopen("temp","wb+");
		if(fp==NULL)printf("Error in opening the file");
		else{
			
			int choice;
			printf("\n***DELETION MENU***\n");
			printf("1.Deletion through mobile number\n2.Deletion through name\n");
			printf("Enter your choice: ");
			scanf("%d",&choice);
			if(choice==1){
				char mobile_no[25];
				printf("Enter CONTACT's mobile_no:");
				scanf("%s",&mobile_no);
				fflush(stdin);
				while(fread(&c,sizeof(c),1,f)==1){
					if(strcmp(mobile_no,c.mobile_no)!=0){
						fwrite(&c,sizeof(c),1,fp);
					}
					if(strcmp(mobile_no,c.mobile_no)==0){
						flag=1;
					}
				}
			}
			else if(choice==2){
			char fname[25],lname[25];
			printf("Enter CONTACT's fname: ");
			scanf("%s",&fname);
			printf("Enter CONTACT's lname: ");
			scanf("%s",&lname);
			fflush(stdin);
			while(fread(&c,sizeof(c),1,f)==1){
				if(strcmp(strlwr(c.fname),strlwr(fname))!=0||strcmp(strlwr(c.lname),strlwr(lname))!=0){
					fwrite(&c,sizeof(c),1,fp);
				}
				if(strcmp(strlwr(c.fname),strlwr(fname))==0&&strcmp(strlwr(c.lname),strlwr(lname))==0){
					flag=1;
				}
			}
		}else{
			printf("\nWrong choice!\nEnter any key to continue");
			getch();
			system("cls");
		}
		
			fclose(f);
			fclose(fp);
			if(flag!=1){
				printf("NO CONTACT'S RECORD TO DELETE!\n");
				remove("temp");
			}
			else{
				remove("project1");
				rename("temp","project1");
				printf("RECORD DELETED SUCCESSFULLY!\n");
			}
		}
	}
	printf("Enter ay key:");
	getch();
	system("cls");
}
