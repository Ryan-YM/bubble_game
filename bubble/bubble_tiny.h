#ifndef bubble_tiny_h 
#define bubble_tiny_h

#include"acllib.h"

class bubble_tiny
{
protected:
	int x, y;
	int width, height;
	int dx, dy;
	ACL_Image *img;
	rect r;
public:
	bubble_tiny(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	bubble_tiny(bubble_tiny & base);
	virtual ~bubble_tiny();

	virtual void move(rect r)=0;
	void drawSprite(int width, int height);
	void drawSprite();
	rect getRect();
};

#endif