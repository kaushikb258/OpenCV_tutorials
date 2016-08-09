#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);
 
    
    Mat dst, dst2, dst3;
   
    inRange(src,Scalar(0,0,10),Scalar(40,30,179),dst);

    Mat element = getStructuringElement(MORPH_ELLIPSE,Size(15,15));
    dilate(dst,dst2,element);    
    erode(dst2,dst3,element);

    namedWindow("segmented",WINDOW_AUTOSIZE);
    imshow("segmented",dst);

    namedWindow("dilation",WINDOW_AUTOSIZE);
    imshow("dilation",dst2);

    namedWindow("erosion",WINDOW_AUTOSIZE);
    imshow("erosion",dst3);

    waitKey(0);

    return 0;
}
