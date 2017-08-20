#include "Ripple.h"

Ripple::Ripple() : Ripple(ofVec3f(0, 0, 0))
{
	
}

Ripple::Ripple(ofVec3f location)
{
	this->location = location;
	this->radius = 1;
	this->radius_max = location.z / 10;
	this->radius_span = 1;
	this->alpha = 255;
	this->alpha_span = this->alpha / this->radius_max;
	this->life = true;

	this->body_color.setHsb(ofRandom(255), 255, 255);
}

Ripple::~Ripple()
{

}

void Ripple::update()
{
	if (this->location.z > 0) {
		this->location = this->location - ofVec3f(0, 0, 30);
		return;
	}

	if (this->radius > this->radius_max) {
		this->life = false;
		return;
	}

	this->radius += this->radius_span;
	this->alpha -= this->alpha_span;	
}

void Ripple::draw()
{
	ofPushMatrix();
	ofTranslate(this->location);

	//ofSetColor(this->body_color, this->alpha);

	if (this->location.z > 0) {
		ofLine(ofVec3f(0, 0, 0), ofVec3f(0, 0, 30));
	} else {
		ofEllipse(ofVec3f(0, 0, 0), this->radius, this->radius);
	}

	ofPopMatrix();
}

bool Ripple::isLife()
{
	return this->life;
}