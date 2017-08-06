//
//  processing.hpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 03/07/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#ifndef processing_hpp
#define processing_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class processing
{
    
    public:
        processing();
        void Segment(Mat);
        Mat CreateStaticBackground(deque<Mat>);
        //vector<Point2f> processNewImageForMid(Mat);
    private:
    
    
};

#endif /* processing_hpp */
