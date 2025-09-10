#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_struct.h"


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