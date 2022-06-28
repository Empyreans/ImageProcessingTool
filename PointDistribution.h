#pragma once

#include <ofPoint.h>
#include <vector>

enum class PointDistributionType { Spacer, Random };

struct PointDistributionResult {
	std::vector<ofPoint> points;

	PointDistributionResult() = default;
	PointDistributionResult(std::vector<ofPoint> _points) : points(_points) {}

	void draw();
};

struct PointDistributionSettings {
	int spacer;
	int particleCount;
	float power;

	PointDistributionSettings() = default;
	PointDistributionSettings(int _spacer, int _particleCount, float _power) : spacer(_spacer), particleCount(_particleCount), power(_power) {};
};

struct ImageFilterResult;
class PointDistribution
{
public:
	PointDistribution() = default;

	static PointDistributionResult calculate(const ImageFilterResult & _filterImageResult, const PointDistributionSettings & _pointDistributionSettings, const PointDistributionType& _pointDistributionType);
};

