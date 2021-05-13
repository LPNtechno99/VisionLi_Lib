#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

class ExtractRotateRectArea
{
public:
	static cv::Mat Extract(cv::Mat srcMat, cv::Size2f sizeROI, cv::Point2f centerPoint, double angle);
};
