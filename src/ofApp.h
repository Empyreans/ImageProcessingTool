#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../BaseImage.h"
#include "ofxDelaunay.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		BaseImage baseImage;

		vector<float> imgFilter;
		vector<float> calculateImgFilter();
		vector<ofPoint> points;
		vector<ofPoint>  calculatePointDistribution(vector<float> points);
		ofxDelaunay delaunay;
		ofxDelaunay calculateDelaunayTriangulation(vector<ofPoint> points);

		// GUI
		void setupGui();
		ofxPanel gui;
		ofxFloatSlider gPower;
		void gPowerChanged(float& gPower);
		ofxIntSlider gSpacer;
		void gSpacerChanged(int& gSpacer);
		ofxToggle gLightOrDark;
		void gLightOrDarkChanged(bool& lightOrDark);
		ofxIntSlider gPointDistributionMethod;
		void gPointDistributionMethodChanged(int& gPointDistributionMethod);
		ofxIntSlider gParticleCount;
		void gParticleCountChanged(int& gParticleCount);
		ofxToggle gDrawDelaunay;
		ofxToggle gDrawImage;

};
