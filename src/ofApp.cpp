#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bot = false;
    ofBackground(255);
    ofSetCircleResolution(60);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
   radius=sqrt(pow(mouseX-ofGetWidth()/2 ,2.0)+pow(mouseY-ofGetHeight()/2,2.0));
    if (ofGetHeight()/2>=mouseY) {
        c = acos((mouseX-ofGetWidth()/2)/radius)*180/M_PI;
    }else{
        c = 360-acos((mouseX-ofGetWidth()/2)/radius)*180/M_PI;
    }
    hsb.setHsb(c*255/360, 255, 255);
    
  
   
    }

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(50);
    ofLine(0, mouseY, ofGetWidth(), mouseY);
    ofLine(mouseX,0 , mouseX, ofGetHeight());
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2  , ofGetHeight()/2);
    
        r = ofRandom(-5,5);
        ofSetColor(hsb);
    
        ofNoFill();
        ofCircle(0, 0, radius+r);
    
        ofFill();
        ofCircle(0, 0, radius/5+r);
    
        ofLine((mouseX-ofGetWidth()/2), mouseY-ofGetHeight()/2, 0,0);
    
        if(bot){
            ofSetColor(0,0,0,150);
            ofBeginShape();
                ofVertex(0, 0);
               
                for (float i =0; i<c; i+=0.01){
                    ofVertex((radius+r)*cos(ofDegToRad(i)), -(radius+r)*sin(ofDegToRad(i)));
                }
            ofEndShape();
            
            ofSetColor(0);
            ofDrawBitmapString("radius: "+ ofToString(radius)+"\n"+"deg: "+ofToString(c),mouseX+30-ofGetWidth()/2,mouseY+30-ofGetHeight()/2);
        
        }

    ofPopMatrix();
    
    
    ofSetColor(50);
    for (int i=1; i<=30; i++){
        ofLine(ofGetWidth()/30*i, 0, ofGetWidth()/30*i, ofGetHeight());
    }
    for (int i=1; i<=20; i++){
        ofLine(0, ofGetHeight()/20*i, ofGetWidth()  ,  ofGetHeight()/20*i);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    }

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            bot = !bot;
            break;

    }

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
