#include <boost/program_options.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "gui/gui_window.h"
#include "image/blur_faces.h"
#include "image/face_detection.h"
#include "image/file_utils.h"

namespace po = boost::program_options;

FaceDetector faceDetector;

int main(int argc, char **argv)
{
    std::string filename;

    po::options_description desc("Allowed options");
    desc.add_options()("help,h", "produce help message")("file,f", po::value<std::string>(), "input filename");

    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    }
    catch (const po::error &ex)
    {
        std::cerr << "Error parsing command line: " << ex.what() << std::endl;
        return 1;
    }

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    if (vm.count("file"))
    {
        filename = vm["file"].as<std::string>();
        std::cout << "Filename provided: " << filename << std::endl;

        if (fileExists(filename))
        {
            auto img = loadImage(filename);
            auto faces = faceDetector.detectFaces(img);

            std::vector<FaceRegion> faceRegions;
            for (const auto &face : faces)
            {
                cv::Rect rect(face.x, face.y, face.width, face.height);
                faceRegions.push_back({rect, false});
            }

            MouseContext context;
            context.original = img.clone();
            context.faces = faceRegions;

            // Draw initial rectangles and blur
            cv::Mat initialDisplay = context.original.clone();
            for (const auto &region : context.faces)
            {
                if (region.blurred)
                {
                    cv::Mat roi = initialDisplay(region.rect);
                    cv::GaussianBlur(roi, roi, cv::Size(0, 0), 30);
                }
                cv::rectangle(initialDisplay, region.rect, cv::Scalar(0, 255, 0), 2);
            }

            cv::namedWindow("Interactive Blur");
            cv::setMouseCallback("Interactive Blur", onMouse, &context);
            cv::imshow("Interactive Blur", initialDisplay);
            while (cv::getWindowProperty("Interactive Blur", cv::WND_PROP_VISIBLE) >= 1)
            {
                int key = cv::waitKey(30);
                if (key >= 0)
                    break;
            }
            cv::destroyAllWindows();

            // Collect final blurred faces
            std::vector<FaceCoordinates> finalFaces;
            for (const auto &region : context.faces)
            {
                if (region.blurred)
                {
                    finalFaces.push_back({region.rect.x, region.rect.y, region.rect.width, region.rect.height});
                }
            }

            if (!finalFaces.empty())
            {
                auto blurredImg = blurFaces(img, finalFaces);
                auto newFileName = saveImage(blurredImg, filename);
                std::cout << "Image saved to: " << newFileName << std::endl;

                cv::imshow("Image Viewer", blurredImg);
                while (cv::getWindowProperty("Image Viewer", cv::WND_PROP_VISIBLE) >= 1)
                {
                    int key = cv::waitKey(30);
                    if (key >= 0)
                        break;
                }
                cv::destroyAllWindows();
            }
            else
            {
                std::cout << "No faces were blurred. Skipping save." << std::endl;
            }
        }
        else
        {
            std::cerr << "File does not exist: " << filename << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "No filename provided. Use --file <filename> to specify one." << std::endl;
    }

    return 0;
}
