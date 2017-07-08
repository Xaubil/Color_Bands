//
//  cband_vertical.cpp
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "cband_vertical.h"

void CBandVertical::init(int lcount, float lcalc, ofRectangle bounds, bool horiz)
{
    CBand::init(lcount, lcalc, bounds);
    horizontal = horiz;
}

void CBandVertical::setup()
{
    CBand::setup();
    
    if(horizontal) {
        line_width = abs((boundh)/float(line_count));
    } else {
        line_width = abs((boundw)/float(line_count));
    }
    
    for (int i=0; i<line_count; i++) {
        ofPoint point1;
        if(horizontal) {
            point1.set(boundx, boundy + float(i) * line_width);
        } else {
            point1.set(boundx + float(i) * line_width, boundy);
        }
        float w = line_width;
        float h = boundh;
        if(horizontal) {
            w = boundh;
            h = line_width;
        }
        color_bands[i].rectangle(point1, w, h);
        color_bands[i].setFilled(true);
    }
}

ofColor CBandVertical::getGradientColor(int x, ofColor thisColor, ofColor prevColor, ofColor nextColor)
{
    ofColor color = thisColor;
    if(x < line_width) {
        color = ofColor::fromHsb(x/line_width/2 * thisColor.getHue() + (x + line_width/2)/line_width/2 * prevColor.getHue(), 255, 255);
    } else if (x > line_width) {
        color = ofColor::fromHsb((x - line_width/2)/line_width/2 * thisColor.getHue() + (x + line_width/2)/line_width/2 * nextColor.getHue(), 255, 255);
    }
    return color;
}

ofColor CBandVertical::getColorBasedOnMode(int mode, int n, int frame, int idx)
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

void CBandVertical::draw(int mode, int n)
{
    ofColor color;
    int frame = ofGetFrameNum();
    
    if(mode == 3) {
        for(int x=0; x<boundx; x++) {
            ofColor color;
            int len = sizeof(color_set)/sizeof(ofColor);
            int thisIdx = x/line_width;
            ofColor prev = sol_colors[color_set[(thisIdx - 1 + len) % len]];
            ofColor next = sol_colors[color_set[(thisIdx + 1) % len]];
            color = getGradientColor(x, sol_colors[thisIdx], prev, next);
        }
    } else {
        for (int i=0; i<line_count; i++) {
            color = getColorBasedOnMode(mode, n, frame, i);
            color_bands[i].setFillColor(color);
            color_bands[i].draw();
        }
    }
}
