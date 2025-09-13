#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/person_struct.h"


int main(){

	int choice, index, count;
    Person obj;
    char name[50];
    char path[] = "../store/struct.bin";
	
	rename("../store/Persons.txt","../store/.Persons.txt");

	printMenu();

	printf("Enter your choice: ");
	scanf("%d",&choice);

	 while(1){

		switch (choice)
		{
		case 1:
			printf("How many peoples do you want add: ");
			scanf("%d",&count);
			PersonToFile(&obj,count);
			break;
		case 2:
			printf("Enter index: ");
			scanf("%d",&index);
			Print_One_Person(&obj,index);
			break;
		case 3:
			printf("Enter name: ");
			scanf("%s",name);
			FindByName(&obj,name);
			break;
		case 4:
			ChangeInfo(&obj);
			break;
		case 5:
			printf("Enter index: ");
			scanf("%d",&index);
			RemovePerson(index);
			break;
		case 6:
			printf("Count of persons is %d\n",personCount(path));
			break;
		case 7:
			reset(path);
			break;
		case 8:
			Print_Persons();
			break;
		case 9:
			printMenu();
			break;		
		case 10:
			bin_to_txt(path);
			break;	
		case 0:
			 printf("Exiting...\n");
			 return 0;		
		default:
			 printf("Invalid choice, please try again.\n");
			 break;
		}

		printf("If you want open menu again type 9 else type what action you want: ");
		scanf("%d",&choice);

	}

	return 0;

}
