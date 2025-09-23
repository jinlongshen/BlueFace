#ifndef IMAGE_FACE_DETECTION_H
#define IMAGE_FACE_DETECTION_H

#include <opencv2/opencv.hpp>
#include <vector>

#include "face_detection.h"
#include "types.h"

class FaceDetector
{
  public:
    FaceDetector();
    std::vector<FaceCoordinates> detectFaces(const cv::Mat &image);

  private:
    cv::CascadeClassifier faceCascade;
};

#endif // IMAGE_FACE_DETECTION_H