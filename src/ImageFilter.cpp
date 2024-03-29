#include "ImageFilter.h"
#include "BaseImage.h"

ImageFilterResult ImageFilter::calculate(const BaseImage& _baseImage, const ImageFilterSettings& _imageFilterSettings)
{
	std::vector<float> _filterPixels;

	ImageFilterType imageFilterSettings = _imageFilterSettings.imageFilterType;
	bool lightMode = _imageFilterSettings.lightMode;
	int w = _baseImage.w;
	int h = _baseImage.h;
	ofImage image = _baseImage.getImage();

	switch (imageFilterSettings) {
	case ImageFilterType::Brightness:
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				ofColor color = image.getColor(x, y);
				float brightness = ofMap(color.getBrightness(), 0, 255.0, 0, 1.0);
				if (_imageFilterSettings.lightMode) {
					_filterPixels.push_back(brightness);
				}
				else {
					_filterPixels.push_back(1 - brightness);
				}
			}
		}
		break;
	}

	return ImageFilterResult(_filterPixels, w, h);
}

// Mhhh...
bool ImageFilterResult::checkPointOnThreshold(int _x, int _y, float _power) const {
	int p = _x + _y * w;
	return ofRandom(1.0) < powf(filterPixels[p], _power);
}

void ImageFilterResult::draw() {
}