#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  _kinect = KinectSensor::GetDefault();
  if(_kinect != nullptr)
  {
    _multiFrameReader = _kinect->OpenMultiSourceFrameReader(FrameSourceTypes::Color | FrameSourceTypes::Body);

    _colorFrameDescription = _kinect->ColorFrameSource->CreateFrameDescription(ColorImageFormat::Rgba);
    _coodinateMapper = _kinect->CoordinateMapper;

    // RGBA is 4 bytes per pixel
    _bytesPerPixel = _colorFrameDescription->BytesPerPixel;

    _colorPixels = ref new Array<byte>(_colorFrameDescription->Width * _colorFrameDescription->Height * _bytesPerPixel);

    _bodies = ref new Vector<body^>(_kinect->BodyFrameSource->BodyCount);
    _kinect->Open();
  }

  _box2World.init();
  float w = ofGetWidth();
  float h = ofGetWidth();

  _box2dWorld.createBounds(0.0f, 0.0f, w, h);
  _box2dWorld.setGravity(0, 1.0f);
  _box2dWorld.createGround(0.0f, h - 300.0f, w, h - 300.0f);

  b2BodyDef bd;
  auto wallleft = _box2dWorld.world->CreateBody(&bd);

  b2BodyDef bd2;
  auto wallRight = _box2dWorld.world->CreateBody(&bd2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
