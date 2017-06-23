#pragma once
#include "Layer.h"
#include <vector>

using namespace std;

class LayerManager {
private:
	Layer base;
	vector<Layer*> layers;
	Layer front;

	LayerManager();
	~LayerManager();
	static LayerManager *mInstance;
public:
	static LayerManager* instance();
	void deleteInstance();

	Layer* getNext(Layer *layer);
	Layer* getPrevious(Layer *layer);
	Layer* getBase() { return &base; }
	Layer* getFront() { return &front; }

	void updateGraphics();
};
