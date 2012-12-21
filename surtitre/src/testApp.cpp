#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	receiver.setup(PORT);
	
	// font.loadFont("../../src/font1550.ttf", 20, true);
	font.loadFont("../../src/fontmono.ttf", 20, true);	

	mainOutputSyphonServer.setName("Screen Output");
	individualTextureSyphonServer.setName("Texture Output");	

	ofBackground(30);
}

//--------------------------------------------------------------
void testApp::update(){
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		// unrecognized message: display on the bottom of the screen
		msg = m.getArgAsString(0);
	}
}


//--------------------------------------------------------------
void testApp::draw(){
	font.drawString(msg+" é", 50,50);
	
	mainOutputSyphonServer.publishScreen();
//    individualTextureSyphonServer.publishTexture(&tex);
}
	
	

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}
