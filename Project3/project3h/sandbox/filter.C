#include <filter.h>
#include <stdlib.h>
// #include <iostream>
#include <logging.h>

// using namespace std;
Shrinker::Shrinker(){;}
LRCombine::LRCombine(){;}
TBCombine::TBCombine(){;}
Blender::Blender(){;}

Filter::Filter() : Sink(), Source() {
	latest = false;
}

void
Filter::Update() {
	
	if (latest) {
		return;
	}

	latest = true;

	if (sink_image != NULL) {
        char msg[128];
        sprintf(msg, "%s: about to update input1\n", SourceName());
        Logger::LogEvent(msg);
		try {
     		sink_image->Update();
		} catch (DataFlowException &e) {
			// Reset latest, allow re-update
			latest = false;
			throw e;
		}
        sprintf(msg, "%s: done updating input1\n", SourceName());
        Logger::LogEvent(msg);
	}
	// else {
	// 	cerr << "no input1 to filter" << endl;
	// 	exit(EXIT_FAILURE);
	// }

	if (GetNumberofInputs() == 2) {
		if (sink_image2 != NULL) {
		    char msg[128];
	        sprintf(msg, "%s: about to update input2\n", SourceName());
	        Logger::LogEvent(msg);
			try {
				sink_image2->Update();
			} catch (DataFlowException &e) {
				// Reset latest, allow re-update
				latest = false;
				throw e;
			}
	        sprintf(msg, "%s: done updating input2\n", SourceName());
	        Logger::LogEvent(msg);
		}
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

void
Shrinker::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!\n", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

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
			for (int j = 0; j < sink_image_height; j++) {
				source_image_pixel[j*source_image_width+i] = sink_image_pixel[j*sink_image_width+i];
			}
		}
		for (int i = 0; i < source_image_width; i++){
			for (int j = sink_image_height; j < source_image_height; j++) {
				source_image_pixel[j*source_image_width+i] = sink_image2_pixel[(j-sink_image_height)*sink_image2_width+i];
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

	if (sink_image->getWidth() != sink_image2->getWidth() || sink_image->getHeight() != sink_image2->getHeight()) {
		char msg[1024];
    	sprintf(msg, "%s: not the same size\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
	}

	if (factor > 1 || factor < 0) {
		char msg[1024];
		sprintf(msg, "%s: invalid factor for blender: %f\n", SinkName(), factor);
		DataFlowException e(SinkName(), msg);
		throw e;
	}

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

// 1) Mirror
// 2) Rotate
// 3) Subtract
// 4) Grayscale
// 5) Blur

void
Mirror::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

	int sink_image_width  = sink_image->getWidth();
	int sink_image_height  = sink_image->getHeight();
	Pixel * sink_image_pixel = sink_image->getPixel();

	source_image.ResetSize(sink_image_width, sink_image_height);

	Pixel *source_image_pixel = source_image.getPixel();

	for(int c = 0; c < sink_image_width; c++) {
		for(int r = 0; r < sink_image_height; r++) {
			int index = r*sink_image_width + c;
			int index2 = r*sink_image_width + (sink_image_width - c) - 1;
			source_image_pixel[index] = sink_image_pixel[index2];
		}
	}
}

void
Rotate::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

	int sink_image_width  = sink_image->getWidth();
	int sink_image_height  = sink_image->getHeight();
	Pixel * sink_image_pixel = sink_image->getPixel();

	source_image.ResetSize(sink_image_height, sink_image_width);

	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	Pixel *source_image_pixel = source_image.getPixel();

	for(int c = 0; c < source_image_width; c++) {
		for(int r = 0; r < source_image_height; r++) {
			int index = r*source_image_width + source_image_width-c-1;
			int index2 =c*sink_image_width + r;
			source_image_pixel[index] = sink_image_pixel[index2];
		}
	}    	
}

void
Subtract::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    if (sink_image2 == NULL) {
    	char msg[1024];
    	sprintf(msg, "%s: no input2!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

	if (sink_image->getWidth() != sink_image2->getWidth() || sink_image->getHeight() != sink_image2->getHeight()) {
		char msg[1024];
    	sprintf(msg, "%s: not the same size\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
	}

	int sink_image_width  = sink_image->getWidth();
	int sink_image_height  = sink_image->getHeight();
	Pixel * sink_image_pixel = sink_image->getPixel();

	int sink_image2_width  = sink_image2->getWidth();
	int sink_image2_height  = sink_image2->getHeight();
	Pixel * sink_image2_pixel = sink_image2->getPixel();

	//two input images have exactly the same dimensions
	source_image.ResetSize(sink_image_width, sink_image_height);

	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	Pixel *source_image_pixel = source_image.getPixel();

	for(int c = 0; c < source_image_width; c++) {
		for(int r = 0; r < source_image_height; r++) {
			int index = r*source_image_width + c;
			if (sink_image_pixel[index].r > sink_image2_pixel[index].r) {
				source_image_pixel[index].r = sink_image_pixel[index].r - sink_image2_pixel[index].r;
			}
			else { source_image_pixel[index].r = 0; }

			if (sink_image_pixel[index].g > sink_image2_pixel[index].g) {
				source_image_pixel[index].g = sink_image_pixel[index].g - sink_image2_pixel[index].g;
			}
			else { source_image_pixel[index].g = 0; }

			if (sink_image_pixel[index].b > sink_image2_pixel[index].b) {
				source_image_pixel[index].b = sink_image_pixel[index].b - sink_image2_pixel[index].b;
			}
			else { source_image_pixel[index].b = 0; }
		}
	}    	
}

void
Grayscale::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

	int sink_image_width  = sink_image->getWidth();
	int sink_image_height  = sink_image->getHeight();
	Pixel * sink_image_pixel = sink_image->getPixel();

	source_image.ResetSize(sink_image_width, sink_image_height);

	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	Pixel *source_image_pixel = source_image.getPixel();

	for(int c = 0; c < source_image_width; c++) {
		for(int r = 0; r < source_image_height; r++) {
			int index = r*source_image_width + c;
			source_image_pixel[index].r = sink_image_pixel[index].r / 5 + sink_image_pixel[index].g / 2 + sink_image_pixel[index].b / 4;
			source_image_pixel[index].g = source_image_pixel[index].r;
			source_image_pixel[index].b = source_image_pixel[index].r;
		}
	}    	
}

void
Blur::Execute() {
	if (sink_image == NULL) {
		char msg[1024];
        sprintf(msg, "%s: no input1!\n", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

	int sink_image_width  = sink_image->getWidth();
	int sink_image_height  = sink_image->getHeight();
	Pixel * sink_image_pixel = sink_image->getPixel();

	source_image.ResetSize(sink_image_width, sink_image_height);

	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	Pixel *source_image_pixel = source_image.getPixel();

	for(int c = 0; c < source_image_width; c++) {
		for(int r = 0; r < source_image_height; r++) {
			int index = r*source_image_width + c;
			int index1 = r*source_image_width + c + 1;
			int index2 = r*source_image_width + c - 1;
			int index3 = (r+1)*source_image_width + c;
			int index4 = (r+1)*source_image_width + c + 1;
			int index5 = (r+1)*source_image_width + c - 1;
			int index6 = (r-1)*source_image_width + c;
			int index7 = (r-1)*source_image_width + c + 1;
			int index8 = (r-1)*source_image_width + c - 1;
			if (c == 0 || r == 0 || c == source_image_width - 1 || r == source_image_height - 1) {
				source_image_pixel[index] = sink_image_pixel[index];
			}
			else {
				source_image_pixel[index].r = 
				sink_image_pixel[index1].r/8 + 
				sink_image_pixel[index2].r/8 + 
				sink_image_pixel[index3].r/8 + 
				sink_image_pixel[index4].r/8 + 
				sink_image_pixel[index5].r/8 + 
				sink_image_pixel[index6].r/8 + 
				sink_image_pixel[index7].r/8 + 
				sink_image_pixel[index8].r/8;

				source_image_pixel[index].g = 
				sink_image_pixel[index1].g/8 + 
				sink_image_pixel[index2].g/8 + 
				sink_image_pixel[index3].g/8 + 
				sink_image_pixel[index4].g/8 + 
				sink_image_pixel[index5].g/8 + 
				sink_image_pixel[index6].g/8 + 
				sink_image_pixel[index7].g/8 + 
				sink_image_pixel[index8].g/8;

				source_image_pixel[index].b = 
				sink_image_pixel[index1].b/8 + 
				sink_image_pixel[index2].b/8 + 
				sink_image_pixel[index3].b/8 + 
				sink_image_pixel[index4].b/8 + 
				sink_image_pixel[index5].b/8 + 
				sink_image_pixel[index6].b/8 + 
				sink_image_pixel[index7].b/8 + 
				sink_image_pixel[index8].b/8;		        
			}
		}
	}    	
}