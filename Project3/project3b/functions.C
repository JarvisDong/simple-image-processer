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
	int w = input.width / 2;
	int h = input.height / 2;
	output.ResetSize(w, h);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			output.pixel[j*w+i] = input.pixel[2*(j*input.width+i)];
		}
	}
};

void LeftRightCombine(Image &leftInput, Image &rightInput, Image &output) {
	// assume leftInput.height = rightInput.height.
	int w = leftInput.width + rightInput.width;
	int h = leftInput.height;
	output.ResetSize(w, h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w / 2; j++) {
			output.pixel[i*w+j] = leftInput.pixel[i*leftInput.width+j];
		}
		for (int k = w / 2; k < w; k++) {
			output.pixel[i*w+k] = rightInput.pixel[i*rightInput.width+k];
		}
	}
};

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output) {
	//assume topInput.width = bottomInput.width.
	int w = topInput.width;
	int h = topInput.height + bottomInput.height;
	output.ResetSize(w, h);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h / 2; j++) {
			output.pixel[j*w+i] = topInput.pixel[j*topInput.width+i];
		}
	}
	for (int i = 0; i < w; i++){
		for (int j = h / 2; j < h; j++) {
			output.pixel[j*w+i] = bottomInput.pixel[(j-h/2)*bottomInput.width+i];
		}
	}
};

void Blend(Image &input1, Image &input2, double factor, Image &output) {
	//assume two input images have same dimension.
	int w = input1.width;
	int h = input1.height;
	output.ResetSize(w, h);
	// unsigned char *blend[w*h*3];

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			output.pixel[j*w+i].r = input1.pixel[j*w+i].r*factor + input2.pixel[j*w+i].r*(1-factor);
			output.pixel[j*w+i].g = input1.pixel[j*w+i].g*factor + input2.pixel[j*w+i].g*(1-factor);
			output.pixel[j*w+i].b = input1.pixel[j*w+i].b*factor + input2.pixel[j*w+i].b*(1-factor);
		}
	}
};

