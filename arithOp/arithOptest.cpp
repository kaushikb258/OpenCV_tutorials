#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{

    Mat img1 = imread("kaushik.jpg",IMREAD_GRAYSCALE);
    if (img1.empty())
    {
     cout<<"cannot load image \n";
     return -1;
    } 

    imshow("Original",img1);

    cout<<"# rows in image: "<<img1.rows<<"\n";
    cout<<"# cols in image: "<<img1.cols<<"\n"; 
  
    // create mask image
    Mat mask(img1.rows,img1.cols,CV_8UC1,Scalar(0,0,0));
    Point center(img1.rows/2,img1.cols/2);
    
    const int radius = 1000;
    circle(mask,center,radius,255,-1);   
    imshow("Mask",mask); 

    // perform AND
    Mat r;
    bitwise_and(img1,mask,r);
    
    // fill outside with white
    const uchar white = 255;
    for (int i=0; i<r.rows; i++)
    {
     for (int j=0; j<r.cols; j++)
     {
      if (!mask.at<uchar>(i,j))
      {
       r.at<uchar>(i,j) = white;
      }
     } 
    }

    imshow("Result",r); 
   
    waitKey(0);
    exit(0);
    return 0;
}
