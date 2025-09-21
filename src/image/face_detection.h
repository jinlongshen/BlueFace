#pragma once
#include "../types/types.h"
#include <opencv2/opencv.hpp>
#include <vector>

class FaceDetector
{
  public:
    FaceDetector();
    std::vector<FaceCoordinates> detectFaces(const cv::Mat &image);

  private:
    cv::CascadeClassifier faceCascade;
};