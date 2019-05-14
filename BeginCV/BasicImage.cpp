#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <sstream>


using namespace cv;
using namespace std;

int basicImage() {
	Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));
	String windowName = "Window with Blank Image";

	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}

int basicImage2() {
	Mat color = imread("./data/lena.jpg");
	Mat gray = imread("./data/lena.jpg", IMREAD_GRAYSCALE);

	if (!color.data) {
		cerr << "Could not open or find the image" << endl;
		return -1;
	}

	imwrite("./outdata/lenaGray.jpg", gray);

	int r = color.cols - 1;
	int c = color.rows - 1;

	cout << "color (r, c): (" << color.rows -1 << "," << color.cols -1 << ")" << endl;

	Vec3b pixel = color.at<Vec3b>(r, c);
	cout << "Pixel value (B, G, R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
	imshow("Lena BGR", color);
	imshow("Lena Gray", gray);
	waitKey(0);
	return 0;
}