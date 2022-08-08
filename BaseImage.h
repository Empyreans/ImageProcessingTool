#pragma once

#include <ofImage.h>
#include <string>

class BaseImage
{
private:
	ofImage image;

public:
	int w, h;

	BaseImage() = default;
	BaseImage(std::string _filePath, int _w, int _h) : w(_w), h(_h) {
		image.load(_filePath);
		image.resize(w, h);
	};
	BaseImage(ofTexture _texture) {
		ofPixels pixels;
		_texture.readToPixels(pixels);
		image.setFromPixels(pixels);
		w = image.getWidth();
		h = image.getHeight();
	};

	void draw(const ofRectangle & rect) {
		image.draw(rect);
	};

	ofImage getImage() const {
		return image;
	}
};

