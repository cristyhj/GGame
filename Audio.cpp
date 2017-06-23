#include "Audio.h"
#include <Windows.h>
#include <mmsystem.h>
#include "Log.h"
#pragma comment(lib, "winmm.lib")

Audio::Audio() {
}

Audio::Audio(string path) {
	this->path = path;
}


Audio::~Audio() {
}

void Audio::set(string path) {
	this->path = path;
}

void Audio::play() {
	if (path.length() == 0) return;
	BOOL ret = PlaySoundA(path.data(), NULL, SND_FILENAME | SND_ASYNC);
	if (ret == FALSE) {
		Log::instance()->log("Fisierul " + path + " nu s-a deschis!");
	}
}
