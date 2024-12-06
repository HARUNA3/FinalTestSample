#pragma warning(disable : 4996) 
#define _cart_secure_no_warnings 
#include <stdio.h>
#include <string.h>
#define MAX 50

void advance(struct Ribbon* ribbon, int n);
int readRibbons(const char filename[], struct Ribbon ribbons[], int maxCapacity);
void overUnder(int n, struct Ribbon ribbons[], int size, int* over, int* under, int* equals);
int appendAtPosition(struct Ribbon* ribbon, const char str[]);
void printRibbon(const char filename[], struct Ribbon ribbons[], int size, int longForm);

struct Ribbon
{
	char text[MAX+1];
	int pos;
	int length;
};

int main(void) {
	int result;

	//For first function
	struct Ribbon data1[MAX] = { 0 };
	result = readRibbons("test.txt", data1, 3);
	printf("Function - readRibbons result is : %d\n\n",result);

	//Function 2
	//original position = 0
	struct Ribbon ribbonn = { "Hello world! I'm Haruna Fujishima!", 0, 30 };
	advance(&ribbonn,1);
	
	//Function 3
	int over = 0, under = 0, equals = 0;
	struct Ribbon ribbonss[] = {{"abcd"},{"abcde"},{"ab"},{"ab"},{"a"}};
	overUnder(2, ribbonss, 5, &over, &under, &equals);
	printf("Over:%d, Under:%d, Equals:%d\n\n", over, under, equals);

	//Function 4
	struct Ribbon ribbon = { "Hot air Baloon" };
	char str[] = "Dog";
	result = appendAtPosition(&ribbon, str);
	printf("Function4: New string length is .. %d\n\n", result);

	//Function 5
	struct Ribbon ribbons[] = { {"HARUNA"},{"FUJISHIMA"},{"DOG"},{"CAT"},{"SUNNY"},{"Programing"},
								{"JAZZ"},{"jazz"},{"Random word"},{"Hello world!!"}};
	printRibbon("input.txt", ribbons, 10, 0);

	return 0;

}

int readRibbons(const char filename[], struct Ribbon ribbons[], int maxCapacity) {

	int i = 0;
	FILE* fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (i < maxCapacity && fgets(ribbons[i].text, sizeof(ribbons[i].text), fp)) {
			ribbons[i].text[strcspn(ribbons[i].text,"\n")] = '\0';
			strcspn count until match word2 in word1
			i++;
		}

		fclose(fp);

		for (i = 0; i < 3; i++)
		{
			printf("ribbons value is .. %s\n", ribbons[i].text);
		}
		
		//printf("subfunction i is .. %d\n", i);
		return i;
		
	}
	else {
		printf("FIle is not opened");
		return 0;
	}

}

//I assume struct Ribbon is character only one line data,it include whitespace or symbols
//How to decided original posision??
//What is the position member??
void advance(struct Ribbon* ribbon, int n) {
	int original = 0;
	int cal = 0;
	int count = 0;
	int i = 0;
	int len = strlen(ribbon->text);

	printf("Original posiion alphabet is.. %c\n", ribbon->text[original]);
	cal = original + n;
	if (cal < 0 )
	{
		cal = 0;
	}
	else if (cal >= len) {
		cal = len -1;
	}
	printf("Changed posiion alphabet is.. %c\n\n", ribbon->text[cal]);

}

void overUnder(int n, struct Ribbon ribbons[], int size, int* over, int* under, int* equals) {
	for (int i = 0; i < size; i++)
	{
		int len = strlen(ribbons[i].text);
		if (len == n) {
			(*equals)++;
		}
		else if (len < n) {
			*under = *under+1;
		}
		else {
			*over = *over +1;
		}
	}
}

int appendAtPosition(struct Ribbon* ribbon, const char str[]) {
	//position 4
	int position = 4;
	int len = strlen(str);
	printf("strlen is ..%d\n", len);
	ribbon->text[position] = '\0';
	strcat(ribbon->text, str);
	ribbon->text[position + len] = '\0'; //4+dog(3)
	len = strlen(ribbon->text);
	printf("ribbon text is.. %s\n" , ribbon->text);
	return len;
}

void printRibbon(const char filename[], struct Ribbon ribbons[], int size, int longForm) {
	FILE* fp = fopen(filename, "w");

	if (fp != NULL)
	{

		if (longForm == 0)
		{
			for (int i = 0; i < size; i++)
			{
				fprintf(fp, "%s\n", ribbons[i]);
			}
		}
		else {
			for (int i = 0; i < size; i++)
			{
				fprintf(fp, "position %d: %s\n",i+1, ribbons[i]);
			}
		}
		

		fclose(fp);
	}
	else {
		printf("File not opened\n");
		return 0;
	}
}

