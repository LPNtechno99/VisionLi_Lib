#include <Binaryzation.h>

cv::Mat Binaryzation::threshold(cv::Mat srcMat, int value)
{
	cv::Mat threshMat;
	if (srcMat.channels() == 3 || srcMat.channels() == 4)
		cv::cvtColor(srcMat, srcMat, cv::COLOR_BGR2GRAY);
	cv::threshold(srcMat, threshMat, value, 255, cv::THRESH_BINARY);
	return threshMat;
}
cv::Mat Binaryzation::thresholdInv(cv::Mat srcMat, int value)
{
	cv::Mat threshMat;
	if (srcMat.channels() == 3 || srcMat.channels() == 4)
		cv::cvtColor(srcMat, srcMat, cv::COLOR_BGR2GRAY);
	cv::threshold(srcMat, threshMat, value, 255, cv::THRESH_BINARY_INV);
	return threshMat;
}