//
//  cb1_border.cpp
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-11.
//
//

#include "cb1_border.h"

void CB1Border::setup(ofColor borderColor)
{
    _border.setFilled(true);
    _border.setFillColor(borderColor);
    
    float bw = Constants::BORDER_WIDTH/2;
    float dx = Constants::DIMENSION_X;
    float dy = Constants::DIMENSION_Y;
    float d = bw * (1 + cos(ofDegToRad(angle)));
    
    ofDrawRectangle(0, 0, dx, dy);
    
    /*
     point0: top left
     point1: top middle
     point2: top right
     point4: middle
     point5: bottom left
     point6: bottom right
    */
    point0_1.set(0, 0);
    point0_2.set(0, dy);
    point0_3.set(dx, dy);
    point0_4.set(dx, 0);
    point1.set(bw, bw);
    point2_1.set(dx/2 - bw/2, bw);
    point2_2.set(dx/2 + bw/2, bw);
    point3.set(dx - bw, bw);
    point4_1.set(dx/2 - bw/2, dy/2);
    point4_2.set(dx/2 + bw/2, dy/2);
    point4_3.set(dx/2, dy/2 + bw);
    point5_1.set(bw, dy - d);
    point5_2.set(d, dy - bw);
    point6_1.set(dx - bw, dy - d);
    point6_2.set(dx - d, dy - bw);
}

void CB1Border::draw()
{
    _border.draw();
}

void CB1Border1::setup(ofColor borderColor)
{
    CB1Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point1);
    _border.lineTo(point2_1);
    _border.lineTo(point4_1);
    _border.lineTo(point5_1);
    _border.lineTo(point1);
}

void CB1Border2::setup(ofColor borderColor)
{
    CB1Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point2_2);
    _border.lineTo(point3);
    _border.lineTo(point6_1);
    _border.lineTo(point4_2);
    _border.close();
}

void CB1Border3::setup(ofColor borderColor)
{
    CB1Border::setup(borderColor);
    
    _border.moveTo(point0_1);
    _border.lineTo(point0_2);
    _border.lineTo(point0_3);
    _border.lineTo(point0_4);
    _border.moveTo(point4_3);
    _border.lineTo(point5_2);
    _border.lineTo(point6_2);
    _border.close();
}
