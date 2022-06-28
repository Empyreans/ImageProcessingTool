#include "ImageFilter.h"
#include "BaseImage.h"

ImageFilterResult ImageFilter::calculate(const BaseImage& _baseImage, const ImageFilterSettings& _imageFilterSettings, const ImageFilterType& _imageFilterType)
{
	std::vector<float> _filterPixels;

	int h = _baseImage.h;
	int w = _baseImage.w;
	ofImage image = _baseImage.getImage();

	switch (_imageFilterType) {
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
			ofLog(OF_LOG_NOTICE, ofToString(y));
		}
		break;
	}

	return ImageFilterResult(_filterPixels, _baseImage.w, _baseImage.h);
}

bool ImageFilterResult::checkPointOnThreshold(int _x, int _y, float _power) const {
	int p = _x + _y * w;
	return ofRandom(1.0) < powf(filterPixels[p], _power);
}

void ImageFilterResult::draw() {
}