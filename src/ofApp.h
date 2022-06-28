#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "../BaseImage.h"
#include "../ImageFilter.h"
#include "../PointDistribution.h"
#include "../PointConnection.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	    BaseImage baseImage;

		ImageFilterType imageFilterType;
		ImageFilterSettings imageFilterSettings;
		ImageFilterResult imageFilterResult;

		PointDistributionType pointDistributionType;
		PointDistributionSettings pointDistributionSettings;
		PointDistributionResult pointDistributionResult;

		PointConnectionType pointConnectionType;
		PointConnectionSettings pointConnectionSettings;
		PointConnectionResult pointConnectionResult;

		void calculateFromImageFilterOnward();
		void calculateFromPointDistributionOnward();

		// GUI
		void setupGui();
		ofxPanel gui;
		ofxFloatSlider gPower;
		void gPowerChanged(float& gPower);
		ofxIntSlider gSpacer;
		void gSpacerChanged(int& gSpacer);
		ofxToggle gLightMode;
		void gLightModeChanged(bool& gLightMode);
		ofxIntSlider gPointDistributionMethod;
		void gPointDistributionMethodChanged(int& gPointDistributionMethod);
		ofxIntSlider gParticleCount;
		void gParticleCountChanged(int& gParticleCount);
		ofxToggle gDrawDelaunay;
		ofxToggle gDrawImage;

};
