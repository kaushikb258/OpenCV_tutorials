#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("sally.jpg",CV_LOAD_IMAGE_COLOR);
 
    // translation
    Mat dst;   
    Mat M = (Mat_<double>(2,3) << 1, 0, 200, 0, 1, 150);
    warpAffine(src,dst,M,src.size());
    

    // rotation
    Mat dst1;
    Mat M1 = getRotationMatrix2D(Point2f(src.cols/2,src.rows/2),45,1);
    warpAffine(src,dst1,M1,src.size());


    namedWindow("trans",WINDOW_AUTOSIZE);
    imshow("trans",dst);

    namedWindow("rot",WINDOW_AUTOSIZE);
    imshow("rot",dst1);


    waitKey(0);

    return 0;
}
