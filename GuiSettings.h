#include <ofParameter.h>

#pragma once
class GuiSettings
{
public:
	// --- Main Settings ---
	ofParameterGroup mainSettingsGroup;
	ofParameter<bool> drawImage;

	// --- Image Filter Settings ---
	ofParameterGroup imageFilterSettingsGroup;

	ofParameter<int> imageFilterTypeSelection;
	ImageFilterType imageFilterType;
	void imageFilterTypeChanged(int& imageFilterMethod);

	ofParameter<float> power;
	void powerChanged(float& power);

	ofParameter<bool> lightMode;
	void lightModeChanged(bool& lightMode);

	// --- Point Distribution Settings ---
	ofParameterGroup pointDistributionSettingsGroup;

	ofParameter<int> pointDistributionTypeSelection;
	PointDistributionType pointDistributionType;
	void pointDistributionTypeChanged(int& pointDistributionMethod);

	ofParameter<int> particleCount;
	void particleCountChanged(int& particleCount);

	ofParameter<int> spacer;
	void spacerChanged(int& spacer);

	ofParameter<bool> drawDistribution;

	// --- Point Connection Settings ---
	ofParameterGroup pointConnectionSettingsGroup;

	ofParameter<int> pointConnectionTypeSelection;
	PointConnectionType pointConnectionType;
	void pointConnectionTypeChanged(int& pointConnectionMethod);

	ofParameter<bool> drawConnection;

	// --- All Settings Collection ---
	ofParameterGroup allParameters;

	// -------------------------------

	// main callback
	ofApp * app;

	GuiSettings(ofApp * _app);
};