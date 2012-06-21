#ifndef IMAGESTITCH_H
#define IMAGESTITCH_H
#include "picture.h"

class ImageStitch
{
public:
	// core methods
	void run();
	void load_img();

private:
	double zoom_calc; // Not quite sure what this means.
	double zoom_disp; // Or this.

	std::vector<Picture> pics;
};

#endif