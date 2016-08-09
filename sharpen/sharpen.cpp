#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    // Apply Sobel and Laplacian

    Mat dst, dst2;
    Sobel(src,dst,-1,1,1);
    Laplacian(src,dst2,-1);

    namedWindow("original",WINDOW_AUTOSIZE);
    imshow("original",src);  

    namedWindow("sobel",WINDOW_AUTOSIZE);
    imshow("sobel",dst);

    namedWindow("laplacian",WINDOW_AUTOSIZE);
    imshow("laplacian",dst2);

    waitKey(0);
    //exit(0);
    return 0;

}
