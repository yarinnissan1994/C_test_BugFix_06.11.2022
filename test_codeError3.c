#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
// struct to collect counting info about english letters found in a text file.

// bug - miising next and prev for creating linked list
typedef struct letter {
	char small;
	char big;
	int counter;
	struct letter* next; // fix - adding next to struct
	struct letter* prev; // fix - adding prev to struct
}letter;

//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}
int main()
{
	//Next two string represents all the english alphabets
	//(small and capital) // bug - uncorrect line - fix - commenting line
	//char* smallAlpha = "abcdefghijklmnopqrstuvwxyz"; // bug - string can be8 static
	//char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // bug - string can be8 static
	char smallAlpha[] = "abcdefghijklmnopqrstuvwxyz"; // fix - initialized static array
	char bigAlpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // fix - initialized static array
	//int lettersCountArr[20] = { 0 }; // bug - missing space for all letters in ABC
	int lettersCountArr[26] = { 0 };
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");
	// bug - missing open file varification
	if (f == NULL) // fix - verifiyng file
	{
		printf("failed to open \"myFile.txt\"");
	}
	else
	{
		// Dis[lay the content of myFile.txt and count letters
		printf("the content of myFile.txt :\n");
		while ((readChar = fgetc(f)) != EOF /*0 - BUG*/) { // bug fix - replacing while condition from "0" to "EOF"
			printf("%c", readChar);
			for (int i = 0; i < strlen(smallAlpha); ++i) {
				if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
					lettersCountArr[i]++;
			}
		}
		fclose(f);
	}


	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); ++j) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			puts("Error Allocating Memory!");
			exit(1);
		}
		letterItem->small = 'a' + j;
		letterItem->big = 'A' + j;
		letterItem->counter = lettersCountArr[j];
		// Creating the linked list

		// bug - need to check head first
		//TAIL->next = letterItem;
		//letterItem->prev = TAIL;
		//TAIL = letterItem;
		//TAIL->next = NULL;

		// fix - correct order to put in linked list
		letterItem->next = NULL;
		if (HEAD == NULL)
		{
			letterItem->prev = NULL;
			HEAD = letterItem;
			TAIL = letterItem;
		}
		else
		{
			letterItem->prev = TAIL;
			TAIL->next = letterItem;
			TAIL = letterItem;
		}
	}
	// bug - missing free function to linked list
	freeList(HEAD); // FIX - freeing linked list

	return 0;
}