#pragma once
#pragma once

#include "ofMain.h"

class BaseImage
{
public:
	ofImage image;
	int w, h;


	BaseImage();
	BaseImage(string _filepath, int _w, int _h);

	void draw();
	vector<float> getImgBrightness();
	bool checkFunc(vector<float>& , int x, int y);
	vector<ofPoint> pdSpacer(vector<float>& imgVec);
	vector<ofPoint> pdRandom(vector<float>& imgVec);
};

