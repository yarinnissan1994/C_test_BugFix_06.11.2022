//#include <stdio.h< bug
#include <stdio.h> // fix syntax
#pragma warning (disable : 4996) //fix included pragma warning

	int main1() {

		//int a = 4; b = 7; bug 
		int a = 4, b = 7; // fix - replaced ";" to "," between "a" and "b";
		
		float c;
		
		//scanf("%f", c); bug
		scanf("%f", &c); // fix - added "&" before "c" for sending user input
		
		//if (5 = c) bug
		//
		//        print("%f", c); bug
		//

		if (5 == c) { // fix - fixed if statment syntax
			printf("%f", c); // fix - changed "print" to "printf" to execute print function
		}
		return 0; // fix - main must return a value
}