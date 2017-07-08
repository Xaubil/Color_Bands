//
//  constants.h
//  SolLewitt_ColorBand_01_v1
//
//  Created by Tin Tin on 2017-06-12.
//
//

#ifndef constants_h
#define constants_h

#include "ofColor.h"

enum modes_e {
    MODE_1 = 0,
    MODE_2,
    MODE_3,
    MODES_COUNT
};

namespace Constants {
    
    enum SolColors {
        PURPLE = 0,
        YELLOW,
        RED,
        GREEN,
        ORANGE,
        BLUE,
        SOL_COLORS_COUNT
    };
    
    const float DIMENSION_X  = 620.0f;
    const float DIMENSION_Y  = 620.0f;
    const float BORDER_WIDTH = 30.0f;

    const int   BORDER_COLOR = 0;
    const int   BACKGROUND_COLOR = 0;
    const int   sol_colors[] = {
        0x3b275a,   /* PURPLE */
        0xffd00f,   /* YELLOW */
        0xc6081e,   /* RED */
        0x007d1e,   /* GREEN */
        0xff4e1b,   /* ORANGE */
        0x005faf    /* BLUE */
    };
}

#endif /* constants_h */
