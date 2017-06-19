//
//  cband_arc.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef cband_arc_h
#define cband_arc_h

#include "cband.h"

class CBandArc : public CBand {
public:
    void init(int lcount, float lcalcs, ofRectangle bounds, float ang1, float ang2);
    void setup();
    void draw(int mode, int n = 0);
    ofColor getColorBasedOnMode(int mode, int n, int frame, int idx);
    
    float start_angle;
    float end_angle;
};


#endif /* cband_arc_h */
