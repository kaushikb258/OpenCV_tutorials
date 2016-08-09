#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void convert2CIE(vector<Mat>, Mat, Mat, Mat);


int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat X=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat Y=Mat::zeros(src.rows, src.cols, CV_8UC3);
    Mat Z=Mat::zeros(src.rows, src.cols, CV_8UC3);
  
    
    vector<Mat> BGR;
    split(src, BGR);
       

    convert2CIE(BGR,X,Y,Z); 
   
    
    imwrite("X_image.jpg",X);
    imwrite("Y_image.jpg",Y);
    imwrite("Z_image.jpg",Z);
     

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void convert2CIE(vector<Mat>rgb, Mat dst1, Mat dst2, Mat dst3)
{

  const int cols = dst1.cols;
  const int rows = dst1.rows;
  uchar r, g, b, x, y, z;
  int i, j;

  for (i=0; i<dst1.rows; i++)
  {
   for (j=0; j<dst1.cols; j++)
   {

    b = rgb[0].at<uchar>(i,j);
    g = rgb[1].at<uchar>(i,j);
    r = rgb[2].at<uchar>(i,j);

    x = 0.412453*r + 0.357580*g + 0.180423*b;
    y = 0.212671*r + 0.715160*g + 0.072169*b;
    z = 0.019334*r + 0.119193*g + 0.950227*b;

    dst1.at<Vec3b>(i,j)[2] = x;
    dst2.at<Vec3b>(i,j)[1] = y;
    dst3.at<Vec3b>(i,j)[0] = z;
    
   }
  }
       
}

//------------------------------------------------------------------------

