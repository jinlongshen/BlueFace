#include "blur_faces.h"
#include <opencv2/opencv.hpp>

cv::Mat blurFaces(const cv::Mat& image, const std::vector<FaceCoordinates>& faceCoordinates) {
    cv::Mat result = image.clone();
    for (const auto& face : faceCoordinates) {
        cv::Rect roi(face.x, face.y, face.width, face.height);
        cv::Mat faceRegion = result(roi);
        cv::GaussianBlur(faceRegion, faceRegion, cv::Size(0, 0), 10);
    }
    return result;
}