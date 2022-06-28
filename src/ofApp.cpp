#include "ofApp.h"

void ofApp::setup() {
	
	setupGui();
	 
	baseImage = BaseImage("DSC_0658.jpg", 1200, 1200);

	imageFilterType = ImageFilterType::Brightness;
	imageFilterResult = ImageFilter::calculate(baseImage, ImageFilterSettings(gLightMode), imageFilterType);

	pointDistributionType = PointDistributionType::Spacer;
	pointDistributionResult = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gSpacer, gParticleCount, gPower), pointDistributionType);

	pointConnectionType = PointConnectionType::Delaunay;
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(), pointConnectionType);
}

void ofApp::draw() {
	if (gDrawImage) {
		baseImage.draw();
	}
	else {
		ofBackground(25, 25, 25);
	}
	if (gDrawDelaunay) {
		pointConnectionResult.draw();
	}
	else {
		pointDistributionResult.draw();
	}
	gui.draw();
}

void ofApp::update() { }

void ofApp::setupGui() {
	gui.setup();

	gui.add(gPower.setup("power", 5.0, 2.0, 24.0));
	gPower.addListener(this, &ofApp::gPowerChanged);
	gui.add(gSpacer.setup("spacer", 5, 5, 120));
	gSpacer.addListener(this, &ofApp::gSpacerChanged);
	gui.add(gLightMode.setup("lightOrDark", true));
	gLightMode.addListener(this, &ofApp::gLightModeChanged);
	gui.add(gPointDistributionMethod.setup("pointDistributionMethod", 0, 0, 1));
	gPointDistributionMethod.addListener(this, &ofApp::gPointDistributionMethodChanged);
	gui.add(gParticleCount.setup("particleCount", 100, 100, 10000));
	gParticleCount.addListener(this, &ofApp::gParticleCountChanged);

	gui.add(gDrawDelaunay.setup("drawDelaunay", true));
	gui.add(gDrawImage.setup("drawImage", true));
}

void ofApp::gPowerChanged(float& gPower)
{
	calculateFromPointDistributionOnward();
}

void ofApp::gSpacerChanged(int& gSpacer)
{
	calculateFromPointDistributionOnward();
}

void ofApp::gLightModeChanged(bool& lightOrDark)
{
	calculateFromImageFilterOnward();
}

void ofApp::gPointDistributionMethodChanged(int& gPointDistributionMethod)
{
	switch (gPointDistributionMethod) {
	case 0:
		pointDistributionType = PointDistributionType::Spacer;
		break;
	case 1:
		pointDistributionType = PointDistributionType::Random;
		break;
	}
	calculateFromPointDistributionOnward();
}

void ofApp::gParticleCountChanged(int& gParticleCount)
{
	calculateFromPointDistributionOnward();
}

void ofApp::calculateFromImageFilterOnward() {
	imageFilterResult = ImageFilter::calculate(baseImage, ImageFilterSettings(gLightMode), imageFilterType);
	pointDistributionResult = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gSpacer, gParticleCount, gPower), pointDistributionType);
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(), pointConnectionType);
}

void ofApp::calculateFromPointDistributionOnward() {
	pointDistributionResult = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gSpacer, gParticleCount, gPower), pointDistributionType);
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(), pointConnectionType);
}

void ofApp::keyPressed(int key) {
	// add current points to previous points
	if (key == 'a') {
		//points.insert();
	}
	// add new layer 
	else if (key == 's') {

	}
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
