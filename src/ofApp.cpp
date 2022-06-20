#include "ofApp.h"
#include "../BaseImage.h"

vector<float> ofApp::calculateImgFilter() {
    // TODO add more
	return baseImage.getImgBrightness();
}

vector<ofPoint> ofApp::calculatePointDistribution(vector<float> imgBrightness) {
	vector<ofPoint> points;
	
	switch (gPointDistributionMethod) {
	case 0:
		points = baseImage.pdSpacer(imgBrightness);
		break;
	case 1:
		points = baseImage.pdRandom(imgBrightness);
		break;
	}
	return points;
}

ofxDelaunay ofApp::prepareDelaunayTriangulation(vector<ofPoint> points) {
	ofxDelaunay delaunay;
	for (ofPoint p : points) {
		delaunay.addPoint(p);
	}
	delaunay.triangulate();
	return delaunay;
}

void ofApp::setup() {
	baseImage = BaseImage("DSC_0658.jpg", 1200, 1200);
	setupGui();
	imgFilter = calculateImgFilter();
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

void ofApp::draw() {
	if (gDrawImage) {
		baseImage.draw();
	}
	else {
		ofBackground(25, 25, 25);
	}

	if (gDrawDelaunay) {
		ofNoFill();
		ofSetLineWidth(1.0);
		delaunay.draw();
	}
	else {
		for (ofPoint p : points) {
			ofDrawEllipse(p, 5, 5);
		}
	}

	gui.draw();
}

void ofApp::update() {

}

void ofApp::setupGui() {
	// GUI
	gui.setup();
	// for setup functions
	gui.add(gPower.setup("power", 5.0, 2.0, 24.0));
	gPower.addListener(this, &ofApp::gPowerChanged);
	gui.add(gSpacer.setup("spacer", 5, 5, 120));
	gSpacer.addListener(this, &ofApp::gSpacerChanged);
	gui.add(gLightOrDark.setup("lightOrDark", true));
	gLightOrDark.addListener(this, &ofApp::gLightOrDarkChanged);
	gui.add(gPointDistributionMethod.setup("pointDistributionMethod", 0, 0, 1));
	gPointDistributionMethod.addListener(this, &ofApp::gPointDistributionMethodChanged);
	gui.add(gParticleCount.setup("particleCount", 100, 100, 10000));
	gParticleCount.addListener(this, &ofApp::gParticleCountChanged);
	// for draw function
	gui.add(gDrawDelaunay.setup("drawDelaunay", true));
	gui.add(gDrawImage.setup("drawImage", true));
}

void ofApp::gPowerChanged(float& gPower)
{
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

void ofApp::gSpacerChanged(int& gSpacer)
{
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

void ofApp::gLightOrDarkChanged(bool& lightOrDark)
{
	imgFilter = calculateImgFilter();
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

void ofApp::gPointDistributionMethodChanged(int& gPointDistributionMethod)
{
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

void ofApp::gParticleCountChanged(int& gParticleCount)
{
	points = calculatePointDistribution(imgFilter);
	delaunay = prepareDelaunayTriangulation(points);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
