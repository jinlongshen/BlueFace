#ifndef IMAGE_FILE_UTILS_H
#define IMAGE_FILE_UTILS_H

#include <string>

#include <opencv2/opencv.hpp>

cv::Mat loadImage(const std::string &filePath);
std::string saveImage(const cv::Mat &image, const std::string &originalFileName);
bool fileExists(const std::string &fileName);

#endif // IMAGE_FILE_UTILS_H