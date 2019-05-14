#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int matOps() {
	FileStorage fs("outdata/test.yml", FileStorage::WRITE);
	int fps = 5;
	fs << "fps" << fps;

	Mat m1 = Mat::eye(2, 3, CV_32F);
	Mat m2 = Mat::ones(3, 2, CV_32F);
	auto result = (m1 + 1).mul(m1 + 3);
	fs << "Result" << result;

	cout << "Reading test.yml" << endl;

	fs.release();

	FileStorage fs2("outdata/test.yml", FileStorage::READ);
	Mat r;
	fs2["Result"] >> r;
	cout << r << endl;

	int r1;
	fs2["fps"] >> r1;
	cout << r1 << endl;

	fs2.release();

	waitKey(0);
	return 0;
}