#include "Log.h"

class Console;
Log* Log::mInstance = nullptr;

Log::Log() {
	file.open("log.txt");
}


Log::~Log() {
	file.close();
}

Log * Log::instance() {
	if (!mInstance) {
		mInstance = new Log();
	}
	return mInstance;
}

void Log::deleteInstance() {
	if (mInstance) {
		delete mInstance;
		mInstance = nullptr;
	}
}

void Log::log(string str) {
	file << str << endl;
}


