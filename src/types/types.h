#pragma once
#include <string>

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