#pragma once
#include "Console.h"
#include "Layer.h"
#include <string>
#include "Sprite.h"
#include "StandardObject.h"
using namespace std;

class UI : private Console, private StandardObject {
private:
	vector<pair<int*, Vector>> intReg;
	vector<pair<string*, Vector>> strReg;
	UI();
	~UI();
	static UI* mInstance;

	void lateUpdate() override;
public:
	static UI* instance();
	void deleteInstance();

	void addUpdatedInt(int*, Vector);
	void addUpdatedString(string*, Vector);
	Sprite* putSprite(Sprite);
	void debugMessage(string);
};

