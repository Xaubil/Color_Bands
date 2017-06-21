//
//  color_bands5.cpp
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-19.
//
//

#include "color_bands5.h"

void ColorBands5::setupTriangles()
{
    int dx = DIMENSION_X;
    int dy = DIMENSION_Y;
    float bw = BORDER_WIDTH/2;
    
    float angle = atan(2);
    line_width = (dy - 2 * bw) * sin(M_PI_2 - angle)/20.5;
    
    for(int i=0; i<21; i++) {
        triangles[i].triangle(bw - float(21 - i) * line_width / tan(angle/2),
                              bw - float(21 - i) * line_width,
                              dx - bw + float(21 - i) * line_width / tan(angle/2),
                              bw - float(21 - i) * line_width,
                              dx / 2,
                              dy - bw + float(21 - i) * line_width / cos(angle));
        triangles[i].setFillColor(ofColor::fromHex(sol_colors[color_set[i]]));
        triangles[i].setFilled(true);
    }
    triangles[21].triangle(bw, bw, dx - bw, bw, dx/2, dy - bw);
    triangles[21].setFillColor(ofColor::fromHex(sol_colors[color_set[21]]));
    triangles[21].setFilled(true);
    for(int i=1; i<=13; i++) {
        triangles[21 + i].triangle(bw + float(i) * line_width / tan(angle/2),
                                   bw + float(i) * line_width,
                                   dx - bw - float(i) * line_width / tan(angle/2),
                                   bw + float(i) * line_width,
                                   dx / 2,
                                   dy - bw - float(i) * line_width / cos(angle));
        triangles[21 + i].setFillColor(ofColor::fromHex(sol_colors[color_set[i]]));
        triangles[21 + i].setFilled(true);
    }
}

void ColorBands5::setupMask()
{
    int dx = DIMENSION_X;
    int dy = DIMENSION_Y;
    float bw = BORDER_WIDTH/2;

    mask.setup(DIMENSION_X, DIMENSION_Y);
    mask.newLayer();
    
    border.setFilled(true);
    border.setFillColor(BORDER_COLOR);
    ofDrawRectangle(0, 0, dx, dy);
    border.moveTo(0, 0);
    border.lineTo(0, dy);
    border.lineTo(dx, dy);
    border.lineTo(dx, 0);
    border.moveTo(bw, bw);
    border.lineTo(bw, dy - bw);
    border.lineTo(dx - bw, dy - bw);
    border.lineTo(dx - bw, bw);
    border.close();
}

void ColorBands5::setup()
{
    framerate = 60;
    ofSetFrameRate(framerate);
    ofSetCurveResolution(100);
    ofSetBackgroundColor(ofColor::fromHex(BACKGROUND_COLOR));

    setupTriangles();
    setupMask();
}

ofColor ColorBands5::getColorBasedOnMode(int mode, int n, int frame, int idx)
{
    ofColor color;
    switch(mode) {
        case 0:
            color = ofColor::fromHex(sol_colors[color_set[idx]]);
            break;
        case 1:
            color = ofColor::fromHex(sol_colors[color_set[(frame/10 - idx + 35) % 35]]);
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

void ColorBands5::draw()
{
    ofColor color;
    int n = last_mode_color;
    if(mode == 2) {
        if((ofGetFrameNum() % (framerate)) == 0) {
            int n = (int)ofRandom((float)SOL_COLORS_COUNT);
            if(n == last_mode_color) {
                n = (n + 1) % SOL_COLORS_COUNT;
            }
            last_mode_color = n;
        }
    }

    mask.beginMask();
    border.draw();
    mask.endMask();
    
    mask.beginLayer();
    int frame = ofGetFrameNum();
    for(int i=0; i<35; i++) {
        color = getColorBasedOnMode(mode, n, frame, i);
        triangles[i].setFillColor(color);
        triangles[i].draw();
    }
    mask.endLayer();
    
    mask.draw();
}

void ColorBands5::keyPressed(int key)
{
    if(key == ' ') {
        mode = (mode + 1) % MODES_COUNT;
    }
    cout << mode;
}
