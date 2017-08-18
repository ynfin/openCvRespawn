#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "graphics.hpp"
#include "processing.hpp"
#include "segmentation.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat currentFrame;
Mat foregroundMask;
int frameCount = 0;

string testVidPath = "/Users/yngve/github/openCvRespawn/media/rotated_tracking_low_long.m4v";

int main(int argc, const char *argv[])
{

    // Make engines for processing and graphing
    processing processor = processing();
    graphics graph = graphics();
    segmentation segmentor = segmentation();

    // open capture stream from video file
    VideoCapture capture;
    //capture.open(testVidPath);
    capture.open(0);

    if (!capture.isOpened())
    {
        cerr << "can not open camera or video file" << endl;
        return -1;
    }

    capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    // go through each frame
    while (true)
    {

        int64 start = cv::getTickCount();

        frameCount++;
        capture >> currentFrame;
        if (currentFrame.empty())
            break;

        foregroundMask = segmentor.Update(currentFrame);
        foregroundMask = processor.FindTargetCoords(foregroundMask);

        // Wait until user press some key for 20ms
        int iKey = waitKey(20);
        if (iKey == 27)
        {
            break;
        }

        Mat colorMapImg;
        applyColorMap(foregroundMask, colorMapImg, COLORMAP_JET);
        graph.Render(colorMapImg);

        // -------- debug ---------------
        double fps = cv::getTickFrequency() / (cv::getTickCount() - start);
        double duration = ((cv::getTickCount() - start) * (1 / getTickFrequency())) * 1000;
        cout << "main loop duration: (dur/fps) " << duration << " / " << fps << endl;
    }

    destroyAllWindows();
    return 0;
}
