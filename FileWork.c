#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE* file = fopen("./file.txt","w");

fprintf(file, "Lorem Ipsum is simply dummy text of the printing and typesetting industry. ");
    fprintf(file, "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, ");
    fprintf(file, "when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
    fprintf(file, "It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
    fprintf(file, "It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, ");
    fprintf(file, "and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.\n");

	fclose(file);

	FILE* file1 = fopen("./file.txt","r");

	char str[1024];

	while(fgets(str, sizeof(str), file1)){

    	printf("%s", str);

	}
	
	fclose(file1);

	return 0;


}
