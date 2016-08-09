#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Callback functions declarations
void cbMouse(int event, int x, int y, int flags, void*);
void tb1_Callback(int value, void *);
void tb2_Callback(int value, void *);
void checkboxCallBack(int state, void *);
void radioboxCallBack(int state, void *id);
void pushbuttonCallBack(int, void *font);

// Global definitions and variables
Mat orig_img, tmp_img;
const char main_win[]="main_win";
char msg[50];

int main(int, char* argv[]) {
  const char track1[]="TrackBar 1";
  const char track2[]="TrackBar 2";
  const char checkbox[]="Check Box";
  const char radiobox1[]="Radio Box1";
  const char radiobox2[]="Radio Box2";
  const char pushbutton[]="Push Button";
  int tb1_value = 50; // Initial value of trackbar 1
  int tb2_value = 25; // Initial value of trackbar 1

  orig_img = imread(argv[1]); // Open and read the image
  if (orig_img.empty()) {
    cout << "Error!!! Image cannot be loaded..." << endl;
    return -1;
  }
  namedWindow(main_win); // Creates main window
  // Creates a font for adding text to the image
  QtFont font = fontQt("Arial", 20, Scalar(255,0,0,0),
    QT_FONT_BLACK, QT_STYLE_NORMAL);
  // Creation of CallBack functions
    setMouseCallback(main_win, cbMouse, NULL);
    createTrackbar(track1, main_win, &tb1_value,
      100, tb1_Callback);
    createButton(checkbox, checkboxCallBack, 0, 
     QT_CHECKBOX);
    // Passing values (font) to the CallBack
    createButton(pushbutton, pushbuttonCallBack,
      (void *)&font, QT_PUSH_BUTTON);
    createTrackbar(track2, NULL, &tb2_value,
      50, tb2_Callback);
    // Passing values to the CallBack
    createButton(radiobox1, radioboxCallBack,
      (void *)radiobox1, QT_RADIOBOX);
    createButton(radiobox2, radioboxCallBack,
      (void *)radiobox2, QT_RADIOBOX);

  imshow(main_win, orig_img); // Shows original image
  cout << "Press any key to exit..." << endl;
  waitKey(); // Infinite loop with handle for events
  return 0;
}
