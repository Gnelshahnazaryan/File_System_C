#include <stdio.h>
#include <stdlib.h>


typedef struct Person{

	char name[50];
	char surname[50];


}Person;

int main(){

	FILE* file = fopen("./StructFile.txt", "w");

	if(file == NULL){

		perror("Error opening file");
		return 0;

	}

	Person P1;

	printf("Enter name,surname and age: ");
	scanf("%s %s",P1.name,P1.surname);


	int person = fprintf(file,"%s\n","Person 1");

	int fpf = fprintf(file,"Name: %s ",P1.name);
	int fpf1 = fprintf(file,"Surname: %s\n",P1.surname);

	if(fpf == 0 || fpf1 == 0){

		return 0;

	}

	fclose(file);


	FILE* file1 = fopen("./StructFile.txt", "r");

	char name[50];
	char surname[50];
	
	
	while(fgets(name,sizeof(name),file1)){

		printf("%s",name);

	}

	 fseek(file1, sizeof(name), SEEK_SET);


	while(fgets(surname,sizeof(surname),file1)){

		printf("%s",surname);

	}


	fclose(file1);
	return 0;


}
