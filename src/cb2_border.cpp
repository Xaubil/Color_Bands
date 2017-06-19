//
//  cb2_border.cpp
//  SolLewitt_ColorBand_02_v1
//
//  Created by Tin Tin on 2017-06-17.
//
//

#include "cb2_border.h"

void CB2Border::setup(ofColor borderColor)
{
    _border.setFilled(true);
    _border.setFillColor(borderColor);
    
    float bw = Constants::BORDER_WIDTH/2;
    float dx = Constants::DIMENSION_X;
    float dy = Constants::DIMENSION_Y;
    float d = bw * (1 + 2 * cos(ofDegToRad(45)));
    
    ofDrawRectangle(0, 0, dx, dy);
    
    /*
     point0: Full square
     point1: top left
     point2: top right
     point3: midle left
     point4: middle
     point5: middle right
     point6: bottom left
     point7: bottom middle
     point8: bottom right
    */
    point0_1.set(0, 0);
    point0_2.set(0, dy);
    point0_3.set(dx, dy);
    point0_4.set(dx, 0);
    point1.set(bw, bw);
    point2.set(dx - bw, bw);
    point3_1.set(bw, 0.4 * (dy - 3 * bw) + bw);
    point3_2.set(bw, 0.4 * (dy - 3 * bw) + 2 * bw);
    point4_1.set(dx/2 - bw/2, 0.4 * (dy - 3 * bw) + 2 * bw);
    point4_2.set(dx/2 + bw/2, 0.4 * (dy - 3 * bw) + 2 * bw);
    point5_1.set(dx - bw, 0.4 * (dy - 3 * bw) + bw);
    point5_2.set(dx - bw, 0.4 * (dy - 3 * bw) + 2 * bw);
    point6.set(bw, dy - bw);
    point7_1.set(dx/2 - bw/2, dy - bw);
    point7_2.set(dx/2 + bw/2, dy - bw);
    point8.set(dx - bw, dy - bw);
}

void CB2Border::draw()
{
    _border.draw();
}

void CB2Border1::setup(ofColor borderColor)
{
    CB2Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point1);
    _border.lineTo(point2);
    _border.lineTo(point5_1);
    _border.lineTo(point3_1);
    _border.close();
}

void CB2Border2::setup(ofColor borderColor)
{
    CB2Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point3_2);
    _border.lineTo(point4_1);
    _border.lineTo(point7_1);
    _border.lineTo(point6);
    _border.close();
}

void CB2Border3::setup(ofColor borderColor)
{
    CB2Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point4_2);
    _border.lineTo(point5_2);
    _border.lineTo(point8);
    _border.lineTo(point7_2);
    _border.close();
}
