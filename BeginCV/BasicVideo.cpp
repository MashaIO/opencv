#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

int basicCamera() {
	VideoCapture cam(0);

	if (cam.isOpened() == false) {
		cerr << "Cannot open the video" << endl;
		cin.get();
		return -1;
	}

	double dWidth = cam.get(CAP_PROP_FRAME_WIDTH);
	double dHeight = cam.get(CAP_PROP_FRAME_HEIGHT);

	cout << "Resolution of the video: " << dWidth << " x " << dHeight << endl;

	string window_name = "My Camera Feed";
	namedWindow(window_name);

	while (true) {
		Mat frame;
		bool isSuccess = cam.read(frame);

		if (isSuccess == false) {
			cout << "Video camera is disconnected" << endl;
			cin.get();
			break;
		}

		imshow(window_name, frame);

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by user.  Stopping the video" << endl;
			break;
		}
	}

	return 0;
}