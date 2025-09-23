#ifndef IMAGE_BLUR_FACES_H
#define IMAGE_BLUR_FACES_H

#include "blur_faces.h"

#include <vector>

#include "types.h"

cv::Mat blurFaces(const cv::Mat &image, const std::vector<FaceCoordinates> &faceCoordinates);

void onMouse(int event, int x, int y, int, void *userdata);

#endif // IMAGE_BLUR_FACES_H