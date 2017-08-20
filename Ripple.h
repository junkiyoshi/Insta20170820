#pragma once
#include <ofMain.h>

class Ripple {
public:
	Ripple();
	Ripple(ofVec3f location);
	~Ripple();
	void update();
	void draw();
	bool isLife();
private:
	ofVec3f location;
	float radius;
	float radius_max;
	float radius_span;
	float alpha;
	float alpha_span;
	bool life;

	ofColor body_color;
};