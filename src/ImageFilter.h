#pragma once

#include <vector>

enum class ImageFilterType { Brightness };

struct ImageFilterResult {
	std::vector<float> filterPixels;
	int w;
	int h;

	ImageFilterResult() = default;
	ImageFilterResult(std::vector<float> _filterPixels, int _w, int _h) : filterPixels(_filterPixels), w(_w), h(_h) {};

	bool checkPointOnThreshold(int _x, int _y, float _power) const;
	void draw();
};

struct ImageFilterSettings {
	ImageFilterType imageFilterType;
	bool lightMode;

	ImageFilterSettings() = default;
	ImageFilterSettings(ImageFilterType _imageFilterType, bool _lightMode) : lightMode(_lightMode), imageFilterType(_imageFilterType) {};
};

class BaseImage;
class ImageFilter
{
public:
	ImageFilter() = default;

	static ImageFilterResult calculate(const BaseImage & _baseImage, const ImageFilterSettings & _imageFilterSettings);
};

