#pragma once
#include <string>
#include <opencv2/opencv.hpp>

cv::Mat loadImage(const std::string& filePath);
std::string saveImage(const cv::Mat& image, const std::string& originalFileName);
bool fileExists(const std::string& fileName);

struct ImageData {
    std::string src;
    int width;
    int height;
};

struct FaceCoordinates {
    int x;
    int y;
    int width;
    int height;
};