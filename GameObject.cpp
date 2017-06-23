#include "GameObject.h"

GameObject::GameObject(unsigned char tagg) {
	tag = tagg;
	body.tag = tagg;
	body.setLayer(LayerManager::instance()->getBase());
}

GameObject::GameObject(unsigned char tagg, Vector pos) {
	tag = tagg;
	body.tag = tagg;
	body.setPosition(pos);
	body.setLayer(LayerManager::instance()->getBase());
}


GameObject::~GameObject() {
}
