#ifndef Sound_h
#define Sound_h

#include "acllib.h"

extern void sound(const char *soundPath, int opt);
extern void switchBGM(int id);

extern ACL_Sound BGM, curRegion;

const char BG_Music[3][40] =
{
	"res/sound/LightWorld.mid",
	"res/sound/Kakariko342.mid",
	"res/sound/LostWoods.mid"
};

#endif
