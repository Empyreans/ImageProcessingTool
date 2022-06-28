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
	bool lightMode;

	ImageFilterSettings() = default;
	ImageFilterSettings(bool _lightMode) : lightMode(_lightMode) {};
};

class BaseImage;
class ImageFilter
{
public:
	ImageFilter() = default;

	static ImageFilterResult calculate(const BaseImage & _baseImage, const ImageFilterSettings & _imageFilterSettings, const ImageFilterType & _imageFilterType);
};

