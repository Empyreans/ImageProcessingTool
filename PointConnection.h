#pragma once

#include "ofxDelaunay.h"
#include "CDT/CDT.h"
#include "BaseImage.h"

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
	bool colorMode;

	PointConnectionSettings(PointConnectionType _pointConnectionType, bool _colorMode) : pointConnectionType(_pointConnectionType), colorMode(_colorMode) {};
};

struct PointDistributionResult;
class PointConnection
{
public:
	PointConnection() = default;
	static PointConnectionResult calculate(const PointDistributionResult& pointDistributionResult, const BaseImage& _baseImage, const PointConnectionSettings& _pointConnectionSettings);
};