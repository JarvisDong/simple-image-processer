#include <image.h>
#include <functions.h>
#include <stdio.h>

void ReadImage(char *filename, Image &output) {
	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");

 	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);
 	output.ResetSize(w, h);
 	fread(output.pixel, sizeof(Pixel), w*h, f_in);
 	fclose(f_in);
};

void WriteImage(char *filename, Image &img) {
	FILE *f_out = fopen(filename, "w");

	fprintf(f_out, "P6\n%d %d\n%d\n", img.width, img.height, 255);
	fwrite(img.pixel, sizeof(Pixel), (img.height) * (img.width), f_out);
	fclose(f_out);
};

void HalfSize(Image &input, Image &output) {
	output.ResetSize(input.width / 2, input.height / 2);

	for (int i = 0; i < output.width; i++) {
		for (int j = 0; j < output.height; j++) {
			output.pixel[j*output.width+i] = input.pixel[2*(j*input.width+i)];
		}
	}
};

void LeftRightCombine(Image &leftInput, Image &rightInput, Image &output) {
	// assume leftInput.height = rightInput.height.
	output.ResetSize(leftInput.width + rightInput.width, leftInput.height);

	for (int i = 0; i < output.height; i++) {
		for (int j = 0; j < output.width / 2; j++) {
			output.pixel[i*output.width+j] = leftInput.pixel[i*leftInput.width+j];
		}
		for (int k = output.width / 2; k < output.width; k++) {
			output.pixel[i*output.width+k] = rightInput.pixel[i*rightInput.width+k];
		}
	}
};

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output) {
	//assume topInput.width = bottomInput.width.
	output.ResetSize(topInput.width, topInput.height + bottomInput.height);

	for (int i = 0; i < output.width; i++) {
		for (int j = 0; j < output.height / 2; j++) {
			output.pixel[j*output.width+i] = topInput.pixel[j*topInput.width+i];
		}
	}
	for (int i = 0; i < output.width; i++){
		for (int j = output.height / 2; j < output.height; j++) {
			output.pixel[j*output.width+i] = bottomInput.pixel[(j-output.height/2)*bottomInput.width+i];
		}
	}
};

void Blend(Image &input1, Image &input2, double factor, Image &output) {
	//assume two input images have same dimension.
	output.ResetSize(input1.width, input1.height);
	double factor2 = double(1) - factor;
	// unsigned char *blend[w*h*3];

	for (int i = 0; i < output.width; i++) {
		for (int j = 0; j < output.height; j++) {
			output.pixel[j*output.width+i].r = (input1.pixel[j*input1.width+i].r)*factor + (input2.pixel[j*input2.width+i].r)*factor2;
			output.pixel[j*output.width+i].g = (input1.pixel[j*input1.width+i].g)*factor + (input2.pixel[j*input2.width+i].g)*factor2;
			output.pixel[j*output.width+i].b = (input1.pixel[j*input1.width+i].b)*factor + (input2.pixel[j*input2.width+i].b)*factor2;
		}
	}
};

