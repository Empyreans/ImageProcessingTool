//#include "GuiSettings.h"
//#include "PointDistribution.h"
//#include "PointConnection.h"
//#include "ImageFilter.h"
#include "ofApp.h"

GuiSettings::GuiSettings() {
	// initialize default values
	imageFilterType = ImageFilterType::Brightness;
	pointDistributionType = PointDistributionType::Spacer;
	pointConnectionType = PointConnectionType::Delaunay;

	// --- Main Settings ---
	mainSettingsGroup.setName("main settings");
	mainSettingsGroup.add(drawImage.set("draw image", true));

	// --- Image Filter Settings ---
	imageFilterSettingsGroup.setName("image filter settings");
	imageFilterSettingsGroup.add(imageFilterTypeSelection.set("image filter method", 0, 0, 1));
	imageFilterSettingsGroup.add(power.set("power", 5.0, 2.0, 24.0));
	imageFilterSettingsGroup.add(lightMode.set("light mode", true));

	// --- Point Distribution Settings ---
	pointDistributionSettingsGroup.setName("point distribution settings");
	pointDistributionSettingsGroup.add(pointDistributionTypeSelection.set("point distribution method", 0, 0, 1));
	pointDistributionSettingsGroup.add(particleCount.set("particle count", 100, 100, 50000));
	pointDistributionSettingsGroup.add(spacer.set("spacer", 20, 1, 120));
	pointDistributionSettingsGroup.add(drawDistribution.set("draw distribution", false));
	pointDistributionTypeSelection.addListener(this, &GuiSettings::pointDistributionTypeChanged);

	// --- Point Connection Settings ---
	pointConnectionSettingsGroup.setName("point connection settings");
	pointConnectionSettingsGroup.add(drawConnection.set("draw connection", true));

	// collect all parameters into one gorup
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
}

void GuiSettings::pointConnectionTypeChanged(int& pointConnectionMethod)
{
	switch (pointConnectionMethod) {
	case 0:
		pointConnectionType = PointConnectionType::Delaunay;
		break;
	}
}