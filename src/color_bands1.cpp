//
//  color_bands1.cpp
//  SolLewitt_ColorBand_03_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "color_bands1.h"

//--------------------------------------------------------------
void ColorBands1::setup()
{
    framerate = 60;
    ofSetFrameRate(framerate);
    ofSetCurveResolution(100);
    ofSetBackgroundColor(ofColor::fromHex(BACKGROUND_COLOR));
    
    float bw = BORDER_WIDTH/2;
    float dx = DIMENSION_X;
    float dy = DIMENSION_Y;
    
    ofRectangle b1_bounds;
    float d = bw * (1 + cos(ofDegToRad(45)));
    b1_bounds.set(bw,
                  bw,
                  dy - bw - d,
                  dx/2);
    band1.init(32,
               32,
               b1_bounds,
               45);
    SolColors b1_colors[] = {
        ORANGE, BLUE, YELLOW, RED, PURPLE, BLUE, GREEN, ORANGE,
        PURPLE, YELLOW, RED, GREEN, PURPLE, BLUE, ORANGE, PURPLE,
        RED, YELLOW, GREEN, BLUE, RED, ORANGE, PURPLE, YELLOW,
        GREEN, RED, PURPLE, ORANGE, BLUE, PURPLE, GREEN, YELLOW
    };
    
    band1.setColors(b1_colors);
    
    mask1.setup(DIMENSION_X, DIMENSION_Y);
    mask1.newLayer();
    band1.setup();
    border1.setup(ofColor::fromHex(BORDER_COLOR));

    
    ofRectangle b2_bounds;
    b2_bounds.set(BORDER_WIDTH/4 + DIMENSION_X/2,
                  BORDER_WIDTH/2,
                  DIMENSION_X/2 - 1.5 * BORDER_WIDTH/2,
                  DIMENSION_Y);
    band2.init(22,
               22,
               b2_bounds);
               
    SolColors b2_colors[] = {
        ORANGE, BLUE, YELLOW, GREEN, PURPLE, BLUE, ORANGE, RED,
        YELLOW, GREEN, ORANGE, RED, PURPLE, BLUE, YELLOW, RED,
        ORANGE, GREEN, YELLOW, PURPLE, BLUE, RED,
    };
    band2.setColors(b2_colors);
    
    mask2.setup(DIMENSION_X, DIMENSION_Y);
    mask2.newLayer();
    band2.setup();
    border2.setup(ofColor::fromHex(BORDER_COLOR));

    ofRectangle b3_bounds;
    b3_bounds.set(dx/2,
                  dy/2 + bw,
                  (dy/2 - 2 * bw)/cos(ofDegToRad(45)),
                  dx/2);
    
    band3.init(32,
               32,
               b3_bounds,
               45,
               135);
    SolColors b3_colors[] = {
        PURPLE, RED, ORANGE, BLUE, GREEN, PURPLE, YELLOW, RED,
        ORANGE, BLUE, PURPLE, RED, ORANGE, YELLOW, PURPLE, BLUE,
        GREEN, ORANGE, PURPLE, RED, YELLOW, GREEN, PURPLE, ORANGE,
        BLUE, YELLOW, GREEN, PURPLE, RED, BLUE, ORANGE, GREEN,
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
void ColorBands1::draw()
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
void ColorBands1::keyPressed(int key)
{
    if(key == ' ') {
        mode = (mode + 1) % MODES_COUNT;
    }
}
