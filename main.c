#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct contact{
	char firstName[35];
	char lastName[20];
	long int mobile_no;
	char father_name[35];
	char mother_name[35];
	char address[50];
	char gender[10];
	char mail[100];
	char citizen_no[20];
};

void add_contact();

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
				printf("Add New contact now");
				add_contact(); //Function not yet created
				break;
				
			//other cases to be added
	}
}
	return 0;
}
void add_contact(){
	system("cls");
	FILE *fp;
	fp=fopen("project","a+");
	struct contact p;
	printf("Enter the first name: ");
	scanf("%s",&p.firstName);
	printf("Enter the last name: ");
	scanf("%s",&p.lastName);
	printf("Enter the mobile number: ");
	scanf("%ld",&p.mobile_no);
	printf("Enter father's name: ");
	scanf("%s",&p.father_name);
	printf("Enter the mother's name: ");
	scanf("%s",&p.mother_name);
	printf("Enter the address: ");
	scanf("%s",&p.address);
	printf("Enter the gender: ");
	scanf("%s",&p.gender);
	printf("Enter gmail: ");
	scanf("%s",&p.mail);
	printf("Enter citizen number: ");
	scanf("%s",&p.citizen_no);
	fflush(stdin);
	printf("\nRecord Saved\n");
	
}

