#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_struct.h" 

void Print_Persons(){

	 FILE* file = fopen("./struct.bin", "rb");
	 int count = 0;
	 Person obj;

	 if(file == NULL){

		printf("Error\n ");
		return;

	 }

	 while(fread(&obj, sizeof(Person), 1, file) == 1){

		printf("Person %d\n Name: %s\n Surname: %s\n Age: %d\n",count, obj.name,obj.surname,obj.age);
		count++;

	 }


	  if (count == 0) {

		printf("File is empty or reading error\n");

     }
	
	 fclose(file);

}

void PersonToFile(Person* obj){

	FILE* file = fopen("./struct.bin", "ab");

	if(file == NULL){

		perror("Error opening file");
		return;

	}

	printf("Enter name,surname and age: ");
	if(scanf("%49s %49s %d",obj->name,obj->surname,&obj->age) != 3){

         printf("Invalid input.\n");
         fclose(file);
         return;

    }

	

        if (fwrite(obj, sizeof(Person), 1, file) == 1) {

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

	 

       if (fread(obj, sizeof(Person), 1, file) == 1) {

            printf("Name: %s\n Surname: %s\n Age: %d\n", obj->name,obj->surname,obj->age);

        } else {

            printf("Error reading the file or reached EOF.\n");

        }

	fclose(file);

}



void FindByName(const char str[],Person* obj){

	FILE* file = fopen("./struct.bin","rb");


    int found = 0;

	while(fread(obj, sizeof(Person), 1, file) == 1){

			if(strcmp(str,obj->name) == 0){

				printf("Name: %s\n Surname: %s\n Age: %d\n", obj->name,obj->surname,obj->age);
                found = 1;
                break;
				
            }
    }	

		
	if(!found){
		
         printf("Person with name \"%s\" not found.\n", str);

    }

	fclose(file);
}

void ChangeInfo(Person* obj){

	FILE* file = fopen("./struct.bin", "rb+");

    if(file == NULL){

        perror("Error opening file");
        return;

    }

	char NewName[50], NewSurname[50];
	int NewAge;
	int index = 0;

	printf("Enter person index for changing info:");
	scanf("%d", &index);
	
	if(fseek(file,index * sizeof(Person),SEEK_CUR)){

        printf("Seek failed.\n");
        fclose(file);
        return;

    }

	if(fread(obj, sizeof(Person), 1, file) == 1){

        printf("Enter new name,surname and age: ");
	    scanf("%s %s %d",NewName,NewSurname,&NewAge);

    }else{

        printf("Read failed\n");
        return;

    }
	 
	
	strcpy(obj->name,NewName);
	strcpy(obj->surname,NewSurname);
	obj->age = NewAge;

	fseek(file, -sizeof(Person), SEEK_CUR); 

    if (fwrite(obj, sizeof(Person), 1, file) != 1) {

        perror("Write failed");

    } else {

        printf("Person updated successfully.\n");

    }

	fclose(file);

}

void RemovePerson(int index){

	 FILE* file = fopen("./struct.bin","rb");

	 FILE* file1 = fopen("./NewStruct.bin","ab");

     if (!file || !file1) {
        perror("Error opening files");
        if (file) fclose(file);
        if (file1) fclose(file1);
        return;
     }

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


     remove("./struct.bin");
     rename("./NewStruct.bin", "./struct.bin");

     printf("Person at index %d removed (if existed).\n", index);


}

int personCount(const char pathname[]) {
    int count = 0;
    FILE* file = fopen(pathname, "rb");

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

void reset(const char pathname[]){

	FILE* file = fopen(pathname, "wb");

    if (file != NULL) {

        fclose(file);
        printf("File reset successfully.\n");

    } else {

        perror("Error resetting file");

    }

	fclose(file);

}

void restore(Person* obj,int index){

	FILE* file = fopen("./struct.bin","rb");

	if(file == NULL){

		perror("Can't open file;");
		return;

	}

	if(fseek(file,index * sizeof(Person),SEEK_SET) != 0){

        printf("Seek error.\n");
        fclose(file);
        return;

    }
	
	if(fread(obj, sizeof(Person), 1, file) == 1){

        printf("Name: %s Surname: %s Age: %d\n", obj->name,obj->surname,obj->age);

    }else{

    	printf("Error reading the file or reached EOF.\n");

	}
	 
	fclose(file);

}

