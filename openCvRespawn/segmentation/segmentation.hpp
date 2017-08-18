//
//  segmentation.hpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 10/08/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#ifndef segmentation_hpp
#define segmentation_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class segmentation
{
  public:
    segmentation();
    Mat Update(Mat);

  private:
    Ptr<BackgroundSubtractor> mog2;
    Mat fgmask;
    Mat bgimg;
    
    deque<double> fpsAvg;
};

#endif /* segmentation_hpp */
