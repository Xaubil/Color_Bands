//
//  color_bands4.cpp
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-18.
//
//

#include "color_bands4.h"

//--------------------------------------------------------------
void ColorBands4::setup()
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
               16,
               b1_bound,
               45);
    SolColors b1_colors[] = {
        RED, BLUE, ORANGE, GREEN, PURPLE, RED, ORANGE, BLUE,
        YELLOW, GREEN, RED, YELLOW, BLUE, ORANGE, GREEN, PURPLE,
        YELLOW, RED, BLUE, GREEN, ORANGE, RED, PURPLE, YELLOW,
        BLUE, GREEN, RED, PURPLE, YELLOW, ORANGE, RED, GREEN,
    };
    band1.setColors(b1_colors);
    
    mask1.setup(DIMENSION_X, DIMENSION_Y);
    mask1.newLayer();
    band1.setup();
    border1.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b2_bound;
    b2_bound.set(dx - bw,
                 bw,
                 dx/2 - 1.5 * bw,
                 dx/2);
    band2.init(32,
               22.5,
               b2_bound,
               90,
               180);
    SolColors b2_colors[] = {
        BLUE, ORANGE, PURPLE, GREEN, YELLOW, RED, BLUE, GREEN,
        ORANGE, RED, PURPLE, YELLOW, BLUE, ORANGE, GREEN, PURPLE,
        YELLOW, RED, ORANGE, GREEN, BLUE, PURPLE, YELLOW, GREEN,
        RED, BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, ORANGE
    };
    band2.setColors(b2_colors);
    
    mask2.setup(DIMENSION_X, DIMENSION_Y);
    mask2.newLayer();
    band2.setup();
    border2.setup(ofColor::fromHex(BORDER_COLOR));
    
    ofRectangle b3_bound;
    b3_bound.set(dx/2 - bw/2,
                 dy - bw,
                 dx/2 - 1.5 * bw,
                 dx/2);
    band3.init(32,
               22.5,
               b3_bound,
               180,
               270);
    SolColors b3_colors[] = {
        YELLOW, RED, BLUE, PURPLE, GREEN, ORANGE, YELLOW, RED,
        PURPLE, BLUE, YELLOW, RED, GREEN, ORANGE, PURPLE, BLUE,
        GREEN, ORANGE, RED, PURPLE, YELLOW, ORANGE, BLUE, RED,
        GREEN, ORANGE, PURPLE, BLUE, RED, YELLOW, GREEN, PURPLE
    };
    band3.setColors(b3_colors);
    
    mask3.setup(DIMENSION_X, DIMENSION_Y);
    mask3.newLayer();
    band3.setup();
    border3.setup(ofColor::fromHex(BORDER_COLOR));

    ofRectangle b4_bound;
    b4_bound.set(dx/2 + bw/2,
                 dy/2 + bw/2,
                 dx/2,
                 dx/2 - 1.5 * bw);
    band4.init(22,
               22,
               b4_bound,
               true);
    SolColors b4_colors[] = {
        GREEN, RED, ORANGE, BLUE, GREEN, RED, YELLOW, PURPLE,
        ORANGE, BLUE, RED, GREEN, YELLOW, PURPLE, BLUE, RED,
        GREEN, PURPLE, YELLOW, RED, BLUE, ORANGE,
    };
    band4.setColors(b4_colors);
    
    mask4.setup(DIMENSION_X, DIMENSION_Y);
    mask4.newLayer();
    band4.setup();
    border4.setup(ofColor::fromHex(BORDER_COLOR));

    /* Start with mode 1 */
    mode = MODE_1;
}

//--------------------------------------------------------------
void ColorBands4::draw()
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

    /* Fourth Region */
    mask4.beginMask();
    border4.draw();
    mask4.endMask();
    
    mask4.beginLayer();
    band4.draw(mode, n);
    mask4.endLayer();
    
    mask4.draw();
}

//--------------------------------------------------------------
void ColorBands4::keyPressed(int key)
{
    if(key == ' ') {
        mode = (mode + 1) % MODES_COUNT;
    }
}
