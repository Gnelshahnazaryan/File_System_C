#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/person_struct.h" 

void Print_Persons(){

	 FILE* file = fopen("../store/struct.bin", "rb");
	 int count = 0;
	 Person obj;

	 if(file == NULL){

		printf("Error\n ");
		return;

	 }

	 while(fread(&obj, sizeof(Person), 1, file) == 1){

		printf(" Person %d\n Name: %s\n Surname: %s\n Age: %d\n",count + 1, obj.name,obj.surname,obj.age);
		count++;

	 }


	  if (count == 0) {

		printf("File is empty or reading error\n");

     }
	
	 fclose(file);

}

void PersonToFile(Person* obj,int count){

	FILE* file = fopen("../store/struct.bin", "ab");

    if(file == NULL){

		perror("Error opening file");
		return;

	}

    if(count == 0){

        printf("Wrong count:");
        return;

    }


    if(count == 1){
        printf("Enter name,surname and age: ");

	    if(scanf("%49s %49s %d",obj->name,obj->surname,&obj->age) != 3){

         printf("Invalid input.\n");
         fclose(file);
         return;

        }
    }else if(count > 1){

        for (size_t i = 0; i < count; i++)
        {
            
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

        }


    }

    fclose(file);
    return;

}

void FindByName(Person* obj,const char str[]){

	FILE* file = fopen("../store/struct.bin","rb");

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

	FILE* file = fopen("../store/struct.bin", "rb+");

    if(file == NULL){

        perror("Error opening file");
        return;

    }

	char NewName[50], NewSurname[50];
	int NewAge;
	int index = 0;

	printf("Enter person index for changing info:");
	scanf("%d", &index);
	
	if(fseek(file,index * sizeof(Person),SEEK_CUR) != 0){

        printf("Seek failed.\n");
        fclose(file);
        return;

    }

	if(fread(obj, sizeof(Person), 1, file) == 1){

        printf("Enter new name,surname and age: ");
	    if(scanf("%49s %49s %d",NewName,NewSurname,&NewAge) != 3){

         printf("Invalid input.\n");
         fclose(file);
         return;

        }
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

	 FILE* file = fopen("../store/struct.bin","rb");

	 FILE* file1 = fopen("../store/NewStruct.bin","ab");

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


     remove("../store/struct.bin");
     rename("../store/NewStruct.bin", "../store/struct.bin");

     printf("Person at index %d removed (if existed).\n", index);


}

int personCount(const char pathname[]) {
    int count = 0;
    FILE* file = fopen(pathname, "rb");

    if (file == NULL) {

        return 0;

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

void Print_One_Person(Person* obj,int index){

	FILE* file = fopen("../store/struct.bin","rb");
    const char path[] = "../store/struct.bin";

	if(file == NULL){

		perror("Can't open file;");
		return;

	}

      if (index < 0 || index >= personCount(path)) {
        printf("Index out of range.\n");
        fclose(file);
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
        clearerr(file);

	}
	 
	fclose(file);

}

void bin_to_txt(const char path[]){

    rename("../store/.Persons.txt","../store/Persons.txt");

    FILE* file = fopen(path,"rb");

    if(file == NULL){

        printf("Error opening file");
        fclose(file);
        return;

    }

    FILE* txt;
    char choice[15];
    Person obj;
    int count = 1;

    printf("Want append persons or overwrite: ");
    scanf("%s",choice);

    if(strcmp(choice,"append") == 0 || strcmp(choice,"Append") == 0){

        txt = fopen("../store/Persons.txt", "a");

    }else if (strcmp(choice,"overwrite") == 0 || strcmp(choice,"Overwrite") == 0){

        txt = fopen("../store/Persons.txt", "w");

    }else{

        printf("Wrong input::\n");
        fclose(file);
        fclose(txt);
        return;

    }

    if(txt == NULL){

        printf("Error opening file:\n");
        fclose(txt);
        return;

    }



    for (size_t i = 0; i < personCount(path); i++)
    {
        if(fread(&obj,sizeof(Person),1,file) == 1){

            fprintf(txt,"Person %d {%s:%s:%d}\n",count,obj.name,obj.surname,obj.age);
            count++;

        }else{

            printf("Failed convert to txt file\n");
            fclose(file);
            fclose(txt);
            return;

        }

    }
    
    fclose(file);
    fclose(txt);

}




void printMenu() {
    printf("\n======= MENU =======\n");
    printf("1. Add a person\n");
    printf("2. Print person by index\n");
    printf("3. Search by name\n");
    printf("4. Modify person by index\n");
    printf("5. Remove person by index\n");
    printf("6. Show total number of persons\n");
    printf("7. Clear file (reset)\n");
    printf("8. Print all persons\n");
    printf("9. Show menu (help)\n");
    printf("10. Convert to txt file\n");
    printf("0. Exit\n");
    printf("====================\n");
}
