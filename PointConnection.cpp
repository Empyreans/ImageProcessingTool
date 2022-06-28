#include "PointConnection.h"
#include "PointDistribution.h"

PointConnectionResult PointConnection::calculate(const PointDistributionResult & pointDistributionResult, const PointConnectionSettings & _pointConnectionSettings, const PointConnectionType & _pointConnectionType)
{
	ofxDelaunay delaunay;

	switch (_pointConnectionType) {
	case PointConnectionType::Delaunay:
		for (ofPoint p : pointDistributionResult.points) {
			delaunay.addPoint(p);
		}
		delaunay.triangulate();
	}

	return PointConnectionResult(delaunay);
}

void PointConnectionResult::draw() {
	ofNoFill();
	ofSetLineWidth(1.0);
	delaunay.draw();
}