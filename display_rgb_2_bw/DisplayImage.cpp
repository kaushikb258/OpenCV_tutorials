#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char* argv[])
{

    Mat in_image, out_image;
    in_image = imread(argv[1],IMREAD_UNCHANGED);

    
    if (in_image.empty())
    {
        cout<<" No image data \n";
        return -1;
    }

    
    namedWindow(argv[1], WINDOW_AUTOSIZE );
    namedWindow(argv[2], WINDOW_AUTOSIZE );

    
    imshow(argv[1], in_image);
    cvtColor(in_image, out_image, COLOR_BGR2GRAY);
    imshow(argv[2], in_image);
    cout<<"press any key \n";
    waitKey();
    imwrite(argv[2],out_image);
    return 0;

}
