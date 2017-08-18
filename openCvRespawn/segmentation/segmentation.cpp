//
//  segmentation.cpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 10/08/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#include "segmentation.hpp"
#include <numeric>

segmentation::segmentation()
{
    int windowHistory = 500; // default window setting
    int distanceTreshold = 16;
    int detectShadows = false;
    mog2 = createBackgroundSubtractorMOG2(windowHistory,distanceTreshold,detectShadows);
    
    //namedWindow("image", WINDOW_NORMAL);
    namedWindow("foreground mask", WINDOW_NORMAL);

}

Mat segmentation::Update(Mat inputimage)
{
    int64 start = cv::getTickCount();
    
    mog2->apply(inputimage, fgmask);
    mog2->getBackgroundImage(bgimg);
    
    double fps = cv::getTickFrequency() / (cv::getTickCount() - start);
    double duration = ((cv::getTickCount()-start)*(1/getTickFrequency()))*1000;
    cout << "segm loop duration: (dur/fps) " << duration << " / " << fps << endl;
    
    return fgmask;
}
