#include <opencv2/opencv.hpp>

using namespace cv;

int basicImage() {
	Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));
	String windowName = "Window with Blank Image";

	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}