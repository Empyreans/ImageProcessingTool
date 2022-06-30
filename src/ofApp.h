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

		// initial values
		void setupInitCalcSettings();
		ImageFilterType imageFilterType;
		PointDistributionType pointDistributionType;
		PointConnectionType pointConnectionType;

		// calculation data
	    BaseImage baseImage;
		ImageFilterResult imageFilterResult;
		PointDistributionResult pointDistributionResult;
		PointConnectionResult pointConnectionResult;

		void calculateFromImageFilterOnward();
		void calculateFromPointDistributionOnward();

		// gui
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

		// input
		void keyPressed(int key);

};
