#include<opencv2/opencv.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

void comp_grad(Mat, Mat);
void normalize(Mat);



int main()
{

    Mat src = imread("kaushik.jpg",CV_LOAD_IMAGE_COLOR);

    Mat R=Mat::zeros(src.rows, src.cols, CV_8UC1);
    Mat G=Mat::zeros(src.rows, src.cols, CV_8UC1);
    Mat B=Mat::zeros(src.rows, src.cols, CV_8UC1);
  
    
    vector<Mat> BGR;
    split(src, BGR);
    
  
    // compute gradients
    comp_grad(BGR[0],B);
    comp_grad(BGR[1],G);
    comp_grad(BGR[2],R);

      
    // normalize to 0-255 range
    normalize(R);
    normalize(G);
    normalize(B);

       
    // merge R, G and B into one
   
    vector<Mat> array_to_merge;

    
    array_to_merge.push_back(B);
    array_to_merge.push_back(G);
    array_to_merge.push_back(R);

       
    Mat dst;
    merge(array_to_merge, dst);


    namedWindow("original",WINDOW_AUTOSIZE);
    imshow("original",src);

    namedWindow("mygrad",WINDOW_AUTOSIZE);
    imshow("mygrad",dst);

    imwrite("grad.jpg",dst);

    waitKey(0);
    exit(0);
    return 0;

}


//------------------------------------------------------------------------

void comp_grad(Mat rgb, Mat dst)
{
   
  int i, j;
  int dx, dy;
 
    

    for (i=0; i<rgb.rows; i++)
    {
     for (j=0; j<rgb.cols; j++)
     {

      if(i==0)
      {
       // forward
       dx = rgb.at<uchar>(i+1,j) - rgb.at<uchar>(i,j);
      }
      else if(i==rgb.rows-1)
      {
       // backward
       dx = rgb.at<uchar>(i,j) - rgb.at<uchar>(i-1,j);
      }
      else
      {
       // central
       dx = (rgb.at<uchar>(i+1,j) - rgb.at<uchar>(i-1,j))/2;
      } 


      if(j==0)
      {
       // forward
       dy = rgb.at<uchar>(i,j+1) - rgb.at<uchar>(i,j);
      }
      else if(j==rgb.cols-1)
      {
       // backward
       dy = rgb.at<uchar>(i,j) - rgb.at<uchar>(i,j-1);
      }
      else
      {
       // central
       dy = (rgb.at<uchar>(i,j+1) - rgb.at<uchar>(i,j-1))/2;
      } 


      dst.at<uchar>(i,j) = sqrt(dx*dx + dy*dy);     

     }
    }
        

}

//------------------------------------------------------------------------

void normalize(Mat rgb)
{
   
  int i, j;
  int maxval, minval, val;  
  float num, den; 

  maxval = -1;
  minval = 257; 


    for (i=0; i<rgb.rows; i++)
    {
     for (j=0; j<rgb.cols; j++)
     {      
      val = rgb.at<uchar>(i,j);
      maxval = (maxval > val)? maxval : val;
      minval = (minval < val)? minval : val;
     }
    }

    for (i=0; i<rgb.rows; i++)
    {
     for (j=0; j<rgb.cols; j++)
     {      
      val = rgb.at<uchar>(i,j);
      num = (float)(val-minval);
      den = (float)(maxval-minval);      
      rgb.at<uchar>(i,j) = 255 - (uchar)(num/den*255);
     }
    }

        
}

//------------------------------------------------------------------------

