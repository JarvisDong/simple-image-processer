#include <filter.h>

void
Shrinker::Execute() {
	for (int i = 0; i < source_image.width; i++) {
		for (int j = 0; j < source_image.height; j++) {
			source_image.pixel[j*source_image.width+i] = sink_image.pixel[2*(j*sink_image.width+i)];
		}
	}
}



void
LRCombine::Execute() {
	for (int i = 0; i < source_image.height; i++) {
		for (int j = 0; j < sink_image.width; j++) {
			source_image.pixel[i*source_image.width+j] = sink_image.pixel[i*sink_image.width+j];
		}
		for (int k = sink_image.width; k < source_image.width; k++) {
			source_image.pixel[i*source_image.width+k] = sink_image2.pixel[i*sink_image2.width+k-sink_image.width];
		}
	}
}



void
TBCombine::Execute() {
	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	int sink_image_width = sink_image.getWidth();
	int sink_image2_width = sink_image2.getWidth();
	int 

	for (int i = 0; i < source_image.width; i++) {
		for (int j = 0; j < source_image.height - sink_image.height; j++) {
			source_image.pixel[j*source_image.width+i] = sink_image.pixel[j*sink_image.width+i];
		}
	}
	for (int i = 0; i < source_image.width; i++){
		for (int j = sink_image.height; j < source_image.height; j++) {
			// source_image.pixel[j*source_image.width+i] = sink_image2.pixel[(j-source_image.height+sink_image.height)*sink_image2.width+i];
		}
	}
}


void
Blender::SetFactor(double f) {
	factor = f;
	factor2 = double(1) - f;
}

void
Blender::Execute() {
	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	for (int i = 0; i < source_image_width; i++) {
		for (int j = 0; j < source_image_height; j++) {
			// source_image.pixel[j*source_image.width+i].r = (sink_image.pixel[j*sink_image.width+i].r)*factor + (sink_image2.pixel[j*sink_image2.width+i].r)*factor2;
			// source_image.pixel[j*source_image.width+i].g = (sink_image.pixel[j*sink_image.width+i].g)*factor + (sink_image2.pixel[j*sink_image2.width+i].g)*factor2;
			// source_image.pixel[j*source_image.width+i].b = (sink_image.pixel[j*sink_image.width+i].b)*factor + (sink_image2.pixel[j*sink_image2.width+i].b)*factor2;
}
