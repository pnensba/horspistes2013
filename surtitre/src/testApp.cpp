#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetDataPathRoot("../Resources/"); // pour osx, put arialbd.ttf in Resources
	receiver.setup(PORT);
	font.loadFont("arialbd.ttf", 24, true);	
	mainOutputSyphonServer.setName("Screen Output");
	ofSetFrameRate(10);
	ofBackground(30);
}

//--------------------------------------------------------------
void testApp::update(){
	while(receiver.hasWaitingMessages()){
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		lines.erase(lines.begin(),lines.end());
		for (int i=0; i<m.getNumArgs(); i++){
			msg = m.getArgAsString(i);
			std::strcpy(punt, msg.c_str());
			u8_unescape(buf,255,punt);
			lines.push_back(buf);
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofScale(1.1,1.1,1);
	for (int i=0; i<lines.size(); i++){
		ofSetHexColor(0xff0000);
		font.drawString(lines.at(i),50,40*i+50);
		ofSetHexColor(0xfffa04);
		font.drawString(lines.at(i), 50,40*i+50);
	}
	mainOutputSyphonServer.publishScreen();
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
	ofLogNotice(msg.message);
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
}
