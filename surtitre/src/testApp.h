#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxSyphon.h"
extern "C" {
	#include "utf8.h"
}

// listen on port 9001
#define PORT 9001

class testApp : public ofBaseApp {
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	ofxTrueTypeFontUC font;
	ofxOscReceiver receiver;
	vector <string> lines;
	string msg;
	char buf[255], punt[255];

	ofxSyphonServer mainOutputSyphonServer;
};

#endif

