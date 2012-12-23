#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	receiver.setup(PORT);
	
	// font.loadFont("../../src/font1550.ttf", 20, true);
	font.loadFont("../../src/arialbd.ttf", 32, true);	
	//font.loadFont("../../src/fenwick.ttf", 32, true);	

	mainOutputSyphonServer.setName("Screen Output");
	//individualTextureSyphonServer.setName("Texture Output");	

	ofSetFrameRate(10);
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
		char punt[255];
		std::strcpy(punt, msg.c_str());
		u8_unescape(buf,255,punt);
		msg.assign(buf);
	}
}


//--------------------------------------------------------------
void testApp::draw(){
	ofScale(1.1,1.1,1);
	ofSetHexColor(0xff0000);
	font.drawString(msg,50,50);
	ofSetHexColor(0xfffa04);
	font.drawString(msg, 50,50);
	

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
