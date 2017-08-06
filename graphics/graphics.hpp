//
//  graphics.hpp
//  openCvRespawn
//
//  Created by Yngve Finnestad on 03/07/2017.
//  Copyright © 2017 Yngve Finnestad. All rights reserved.
//

#ifndef graphics_hpp
#define graphics_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class graphics
{
    
public:
    graphics();
    void Render(Mat);
    
private:
    
};

#endif /* graphics_hpp */
