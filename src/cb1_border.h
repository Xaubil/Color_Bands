//
//  cb1_border.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-11.
//
//

#ifndef cb1_border_h
#define cb1_border_h

#include "ofMain.h"
#include "constants.h"

class CB1Border {
    
    public:
    void setup(ofColor borderColor);
    void draw();
    
    protected:
    float bw, dx, dy;
    ofPoint point0_1;
    ofPoint point0_2;
    ofPoint point0_3;
    ofPoint point0_4;
    ofPoint point1;
    ofPoint point2_1;
    ofPoint point2_2;
    ofPoint point3;
    ofPoint point4_1;
    ofPoint point4_2;
    ofPoint point4_3;
    ofPoint point5_1;
    ofPoint point5_2;
    ofPoint point6_1;
    ofPoint point6_2;
    
    ofPath _border;
    float angle = 45;
};

class CB1Border1 : public CB1Border {
    public:
    void setup(ofColor borderColor);
};

class CB1Border2 : public CB1Border {
public:
    void setup(ofColor borderColor);
};

class CB1Border3 : public CB1Border {
public:
    void setup(ofColor borderColor);
};

#endif /* cb1_border_h */
