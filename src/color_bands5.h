//
//  color_bands5.h
//  SolLewitt_ColorBands
//
//  Created by Tin Tin on 2017-06-19.
//
//

#ifndef color_bands5_h
#define color_bands5_h

#include "ofMain.h"
#include "constants.h"
#include "ofxLayerMask.h"

using namespace Constants;

class ColorBands5 : public ofBaseApp {
    
public:
    void            setup();
    void            draw();
    void            keyPressed(int key);
    
private:
    void            setupMask();
    void            setupTriangles();
    ofColor         getColorBasedOnMode(int mode, int n, int frame, int idx);

    ofxLayerMask    mask;
    ofPath          triangles[35];
    ofPath          border;
    int             framerate;
    int             mode;
    int             last_mode_color;
    float           line_width;
    ofColor     	last_color[35];
    const SolColors color_set[35] = {
        BLUE, YELLOW, PURPLE, RED, ORANGE, GREEN, BLUE, GREEN,
        YELLOW, ORANGE, PURPLE, RED, BLUE, YELLOW, GREEN, ORANGE,
        PURPLE, BLUE, GREEN, YELLOW, RED, GREEN, YELLOW, PURPLE,
        RED, ORANGE, BLUE, GREEN, YELLOW, PURPLE, BLUE, ORANGE,
        GREEN, RED, YELLOW
    };
};


#endif /* color_bands5_h */
