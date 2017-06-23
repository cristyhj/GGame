#pragma once
#include <string>
using namespace std;

class Audio {
private:
	string path;
public:
	Audio();
	Audio(string);
	~Audio();

	void set(string);
	void play();
};

