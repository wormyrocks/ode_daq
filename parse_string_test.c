#include <stdio.h>
#include <string.h>

int main(){
	
	char input[4] = {0x03,0xff};
	int n = strtol (input, NULL, 16);
	printf("int %d", n);
// 	printf("input %s",input);
// 	char input[4] = {0x55, 0x66, 0x77, 0x88};
// 	char test[2];	
// 
// 	memcpy(&test, &input, 2);
// 	printf("contents: %x %x \n", test[0], test[1]);

}