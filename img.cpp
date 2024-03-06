#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

using namespace cv;
using namespace std;

int main()
{
    Mat img(400, 500, CV_8UC3);

    string text = "Hello Discord!";
    Point textOrg(100, img.rows / 2);
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 2;
    Scalar color(200, 100, 50);



    rectangle(img, Rect(50, 50, 100, 100), Scalar(0, 0, 255), 2);
    circle(img, Point(350, 75), 25, Scalar(255, 0, 0), 2);
    circle(img, Point(450, 75), 25, Scalar(255, 0, 0), -1);
    rectangle(img, Rect(50, img.rows - 100, 100, 100), Scalar(0, 255, 255), -1);
    line(img, Point(500, img.rows - 190), Point(img.cols - 100, img.rows - 1), Scalar(0, 255, 0), 2);

    string sizeText = "Image Size: " + to_string(img.cols) + " x " + to_string(img.rows);
    Point sizeTextOrg(10, 30);

    putText(img, text, textOrg, fontFace, fontScale, color);
    putText(img, sizeText, sizeTextOrg, fontFace, 0.5, color);

    imshow("img", img);

   

    Mat qu1 = img(Rect(0, 0, img.cols / 2, img.rows / 2)).clone();
    Mat qu2 = img(Rect(img.cols / 2, 0, img.cols / 2, img.rows / 2)).clone();
    Mat qu3 = img(Rect(0, img.rows / 2, img.cols / 2, img.rows / 2)).clone();
    Mat qu4 = img(Rect(img.cols / 2, img.rows / 2, img.cols / 2, img.rows / 2)).clone();

    imshow("1", qu1);
    imshow("2", qu2);
    imshow("3", qu3);
    imshow("4", qu4);

    


    Mat circularMask = Mat::zeros(img.size(), img.type());
    circle(circularMask, Point(img.cols / 2, img.rows / 2), 100, Scalar(255, 255, 255), -1);


    Mat inMask;
    bitwise_not(circularMask, inMask);


    Mat maskedImage;
    img.copyTo(maskedImage, circularMask);

    img.setTo(Scalar(255, 255, 255), inMask);

    imshow("Mask", img);



    waitKey(0);



    return 0;
}
