#include "ofApp.h"
#include "utils.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(30);
    ofSetSphereResolution(10);
    ofEnableLighting();
    ofEnableDepthTest();
    light.enable();
    light.setDirectional();

    worm = Worm(1000, 1);
}

//--------------------------------------------------------------
void ofApp::update()
{
    worm.update();
    showFps();
    // vr.record("/home/ezequiel/Videos/worms", 18);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    camera.begin();
    worm.draw();
    camera.end();
}

//--------------------------------------------------------------
void ofApp::exit()
{
    // vr.stopRecording();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
