#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);
 
    // apply two times pyrDown
    Mat dst, dst2;
   
    pyrDown(src,dst);
    pyrDown(dst,dst2);    
 
    namedWindow("pyrdown1",WINDOW_AUTOSIZE);
    imshow("pyrdown1",dst);

    namedWindow("pyrdown2",WINDOW_AUTOSIZE);
    imshow("pyrdown2",dst2);


    imwrite("sally.jpg",dst2);

    // apply two times pyrUp
   
    pyrUp(dst2,dst);
    pyrUp(dst,src);

    namedWindow("pyrup1",WINDOW_AUTOSIZE);
    imshow("pyrup1",dst);

    namedWindow("pyrup2",WINDOW_AUTOSIZE);
    imshow("pyrup2",src);

    waitKey(0);

    return 0;
}
