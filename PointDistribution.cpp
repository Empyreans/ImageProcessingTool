#include "PointDistribution.h"
#include "ImageFilter.h"
#include "ofMain.h"

// TODO power -> imagefiltersettings?
PointDistributionResult PointDistribution::calculate(const ImageFilterResult & _filterImageResult, const PointDistributionSettings & _pointDistributionSettings)
{
	std::vector<ofPoint> _points;
	// std::vector<ofColor> _colors;

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
				//_colors.push_back(_filterImageResult.getColorAt(x, y));
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

std::vector<CDT::V2d<float>> PointDistributionResult::getCdtPoints() const {
	std::vector<CDT::V2d<float>> cdtPoints;
	for (ofPoint p : points) {
		CDT::V2d<float> f;
		cdtPoints.push_back(f.make(p.x, p.y));
	}
	return cdtPoints;
}

void PointDistributionResult::addPoints(const PointDistributionResult & result) {
	points.insert(points.end(), result.points.begin(), result.points.end());
}
