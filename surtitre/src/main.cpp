#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

  ofAppGlutWindow window;
  ofSetupOpenGL(&window, 1024,300, OF_WINDOW);
  ofRunApp( new testApp());
}
