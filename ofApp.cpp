#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp()
{
	for (Ripple* r : this->ripple_list)
	{
		delete r;
	}

	this->ripple_list.clear();
}


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1);
	ofNoFill();

	//ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
	Ripple* r = new Ripple(ofVec3f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(500, 1000)));
	this->ripple_list.push_back(r);

	for (int i = 0; i < this->ripple_list.size(); i++) {
		if (this->ripple_list[i]->isLife()) {
			this->ripple_list[i]->update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	//ofRotateX(ofGetFrameNum() % 360);
	ofRotateY(ofGetFrameNum() % 360);

	for (int i = 0; i < this->ripple_list.size(); i++) {
		if (this->ripple_list[i]->isLife()) {
			this->ripple_list[i]->draw();
		}
	}
	
	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
