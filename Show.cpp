#include <Show.h>

void ShowResult::Show(cv::Mat mat)
{
	cv::imshow("Image Result", mat);
	cv::waitKey(0);
}