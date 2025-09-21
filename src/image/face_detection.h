#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include "../types/types.h"

class FaceDetector {
public:
    FaceDetector();
    std::vector<FaceCoordinates> detectFaces(const cv::Mat& image);
private:
    cv::CascadeClassifier faceCascade;
};