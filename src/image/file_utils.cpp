#include "file_utils.h"

#include <filesystem>
#include <opencv2/imgcodecs.hpp>

cv::Mat loadImage(const std::string &filePath)
{
    return cv::imread(filePath);
}

bool fileExists(const std::string &fileName)
{
    return std::filesystem::exists(fileName);
}

std::string saveImage(const cv::Mat &image, const std::string &originalFileName)
{
    std::filesystem::path path(originalFileName);
    std::string baseName = path.stem().string();
    std::string extension = path.extension().string();
    std::string dir = path.parent_path().string();
    std::string newFileName = dir + "/" + baseName + "_blurred" + extension;
    int counter = 1;

    while (fileExists(newFileName))
    {
        newFileName = dir + "/" + baseName + "_blurred(" + std::to_string(counter) + ")" + extension;
        counter++;
    }

    cv::imwrite(newFileName, image);
    return newFileName;
}