#include "GGame.h"
#include "GameObject.h"
#include "Input.h"
#include "Audio.h"
#include "UI.h"

using namespace std;

class Wall : public GameObject {
public:
	Wall(unsigned char tag, Vector pos, Vector dim) : GameObject(tag) {
		body.load(dim, darkGray);
		body.setTag(tag);
		body.setPosition(pos);
		body.updatePosition();
	};
};

class Fier : public GameObject {
public:
	Fier(unsigned char tag, Vector pos) : GameObject(tag) {
		body.setMass(2);
		body.setFriction(0.2);
		body.useGravity();
		body.setPosition(pos);
		body.load(Vector(1, 1), darkRed);
	}

	void lateUpdate() override {
		body.updatePosition();
	}
};
class Nisip : public GameObject {
public:
	Nisip(unsigned char tag, Vector pos) : GameObject(tag) {
		body.setMass(0.5);
		body.setFriction(0.2);
		body.useGravity();
		body.setPosition(pos);
		body.load(Vector(1, 1), darkYellow);
	}

	void lateUpdate() override {
		body.updatePosition();
	}
};
class Apa : public GameObject {
public:
	Apa(unsigned char tag, Vector pos) : GameObject(tag) {
		body.setMass(1);
		body.setFriction(0.2);
		body.useGravity();
		body.setPosition(pos);
		body.load(Vector(1, 1), darkBlue);
	}

	void lateUpdate() override {
		body.updatePosition();
	}

	void onCollision(unsigned char tag) override {
		if (tag == 4) {
			this->tag = 4;
			this->body.tag = 4;
			this->body.setTag(4);
		}
	}
};


class GameController : public StandardObject {
public:
	void start() override {
		Vector res = Resolution::getApplicationResolution();
		new Wall(5, Vector(5, 5), Vector(2, res.y - 10));
		new Wall(5, Vector(res.x - 5, 5), Vector(2, res.y - 10));
		new Wall(4, Vector(5, res.y - 5), Vector(res.x - 8, 2));
	}

	void update() override {
		//if (Input::isPressed(Input::mouseButton::LeftButton)) {
		//	GGame::instantiateObject<Particula>(9, Input::mousePosition());
		//}
		if (Input::onPressed(Input::keyCode::Space)) {
			GGame::instantiateObject<Apa>(7, Input::mousePosition());
		}
		if (Input::onPressed(Input::keyCode::W)) {
			GGame::instantiateObject<Fier>(8, Input::mousePosition());
		}
		if (Input::onPressed(Input::keyCode::N)) {
			GGame::instantiateObject<Nisip>(9, Input::mousePosition());
		}
		if (Input::onPressed(Input::keyCode::Esc)) {
			GGame::end();
		}
	}
};

void main34() {
	GGame game(30);

	Console::setCharacter(Vector(8, 10));
	Console::setFullScreen();


	GameController gc;

	UI *ui = UI::instance();

	Vector res = Resolution::getApplicationResolution();
	string fpsText = "FPS: ";
	ui->addUpdatedString(&fpsText, Vector(res.x / 8, 7));
	ui->addUpdatedInt(&GGame::actualFps, Vector(res.x / 8 + 8, 7));

	game.start();
}