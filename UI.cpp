#include "UI.h"

UI* UI::mInstance = nullptr;

UI::UI() {
}


UI::~UI() {
}

void UI::lateUpdate() {
	string a;
	Console::setColor(black, lightGray);
	for each (pair<int*, Vector> var in intReg) {
		Console::setPosition(var.second);
		cout << *var.first;
	}
	for each (pair<string*, Vector> var in strReg) {
		Console::setPosition(var.second);
		cout << *var.first;
	}
}

UI * UI::instance() {
	if (!mInstance) {
		mInstance = new UI();
	}
	return mInstance;
}

void UI::deleteInstance() {
	if (mInstance) {
		delete mInstance;
		mInstance = nullptr;
	}
}

void UI::addUpdatedInt(int *adress, Vector position) {
	intReg.push_back(pair<int*, Vector>(adress, position));
}

void UI::addUpdatedString(string *str, Vector position) {
	strReg.push_back(pair<string*, Vector>(str, position));
}

Sprite * UI::putSprite(Sprite sprite) {
	return nullptr;
}

void UI::debugMessage(string message) {
	//setPosition(Vector(1, resolution.y - 1));
	//cout << message;
}
