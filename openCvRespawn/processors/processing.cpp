//
//  processing.cpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 03/07/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#include "processing.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

processing::processing()
{
    namedWindow("processed", WINDOW_NORMAL);
}

//vector<Point> processing::FindTargetCoords(Mat inputimage)
Mat processing::FindTargetCoords(Mat inputimage)
{
    segmentedImageInput = inputimage;
    GaussianBlur(segmentedImageInput, segmentedGauss, Size(15, 15), 15);
    
    SimpleBlobDetector blobdetect;
    blobdetect = 
    
    
    return segmentedGauss;
}

void processing::FindCenterMass()
{
    
}

void processing::Segment()
{
    GaussianBlur(segmentedImageInput, segmentedGauss, Size(9, 9), 9);
    imshow("processed", segmentedGauss);
}

