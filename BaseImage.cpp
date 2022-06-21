#include "BaseImage.h"
#include "ofMain.h"
#include "ofApp.h"

BaseImage::BaseImage() {}

BaseImage::BaseImage(string _filepath, int _w, int _h) {
	w = _w;
	h = _h;
	image.load(_filepath);
	image.resize(w, h);
}

void BaseImage::draw() {
	image.draw(0, 0);
}

vector<float> BaseImage::getImgBrightness() {
	bool lightMode = ((ofApp*)ofGetAppPtr())->gLightOrDark;
	vector<float> brightnessVec;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			ofColor color = image.getColor(x, y);
			float brightness = ofMap(color.getBrightness(), 0, 255.0, 0, 1.0);
			if (lightMode) {
				brightnessVec.push_back(brightness);
			}
			else {
				brightnessVec.push_back(1 - brightness);
			}
		}
	}
	return brightnessVec;
}

bool BaseImage::checkFunc(vector<float>& imgFilter, int x, int y) {
	int power = ((ofApp*)ofGetAppPtr())->gPower;
	int p = x + y * w;
	return ofRandom(1.0) < powf(imgFilter[p], power);
}

vector<ofPoint> BaseImage::pdSpacer(vector<float>& imgFilter) {
	vector<ofPoint> points;
	int spacer = ((ofApp*)ofGetAppPtr())->gSpacer;
	for (int y = 0; y < h; y += spacer) {
		for (int x = 0; x < w; x += spacer) {
			if (checkFunc(imgFilter, x, y)) {
				points.push_back(ofPoint(x, y));
			}
		}
	}
	return points;
}

vector<ofPoint> BaseImage::pdRandom(vector<float>& imgFilter) {
	vector<ofPoint> points;
	int particleCount = ((ofApp*)ofGetAppPtr())->gParticleCount;
	for (int i = 0; i < particleCount; i++) {
		int x = (int)ofRandom(w);
		int y = (int)ofRandom(h);
		if (checkFunc(imgFilter, x, y)) {
			points.push_back(ofPoint(x, y));
		}
	}
	return points;
}