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
        Mat FindTargetCoords(Mat);
    
    private:
        void Segment();
        void FindCenterMass();
    
        // the variables used while determining the coordinates of the targets
        Mat segmentedImageInput;
        Mat segmentedGauss;

        vector<Point> targets;
};

#endif /* processing_hpp */
