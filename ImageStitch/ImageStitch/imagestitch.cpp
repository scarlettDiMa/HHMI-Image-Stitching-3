// This was already included in "picture.h".
// Thank god for #include guards.
#include <opencv2\core\core.hpp>

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include "imagestitch.h"
#include <fstream>
#include <string>
#include "picture.h"

void ImageStitch::run()
{
	load_img();
}

// **************
// 1. Load photos
// **************
//
//   List of bugs:
// @ The rock pictures aren't in the folder.
void ImageStitch::load_img()
{
	std::ifstream fin("input.txt");
	std::string line;

	while (fin >> line)
	{
		if (line[0] == '*') break;

		// Read an image's name and data into a Picture object.
		Picture new_pic;
		new_pic.name = line;
		cv::Mat new_img = cv::imread(line);
		new_pic.img = new_img;

		// 1. Create an empty Mat with the dimensions of 'new_img'
		//    scaled by 'zoom_calc'.
		cv::Mat new_img_calc;
		new_img_calc.create(new_img.size().width * zoom_calc,
			new_img.size().height * zoom_calc, CV_8UC1);

		// 2. This function is in OpenCV's imgproc module.
		//    'new_img_calc' contains the scaled version of
		//    'new_img'.
		resize(new_img, new_img_calc, new_img_calc.size());

		// 3. Normalize the histogram for pixel intensity values
		//    in order to deal with light exposure.
		equalizeHist(new_img_calc, new_img_calc);

		// 4. Read 'new_img_calc' into the Picture object.
		new_pic.img_calc = new_img_calc;

		// Do the same four steps for 'new_img_disp'.
		cv::Mat new_img_disp;
		new_img_disp.create(new_img.size().width * zoom_disp,
			new_img.size().height * zoom_disp, CV_8UC1);
		resize(new_img, new_img_disp, new_img_calc.size());
		equalizeHist(new_img_calc, new_img_calc);
		new_pic.img_disp = new_img_disp;
		
		// Add to 'pics' vector.
		pics.push_back(new_pic);
	}

	fin.close();
}