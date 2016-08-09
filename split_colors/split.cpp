#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void separate(int, vector<Mat>, Mat);


int main()
{

    Mat src = imread("images.png",CV_LOAD_IMAGE_COLOR);

    Mat R=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat G=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat B=Mat::zeros(src.rows, src.cols, CV_8UC3);
  
    
    vector<Mat> BGR;
    split(src, BGR);
    
      
    imwrite("B_image_gray.jpg",BGR[0]);
    imwrite("G_image_gray.jpg",BGR[1]);
    imwrite("R_image_gray.jpg",BGR[2]);
 

    separate(0,BGR,B);
    separate(1,BGR,G);
    separate(2,BGR,R);  

    
    imwrite("B_image.jpg",B);
    imwrite("G_image.jpg",G);
    imwrite("R_image.jpg",R);
     

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void separate(int channel, vector<Mat>rgb, Mat dst)
{

  const int cols = dst.cols;
  const int rows = dst.rows;

  int i, j;

  for (i=0; i<dst.rows; i++)
  {
   for (j=0; j<dst.cols; j++)
   {
    dst.at<Vec3b>(i,j)[channel] = rgb[channel].at<uchar>(i,j);
   }
  }
       
}

//------------------------------------------------------------------------

