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


Mat imageInput;
Mat imageProcessedHSV;
Mat imageProcessedRGB;
Mat imageProcessedGray;
Mat imageProcessedGrayGauss;
Mat imageProcessedGrayErode;
Mat imageProcessedGrayDilate;

Ptr<BackgroundSubtractor> pMOG2;

processing::processing()
{

}

Mat processing::CreateStaticBackground(deque<Mat> inputFrames)
{
    Mat fgMaskMOG2;
    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
    int sampleSize = static_cast<int>(inputFrames.size());
    Mat avgImg;
    
    avgImg.create(inputFrames.front().size(),CV_32FC3);
    
    for(int i = 1; i < sampleSize; i++)
    {
        Mat iterateFrame = inputFrames.at(i);
        accumulate(inputFrames.at(i), avgImg);
    }
    
    //avgImg = avgImg / sampleSize;
    avgImg.convertTo(avgImg,CV_8U);
    
    return avgImg;
}


void processing::Segment(Mat inputMat)
{
    GaussianBlur(inputMat, imageProcessedGrayGauss, Size(9,9), 9);
    imshow("BLUR", imageProcessedGrayGauss);
}

