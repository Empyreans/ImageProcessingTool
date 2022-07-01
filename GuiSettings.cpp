//#include "GuiSettings.h"
//#include "PointDistribution.h"
//#include "PointConnection.h"
//#include "ImageFilter.h"
#include "ofApp.h"

GuiSettings::GuiSettings(ofApp * _app) {

	app = _app;

	// --- Main Settings ---
	mainSettingsGroup.setName("main settings");
	mainSettingsGroup.add(drawImage.set("draw image", true));

	// --- Image Filter Settings ---
	imageFilterSettingsGroup.setName("image filter settings");

	imageFilterSettingsGroup.add(imageFilterTypeSelection.set("image filter method", 0, 0, 1));
	imageFilterTypeSelection.addListener(this, &GuiSettings::imageFilterTypeChanged);

	imageFilterSettingsGroup.add(power.set("power", 5.0, 2.0, 24.0));
	power.addListener(this, &GuiSettings::powerChanged);

	imageFilterSettingsGroup.add(lightMode.set("light mode", true));
	lightMode.addListener(this, &GuiSettings::lightModeChanged);

	// --- Point Distribution Settings ---
	pointDistributionSettingsGroup.setName("point distribution settings");

	pointDistributionSettingsGroup.add(pointDistributionTypeSelection.set("point distribution method", 0, 0, 1));
	pointDistributionTypeSelection.addListener(this, &GuiSettings::pointDistributionTypeChanged);

	pointDistributionSettingsGroup.add(particleCount.set("particle count", 100, 100, 10000));
	particleCount.addListener(this, &GuiSettings::particleCountChanged);

	pointDistributionSettingsGroup.add(spacer.set("spacer", 5, 5, 120));
	spacer.addListener(this, &GuiSettings::spacerChanged);

	pointDistributionSettingsGroup.add(drawDistribution.set("draw distribution", false));

	// --- Point Connection Settings ---
	pointConnectionSettingsGroup.setName("point connection settings");

	pointConnectionSettingsGroup.add(drawConnection.set("draw connection", true));

	// --- All Settings Collection ---
	allParameters.setName("settings");
	allParameters.add(mainSettingsGroup);
	allParameters.add(imageFilterSettingsGroup);
	allParameters.add(pointDistributionSettingsGroup);
	allParameters.add(pointConnectionSettingsGroup);
}

void GuiSettings::imageFilterTypeChanged(int& imageFilterMethod)
{
	switch (imageFilterMethod) {
	case 0:
		imageFilterType = ImageFilterType::Brightness;
		break;
	}
	app->calculateAll();
}

void GuiSettings::powerChanged(float& power)
{
	app->calculateDistribution();
}

void GuiSettings::lightModeChanged(bool& lightMode)
{
	app->calculateAll();
}

// TODO ofParameter<PointDistributionType> ?
void GuiSettings::pointDistributionTypeChanged(int& pointDistributionMethod)
{
	switch (pointDistributionMethod) {
	case 0:
		pointDistributionType = PointDistributionType::Spacer;
		break;
	case 1:
		pointDistributionType = PointDistributionType::Random;
		break;
	}
	app->calculateDistribution();
}

void GuiSettings::particleCountChanged(int& particleCount)
{
	app->calculateDistribution();
}

void GuiSettings::spacerChanged(int& spacer)
{
	app->calculateDistribution();
}

void GuiSettings::pointConnectionTypeChanged(int& pointConnectionMethod)
{
	switch (pointConnectionMethod) {
	case 0:
		pointConnectionType = PointConnectionType::Delaunay;
		break;
	}
	app->calculateConnection();
}