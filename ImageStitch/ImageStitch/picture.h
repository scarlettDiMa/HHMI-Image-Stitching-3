#ifndef PICTURE_H
#define PICTURE_H
#include <string>
#include <opencv2\core\core.hpp>
#include "point.h"

class Picture
{
public:
	Picture() {}

	std::string name;
	cv::Mat img;
	cv::Mat img_calc;
	cv::Mat img_disp;
	cv::Mat rotated;

	int prev_pic;
	int next_pic;
	int index;
	int stitch_type;
	double angle;
	double gb_angle;
	double prev_gb_angle;
	int overal_height;
	int overal_width;
	Point panCoord;

	// coordinated of origin four corners in the rotated image (cur + 1)
	Point left, upper, bottom, right;
		
	// coordinates of origin upperleft point in the rotated image (cur + 1)
	Point rotated_ul;

	// overlap part (cur) and (cur + 1)
	Point overlap_ul, overlap_br;

	// start point of the two images in the image stitched only by the two images (cur) and (cur + 1)
	// note: loc2 is the start point of the rotated image in the stitched image (cur + 1)
	Point loc1, loc2;
};

#endif PICTURE_H