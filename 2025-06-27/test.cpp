#include <opencv2/opencv.hpp>

int main() {

    cv::Mat cv_img = cv::imread("test.png");
    cv::imshow("test", cv_img);
    cv::waitKey(0);
    return 0;
}

//g++ test.cpp -std=c++17 -ldlib -lpthread -ljpeg -lpng -lwebp $(pkg-config --cflags --libs opencv4) -o app
