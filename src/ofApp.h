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

		void drawToFbo();

		// gui
		GuiSettings gui;
		ofxPanel guiPanel;
		ofEventListener imageFilterListener;
		ofEventListener pointDistributionListener;
		ofEventListener pointConnectionListener;
		void prepareGui();

		// base
		BaseImage baseImage;

		// calculation methods
		void calculateAll();
		void calculateDistribution();
		void calculateConnection();

		// calculation results
		ImageFilterResult imageFilterResult;
		PointDistributionResult pointDistributionResult;
		PointConnectionResult pointConnectionResult;

		ofFbo fbo;

		ofxSpout::Receiver receiver;
		bool isSpoutReceived = false;
		ofTexture spoutTexture;

		ofxSpout::Sender sender;

		boolean manualMode;

		ofRectangle imageSize;

		// input
		void keyPressed(int key);

};
