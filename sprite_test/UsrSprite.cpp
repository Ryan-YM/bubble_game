#include "UsrSprite.h"

CUsrSprite::CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
	:SpriteBase(x,y,width,height,dx,dy,img,r1)
{

}
CUsrSprite::CUsrSprite(CUsrSprite &sprite):SpriteBase(sprite)	//拷贝构造函数
{

}
CUsrSprite::~CUsrSprite(){}

/*
void CUsrSprite::move(int xx, int yy)
{
	x = xx;
	y = yy;
	if (x < r.x)x = r.x;
	if (x >(r.x + r.width - width))x = (r.x + r.width - width);
	if (y < r.y)y = r.y;
	if (y >(r.y + r.height - height))y = (r.y + r.height - height);

}
*/

void CUsrSprite::move(rect r1) //限定移动范围
{
	if (x < r1.x)x = r1.x;
	if (x >(r1.x + r1.width - width))x = (r1.x + r1.width - width);
	if (y < r1.y)y = r1.y;
	if (y >(r1.y + r1.height - height))y = (r1.y + r1.height - height);
}
// {
// 	x = r1.x;
// 	y = r1.y;
// 	if (x < r.x)x = r.x;
// 	if (x >(r.x + r.width - width))x = (r.x + r.width - width);
// 	if (y < r.y)y = r.y;
// 	if (y >(r.y + r.height - height))y = (r.y + r.height - height);

// }

void CUsrSprite::move(int key)
{
	switch (key)
	{
	case VK_UP:
		y -= dx;
		if (y < 0) y = 0;
		break;
	case VK_DOWN:
		y += dy;
		if (y >(r.height - height)) y = (r.height - height);

		break;
	case VK_LEFT:
		x -= dx;
		if (x < r.x)x = r.x;
		break;
	case VK_RIGHT:
		x += dx;
		if (x >(r.width - width)) x = (r.width - width);

		break;
	}
}

int CUsrSprite::collision(rect r2)		// 碰撞检测
{
	rect r1 = { x,y, width, height };
	int c = 0;
	if (r1.x < r2.x && r1.x + r1.width >r2.x){
		if ((r1.y > r2.y && r1.y<r2.y + r2.height) || (r1.y <r2.y && r1.y + r1.height >r2.y)){
			c = 1;
		}
	}
	else {
		if (r1.x > r2.x && r2.x + r2.width > r1.x){
			if ((r1.y > r2.y && r1.y<r2.y + r2.height) || (r1.y <r2.y && r1.y + r1.height >r2.y)){
				c = 1;
			}
		}
	}
	return c;
}

// TODO 使其呈现阶段变化
void CUsrSprite::grow()
{
	if (score == 10){
		width += 5;
		height += 5;
	}
	if (score == 20){
		width += 5;
		height += 5;
	}
}

int CUsrSprite::getScore()
{
	return score;
}
void CUsrSprite::setScore(int s)
{
	score = s;
}
void CUsrSprite::addScore(int m)
{
	score += m;
}
