#pragma once
#include <opencv2/opencv.hpp>
#include "../types/types.h"
#include <vector>

// Blurs the faces in the image given their coordinates
cv::Mat blurFaces(const cv::Mat& image, const std::vector<FaceCoordinates>& faceCoordinates);