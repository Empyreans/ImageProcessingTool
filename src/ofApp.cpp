#include "ofApp.h"
#include <ofLog.cpp>
#include <ofxEasing.h>

using namespace ofxeasing;


void ofApp::setup() {

	prepareGui(); 
	sender.init("ImageProcessingToolOut");
	receiver.init("ImageProcessingTool");

	ofLog() << "waiting for spout texture ...";
	while (!spoutTexture.isAllocated()) {
		receiver.receive(spoutTexture);
	}
	ofLog() << "spout texture received.";

	baseImage = BaseImage(spoutTexture);
	calculateAll();
	fbo.allocate(baseImage.w, baseImage.h, GL_RGBA, 32);
	fbo.begin();
	ofClear(0, 0, 0, 0);
	fbo.end();

	ofRectangle windowSize(0, 0, ofGetWidth(), ofGetHeight());
	imageSize = ofRectangle(0, 0, baseImage.w, baseImage.h);
	imageSize.scaleTo(windowSize);

	manualMode = true;
}

void ofApp::draw() {
	if (gui.drawImage) {
		baseImage.draw(imageSize);
	}
	else {
		ofBackground(25, 25, 25);
	}
	if (gui.drawConnection) {
		drawToFbo();
		fbo.draw(imageSize);
	}
	if (gui.drawDistribution) {
		pointDistributionResult.draw();
	}
	guiPanel.draw();
}

void ofApp::drawToFbo() {
	fbo.begin();
	if (manualMode) {
		pointConnectionResult.draw();
	}
	else {
		int start = 50;
		int end = 25;
		int step = 1;
		for (int i = start; i >= end; i -= step) {
			float alpha = ofxeasing::map(i, end, start, 25, 255, exp::easeOut);
			ofSetColor(255, 255, 255, 255-alpha);
			gui.spacer.set(i);
			calculateDistribution();
			pointConnectionResult.draw();
		}
		gui.spacer.set(3);
		calculateDistribution();
		pointConnectionResult.draw();

	}
	fbo.end();
}

void ofApp::update() { }

// TODO vielleicht für jedes einzelne Methode
// TODO vielleicht calculate Methods nicht statisch
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

void ofApp::keyPressed(int key) {
	// add current points to previous points
	if (key == 'a') {
		PointDistributionResult res = PointDistribution::calculate(imageFilterResult, PointDistributionSettings(gui.pointDistributionType, gui.spacer, gui.particleCount, gui.power));
		pointDistributionResult.addPoints(res);
		calculateConnection();
	}
	// new beginnings...
	else if (key == 'd') {
		fbo.begin();
		ofClear(0, 0, 0, 0);
		fbo.end();
	}
	// send texture via spout
	else if (key == 'x') {
		sender.send(fbo.getTexture());
		ofLog() << "Spout texture sent.";
	}
}
