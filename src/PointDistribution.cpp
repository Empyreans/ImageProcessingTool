#include "PointDistribution.h"
#include "ImageFilter.h"
#include "ofMain.h"

// TODO power -> imagefiltersettings?
PointDistributionResult PointDistribution::calculate(const ImageFilterResult & _filterImageResult, const PointDistributionSettings & _pointDistributionSettings)
{
	std::vector<ofPoint> _points;

	float power = _pointDistributionSettings.power;
	int spacer = _pointDistributionSettings.spacer;
	int particleCount = _pointDistributionSettings.particleCount;
	PointDistributionType pointDistributionType = _pointDistributionSettings.pointDistributionType;
	int h = _filterImageResult.h;
	int w = _filterImageResult.w;

	switch (pointDistributionType) {
	case PointDistributionType::Spacer:
	{
		for (int y = 0; y < h; y += spacer) {
			for (int x = 0; x < w; x += spacer) {
				if (_filterImageResult.checkPointOnThreshold(x, y, power)) {
					_points.push_back(ofPoint(x, y));
				}
			}
		}
	}
	break;
	case PointDistributionType::Random:
		for (int i = 0; i < particleCount; i++) {
			int x = (int)ofRandom(w);
			int y = (int)ofRandom(h);
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

std::vector<CDT::V2d<float>> PointDistributionResult::getCdtPoints() const {
	std::vector<CDT::V2d<float>> cdtPoints;
	for (ofPoint p : points) {
		CDT::V2d<float> f;
		cdtPoints.push_back(f.make(p.x, p.y));
	}
	return cdtPoints;
}

void PointDistributionResult::addPoints(const PointDistributionResult & result) { // nicht den ganzen PointDistributionResult reingeben, sondern nur die relevanten Punkte
	points.insert(points.end(), result.points.begin(), result.points.end());
}
