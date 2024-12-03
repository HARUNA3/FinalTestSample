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
	char text[MAX + 1];
	int pos;
	int length;
};

int main(void) {
	int result;

	//For first function
	struct Ribbon data1[MAX] = { 0 };
	result = readRibbons("test.txt", data1, 3);
	printf("Function - readRibbons result is : %d\n\n", result);

	//Function 2
	//original position = 0
	struct Ribbon ribbonn = { "Hello world! I'm Haruna Fujishima!", 0, 30 };
	advance(&ribbonn, 1);

	//Function 3
	int over = 0, under = 0, equals = 0;
	struct Ribbon ribbonss[] = { {"abcd"},{"abcde"},{"ab"},{"ab"},{"a"} };
	overUnder(2, ribbonss, 5, &over, &under, &equals);
	printf("Over:%d, Under:%d, Equals:%d\n\n", over, under, equals);

	//Function 4
	struct Ribbon ribbon = { "Hot air Baloon" };
	char str[] = "Dog";
	result = appendAtPosition(&ribbon, str);
	printf("Function4: New string length is .. %d\n\n", result);

	//Function 5
	struct Ribbon ribbons[] = { {"HARUNA"},{"FUJISHIMA"},{"DOG"},{"CAT"},{"SUNNY"},{"Programing"},
								{"JAZZ"},{"jazz"},{"Random word"},{"Hello world!!"} };
	printRibbon("input.txt", ribbons, 10, 0);

	return 0;

}

int readRibbons(const char filename[], struct Ribbon ribbons[], int maxCapacity) {

	//Write code here

}

void advance(struct Ribbon* ribbon, int n) {
	
	//Write code here

}

void overUnder(int n, struct Ribbon ribbons[], int size, int* over, int* under, int* equals) {
	
	//Write code here
}

int appendAtPosition(struct Ribbon* ribbon, const char str[]) {
	
	//Write code here
}

void printRibbon(const char filename[], struct Ribbon ribbons[], int size, int longForm) {
	
	//Write code here

}

