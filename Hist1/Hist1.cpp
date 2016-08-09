#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

void histogramcalculation(const Mat &Image, Mat &histoImage)
{
  int histSize = 255;

  // Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  vector<Mat> bgr_planes;
  split(Image, bgr_planes );

  // Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  // Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  // Draw for each channel
  for( int i = 1; i < histSize; i++ ){
  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) , Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ), Scalar( 255, 0, 0), 2, 8, 0  );
  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) , Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ), Scalar( 0, 255, 0), 2, 8, 0  );
  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) , Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ), Scalar( 0, 0, 255), 2, 8, 0  );
  }

  histoImage= histImage;
}


int main( int,  char *argv[] )
{
  Mat src, imageq;
  Mat histImage;

  // Read original image
  src = imread( "kaushik.jpg");
  if(! src.data )
   {  printf("Error imagen\n"); exit(1); }

  // Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  // Display results
  imshow( "Source image", src );

  // Calculate the histogram to each channel of the source image
  histogramcalculation(src, histImage);

  // Display the histogram for each colour channel
  imshow("Colour Image Histogram", histImage );

  // Equalized Image

  // Apply Histogram Equalization to each channel
  equalizeHist(bgr_planes[0], bgr_planes[0]);
  equalizeHist(bgr_planes[1], bgr_planes[1]);
  equalizeHist(bgr_planes[2], bgr_planes[2]);

  // Merge the equalized image channels into the equalized image
  merge(bgr_planes, imageq );

  // Display Equalized Image
  imshow( "Equalized Image ", imageq );

  // Calculate the histogram to each channel of the equalized image
  histogramcalculation(imageq, histImage);

  // Display the Histogram of the Equalized Image
  imshow("Equalized Colour Image Histogram", histImage );


  // Wait until user exits the program
  waitKey();
  exit(0); 
  return 0;
}
