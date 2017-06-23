#pragma once
#include <string>
#include <Windows.h>
#include "Pixel.h"
#include <fstream>
using namespace std;

class Log {
private:
	ofstream file;

	Log();
	~Log();
	static Log *mInstance;
public:
	static Log* instance();
	void deleteInstance();

	void log(string);
};

