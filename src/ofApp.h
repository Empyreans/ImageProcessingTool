#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "../BaseImage.h"
#include "../ImageFilter.h"
#include "../PointDistribution.h"
#include "../PointConnection.h"
#include "../GuiSettings.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		// gui
		GuiSettings gui;
		ofxPanel guiPanel;

		// base
		BaseImage baseImage;

		// calculation
		void calculateAll();
		void calculateDistribution();
		void calculateConnection();

		// calculation results
		ImageFilterResult imageFilterResult;
		PointDistributionResult pointDistributionResult;
		PointConnectionResult pointConnectionResult;

		// input
		void keyPressed(int key);

};
