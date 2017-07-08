//
//  cb4_border.h
//  SolLewitt_ColorBand_04_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#ifndef border_h
#define border_h

#include "ofMain.h"
#include "constants.h"

class CB4Border {
    
    public:
    void        setup(ofColor borderColor);
    void        draw();
    
protected:
    float       bw, dx, dy;
    ofPoint     point0_1;
    ofPoint     point0_2;
    ofPoint     point0_3;
    ofPoint     point0_4;
    ofPoint     point1;
    ofPoint     point2_1;
    ofPoint     point2_2;
    ofPoint     point3;
    ofPoint     point4_1;
    ofPoint     point4_2;
    ofPoint     point5_1;
    ofPoint     point5_2;
    ofPoint     point5_3;
    ofPoint     point5_4;
    ofPoint     point6_1;
    ofPoint     point6_2;
    ofPoint 	point7;
    ofPoint     point8_1;
    ofPoint     point8_2;
    ofPoint     point9;
    ofPath      _border;
};

class CB4Border1 : public CB4Border {
public:
    void        setup(ofColor borderColor);
};

class CB4Border2 : public CB4Border {
public:
    void        setup(ofColor borderColor);
};

class CB4Border3 : public CB4Border {
public:
    void        setup(ofColor borderColor);
};

class CB4Border4 : public CB4Border {
public:
    void        setup(ofColor borderColor);
};

#endif /* border_hpp */
