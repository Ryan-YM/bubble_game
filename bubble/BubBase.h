#ifndef BubBase_h
#define BubBase_h

#include"acllib.h"

class BubBase
{
protected:
	int x, y;
	int width, height;
	int dx, dy;
	ACL_Image *img;
	rect r;
public:
	BubBase(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	BubBase(BubBase & base);
	virtual ~BubBase();

	virtual void move(rect r)=0;
	void drawSprite(int width, int height);
	void drawSprite();
	rect getRect();
};

#endif
