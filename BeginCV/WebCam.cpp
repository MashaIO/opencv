#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

namespace bwcam {
	void setupCam() {
		VideoCapture camera;
		camera.open(0);
		if (!camera.isOpened()) {
			cerr << "ERROR: Cold not access the camera" << endl;
			exit(1);
		}
	}
}