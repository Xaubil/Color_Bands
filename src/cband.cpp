//
//  cband.cpp
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "cband.h"

void CBand::init(int lcount, float lcalc, ofRectangle bounds)
{
    line_count = lcount;
    lines_calc = lcalc;
    boundx = bounds.getTopLeft().x;
    boundy = bounds.getTopLeft().y;
    boundw = bounds.getWidth();
    boundh = bounds.getHeight();
    
    color_bands = new ofPath[line_count];
    last_color = new ofColor[line_count];
    color_set = new SolColors[line_count];
}

void CBand::setup()
{
    bw = Constants::BORDER_WIDTH/2;
    dx = Constants::DIMENSION_X;
    dy = Constants::DIMENSION_Y;
    
    framerate = ofGetFrameRate();
}

void CBand::setColors(SolColors *colors)
{
    memcpy(color_set, colors, line_count * sizeof(SolColors));
}
