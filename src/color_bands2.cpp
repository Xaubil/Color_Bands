//
//  color_bands2.cpp
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-18.
//
//

#include "color_bands2.h"

//--------------------------------------------------------------
void ColorBands2::setup()
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
                 dy - 2 * bw,
                 0.4 * (dy - 3 * bw) + bw);
    band1.init(46,
               46,
               b1_bound);
    SolColors b1_colors[] = {
        PURPLE, ORANGE, RED, YELLOW, BLUE, GREEN, PURPLE, YELLOW,
        BLUE, RED, ORANGE, GREEN, PURPLE, BLUE, RED, ORANGE,
        GREEN, BLUE, YELLOW, RED, PURPLE, ORANGE, BLUE, GREEN,
        YELLOW, BLUE, RED, PURPLE, YELLOW, GREEN, ORANGE, PURPLE,
        GREEN, YELLOW, RED, ORANGE, BLUE, GREEN, PURPLE, BLUE,
        RED, ORANGE, PURPLE, GREEN, RED, BLUE
    };
    band1.setColors(b1_colors);

    mask1.setup(DIMENSION_X, DIMENSION_Y);
    mask1.newLayer();
    band1.setup();
    border1.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b2_bound;
    b2_bound.set(dx/2 - bw/2,
                 0.4 * (dy - 3 * bw) + 2 * bw,
                 0.6 * (dy - 3 * bw),
                 dx/2);
    band2.init(35,
               27,
               b2_bound,
               90,
               180);
    SolColors b2_colors[] = {
        YELLOW, BLUE, ORANGE, RED, PURPLE, GREEN, YELLOW, BLUE,
        RED, PURPLE, ORANGE, GREEN, YELLOW, BLUE, GREEN, RED,
        ORANGE, BLUE, YELLOW, PURPLE, GREEN, BLUE, RED, ORANGE,
        BLUE, GREEN, PURPLE, YELLOW, RED, BLUE, PURPLE, YELLOW,
        ORANGE, GREEN, BLUE
    };
    band2.setColors(b2_colors);
    
    mask2.setup(DIMENSION_X, DIMENSION_Y);
    mask2.newLayer();
    band2.setup();
    border2.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b3_bound;
    b3_bound.set(dx/2 + bw/2,
                 dy - bw,
                 0.6 * (dy - 3 * bw),
                 dx/2);
    band3.init(35,
               27,
               b3_bound,
               270,
               360);
    SolColors b3_colors[] = {
        ORANGE, RED, BLUE, PURPLE, GREEN, YELLOW, RED, ORANGE,
        PURPLE, GREEN, BLUE, RED, YELLOW, RED, PURPLE, BLUE,
        RED, YELLOW, ORANGE, PURPLE, RED, BLUE, PURPLE, ORANGE,
        RED, YELLOW, BLUE, ORANGE, PURPLE, RED, YELLOW, BLUE,
        GREEN, YELLOW, RED
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
void ColorBands2::draw()
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
void ColorBands2::keyPressed(int key)
{
    if(key == ' ') {
        mode = (mode + 1) % MODES_COUNT;
    }
}
