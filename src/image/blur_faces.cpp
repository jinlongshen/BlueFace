#include "blur_faces.h"
#include <opencv2/opencv.hpp>

cv::Mat blurFaces(const cv::Mat &image, const std::vector<FaceCoordinates> &faceCoordinates)
{
    cv::Mat result = image.clone();
    for (const auto &face : faceCoordinates)
    {
        cv::Rect roi(face.x, face.y, face.width, face.height);
        cv::Mat faceRegion = result(roi);
        cv::GaussianBlur(faceRegion, faceRegion, cv::Size(0, 0), 10);
    }
    return result;
}

void onMouse(int event, int x, int y, int, void *userdata)
{
    if (event != cv::EVENT_LBUTTONDOWN)
        return;
    if (userdata == nullptr)
        return;

    MouseContext *ctx = static_cast<MouseContext *>(userdata);
    cv::Mat display = ctx->original.clone();

    for (auto &region : ctx->faces)
    {
        if (region.rect.contains(cv::Point(x, y)))
        {
            region.blurred = !region.blurred;
        }

        if (region.blurred)
        {
            cv::Mat roi = display(region.rect);
            cv::GaussianBlur(roi, roi, cv::Size(0, 0), 30);
        }

        cv::rectangle(display, region.rect, cv::Scalar(0, 255, 0), 2);
    }

    cv::imshow("Interactive Blur", display);
}