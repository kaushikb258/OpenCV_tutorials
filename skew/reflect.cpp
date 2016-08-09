#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("sally.jpg",CV_LOAD_IMAGE_COLOR);
 
    // reflect

    Mat dsth, dstv, dst;

    Mat Mh = (Mat_<double>(2,3) << -1, 0, src.cols, 0, 1, 0);
    Mat Mv = (Mat_<double>(2,3) << 1, 0, 0, 0, -1, src.rows);
    Mat M = (Mat_<double>(2,3) << -1, 0, src.cols, 0, -1, src.rows);

    warpAffine(src,dsth,Mh,src.size());
    warpAffine(src,dstv,Mv,src.size());    
    warpAffine(src,dst,M,src.size());

    namedWindow("h-ref",WINDOW_AUTOSIZE);
    imshow("h-ref",dsth);

    namedWindow("v-ref",WINDOW_AUTOSIZE);
    imshow("v-ref",dstv);

    namedWindow("ref",WINDOW_AUTOSIZE);
    imshow("ref",dst);

 
    waitKey(0);

    return 0;
}
