#include "ofApp.h"
#include "utils.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(30);
    ofEnableDepthTest();

    light1.setDiffuseColor(ofColor::orangeRed);
    light1.setDirectional();
    light1.setOrientation({45, -90, 0});

    light2.setDiffuseColor(ofColor::darkRed);
    light2.setDirectional();
    light2.setOrientation({45, 90, 0});

    font.load("Bungee-Regular.ttf", 22);

    worm = Worm(2000, 1, 2, 20);
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.orbitDeg(ofGetElapsedTimef() * -1, 0, 80);
    worm.update();
    showFps();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(ofColor::white);
    light1.enable();
    light2.enable();
    camera.begin();
    ofEnableDepthTest();
    worm.draw();
    ofDisableLighting();
    camera.end();
    ofDisableDepthTest();
    ofSetColor(ofColor::black);
    ofFill();
    ofDrawRectangle(0, h / 2 - h / 13, w, h / 6.5);
    ofSetColor(ofColor::orangeRed);
    string s = "controlador emocional";
    font.drawString(s, ofGetWidth() / 2 - font.stringWidth(s) / 2, ofGetHeight() / 2 + font.stringHeight(s) / 2);

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
