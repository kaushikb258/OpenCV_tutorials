#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
  const int side=800;
  const int npixels=55000;

  int i,j;
  Mat s1=Mat::zeros(side, side, CV_8UC1);
  Mat s2=s1.clone();
  circle(s1, Point(side/2, side/2), side/2, 255, -1);

  imshow("s1",s1);

  for (int k=0;k<npixels;k++)
  {
  i = rand()%side;
  j = rand()%side;
  s2.at<uchar>(i,j)=255;
  }

  Mat r;
  bitwise_and(s1,s2,r);

  imshow("s2", s2);
  imshow("r", r);

  int Acircle = countNonZero(r);
  int Asquare = countNonZero(s2);
  float Pi=4*(float)Acircle/Asquare;
  cout << "Estimated value of Pi: " << Pi << endl;

  waitKey();
  exit(0);
  return 0;
}
