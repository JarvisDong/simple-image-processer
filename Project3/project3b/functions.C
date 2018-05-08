#include <image.h>
#include <functions.h>
#include <stdio.h>

void ReadImage(char *filename, Image &output) {
	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");

 	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);
  	output.width = w;
  	output.height = h;
 	output.pixel = new Pixel[w*h];
 	fread(output.pixel, sizeof(Pixel), w*h, f_in);
 	fclose(f_in);
};

void WriteImage(char *filename, Image &img) {
	FILE *f_out = fopen(filename, "r");
	fprintf(f_out, "P6\n%d %d\n%d\n", img.width, img.height, 255);
	fwrite(img.pixel, sizeof(Pixel), img.height * img.width, f_out);
	fclose(f_out);
};

void HalfSize(Image &input, Image &output) {
	output.width = input.width / 2;
	output.height = input.height / 2;
	output.pixel = new Pixel[output.width * output.height];
	for (int i = 0; i < output.width; i++) {
		for (int j = 0; j < output.height; j++) {
			output.pixel[j*output.width+i] = input.pixel[2*(j*output.width+i)];
		}
	}
};

// void LeftRightCombine(Image &leftInput, Image &rightInput, Image &output) {
// 	// assume leftInput.height = rightInput.height
// 	output.height = leftInput.height;
// 	output.width = leftInput.width + rightInput.width;
// 	output.pixel = new Pixel[output.height * output.width];
// 	for (int i = 0; i < output.width; i++) {
// 		for (int j = 0; i < output.height; j++) {
// 			output.pixel[j*output.width+i] = 
// 		}
// 	}
// };

// void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output) {
// 	//assume topInput.width = bottomInput.width
// 	output.width = leftInput.width;
// 	output.height = topInput.height + bottomInput.height;
// 	output.pixel = new Pixel[output.width * output.height];
// 	for (int i = 0; i < output.width; i++) {
// 		for (int j = 0; i < output.height; j++) {
// 			output.pixel[j*output.width+i] = 

// };

// void Blend(Image &input1, Image &input2, double factor, Image &output) {
// 	output.width = input1.width;
// 	output.height = input1.height;
// 	output.pixel = new Pixel[output.width * output.height];
// };
