#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Person{

	char name[50];
	char surname[50];
	int age;


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

            printf("Person info written successfully.\n");

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

void restore(Person* obj,int num){

	FILE* file = fopen("./struct.bin","rb");

	if(file == NULL){

		perror("Can't open file;");
		return;

	}

	//fseek(file, 0, SEEK_SET);
	rewind(file);
	fseek(file,num * sizeof(Person),SEEK_SET);
	
	size_t read = fread(obj, sizeof(Person), 1, file);
	 

	if(read == 1){

    	printf("Name: %s Surname: %s Age: %d\n", obj->name,obj->surname,obj->age);

	}else{

    	printf("Error reading the file or reached EOF.\n");

	}

	fclose(file);

}


void FindByName(char str[],Person* obj){

	FILE* file = fopen("./struct.bin","rb");

	rewind(file);


	while(!(feof(file))){

		int read = fread(obj,sizeof(Person),1,file);
		if(read){

			if(strcmp(str,obj->name) == 0){

				printf("Name: %s\n Surname: %s\n Age: %d\n", obj->name,obj->surname,obj->age);
				
				return;

			}

		}else{

			fseek(file,sizeof(Person),SEEK_CUR);

		}

	}
		printf("Error reading the file or reached EOF.\n");

		fclose(file);
}


int personCount() {
    int count = 0;
    FILE* file = fopen("./struct.bin", "rb");

    if (file == NULL) {

        return -1;

    }

    Person tmp;

    while (fread(&tmp, sizeof(Person), 1, file)) {

        count++;

    }

    fclose(file);

    return count;
}



void reset(FILE* file){

	file = fopen("./struct.bin", "wb");
	fclose(file);

}

void ChangeInfo(Person* obj){

	FILE* file = fopen("./struct.bin", "ab+");

	rewind(file);

	char NewName[50];
	char NewSurname[50];
	int NewAge;
	int index = 0;

	printf("Enter person index for changing info:");
	scanf("%d", &index);
	
	fseek(file,index * sizeof(Person),SEEK_CUR);

	fread(obj, sizeof(Person), 1, file);
	 
	printf("Enter new name,surname and age: ");
	scanf("%s %s %d",NewName,NewSurname,&NewAge);


	strcpy(obj->name,NewName);
	strcpy(obj->surname,NewSurname);
	obj->age = NewAge;

	printf("Name: %s Surname: %s Age: %d\n", obj->name,obj->surname,obj->age);

	fwrite(obj,sizeof(Person),1,file);

	if (fwrite(obj, sizeof(Person), 1, file) != 1) {

    	perror("Write failed");

	}


	fclose(file);

}

void RemovePerson(int index){

	FILE* file = fopen("./struct.bin","rb");

	FILE* file1 = fopen("./NewStruct.bin","wb");

	rewind(file);

	Person p;

	int i = 0;
	
	 while (fread(&p, sizeof(Person), 1, file) == 1) {

        if (i != index) {

            fwrite(&p, sizeof(Person), 1, file1);

        }

        i++;

    }

    fclose(file);

    fclose(file1);


}



int main(){

	FILE* file = fopen("./struct.bin","r");

	//reset(file);
	
	Person p;
	int flag = 0;
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

	ChangeInfo(&p);
	int count = personCount();
	printf("%d",count);

	return 0;	
}
