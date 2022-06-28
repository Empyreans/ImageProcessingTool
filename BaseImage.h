#pragma once

#include <ofImage.h>
#include <string>

class BaseImage
{
private:
	ofImage image;

public:
	int w, h;
	std::string filePath;

	BaseImage() = default;
	BaseImage(std::string _filePath, int _w, int _h) : filePath(_filePath), w(_w), h(_h) {
		image.load(filePath);
		image.resize(w, h);
	};

	void draw() {
		image.draw(0, 0);
	};

	ofImage getImage() const {
		return image;
	}
};

