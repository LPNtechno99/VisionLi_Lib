#include <ExtractRotateRectArea.h>

cv::Mat ExtractRotateRectArea::Extract(cv::Mat srcMat, cv::Size2f sizeROI, cv::Point2f centerPoint, double angle)
{
	cv::RotatedRect _rotateRect;
	/*cv::Point2f _centerPoint;*/
	_rotateRect = cv::RotatedRect(centerPoint, sizeROI, angle);
	cv::Point2f vertices[4];
	_rotateRect.points(vertices);
	for (int i = 0; i < 4; i++)
		line(srcMat, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0), 1);
	cv::Size rotateRect_size = _rotateRect.size;
	if (angle < -45.) {
		angle += 90.0;
		cv::swap(rotateRect_size.width, rotateRect_size.height);
	}
	cv::Mat M, rotated, cropped;
	// get the rotation matrix
	M = cv::getRotationMatrix2D(_rotateRect.center, angle, 1.0);
	// perform the affine transformation
	warpAffine(srcMat, rotated, M, srcMat.size(), cv::INTER_CUBIC);
	// crop the resulting image
	getRectSubPix(rotated, rotateRect_size, _rotateRect.center, cropped);

	return cropped;

}