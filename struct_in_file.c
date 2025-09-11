#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_struct.h"


int main(){

	int choice, index, count;
    Person obj;
    char name[50];
    char path[] = "./struct.bin";
	
	printMenu();

	printf("Enter your choice: ");
	scanf("%d",&choice);

	 while(1){

		if (choice == 9)
		{
			
		printMenu();
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

		}

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
		// case 9:
		// 	printMenu();
		// 	break;
		case 0:
			 printf("Exiting...\n");
			 return 0;		
		default:
			 printf("Invalid choice, please try again.\n");
			 break;
		}

		printf("If you want open menu type 9 else type 0: ");
		scanf("%d",&choice);

	}

	return 0;

}





/*int main(){


	//reset(file);
	
	Person p;
	int flag = 0;
	int flag1 = 0;
	int index = 0;
	char name[50];

	for(int i = 0; i < 2; i++){

		PersonToFile(&p);

	}


	printf("If want find person by name write 1 else 0: ");
	scanf("%d",&flag);

	if(flag == 1){

		printf("Enter name: ");
		scanf("%s",name);
		FindByName(name,&p);

	}else{

		printf("Thank you\n");

	}

	//restore(&p,1);


	printf("If want remove person write 1 else 0: ");
	scanf("%d",&flag1);

	if(flag1 == 1){

		printf("Enter index: ");
		scanf("%d",&index);
		RemovePerson(index);

	}else{

		printf("Thank you\n");

	}


	// FILE* file = fopen("./NewStruct.bin","r");
	// Print_Persons(file);	


	//ChangeInfo(&p);
	char str[] = "./struct.bin";
	char str1[] = "./NewStruct.bin";
	//reset(str);

	int count = personCount(str);
	int count1 = personCount(str1);
	printf("%d\n",count);
	printf("%d",count1);

	return 0;	
}*/