#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "../BaseImage.h"
#include "../ImageFilter.h"
#include "../PointDistribution.h"
#include "../PointConnection.h"
#include "../GuiSettings.h"
#include "ofxSpout.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		// receive texture via spout
		ofxSpout::Receiver receiver;
		ofTexture spoutTextureIn;

		// control: gui / run time settings
		GuiSettings gui;
		ofxPanel guiPanel;
		ofEventListener imageFilterListener;
		ofEventListener pointDistributionListener;
		ofEventListener pointConnectionListener;
		void prepareGui();

		// control: key input
		void keyPressed(int key);

		// control: compile time settings
		boolean manualMode;

		// base container for incoming image
		BaseImage baseImage;

		// calculation calls with current gui settings
		ImageFilterResult calculateImageFilterResult();
		PointDistributionResult calculatePointDistributionResult();
		PointConnectionResult calculatePointConnectionResult();

		// callbacks for gui settings change
		void recalculateAll();
		void recalculateDistribution();
		void recalculateConnection();

		// calculation results
		ImageFilterResult imageFilterResult;
		PointDistributionResult pointDistributionResult;
		PointConnectionResult pointConnectionResult;

		// resulting image
		ofFbo fbo;
		void drawToFbo();
		// rescaled dimensions to fit window size for display
		ofRectangle imageSize;

		ofxSpout::Sender sender;

};
