void ReadImage(char *filename, Image &output) {
	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");

 	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);
  	output->width = w;
  	output->height = h;
 	image->pixel = (Pixel *) malloc(w*h*sizeof(Pixel));
 	fread(image->pixel, sizeof(Pixel), w*h, f_in);
 	fclose();
 	return output;
};

void WriteImage(char *filename, Image &img) {

};

void HalfSize(Image &input, Image &output) {

};

void LeftRightCombine(Image &leftInput, Image &rightinput, Image &output) {

};

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output) {

};

void Blend(Image &input1, Image &input2, double factor, Image &output) {

};
