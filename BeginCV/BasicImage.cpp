#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "BasicImage.h"
#include <cmath>

using namespace cv;
using namespace std;

String lenaImageFilePath = "./data/lena.jpg";

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
	Mat color = imread(lenaImageFilePath);
	Mat gray = imread(lenaImageFilePath, IMREAD_GRAYSCALE);

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

#pragma region ImgEffectsChap4
void showHistogram(Mat imge)
{
	vector<Mat> bgr;
	split(imge, bgr);
	int numbins = 256;

	float range[] = { 0, 256 };
	const float* histRange = { range };

	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr[0], 1, 0, Mat(), b_hist, 1, &numbins, &histRange);
	calcHist(&bgr[1], 1, 0, Mat(), g_hist, 1, &numbins, &histRange);
	calcHist(&bgr[2], 1, 0, Mat(), r_hist, 1, &numbins, &histRange);

	int width = 512;
	int height = 300;

	Mat histImage(height, width, CV_8UC3, Scalar(20, 20, 20));

	normalize(b_hist, b_hist, 0, height, NORM_MINMAX);
	normalize(g_hist, g_hist, 0, height, NORM_MINMAX);
	normalize(r_hist, r_hist, 0, height, NORM_MINMAX);

	int binStep = cvRound((float)width / (float)numbins);

	for (int i = 1; i < numbins; i++) {
		line(histImage,
			Point(binStep * (i - 1), height - cvRound(b_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0)
		);

		line(histImage,
			Point(binStep * (i - 1), height - cvRound(g_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(g_hist.at<float>(i))),
			Scalar(0,255, 0)
		);

		line(histImage,
			Point(binStep * (i - 1), height - cvRound(r_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255)
		);
	}

	imshow("Histogram", histImage);
}

int initEffects(int effect) {
	Mat imge = imread(lenaImageFilePath);
	namedWindow("Input");

	showHistogram(imge);
	
	imshow("Input", imge);

	waitKey(0);

	return 0;
}
#pragma endregion