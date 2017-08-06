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

using namespace std;
using namespace cv;

graphics::graphics()
{
    namedWindow( "RENDER", CV_WINDOW_AUTOSIZE );
    namedWindow( "BLUR", CV_WINDOW_AUTOSIZE );
}

void graphics::Render(Mat renderimage)
{
    imshow("RENDER", renderimage);
}

