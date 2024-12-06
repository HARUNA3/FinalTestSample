#pragma warning(disable : 4996) 
//#define _cart_secutre_no_warnings
#include <stdio.h>

struct Student
{
	int stuID;
	char stuName[11]; //10+1 
	float grades[3];
	float total;
	float average;
	int rank;
};

void displayStudent(const struct Student stu);
void display(const struct Student stus[], int size);
float getTotal(float eng, float mat, float sci);
void setAverage(struct Student* stu);
void calcGrade(struct Student stus[], int size);
int getRank(const struct Student stus[], int size, int index);
void setRank(struct Student stus[], int size);
int getTop(const struct Student stus[], int size);
void changeName(struct Student stus[], int index, char* newName);

int main(void) {

	struct Student stus[] = { {1001,"John",{90,80,70},0,0,0}, {1002,"Jane",{60,90,80},0,0,0}, {1003, "David", { 80,50,80 },0,0,0} };

	//displayStudent(stus[0]);
	display(stus,3);
	calcGrade(stus,3);
	setRank(stus,3);
	getTop(stus, 3);
	printf("Top student is..");
	displayStudent(stus[getTop(stus, 3)]);
	changeName(stus, 1, "James");
	display(stus, 3);
};


void displayStudent(const struct Student stus) {
	printf("%4d %10s %.2f %.2f %.2f %.2f %.2f %d\n", stus.stuID, stus.stuName, stus.grades[0], stus.grades[1], stus.grades[2],stus.total, stus.average, stus.rank);
}

void display(const struct Student stus[], int size) {

	printf("ID   NAME      Eng   Mat   Sci   Tot   Aveg   Rank\n==== ========== ==== ==== ==== ==== ==== ====\n");
	for (int i = 0; i < size; i++)
	{
		displayStudent(stus[i]);
	};
}

float getTotal(float eng, float mat, float sci) {
	return eng + mat + sci;
}

void setAverage(struct Student* stu) {
	float average; 
	stu->average = getTotal(stu->grades[0], stu->grades[1], stu->grades[2]) / 3.0;
}

void calcGrade(struct Student stus[], int size) {
	
	for (int i = 0; i < size; i++)
	{
		stus[i].total = getTotal(stus[i].grades[0], stus[i].grades[1], stus[i].grades[2]);
		setAverage(&stus[i]);
	}
}

int getRank(const struct Student stus[], int size, int index) {
	int rank = 1;
	for (int i = 0; i < size; i++)
	{
		if (stus[index].average < stus[i].average)
		{
			rank++;
		}
	}
	return rank;
}

void setRank(struct Student stus[], int size) {
	for (int i = 0; i < size; i++)
	{
		stus[i].rank = getRank(stus,size,i);
	}
}

int getTop(const struct Student stus[], int size) {
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (stus[index].total < stus[i].total)
		{
			index=i;
		}
	}
	return index;
}

void changeName(struct Student stus[],int index, char* newName) {
	strcpy(stus[index].stuName,newName);
}






