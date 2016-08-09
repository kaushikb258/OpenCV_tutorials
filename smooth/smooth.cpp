#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat dst, dst2;
    GaussianBlur(src,dst,Size(9,9),0,0);
    medianBlur(src,dst2,9);

    namedWindow("original",WINDOW_AUTOSIZE);
    imshow("original",src);

    namedWindow("gaussian blur",WINDOW_AUTOSIZE);
    imshow("gaussian blur",dst);

    namedWindow("median blur",WINDOW_AUTOSIZE);
    imshow("median blur",dst2);  

    waitKey(0);
    exit(0);
    return 0;

}
