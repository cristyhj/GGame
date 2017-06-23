#include "GGame.h"
#include "GameObject.h"
#include "Input.h"
#include "Audio.h"
#include "UI.h"

using namespace std;

class GameController : public GameObject {
public:
	GameController(unsigned char tag) : GameObject(tag) {
	};
};

string piceName[6];
int score;

class Pice : public GameObject {
protected:
	bool dead;
public:
	int spawnTime;
public:
	Pice(Vector pos) : GameObject(5) {}
	Pice(unsigned char tag, Vector pos) : GameObject(tag) {
		dead = false;
		spawnTime = 0;

		body.load("Sprites/" + piceName[Random::randomInt(6)]);
		body.setTag(tag);
		body.setPosition(pos);
		body.updatePosition();
	}

	void update() override {
		if (!dead) {
			if (spawnTime >= 8) {
				//body.addForce(Vector::down * 80);
				body.moveDown();
				spawnTime = 0;
				score++;
			} else {
				spawnTime++;
			}
			if (Input::onPressed(Input::keyCode::A)) {
				body.moveLeft();
				//body.addForce(Vector::left * 2);
			}
			if (Input::onPressed(Input::keyCode::D)) {
				body.moveRight();
				//body.addForce(Vector::right * 3);
			}
			if (Input::onPressed(Input::keyCode::W)) {
				body.rotate();
			}
		}
		if (Input::onPressed(Input::keyCode::Esc)) {
			GGame::end();
		}
		if (Input::onPressed(Input::keyCode::Space)) {
			GGame::instantiateObject<Pice>(5, Vector(Resolution::getApplicationResolution().x / 2, 7));
		}
	}

	void lateUpdate() override {
		body.updatePosition();
	}

	void onCollision(unsigned char tag) override {
		if ((tag == 3) && !dead) {
			dead = true;
			this->tag = 3;
			this->body.tag = 3;
			this->body.setTag(3);
			GGame::instantiateObject<Pice>(5, Vector(Resolution::getApplicationResolution().x / 2, 7));
		}
	}
};

class Wall : public GameObject {
public:
	Wall(unsigned char tag, Vector pos, Vector dim) : GameObject(tag) {
		body.load(dim);
		body.setTag(tag);
		body.setPosition(pos);
		body.updatePosition();
	};
};


void main23() {
	GGame game(60);

	Console::setCharacter(Vector(16, 16));
	Console::setFullScreen();

	piceName[0] = "thet";
	piceName[1] = "theline";
	piceName[2] = "thell";
	piceName[3] = "therl";
	piceName[4] = "thels";
	piceName[5] = "thers";

	Vector res = Resolution::getApplicationResolution();
	Wall wallLeft(2, Vector(res.x / 2- 7, 5), Vector(2, 20));
	Wall wallRight(2, Vector(res.x / 2 + 7, 5), Vector(2, 20));
	Wall wallDown(3, Vector(res.x / 2 - 7, 25), Vector(16, 2));
	
	Pice a(5, Vector(res.x / 2, 7));
	//Pice b(3, Vector(res.x / 2, 16));

	UI *ui = UI::instance();
	string text = "Score: ";
	ui->addUpdatedString(&text, Vector(res.x / 8, 5));
	ui->addUpdatedInt(&score, Vector(res.x / 8 + 8, 5));
	string fpsText = "FPS: ";
	ui->addUpdatedString(&fpsText, Vector(res.x / 8, 7));
	ui->addUpdatedInt(&GGame::actualFps, Vector(res.x / 8 + 8, 7));

	game.start();
}