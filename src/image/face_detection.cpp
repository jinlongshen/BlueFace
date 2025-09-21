#include "face_detection.h"

FaceDetector::FaceDetector()
{
    // Load Haar cascade for face detection (adjust path as needed)
    faceCascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml");
}

std::vector<FaceCoordinates> FaceDetector::detectFaces(const cv::Mat &image)
{
    std::vector<cv::Rect> faces;
    std::vector<FaceCoordinates> result;
    faceCascade.detectMultiScale(image, faces, 1.1, 4, 0, cv::Size(30, 30));
    for (const auto &face : faces)
    {
        result.push_back({face.x, face.y, face.width, face.height});
    }
    return result;
}