#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Binaryzation
{
public:
	static cv::Mat threshold(cv::Mat srcMat, int value);
	static cv::Mat thresholdInv(cv::Mat srcMat, int value);
};