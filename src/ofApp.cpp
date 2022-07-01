#include "ofApp.h"

void ofApp::setup() {
	gui = GuiSettings(this);
	guiPanel.setup(gui.allParameters);
	 
	baseImage = BaseImage("DSC_0658.jpg", 1200, 1200);

	calculateAll();
}

void ofApp::draw() {
	if (gui.drawImage) {
		baseImage.draw();
	}
	else {
		ofBackground(25, 25, 25);
	}
	if (gui.drawConnection) {
		pointConnectionResult.draw();
	}

	if (gui.drawDistribution) {
		pointDistributionResult.draw();
	}
	guiPanel.draw();
}

void ofApp::update() { }

void ofApp::calculateAll() {
	imageFilterResult = ImageFilter::calculate(baseImage, ImageFilterSettings(gui.imageFilterType, gui.lightMode));
	pointDistributionResult = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gui.pointDistributionType, gui.spacer, gui.particleCount, gui.power));
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(gui.pointConnectionType));
}

void ofApp::calculateDistribution() {
	pointDistributionResult = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gui.pointDistributionType, gui.spacer, gui.particleCount, gui.power));
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(gui.pointConnectionType));
}

void ofApp::calculateConnection() {
	pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(gui.pointConnectionType));

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