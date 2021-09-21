
#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

#include <iostream>

#include <opencv2/opencv.hpp>

void render() {
    const int width    = 1024;
    const int height   = 768;
    // std::vector<Vec3f> framebuffer(width*height);

    cv::Mat save_img(cv::Size(width, height), CV_8UC3, cv::Scalar(0,0,0));

    for (size_t j = 0; j<width; j++) {
        for (size_t i = 0; i<height; i++) {
            save_img.at<cv::Vec3b>(i, j)[0] = 0;
            save_img.at<cv::Vec3b>(i, j)[1] = 255*j/width;
            save_img.at<cv::Vec3b>(i, j)[2] = 255*i/height;
            }
    }
    std::string outPath = "test.png";
    cv::imwrite(outPath, save_img);
    // std::ofstream ofs; // save the framebuffer to file
    // ofs.open("./out.ppm");
    // ofs << "P6\n" << width << " " << height << "\n255\n";
    // for (size_t i = 0; i < height*width; ++i) {
    //     for (size_t j = 0; j<3; j++) {
    //         ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
    //     }
    // }
    // ofs.close();
    std::cout << "image saved to " <<  outPath;
}

int main() {
    render();

    return 0;
}