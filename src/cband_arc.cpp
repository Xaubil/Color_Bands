//
//  cband_arc.cpp
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "cband_arc.h"

void CBandArc::init(int lcount, float lcalc, ofRectangle bounds, float ang1, float ang2)
{
    CBand::init(lcount, lcalc, bounds);
    start_angle = ang1;
    end_angle = ang2;
}

void CBandArc::setup()
{
    CBand::setup();
    
    line_width = abs(boundw/float(lines_calc));
    
    for (int i=0; i<line_count; i++) {
        color_bands[i].arc(boundx,
                           boundy,
                           float(i+1) * line_width,
                           float(i+1) * line_width,
                           start_angle - 10,
                           end_angle + 10);
        
        color_bands[i].setFilled(true);
        color_bands[i].setCircleResolution(100);
    }
}

ofColor CBandArc::getColorBasedOnMode(int mode, int n, int frame, int idx)
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

void CBandArc::draw(int mode, int n)
{
    ofColor color;
    int frame = ofGetFrameNum();
    for (int i=line_count-1; i>=0; i--) {
        color = getColorBasedOnMode(mode, n, frame, i);
        color_bands[i].setFillColor(color);
        color_bands[i].draw();
    }
}
