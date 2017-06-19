//
//  color_bands3.cpp
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-18.
//
//

#include "color_bands3.h"

//--------------------------------------------------------------
void ColorBands3::setup()
{
    
    framerate = 60;
    ofSetFrameRate(framerate);
    ofSetCurveResolution(100);
    ofSetBackgroundColor(ofColor::fromHex(BACKGROUND_COLOR));
    
    float bw = Constants::BORDER_WIDTH/2;
    float dx = Constants::DIMENSION_X;
    float dy = Constants::DIMENSION_Y;
    
    ofRectangle b1_bound;
    b1_bound.set(bw,
                 bw,
                 dy/2 - 1.5 * bw,
                 dx/2);
    band1.init(32,
               22.5,
               b1_bound,
               0,
               90);
    SolColors b1_colors[] = {
        YELLOW, RED, ORANGE, GREEN, BLUE, YELLOW, PURPLE, ORANGE,
        RED, GREEN, BLUE, YELLOW, PURPLE, GREEN, RED, GREEN,
        BLUE, YELLOW, PURPLE, RED, ORANGE, GREEN, BLUE, YELLOW,
        PURPLE, RED, ORANGE, GREEN, BLUE, YELLOW, RED, GREEN
    };
    band1.setColors(b1_colors);
    
    mask1.setup(DIMENSION_X, DIMENSION_Y);
    mask1.newLayer();
    band1.setup();
    border1.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b2_bound;
    b2_bound.set(dx/2 + bw/2,
                 dy/2,
                 dy - 2 * bw,
                 dx/2);
    band2.init(33,
               46,
               b2_bound,
               279,
               90);
    SolColors b2_colors[] = {
        ORANGE, GREEN, BLUE, YELLOW, RED, ORANGE, BLUE, GREEN,
        YELLOW, PURPLE, RED, BLUE, ORANGE, RED, GREEN, YELLOW,
        BLUE, ORANGE, RED, PURPLE, GREEN, BLUE, ORANGE, BLUE,
        GREEN, YELLOW, RED, PURPLE, ORANGE, BLUE, RED, GREEN,
        PURPLE
    };
    band2.setColors(b2_colors);
    
    mask2.setup(DIMENSION_X, DIMENSION_Y);
    mask2.newLayer();
    band2.setup();
    border2.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b3_bound;
    b3_bound.set(dx/2 - bw/2,
                 dy - bw,
                 dy/2 - 1.5 * bw,
                 dx/2);
    band3.init(32,
               22.5,
               b3_bound,
               180,
               270);
    SolColors b3_colors[] = {
        BLUE, RED, PURPLE, ORANGE, GREEN, YELLOW, BLUE, RED,
        ORANGE, GREEN, YELLOW, PURPLE, RED, GREEN, BLUE, ORANGE,
        RED, YELLOW, PURPLE, GREEN, RED, ORANGE, BLUE, GREEN,
        YELLOW, PURPLE, RED, ORANGE, BLUE, YELLOW, PURPLE, RED,
    };
    band3.setColors(b3_colors);
    
    mask3.setup(DIMENSION_X, DIMENSION_Y);
    mask3.newLayer();
    band3.setup();
    border3.setup(ofColor::fromHex(BORDER_COLOR));
    
    /* Start with mode 1 */
    mode = MODE_1;
}

//--------------------------------------------------------------
void ColorBands3::draw()
{
    int n = last_color;
    if(mode == 2) {
        if((ofGetFrameNum() % (framerate)) == 0) {
            int n = (int)ofRandom((float)SOL_COLORS_COUNT);
            if(n == last_color) {
                n = (n + 1) % SOL_COLORS_COUNT;
            }
            last_color = n;
        }
    }
    
    /* First Region */
    mask1.beginMask();
    border1.draw();
    mask1.endMask();
    
    mask1.beginLayer();
    band1.draw(mode, n);
    mask1.endLayer();
    
    mask1.draw();
    
    /* Second Region */
    mask2.beginMask();
    border2.draw();
    mask2.endMask();
    
    mask2.beginLayer();
    band2.draw(mode, n);
    mask2.endLayer();
    
    mask2.draw();
    
    /* Third Region */
    mask3.beginMask();
    border3.draw();
    mask3.endMask();
    
    mask3.beginLayer();
    band3.draw(mode, n);
    mask3.endLayer();
    
    mask3.draw();
}

//--------------------------------------------------------------
void ColorBands3::keyPressed(int key)
{
    if(key == ' ') {
        mode = (mode + 1) % MODES_COUNT;
    }
}
