#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void HSV(vector<Mat>, Mat);


int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat dst=Mat::zeros(src.rows, src.cols, CV_8UC3);
  
    
    vector<Mat> BGR;
    split(src, BGR);
       
    
    HSV(BGR,dst); 
   
    
    imwrite("HSV_image.jpg",dst);
    

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void HSV(vector<Mat>rgb, Mat dst)
{

  const int cols = dst.cols;
  const int rows = dst.rows;
  uchar r, g, b, h, s, v;
  int i, j;
  float ri, gi, bi, var, hi, si, vi;
  float Cmax, Cmin, delta;

  
  for (i=0; i<dst.rows; i++)
  {
   for (j=0; j<dst.cols; j++)
   {


    b = rgb[0].at<uchar>(i,j);
    g = rgb[1].at<uchar>(i,j);
    r = rgb[2].at<uchar>(i,j);

    bi = (float)b/255.0;
    gi = (float)g/255.0;
    ri = (float)r/255.0;

    var = (ri>gi)? ri : gi;
    Cmax = (var > bi)? var : bi;

    var = (ri<gi)? ri : gi;
    Cmin = (var < bi)? var : bi;

    delta = Cmax - Cmin;


    if (Cmax != 0.0)
    {
     si = delta/Cmax;
    }
    else
    {
     si = 0;
    }


    if(delta == 0.0)
    {
     hi = 0.0;
    } 
    else if(Cmax == ri)
    {
     hi = 60.0*(gi-bi)/delta;
    }
    else if (Cmax == gi)
    {
     hi = 60.0*((bi-ri)/delta + 2.0);
    }
    else if (Cmax == bi)
    {
     hi = 60.0*((ri-gi)/delta + 4.0);
    } 

    if(hi < 0.0) hi += 360.0;


    vi = Cmax;


    // rescale 

    hi = hi/360*255.0;
    si = si*255.0;
    vi = vi*255.0;


    h = (uchar)hi;
    s = (uchar)si;
    v = (uchar)vi;

    dst.at<Vec3b>(i,j)[0] = h;
    dst.at<Vec3b>(i,j)[1] = s;
    dst.at<Vec3b>(i,j)[2] = v;
    
   }
  }
     

}

//------------------------------------------------------------------------

