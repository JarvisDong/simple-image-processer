#include <stdio.h>
int main(){
	unsigned int testInt = 1;
	char *c = (char*)&testInt;
	if (*c) {
		printf("Little endian\n");	
	} 
	else {
		printf("Big endian\n");	
	}
	return 0; 	
}
