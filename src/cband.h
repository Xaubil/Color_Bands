//
//  cband.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef cband_h
#define cband_h

#include "ofMain.h"
#include "constants.h"

using namespace Constants;

class CBand {
public:
    void init(int lcount, float lcalc, ofRectangle bounds);
    void setColors(SolColors *colors);
    void setup();
    void draw();
    virtual ofColor getColorBasedOnMode(int mode, int n, int frame, int idx) = 0;
    
    ~CBand() {
        if(color_bands) {
            delete [] color_bands;
        }
        if(last_color) {
            delete [] last_color;
        }
        if(color_set) {
            delete [] color_set;
        }
    }
    
protected:
    float       bw, dx, dy;
    int         line_count = 1;
    float       lines_calc;
    float       line_width;
    int         framerate;
    float       boundx;
    float       boundy;
    float       boundw;
    float       boundh;

    ofPath      *color_bands;
    ofColor     *last_color;
    SolColors   *color_set;
};

#endif /* cband_h */
