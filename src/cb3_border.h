//
//  cb3_border.h
//  SolLewitt_ColorBand_03_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef cb3_border_h
#define cb3_border_h

#include "ofMain.h"
#include "constants.h"

class CB3Border {
    
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
    ofPoint point5_1;
    ofPoint point5_2;
    ofPoint point6;
    ofPoint point7_1;
    ofPoint point7_2;
    ofPoint point8;
    ofPath _border;
};

class CB3Border1 : public CB3Border {
    public:
    void setup(ofColor borderColor);
};

class CB3Border2 : public CB3Border {
public:
    void setup(ofColor borderColor);
};

class CB3Border3 : public CB3Border {
public:
    void setup(ofColor borderColor);
};

#endif /* cb3_border_h */
