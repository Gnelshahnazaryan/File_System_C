#include <stdio.h>
#include <stdlib.h>

typedef struct Person{

	int age;
	char name[50];
	char surname[50];


}Person;

void PersonToFile(Person* obj){

	FILE* file = fopen("./struct.bin", "ab");

	if(file == NULL){

		perror("Error opening file");
		return;

	}

	printf("Enter name,surname and age: ");
	scanf("%s %s %d",obj->name,obj->surname,&obj->age);

	size_t written = fwrite(obj, sizeof(Person), 1, file);

        if (written == 1) {

            printf("Struct written successfully.\n");

        } else {

            printf("Write error occurred.\n");

        }

	fclose(file);

}

void Print_Person(Person* obj){

	 FILE* file = fopen("./struct.bin","rb");

	 if(file == NULL){

		perror("Error opening file");
		return;

	 } 

	 size_t read = fread(obj, sizeof(Person), 1, file);

        if (read == 1) {

            printf("Name: %s\n Surname: %s\n Age: %d\n", obj->name,obj->surname,obj->age);

        } else {

            printf("Error reading the file or reached EOF.\n");

        }

	fclose(file);

}

void restore(Person obj,int num){

	FILE* file = fopen("./struct.bin","rb");

	if(file == NULL){

		perror("Can't open file;");
		return;

	}

	fseek(file, 0, SEEK_SET);
	fseek(file,num * sizeof(Person),SEEK_SET);
	
	size_t read = fread(&obj, sizeof(Person), 1, file);
	 
	if(read == 1){

    	printf("Name: %s Surname: %s Age: %d\n", obj.name,obj.surname,obj.age);

	}else{

    	printf("Error reading the file or reached EOF.\n");

	}

	fclose(file);

}


int main(){

	Person p;

	for(int i = 0; i < 3; i++){

		PersonToFile(&p);

	}

	restore(p,1);


	return 0;	
}
