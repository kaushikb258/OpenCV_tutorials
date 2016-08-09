#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void convert2YCrCb(vector<Mat>, Mat, Mat, Mat);


int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat X=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat Y=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat Z=Mat::zeros(src.rows, src.cols, CV_8UC3);
  
    
    vector<Mat> BGR;
    split(src, BGR);
       

    convert2YCrCb(BGR,X,Y,Z); 
   
    
    imwrite("X_image.jpg",X);
    imwrite("Y_image.jpg",Y);
    imwrite("Z_image.jpg",Z);
     

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void convert2YCrCb(vector<Mat>rgb, Mat dst1, Mat dst2, Mat dst3)
{

  const int cols = dst1.cols;
  const int rows = dst1.rows;
  uchar r, g, b, Y, Cr, Cb;
  int i, j;
  uchar delta = 128;

  for (i=0; i<dst1.rows; i++)
  {
   for (j=0; j<dst1.cols; j++)
   {

    b = rgb[0].at<uchar>(i,j);
    g = rgb[1].at<uchar>(i,j);
    r = rgb[2].at<uchar>(i,j);

    Y = 0.299*r + 0.587*g + 0.114*b;
    Cr = (r-Y)*0.713 + delta;
    Cb = (b-Y)*0.564 + delta;

    dst1.at<Vec3b>(i,j)[2] = Y;
    dst2.at<Vec3b>(i,j)[1] = Cr;
    dst3.at<Vec3b>(i,j)[0] = Cb;
    
   }
  }
       
}

//------------------------------------------------------------------------

