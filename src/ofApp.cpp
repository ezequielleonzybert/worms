#include "ofApp.h"
#include "utils.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    // ofSetFullscreen(true);
    ofBackground(0);

    light1.setDiffuseColor(ofColor::white);
    light1.setDirectional();
    light1.setOrientation({45, -90, 0});

    light2.setDiffuseColor(ofColor::grey);
    light2.setDirectional();
    light2.setOrientation({45, 90, 0});

    font.load("Gotham-Book.otf", h / 12, true, true, true);
    ofFloatColor c = ofFloatColor(1.0, 1.0, 1.0, 1.0);
    material.setColors(c, c, c, c);
    worm = Worm(2000, 1, w / 700, 20);
}

//--------------------------------------------------------------
void ofApp::update()
{
    camera.orbitDeg(-ofGetElapsedTimef() * .25, 0, 70);
    // camera.setDistance(100);
    worm.update();
    showFps();

    // if (ofGetFrameNum() > 1000)
    // {
    //     ofExit();
    // }
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
    camera.end();
    //     ofSetColor(ofColor::white);
    //     string s1 = "controlador";
    //     string s2 = "emocional";
    //     vector<ofPath> p1 = font.getStringAsPoints(s1);
    //     vector<ofPath> p2 = font.getStringAsPoints(s2);
    //     ofRectangle r1 = font.getStringBoundingBox(s1, 0, 0);
    //     ofRectangle r2 = font.getStringBoundingBox(s2, 0, 0);
    //
    //     material.begin();
    //     for (ofPath pp : p1)
    //     {
    //         pp.draw(w / 2 - r1.width / 2, h / 2 - r1.height / 1.8);
    //     }
    //     for (ofPath pp : p2)
    //     {
    //         pp.draw(w / 2 - r2.width / 2, h / 2 + r2.height / 1.8);
    //     }
    //     material.end();
    ofDisableLighting();
    ofDisableDepthTest();
    ofSetColor(0, 200);
    ofFill();

    // vr.record("/home/ezequiel/Videos/worms", 10);
}

//--------------------------------------------------------------
void ofApp::exit()
{
    vr.stopRecording();
}
// //--------------------------------------------------------------
// void ofApp::keyPressed(int key)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::keyReleased(int key)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseMoved(int x, int y)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseDragged(int x, int y, int button)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mousePressed(int x, int y, int button)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseReleased(int x, int y, int button)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseEntered(int x, int y)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseExited(int x, int y)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::windowResized(int w, int h)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::gotMessage(ofMessage msg)
// {
// }
//
// //--------------------------------------------------------------
// void ofApp::dragEvent(ofDragInfo dragInfo)
// {
// }
