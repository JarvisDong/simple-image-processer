#include <filter.h>
#include <stdlib.h>
// #include <iostream>
#include <logging.h>

// using namespace std;
Shrinker::Shrinker(){;}
LRCombine::LRCombine(){;}
TBCombine::TBCombine(){;}
Blender::Blender(){;}

void
Filter::Update() {
	if (sink_image != NULL) {
        char msg[128];
        sprintf(msg, "%s: about to update input1\n", SourceName());
        Logger::LogEvent(msg);
        sink_image->Update();
        sprintf(msg, "%s: done updating input1\n", SourceName());
        Logger::LogEvent(msg);
	}
	// else {
	// 	cerr << "no input1 to filter" << endl;
	// 	exit(EXIT_FAILURE);
	// }

	if (sink_image2 != NULL) {
	    char msg[128];
        sprintf(msg, "%s: about to update input2\n", SourceName());
        Logger::LogEvent(msg);
        sink_image2->Update();
        sprintf(msg, "%s: done updating input2\n", SourceName());
        Logger::LogEvent(msg);
	}
	// else {
	// 	cerr << "no input2 to filter" << endl;
	// 	exit(EXIT_FAILURE);
	// }

	char msg[1024];
	sprintf(msg, "%s: about to execute\n", SourceName());
    Logger::LogEvent(msg);

	Execute();

    sprintf(msg, "%s: done executing\n", SourceName());
    Logger::LogEvent(msg);
}

const char * Filter::SourceName() {return FilterName();}

const char * Filter::SinkName() {return FilterName();}



void
Shrinker::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
	else {
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
			}
		}			
	}
}


void
LRCombine::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
	if (sink_image2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
//heights not equal
	if (sink_image->getHeight() != sink_image2->getHeight()) {
        char msg[1024];
        sprintf(msg, "%s: heights must match: %d, %d\n", SinkName(), sink_image->getHeight(), sink_image2->getHeight());
        DataFlowException e(SinkName(), msg);
        throw e;
	}
	else {
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
}


void
TBCombine::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if (sink_image2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
//widths not same
	if (sink_image->getWidth() != sink_image2->getWidth()) {
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d\n", SinkName(), sink_image->getHeight(), sink_image2->getHeight());
        DataFlowException e(SinkName(), msg);
        throw e;
	}
	else {
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
}


void
Blender::SetFactor(double f) {
	factor = f;
	factor2 = double(1) - f;
}

void
Blender::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if (sink_image2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if (factor > 1 || factor < 0) {
		char msg[1024];
		sprintf(msg, "%s: invalid factor\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
	else {
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
}
