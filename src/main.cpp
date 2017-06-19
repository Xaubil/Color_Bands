#include "ofMain.h"
#include "color_bands1.h"
#include "color_bands2.h"
#include "color_bands3.h"
#include "color_bands4.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main()
{
    
	ofSetupOpenGL(620, 620, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ColorBands1());

}
