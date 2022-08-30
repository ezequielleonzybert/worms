#include "ofApp.h"
#include "utils.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(30);
    ofEnableLighting();
    ofEnableDepthTest();

    light2.setDiffuseColor(ofColor::red);
    light1.setDirectional();
    light1.setOrientation({45, -90, 0});
    light1.enable();

    light2.setDiffuseColor(ofColor::darkRed);
    light2.setDirectional();
    light2.setOrientation({45, 90, 0});
    light2.enable();

    worm = Worm(1000, 1, 5, 30);
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.orbitDeg(ofGetElapsedTimef() * -10, 0, 100);
    worm.update();
    showFps();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    camera.begin();
    worm.draw();
    camera.end();

    vr.record("/home/ezequiel/Videos/worms", 15);
}

//--------------------------------------------------------------
void ofApp::exit()
{
    vr.stopRecording();
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
