//
//  color_bands1.h
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-18.
//
//

#ifndef color_bands1_h
#define color_bands1_h

#include "ofMain.h"
#include "constants.h"
#include "cb1_border.h"
#include "cband_angled.h"
#include "cband_vertical.h"
#include "cband_arc.h"
#include "ofxLayerMask.h"

using namespace Constants;

class ColorBands1 : public ofBaseApp {

public:
    void            setup();
    void            draw();
    void            keyPressed(int key);

private:
    ofxLayerMask    mask1, mask2, mask3;
    CB1Border1      border1;
    CB1Border2      border2;
    CB1Border3      border3;
    CBandAngled     band1;
    CBandVertical   band2;
    CBandArc        band3;
    int             framerate;
    int             mode;
    int             last_color;
    float           line_width;
};

#endif /* color_bands1_h */

