#ifndef PERSON_H
#define PERSON_H

typedef struct Person{

	char name[50];
	char surname[50];
	int age;


}Person;

void Print_Persons();
void PersonToFile(Person* obj);
void Print_Person(Person* obj);
void FindByName(const char str[],Person* obj);
void ChangeInfo(Person* obj);
void RemovePerson(int index);
int personCount(const char pathname[]);
void reset(const char pathname[]);
void restore(Person* obj,int num);

#endif