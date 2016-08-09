#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void convert2gray(Mat, Mat);


int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat dst=Mat::zeros(src.rows, src.cols, CV_8UC1);  

    convert2gray(src,dst);

    imwrite("graysally.jpg",dst);

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void convert2gray(Mat src, Mat dst)
{

  
  int i, j;
  Vec3b intensity;
  uchar r, g, b;

  for (i=0; i<dst.rows; i++)
  {
   for (j=0; j<dst.cols; j++)
   {
    intensity = src.at<Vec3b>(i,j);
    b = intensity.val[0];
    g = intensity.val[1];
    r = intensity.val[2];
    dst.at<uchar>(i,j) = 0.299*r + 0.587*g + 0.114*b;
   }
  }
       
}

//------------------------------------------------------------------------

