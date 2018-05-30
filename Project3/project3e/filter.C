#include <filter.h>
#include <iostream>
#include <stdlib.h>

void
Filter::Update() {
	if (sink_image == NULL) {
		cerr << "no input1 to filter" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		sink_image->Update();
		Execute();
	}
	if (sink_image2 == NULL) {
		cerr << "no input2 to filter" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		sink_image2->Update();
		Execute();
	}
}

Shrinker::Shrinker(void) {;}

void
Shrinker::Execute() {
	int sink_image_width = sink_image->getWidth();
	int sink_image_height = sink_image->getHeight();
	int source_image_width = sink_image_width / 2;
	int source_image_height = sink_image_height / 2;
	source_image.ResetSize(source_image_width, source_image_height);
	Pixel *source_image_pixel = source_image.getPixel();
	Pixel *sink_image_pixel = sink_image->getPixel();

	for (int i = 0; i < source_image_height; i++) {
		for (int j = 0; j < source_image_width; j++) {
			source_image_pixel[i*source_image_width+j] = sink_image_pixel[2*(i*sink_image_width+j)];
			//source_image.setPixel(sink_image_pixel);
		}
	}
}

LRCombine::LRCombine(void) {;}

void
LRCombine::Execute() {
	int sink_image_width = sink_image->getWidth();
	int sink_image2_width = sink_image2->getWidth();
	int sink_image_height = sink_image->getHeight();
	int source_image_width = sink_image_width + sink_image2_width;
	int source_image_height = sink_image_height;
	source_image.ResetSize(source_image_width, source_image_height);
	Pixel *source_image_pixel = source_image.getPixel();
	Pixel *sink_image_pixel = sink_image->getPixel();
	Pixel *sink_image2_pixel = sink_image2->getPixel();

	for (int i = 0; i < source_image_height; i++) {
		for (int j = 0; j < sink_image_width; j++) {
			source_image_pixel[i*source_image_width+j] = sink_image_pixel[i*sink_image_width+j];
		}
		for (int k = sink_image_width; k < source_image_width; k++) {
			source_image_pixel[i*source_image_width+k] = sink_image2_pixel[i*sink_image2_width+k-sink_image_width];
		}
	}
}

TBCombine::TBCombine(void) {;}

void
TBCombine::Execute() {
	int sink_image_height = sink_image->getHeight();
	int sink_image2_height = sink_image2->getHeight();
	int sink_image_width = sink_image->getWidth();
	int sink_image2_width = sink_image2->getWidth();

	int source_image_width = sink_image2_width;
	int source_image_height = sink_image_height + sink_image2_height;

	source_image.ResetSize(source_image_width, source_image_height);
	Pixel *source_image_pixel = source_image.getPixel();
	Pixel *sink_image_pixel = sink_image->getPixel();
	Pixel *sink_image2_pixel = sink_image2->getPixel();

	for (int i = 0; i < source_image_width; i++) {
		for (int j = 0; j < source_image_height - sink_image_height; j++) {
			source_image_pixel[j*source_image_width+i] = sink_image_pixel[j*sink_image_width+i];
		}
	}
	for (int i = 0; i < source_image_width; i++){
		for (int j = sink_image_height; j < source_image_height; j++) {
			source_image_pixel[j*source_image_width+i] = sink_image2_pixel[(j-source_image_height+sink_image_height)*sink_image2_width+i];
		}
	}
}

Blender::Blender(void) {;}

void
Blender::SetFactor(double f) {
	factor = f;
	factor2 = double(1) - f;
}

void
Blender::Execute() {
	int sink_image_width = sink_image->getWidth();
	int sink_image2_width = sink_image2->getWidth();
	int sink_image_height = sink_image->getHeight();

	int source_image_width = sink_image_width;
	int source_image_height = sink_image_height;
	source_image.ResetSize(source_image_width, source_image_height);
	Pixel *source_image_pixel = source_image.getPixel();
	Pixel *sink_image_pixel = sink_image->getPixel();
	Pixel *sink_image2_pixel = sink_image2->getPixel();


	for (int i = 0; i < source_image_width; i++) {
		for (int j = 0; j < source_image_height; j++) {
			source_image_pixel[j*source_image_width+i].r = (sink_image_pixel[j*sink_image_width+i].r)*factor + (sink_image2_pixel[j*sink_image2_width+i].r)*factor2;
			source_image_pixel[j*source_image_width+i].g = (sink_image_pixel[j*sink_image_width+i].g)*factor + (sink_image2_pixel[j*sink_image2_width+i].g)*factor2;
			source_image_pixel[j*source_image_width+i].b = (sink_image_pixel[j*sink_image_width+i].b)*factor + (sink_image2_pixel[j*sink_image2_width+i].b)*factor2;
		}
	}
}
