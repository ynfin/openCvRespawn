//
//  graphics.cpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 03/07/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#include "graphics.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <sstream>

using namespace std;
using namespace cv;

graphics::graphics()
{


    
    namedWindow( "RENDER", CV_WINDOW_AUTOSIZE );
    namedWindow( "MASK", CV_WINDOW_AUTOSIZE );
}

void graphics::Render(Mat renderimage)
{
    imshow("RENDER", renderimage);
}

void graphics::Render(Mat renderimage, double fps)
{
    ostringstream strs;
    strs << fps;
    
    putText(renderimage, strs.str(), cvPoint( 20, 20 ), FONT_HERSHEY_SIMPLEX, 0.8, cvScalar(255,255,255),1,CV_AA);
    imshow("RENDER", renderimage);
}

Mat DrawCircle(Mat inputimage, Point center)
{
    circle(inputimage, center, 30, Scalar( 0, 0, 255 ));
    return inputimage;
}

