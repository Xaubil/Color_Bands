//
//  cband_angled.cpp
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "cband_angled.h"

void CBandAngled::init(int lcount, float lcalc, ofRectangle bounds, float ang)
{
    CBand::init(lcount, lcalc, bounds);
    
    angle = ang;
    cos_angle = cos(ofDegToRad(angle));
    
    color_bands_p = new ofPoint[line_count];
}

void CBandAngled::setup()
{
    CBand::setup();
    
    line_width = abs((boundw/float(lines_calc)) * cos_angle + 0.05);
    
    for (int i=0; i<line_count; i++) {
        ofPoint point1, point2;
        
        point1.set(boundx - line_width, boundy + line_width + float(i) * line_width/cos_angle);
        point2.set(boundx + line_width + float(i) * line_width/cos_angle, boundy - line_width);
        
        float w = ofDist(point1.x, point1.y, point2.x, point2.y);
        float h = line_width;
        color_bands[i].rectangle(point1, w, h);
        color_bands_p[i] = point1;
        
        color_bands[i].setFilled(true);
        color_bands[i].setCurveResolution(100);
    }
}

ofColor CBandAngled::getColorBasedOnMode(int mode, int n, int frame, int idx)
{
    ofColor color;
    switch(mode) {
        case 0:
            color = ofColor::fromHex(sol_colors[color_set[idx]]);
            break;
        case 1:
            color = ofColor::fromHex(sol_colors[color_set[(frame/10 - idx + line_count) % line_count]]);
            break;
        case 2:
            color = ofColor::black;
            if(color_set[idx] == n) {
                color = ofColor::fromHex(sol_colors[color_set[idx]], 255 - (frame * 255)/framerate);
            }
            last_color[idx] = color;
            break;
    }
    
    return color;
}

void CBandAngled::draw(int mode, int n)
{
    ofColor color;
    int frame = (int)ofGetFrameNum();
    
    for (int i=0; i<line_count; i++) {
        ofPushMatrix();
        ofTranslate(color_bands_p[i].x, color_bands_p[i].y, 0);
        ofRotate(-angle, 0, 0, 1);
        ofPushMatrix();
        color = getColorBasedOnMode(mode, n, frame, i);
        color_bands[i].setFillColor(color);
        color_bands[i].draw(-color_bands_p[i].x, -color_bands_p[i].y);
        ofPopMatrix();
        ofPopMatrix();
    }
}
