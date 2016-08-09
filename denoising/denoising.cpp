#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat src = imread("sally.jpg",CV_LOAD_IMAGE_COLOR);
 
    // add noise
    Mat noisy = src.clone();   
    
    Mat noise(src.size(), src.type());
    randn(noise,0,50);
    noisy += noise;


    // denoise
    Mat dst;
    fastNlMeansDenoisingColored(noisy,dst,30,30,5,15);     


    namedWindow("noisy",WINDOW_AUTOSIZE);
    imshow("noisy",noisy);

    namedWindow("denoised",WINDOW_AUTOSIZE);
    imshow("denoised",dst);


    imwrite("noisy.jpg",noisy);
    imwrite("denoised.jpg",dst);

    waitKey(0);

    return 0;
}
