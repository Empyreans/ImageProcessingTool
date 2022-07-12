#include <ofParameter.h>

#pragma once
class ofApp;
class GuiSettings
{
public:
	// --- Main Settings ---
	ofParameterGroup mainSettingsGroup;
	ofParameter<bool> drawImage;

	// --- Image Filter Settings ---
	ofParameterGroup imageFilterSettingsGroup;
	ofParameter<int> imageFilterTypeSelection;
	ofParameter<float> power;
	ofParameter<bool> lightMode;
	ImageFilterType imageFilterType;
	void imageFilterTypeChanged(int& imageFilterMethod);

	// --- Point Distribution Settings ---
	ofParameterGroup pointDistributionSettingsGroup;
	ofParameter<int> pointDistributionTypeSelection;
	ofParameter<int> particleCount;
	ofParameter<int> spacer;
	ofParameter<bool> drawDistribution;
	PointDistributionType pointDistributionType;
	void pointDistributionTypeChanged(int& pointDistributionMethod);

	// --- Point Connection Settings ---
	ofParameterGroup pointConnectionSettingsGroup;
	ofParameter<int> pointConnectionTypeSelection;
	ofParameter<bool> drawConnection;
	PointConnectionType pointConnectionType;
	void pointConnectionTypeChanged(int& pointConnectionMethod);

	// --- All Settings Collection ---
	ofParameterGroup allParameters;

	GuiSettings();
};