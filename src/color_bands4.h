//
//  color_bands4.h
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-18.
//
//

#ifndef color_bands4_h
#define color_bands4_h

#include "ofMain.h"
#include "constants.h"
#include "cb4_border.h"
#include "cband_vertical.h"
#include "cband_arc.h"
#include "cband_angled.h"
#include "ofxLayerMask.h"

using namespace Constants;

class ColorBands4 : public ofBaseApp {
    
public:
    void            setup();
    void            draw();
    void            keyPressed(int key);

private:
    ofxLayerMask    mask1, mask2, mask3, mask4;
    CB4Border1      border1;
    CB4Border2      border2;
    CB4Border3      border3;
    CB4Border4      border4;
    CBandAngled     band1;
    CBandArc        band2;
    CBandArc        band3;
    CBandVertical   band4;
    int             framerate;
    int             mode;
    int             last_color;
    float           line_width;
};


#endif /* color_bands4_h */
