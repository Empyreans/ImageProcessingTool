#include "ofApp.h"

// TODO vielleicht calculate Methods nicht statisch
void ofApp::setup() {
	prepareGui(); 
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

void ofApp::prepareGui() {
	guiPanel.setup(gui.allParameters);

	imageFilterListener = gui.imageFilterSettingsGroup.parameterChangedE().newListener([&](ofAbstractParameter& p) {
		calculateAll();
		});
	pointDistributionListener = gui.pointDistributionSettingsGroup.parameterChangedE().newListener([&](ofAbstractParameter& p) {
		calculateDistribution();
		});
	pointConnectionListener = gui.pointConnectionSettingsGroup.parameterChangedE().newListener([&](ofAbstractParameter& p) {
		calculateConnection();
		});
}

// addLayer
// addPoints
void ofApp::keyPressed(int key) {
	// add current points to previous points
	if (key == 'a') {
		PointDistributionResult res = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gui.pointDistributionType, gui.spacer, gui.particleCount, gui.power));
		pointDistributionResult.addPoints(res);
		pointConnectionResult = PointConnection::calculate(pointDistributionResult, PointConnectionSettings(gui.pointConnectionType));
	}
	// add new layer
	else if (key == 's') {

	}
}
