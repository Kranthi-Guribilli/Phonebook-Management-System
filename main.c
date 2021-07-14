#include<stdio.h>

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
