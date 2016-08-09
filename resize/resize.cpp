#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);
 
    
    Mat dst;
   
    // apply scale
    
    resize(src,dst,Size(0,0),0.5,0.5); 
    

    namedWindow("original",WINDOW_AUTOSIZE);
    imshow("original",src);

    namedWindow("scaled",WINDOW_AUTOSIZE);
    imshow("scaled",dst);

    imwrite("sally.jpg",dst);

    waitKey(0);

    return 0;
}
