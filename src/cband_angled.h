//
//  cband_angled.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef cband_angled_h
#define cband_angled_h

#include "cband.h"

class CBandAngled : public CBand {
public:
    void init(int line_count, float lines_calc, ofRectangle bounds, float angle);
    void setup();
    void draw(int mode, int n = 0);
    ofColor getColorBasedOnMode(int mode, int n, int frame, int idx);
    
    float       angle;
    float       cos_angle;
    ofPoint     *color_bands_p;
    
    ~CBandAngled() {
        if(color_bands_p) {
            delete []color_bands_p;
        }
    }
};

#endif /* cband_angled_h */
