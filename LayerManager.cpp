#include "LayerManager.h"

LayerManager* LayerManager::mInstance = nullptr;

LayerManager::LayerManager() {
}


LayerManager::~LayerManager() {
}

LayerManager * LayerManager::instance() {
	if (!mInstance) {
		mInstance = new LayerManager();
	}
	return mInstance;
}

void LayerManager::deleteInstance() {
	if (mInstance) {
		delete mInstance;
		mInstance = nullptr;
	}
}

Layer * LayerManager::getNext(Layer * layer) {
	if (layer == &base) {
		if (layers.size() == 0) {
			return &front;
		}
		return layers[0];
	}
	for (int i = 0; i < layers.size(); i++) {
		if (layer == layers[i]) {
			if (i == layers.size() - 1) {
				return &front;
			}
			return layers[i + 1];
		}
	}
	if (layer == &front) {
		return nullptr;
	}
}

Layer * LayerManager::getPrevious(Layer * layer) {
	if (layer == &front) {
		if (layers.size() == 0) {
			return &base;
		}
		return layers[layers.size() - 1];
	}
	for (int i = layers.size() - 1; i >= 0; i--) {
		if (layer == layers[i]) {
			if (i == 0) {
				return &base;
			}
			return layers[i - 1];
		}
	}
	if (layer == &base) {
		return nullptr;
	}
}

void LayerManager::updateGraphics() {
	base.update();
	for each (Layer* lay in layers) {
		lay->update();
	}
	front.update();
}
