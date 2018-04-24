#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int *buffer;
	int buffersize=25;
	FILE *fin;
	FILE *fout;

	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	buffer = (int*)malloc(buffersize * sizeof(int));
	for (int i=0; i<5; i++) {
		fread(buffer, 5*sizeof(int), 1, fin);
		fseek(fin, 5*sizeof(int), SEEK_CUR);	
		for (int j=0; j<5; j++) {
			fprintf(fout, "%d\n", buffer[j]);
		}
	}
	fclose(fin);
	fclose(fout);
	free(buffer);
	return 0;
}