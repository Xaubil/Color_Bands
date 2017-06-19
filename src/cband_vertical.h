//
//  cband_vertical.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef cband_vertical_h
#define cband_vertical_h

#include "cband.h"

class CBandVertical : public CBand {
public:
    void init(int lcount, float lcalc, ofRectangle bounds, bool horizontal = false);
    void setup();
    void draw(int mode, int n = 0);
    ofColor getColorBasedOnMode(int mode, int n, int frame, int idx);
    
    bool horizontal;
};

#endif /* cband_vertical_h */
