#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	char *buffer;
	int buffer_size = 25;
	FILE *fin;
	FILE *fout;

	if (argc != 3) {
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fin = fopen(argv[1], "rb");

	buffer = malloc(buffer_size);
	fread(buffer, buffer_size, 1, fin);
	
	fout = fopen(argv[2], "wb");
	fwrite(buffer, sizeof(buffer), buffer_size, fout);

	fclose(fin);
	fclose(fout);
	free(buffer);
	return 0;
}