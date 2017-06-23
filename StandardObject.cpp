#include "StandardObject.h"


vector<StandardObject*> StandardObject::instancesRegister;



StandardObject::StandardObject() {
	instancesRegister.push_back(this);
	tag = 0;
}


StandardObject::~StandardObject() {
	for (int i = 0; i < instancesRegister.size(); i++) {
		if (this == instancesRegister[i]) {
			instancesRegister.erase(instancesRegister.begin() + i);
		}
	}
}

void GGame::callInitialize() {
	for (int i = 0; i < StandardObject::instancesRegister.size(); i++) {
		StandardObject::instancesRegister[i]->start();
	}
}

void GGame::callGraphicsUpdate() {
	LayerManager::instance()->updateGraphics();
}

void GGame::callOnCollision(unsigned char callerTag, unsigned char tag) {
	int size = StandardObject::instancesRegister.size();
	for (int i = 0; i < size; i++) {
		if (StandardObject::instancesRegister[i]->tag == callerTag) {
			StandardObject::instancesRegister[i]->onCollision(tag);
		}
	}
}

void GGame::setFPS(int fps) {
	if (!mInstance) return;
	mInstance->fps = fps;
}

void GGame::callRoutines() {
	for (int i = 0; i < StandardObject::instancesRegister.size(); i++) {
		StandardObject::instancesRegister[i]->preUpdate();
	}
	for (int i = 0; i < StandardObject::instancesRegister.size(); i++) {
		StandardObject::instancesRegister[i]->update();
	}
	for (int i = 0; i < StandardObject::instancesRegister.size(); i++) {
		StandardObject::instancesRegister[i]->lateUpdate();
	}
}