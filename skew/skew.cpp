#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("sally.jpg",CV_LOAD_IMAGE_COLOR);
 
    // skew
    Mat dst;
    double m = 1/tan(M_PI/3);   
    Mat M = (Mat_<double>(2,3) << 1, m, 0, 0, 1, 0);
    warpAffine(src,dst,M,Size(src.cols+0.5*src.cols,src.rows));
    

    namedWindow("skew",WINDOW_AUTOSIZE);
    imshow("skew",dst);

    imwrite("skew.jpg",dst);


    waitKey(0);

    return 0;
}
