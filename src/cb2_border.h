//
//  cb2_border.h
//  SolLewitt_ColorBand_02_v1
//
//  Created by Tin Tin on 2017-06-11.
//
//

#ifndef cb2_border_hpp
#define cb2_border_hpp

#include "ofMain.h"
#include "constants.h"

class CB2Border {
    
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
    ofPoint point2;
    ofPoint point3_1;
    ofPoint point3_2;
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

class CB2Border1 : public CB2Border {
    public:
    void setup(ofColor borderColor);
};

class CB2Border2 : public CB2Border {
public:
    void setup(ofColor borderColor);
};

class CB2Border3 : public CB2Border {
public:
    void setup(ofColor borderColor);
};

#endif /* cb2_border_hpp */
