#include "PointDistribution.h"
#include "ImageFilter.h"
#include "ofMain.h"

PointDistributionResult PointDistribution::calculate(const ImageFilterResult & _filterImageResult, const PointDistributionSettings & _pointDistributionSettings)
{
	std::vector<ofPoint> _points;

	float power = _pointDistributionSettings.power;

	switch (_pointDistributionSettings.pointDistributionType) {
	case PointDistributionType::Spacer:
	{
		int spacer = _pointDistributionSettings.spacer;
		for (int y = 0; y < _filterImageResult.h; y += spacer) {
			for (int x = 0; x < _filterImageResult.w; x += spacer) {
				if (_filterImageResult.checkPointOnThreshold(x, y, power)) {
					_points.push_back(ofPoint(x, y));
				}
			}
		}
	}
	break;
	case PointDistributionType::Random:
		int particleCount = _pointDistributionSettings.particleCount;
		for (int i = 0; i < particleCount; i++) {
			int x = (int)ofRandom(_filterImageResult.w);
			int y = (int)ofRandom(_filterImageResult.h);
			if (_filterImageResult.checkPointOnThreshold(x, y, power)) {
				_points.push_back(ofPoint(x, y));
			}
		}
		break;
	}
	return PointDistributionResult(_points);
}

void PointDistributionResult::draw() {
	for (ofPoint p : points) {
		ofDrawEllipse(p, 5, 5);
	}
}