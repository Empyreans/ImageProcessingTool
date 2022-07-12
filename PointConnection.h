#pragma once

#include "ofxDelaunay.h"
#include "CDT/CDT.h"

enum class PointConnectionType { Delaunay };

class ofxDelaunay;
struct PointConnectionResult {
	ofMesh triangleMesh;

	PointConnectionResult() = default;
	PointConnectionResult(ofMesh _delaunay) : triangleMesh(_delaunay) {}

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