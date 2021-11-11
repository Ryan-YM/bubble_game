#include "bubble_tiny.h"

bubble_tiny::bubble_tiny(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->dx = dx;
	this->dy = dy;
	this->img = img;
	r = r1;
}
bubble_tiny::bubble_tiny(bubble_tiny & sprite)
{
	x = sprite.x;
	y = sprite.y;
	width = sprite.width;
	height = sprite.height;
	dx = sprite.dx;
	dy = sprite.dy;
	img = sprite.img;
	r = sprite.r;
}
bubble_tiny::~bubble_tiny()
{

}


void bubble_tiny::drawSprite(int width, int height)
{
	putImageScale(img, x, y, width, height);
}
void bubble_tiny::drawSprite()
{
	putImageScale(img, x, y, width, height);
}
rect bubble_tiny::getRect()
{
	rect r = { x, y, width, height };
	return r;
}
