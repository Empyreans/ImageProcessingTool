#pragma once

#include <ofPoint.h>
#include <vector>
#include "CDT/CDT.h"
#include "BaseImage.h"

enum class PointDistributionType { Spacer, Random };

struct PointDistributionResult {
	std::vector<ofPoint> points;

	PointDistributionResult() = default;
	PointDistributionResult(std::vector<ofPoint> _points) : points(_points) {}

	void draw();
	std::vector<CDT::V2d<float>> getCdtPoints() const;
	void addPoints(const PointDistributionResult& result);
};

struct PointDistributionSettings {
	PointDistributionType pointDistributionType;
	int spacer;
	int particleCount;
	float power;

	// TODO remove all default
	PointDistributionSettings() = default;
	PointDistributionSettings(PointDistributionType _pointDistributionType, int _spacer, int _particleCount, float _power) : pointDistributionType(_pointDistributionType), spacer(_spacer), particleCount(_particleCount), power(_power) {};
};

struct ImageFilterResult;
class PointDistribution
{
public:
	PointDistribution() = default;

	static PointDistributionResult calculate(const ImageFilterResult & _filterImageResult, const PointDistributionSettings & _pointDistributionSettings);
};

