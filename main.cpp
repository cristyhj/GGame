#include "GGame.h"
#include "GameObject.h"
#include "Input.h"
#include "UI.h"
#include "Audio.h"

class Wall;
class Wall2;

class Hero : public GameObject {
public:
	bool poateSari;
	Audio sound;
	int score;

	Hero(unsigned char tag, Vector poss) : GameObject(tag) {
		poateSari = false;
		score = 0;
		body.useGravity();

		body.load("Sprites/herox");
		body.setPosition(poss);
		body.setTag(tag);
		body.updatePosition();
		sound.set("Sounds/boom.wav");
	};
	~Hero() {};

	void update() override {
		if (Input::isPressed(Input::keyCode::A)) {
			if (poateSari) {
				poateSari = false;
				body.moveLeft();
			} else {
				body.addForce(Vector::left * 3);
			}
		}
		if (Input::isPressed(Input::keyCode::S)) {
			if (poateSari) {
				poateSari = false;
				body.moveDown();
			} else {
				body.addForce(Vector::down * 3);
			}
		}
		if (Input::isPressed(Input::keyCode::D)) {
			if (poateSari) {
				poateSari = false;
				body.moveRight();
			} else {
				body.addForce(Vector::right * 3);
			}
		}
		if (Input::onPressed(Input::keyCode::W)) {
			if (poateSari) {
				poateSari = false;
				body.addForce(Vector::up * 25 * body.mass());
			}
		}
		if (Input::onPressed(Input::keyCode::Esc)) {
			GGame::end();
		}
	}

	void lateUpdate() override {
		body.updatePosition();
	}

	void onCollision(unsigned char tag) override {
		if (tag >= 1 && tag <= 10) {
			poateSari = true;
		}
		if (tag == 21) {
			sound.play();
			score++;
		}
	}
};

class Enemy : public GameObject {
private:
	int speed;
public:
	bool goingLeft;

	Enemy(unsigned char tag, Vector poss) : GameObject(tag) {
		goingLeft = true;
		speed = 0;
		body.useGravity();

		body.load("Sprites/monstru");
		body.setPosition(poss);
		body.setTag(tag);
		body.updatePosition();
	};
	~Enemy() {};

	void update() override {
		speed++;
		if (speed > 5) {
			speed = 0;
			if (goingLeft) {
				body.moveLeft();
			} else {
				body.moveRight();
			}
		}
	}

	void lateUpdate() override {
		body.updatePosition();
	}

	void onCollision(unsigned char tag) override {
		goingLeft = !goingLeft;
	}
};

class Platform : public GameObject {
public:

	Platform(unsigned char tag, Vector pos, string file) : GameObject(tag, pos) {
		body.setFriction(0);
		body.setMass(0);

		body.load("Sprites/" + file);
		body.setTag(tag);
		body.setPosition(pos);
		body.setLayer(LayerManager::instance()->getBase());
		body.updatePosition();
	};
	~Platform() {};
};
class Wall2 : public GameObject {
public:
	Wall2(unsigned char tag, Vector pos, Vector dim) : GameObject(tag) {
		body.setFriction(0);
		body.setMass(0);

		body.load(dim);
		body.setTag(tag);
		body.setPosition(pos);
		body.updatePosition();
	};
};

Vector *ptr;
void main() {
	GGame game(60);

	Console::setCharacter(Vector(8, 10));
	Console::setFullScreen();

	Resolution res = Resolution::getApplicationResolution();

	Hero hero(15, Vector(20, 20));
	Wall2 wall2(2, Vector(0, 5), Vector(2, res.y));
	Wall2 wall3(3, Vector(res.x - 4, 5), Vector(2, res.y));
	Wall2 wall4(4, Vector(2, res.y - 2), Vector(res.x - 4, 2));
	Wall2 wall5(5, Vector(0, 3), Vector(res.x - 2, 2)); 
	Platform p1(6, Vector(res.x / 2 + 10, 20), "platform");
	Platform p2(6, Vector(15, res.y - 30), "lwall");
	Platform p3(6, Vector(15, res.y - 15), "wall30");
	Platform p5(6, Vector(res.x / 2 - 10, res.y / 2 + 15), "wall31");
	Platform p6(6, Vector(res.x / 2 - 10, res.y / 2 - 15), "wall32");
	//Platform p4(6, Vector(30, res.y / 2 + 10), "wall33");
	Enemy mob(21, Vector(res.x - 20, res.y - 20));


	UI *ui = UI::instance();
	string score = "Score: ";
	ui->addUpdatedString(&score, Vector(3, 1));
	ui->addUpdatedInt(&hero.score, Vector(11, 1));

	game.start();
}
