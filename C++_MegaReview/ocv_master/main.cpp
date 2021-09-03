# define _GLIBCXX_USE_CXX11_ABI 0
#include <opencv.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <objdetect.hpp>

int main()
{
    cv::String path("C:/Users/5106001995/Desktop/git/20210523LangReview/C++/ocv_master/Resources/lambo.png");
    cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);
    cv::imshow("Image", img);
    cv::waitKey(0);

    return 0;
}
