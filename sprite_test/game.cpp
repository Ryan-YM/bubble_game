#include"acllib.h"
#include"AutoSprite.h"
#include"UsrSprite.h"
#include"AvoidSprite.h"
#include<time.h>
#include<stdio.h>

const int maxNum = 50;
const int winWidth = 800, winHeight = 600;
CAutoSprite *autosprite[maxNum] = { 0 };
CUsrSprite *usr = NULL;
int autoWidth = 100, autoHeight = 100;	// auto sprite size
int usrWidth = 100, usrHeight = 100;
ACL_Image img,imgUsr,imgHeart;
rect winRect;
void timerEvent(int id);
void createData(CAutoSprite **autoSprite);
void createData(CUsrSprite **usr);
void keyEvent(int key, int event);
void paint();
int nowNum = 0;

int Setup()
{
	winRect.x = DEFAULT;
	winRect.y = DEFAULT;
	winRect.width = winWidth;
	winRect.height = winHeight;
	initWindow("BUBBLE GAME", DEFAULT, DEFAULT, winWidth, winHeight);	//初始化窗口 BUBBLE GAME
	srand((unsigned)time(NULL));	//初始化随机数
	// TODO socre 分数如何在画面渲染的

	loadImage("diamonds_Small.jpeg", &img);
	loadImage("abstract-016_Small.jpeg", &imgUsr);
	loadImage("duck.jpg", &imgHeart);
	//autosprite[nowNum++] = new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect);
	createData(autosprite);
	createData(&usr);
	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);
	startTimer(0, 40);
	startTimer(1, 1000);
	return 0;
}

void timerEvent(int id)
{
	int i = 0;
	switch (id)
	{
	case 0:
		for (i = 0; i < nowNum; ++i)
			if (autosprite[i])
			{
				rect ur = usr->getRect();
				autosprite[i]->move(ur);
				
			}

		break;
	case 1:
		if (nowNum < maxNum)
		{
			createData(autosprite);
		}
		break;
	}//end switch
	paint();
}

void createData(CAutoSprite **autoSprite)
{
	int x = rand() % winWidth - autoWidth;	//随机生成x坐标
	if (x < 0)x = 0;	//	x坐标不能小于0
	int y = rand() % winHeight - autoHeight; //	随机生成y坐标
	if (y < 0)y = 0;	//	y坐标不能小于0
	int dx = rand() % 5 + 1; //	随机生成x方向的速度
	int dy = rand() % 5 + 1; //	随机生成y方向的速度
	int t = rand() % 100;	//	随机生成类型
	if(t<80)	// 80% 生成1分&img，20% 生成5分&imgHeart
		autosprite[nowNum++] = new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect,1);
	else 
		autosprite[nowNum++] = new CAvoidSprite(x, y, autoWidth, autoHeight, dx, dy, &imgHeart, winRect,5);
		// TODO 如何理解 imgheart 五分的判定过程
}

// 生成用户精灵
void createData(CUsrSprite **usr)
{
	int x = rand() % winWidth - autoWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - autoHeight;
	if (y < 0)y = 0;
	int dx = 5;
	int dy = 5;

	*usr = new CUsrSprite(x, y, usrWidth, usrHeight, dx, dy, &imgUsr, winRect);

}


void paint()
{
	beginPaint();
	clearDevice();
	int i = 0;
	for (i = 0; i < nowNum; ++i)
	{
		if (autosprite[i])
		{
			autosprite[i]->drawSprite();
		}
	}
	if (usr)
	{
		usr->drawSprite();

		char txt[10];
		sprintf_s(txt, "score:%d", usr->getScore());
		setTextSize(20);
		paintText(10, 10, txt);
	}
	endPaint();
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)return;
	if(usr)usr->move(key);
	for (int i = 0; i < nowNum; ++i)
	{
		if (autosprite[i])
		{
			if (usr->collision(autosprite[i]->getRect()))
			{
				int s = autosprite[i]->getScore();
				if (usr)usr->addScore(s);
				delete(autosprite[i]);
				autosprite[i] = NULL;
			}
		}
	}
	paint();
}