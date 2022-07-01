#pragma once

#include "ofxDelaunay.h"

enum class PointConnectionType { Delaunay };

class ofxDelaunay;
struct PointConnectionResult {
	ofxDelaunay delaunay;

	PointConnectionResult() = default;
	PointConnectionResult(ofxDelaunay _delaunay) : delaunay(_delaunay) {}

	void draw();
};

struct PointConnectionSettings {
	PointConnectionType pointConnectionType;

	PointConnectionSettings(PointConnectionType _pointConnectionType) : pointConnectionType(_pointConnectionType) {};
};

struct PointDistributionResult;
class PointConnection
{
public:
	PointConnection() = default;
	static PointConnectionResult calculate(const PointDistributionResult & pointDistributionResult, const PointConnectionSettings & _pointConnectionSettings);
};