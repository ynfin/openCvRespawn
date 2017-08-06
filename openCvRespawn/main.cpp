#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "graphics.hpp"
#include "processing.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat workingImage;
Mat averageImage;
deque<Mat> backGroundImageQueue = deque<Mat>();

string testVidPath = "/Users/yngve/github/openCvRespawn/media/rotated_tracking_low_long.m4v";


int main(int argc, const char * argv[]) {
    
    processing processor = processing();
    graphics graph = graphics();
    VideoCapture capture(testVidPath);

    double fps = capture.get(CV_CAP_PROP_FPS);
    cout << "starting capture from source at " << fps << " FPS" << endl;
    
    if( !capture.isOpened()) throw "Error when reading file, check path and name";
    int frameCount = 0;
    
    int captureFrameHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    int captureFrameWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    
    namedWindow( "BACKGROUND", WINDOW_AUTOSIZE);
    
    while (true)
    {
        frameCount++;
        
        capture >> workingImage;
        if(workingImage.empty())
            break;
        
        backGroundImageQueue.push_front(workingImage);
        cout << "framebuffer " << backGroundImageQueue.size() << endl;
        
        if (backGroundImageQueue.size() > 200)
        {
            backGroundImageQueue.pop_back();
            averageImage = processor.CreateStaticBackground(backGroundImageQueue);
        
            // draw the original image
            graph.Render(averageImage);
        }
        
        // draw blurred
        processor.Segment(workingImage);
        
        // Wait until user press some key for 50ms
        int iKey = waitKey(20);
        if (iKey == 27){break;}
        
    }
    
    
    return 0;
    
    
}
