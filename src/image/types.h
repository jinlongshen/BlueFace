#ifndef TYPES_TYPES_H
#define TYPES_TYPES_H

#include <string>

#include <opencv2/imgcodecs.hpp>

struct ImageData
{
    std::string src;
    int width;
    int height;
};

struct FaceCoordinates
{
    int x;
    int y;
    int width;
    int height;
};

struct FaceRegion
{
    cv::Rect rect;
    bool blurred;
};

struct MouseContext
{
    cv::Mat original;
    std::vector<FaceRegion> faces;
};

#endif // TYPES_TYPES_H