/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//    problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//    // position the sprite on the center of the screen
	//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//    // add the sprite as a child to this layer
	//    this->addChild(sprite, 0);
	//}


	alpha = 255.0f;
	redAlpha = 0.0f;
	blueAlpha = 255.0f;
	slimeAlpha = 255.0f;

	Vec2 spritePos = Vec2(1100.0f, 550.0f);
	//Vec2 spritePos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	animeCount = 0;
	catAnimeCount = 0;
	catRect = Rect(0, 0, 32, 32);

	state = 0;
	velocity = Vec2(-3.0f, 0.0f);


	//�����̏�����(C# : Random rnd = new Random() )
	//srand(time(nullptr));

	//�e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬
	//Sprite* sprite = Sprite::create("fire01.png");
	//sprite = Sprite::create("sample06.png");

	//�摜(sprite)��ǉ�
	//slimeSprite = Sprite::create("slime01.png");
	//catSprite = Sprite::create("sample06.png");
	Sprite* sprite = Sprite::create("sample06.png");

	//�z���for���Œǉ�
	//for (int i = 0; i < 50; i++)
	//{
	//	sprite[i] = Sprite::create("fire01.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(spritePos);
	//	sprite[i]->setScale(0.3f, 0.3f);

	//	float mx, my;

	//	mx = (float)rand() / RAND_MAX * 1400 - 700;
	//	my = (float)rand() / RAND_MAX * 1000 - 500;

	//	//MoveBy* action01 = MoveBy::create(2.0f, Vec2((i-2) * 250, 200));
	//	MoveBy* action01 = MoveBy::create(2.0f, Vec2(mx, my));
	//	sprite[i]->runAction(action01);
	//}

	//�V�[���O���t�ɂȂ�
	this->addChild(sprite);
	//this->addChild(slimeSprite);
	//this->addChild(catSprite);


	//�\�����W�w��
	sprite->setPosition(spritePos); //visibleSize.width�ŉ����AvisibleSize.hight�ŏc��
	//slimeSprite->setPosition(spritePos - Vec2(0, 60.0f));
	//catSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//��]�p���w��
	//sprite->setRotation(45.0f);
	//�g�k���w��
	//sprite->setScale(0.4f, 0.4f);
	//catSprite->setScale(8.0f);
	sprite->setScale(8.0f);
	//���E���]
	//sprite->setFlippedX(true);
	//�㉺���]
	//sprite->setFlippedY(true);
	//��\���ɂ���
	//sprite->setVisible(false);
	//slimeSprite->setVisible(false);
	//catSprite->setVisible(false);
	//�F������ݒ�
	//sprite->setColor(Color3B(128, 255, 255));
	//�s�����x��ݒ�
	//sprite->setOpacity(0x00);
	//slimeSprite->setOpacity(slimeAlpha);
	//�摜�؂���
	//catSprite->setTextureRect(catRect);
	sprite->setTextureRect(catRect);

	//�A���`�G�C���A�X���J�b�g
	//catSprite->getTexture()->setAliasTexParameters();
	sprite->getTexture()->setAliasTexParameters();

	//update���Ăяo�����悤�ɂ���
	//this->scheduleUpdate();

	//�A���J�[�|�C���g��ݒ�(0�`1)
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	//sprite->setRotation(45.0f);


	//�A�N�V�����̍쐬
	//MoveBy* action01 = MoveBy::create(2.0f, Vec2(500, 100));
	//MoveBy* action01b = MoveBy::create(2.0f, Vec2(500, 100));
	//EaseIn* action01_01 = EaseIn::create(action01, 5.0f);
	//EaseBounceOut* action01_02 = EaseBounceOut::create(action01);
	//EaseBackIn* action01_03 = EaseBackIn::create(action01);
	//ScaleBy* action02 = ScaleBy::create(2.0f, 10.0f);
	//JumpTo* action03 = JumpTo::create(1.5f, Vec2(200, 100), 500.0f, 2);
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(500, 500);
	//conf.controlPoint_2 = Vec2(114, 514);
	//conf.endPosition = Vec2(100, 200);
	//BezierTo* action04 = BezierTo::create(3.0f, conf);
	//Blink* action05 = Blink::create(2.0f, 10.0f);
	//SkewTo* action06 = SkewTo::create(2.0f, 10.0f, 10.0f);
	//sprite->setOpacity(0);
	//FadeIn* action07 = FadeIn::create(2.0f);

	//�m�[�h�ɑ΂��ăA�N�V���������s
	//sprite->runAction(action01);
	//slimeSprite->runAction(action01b);
	//slimeSprite->runAction(action01->clone());
	//slimeSprite->runAction(action02);
	//sprite->runAction(action01_01);
	//sprite->runAction(action01_02);
	//sprite->runAction(action01_03);
	//sprite->runAction(action02);
	//sprite->runAction(action03);
	//sprite->runAction(action04);
	//sprite->runAction(action05);
	//sprite->runAction(action06);
	//sprite->runAction(action07);


	//5_����Ă݂悤(1)
	//for (int i = 0; i < 2; i++)
	//{
	//	sprite[i] = Sprite::create("fire01.png");
	//	this->addChild(sprite[i]);

	//	float mx, my;

	//	mx = (float)rand() / RAND_MAX * 1000 ;
	//	my = (float)rand() / RAND_MAX * 1000 - 500;

	//	Vec2 pos = Vec2(mx, 200);

	//	sprite[i]->setPosition(pos);
	//	sprite[i]->setScale(0.5f, 0.5f);

	//	JumpBy* action01 = JumpBy::create(2.0f, Vec2(0.0f, 0.0f), 400.0f, 1);
	//	sprite[i]->runAction(action01);
	//}

	//5_����Ă݂悤(2)
	//for (int i = 0; i < 10; i++)
	//{
	//	sprite[i] = Sprite::create("fire01.png");
	//	this->addChild(sprite[i]);

	//	float mx, my;

	//	mx = (float)rand() / RAND_MAX * 1000;
	//	my = (float)rand() / RAND_MAX * 1000 - 500;

	//	Vec2 pos = Vec2(mx, 200);

	//	sprite[i]->setPosition(pos);
	//	sprite[i]->setScale(0.3f, 0.3f);

	//	JumpBy* action01 = JumpBy::create(2.0f, Vec2(100.0f, 0.0f), 400.0f, 1);
	//	sprite[i]->runAction(action01);
	//}


	//5_����Ă݂悤(3)
	//for (int i = 0; i < 10; i++)
	//{
	//	sprite[i] = Sprite::create("fire01.png");
	//	this->addChild(sprite[i]);

	//	float mx, my, veloX, veloY;

	//	mx = (float)rand() / RAND_MAX * 1000 + 100;
	//	my = (float)rand() / RAND_MAX * 500 + 100;
	//	veloX = (float)rand() / RAND_MAX * 1000 - 500;
	//	veloY = (float)rand() / RAND_MAX * 1000 - 500;

	//	Vec2 pos = Vec2(mx, my);

	//	sprite[i]->setPosition(pos);
	//	sprite[i]->setScale(0.3f, 0.3f);

	//	MoveBy* action01 = MoveBy::create(2.0f, Vec2(veloX, veloY));
	//	sprite[i]->runAction(action01);
	//}


	//5_����Ă݂悤(4)
	//sprite[0] = Sprite::create("fire01.png");
	//this->addChild(sprite[0]);
	//sprite[0]->setPosition(Vec2(1100.0f, 550.0f));
	//sprite[0]->setScale(0.3f, 0.3f);
	////MoveBy* action01 = MoveBy::create(5.0f, Vec2(-1000.0f, 0));
	//sprite[0]->setOpacity(255);
	//FadeOut* action01 = FadeOut::create(5.0f);
	//sprite[0]->runAction(action01);


	//6.�A�N�V�����̘A�g
	//MoveTo* action01 = MoveTo::create(2.0f, Vec2(400.0f, 100.0f));
	//JumpTo* action02 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//sprite->runAction(sequence01);


	//MoveTo�̂��Ƃ�TintTo��JumpTo�𓯎�����
	//MoveTo* action01 = MoveTo::create(2.0f, Vec2(400.0f, 100.0f));
	//JumpTo* action02 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//TintTo* action03 = TintTo::create(2.0f, Color3B(0, 255, 0));
	//Spawn* spawn01 = Spawn::create(action02, action03, nullptr);
	//Sequence* sequence01 = Sequence::create(action01, spawn01, nullptr);
	//sprite->runAction(sequence01);

	//JumpBy* action01 = JumpBy::create(0.5f, Vec2(400.0f, 100.0f), 100.0f, 1);
	//MoveBy* action02 = MoveBy::create(0.5f, Vec2(-400.0f, -100.0f));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//Repeat* repeat01 = Repeat::create(action01, 3);
	//Repeat* repeat01 = Repeat::create(sequence01, 3);
	//RepeatForever* repeat01 = RepeatForever::create(sequence01);
	//sprite->runAction(repeat01);


	//JumpBy* action01 = JumpBy::create(0.5f, Vec2(400.0f, 100.0f), 100.0f, 1);
	//DelayTime* delayTime01 = DelayTime::create(1.0f);
	//MoveBy* action02 = MoveBy::create(0.5f, Vec2(-400.0f, -100.0f));
	//Sequence* sequence01 = Sequence::create(action01, delayTime01, action02, nullptr);
	//sprite->runAction(sequence01);

	//JumpBy* action01 = JumpBy::create(0.5f, Vec2(400.0f, 100.0f), 100.0f, 1);
	//ToggleVisibility* delayTime01 = ToggleVisibility::create();
	//MoveBy* action02 = MoveBy::create(0.5f, Vec2(-400.0f, -100.0f));
	//���g���폜����A�N�V�����B(�K���Ō�ɂ��)
	//RemoveSelf* removeSelf01 = RemoveSelf::create();
	//Sequence* sequence01 = Sequence::create(action01, delayTime01, action02, nullptr);
	//Sequence* sequence01 = Sequence::create(action01, action02, removeSelf01, nullptr);
	//Repeat* repeat01 = Repeat::create(sequence01, 6);
	//sprite->runAction(sequence01);
	//sprite->runAction(repeat01);

	//6.����Ă݂悤(1)
	//MoveBy* action01 = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(5.0f, Vec2(900.0f, 0));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//sprite->runAction(repeatForever01);


	//6.����Ă݂悤(2)
	//MoveBy* action01 = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(5.0f, Vec2(900.0f, 0));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//sprite->setOpacity(0);
	//FadeTo* action03 = FadeTo::create(5.0f, 255);
	//FadeTo* action04 = FadeTo::create(5.0f, 0);
	//Sequence* sequence02 = Sequence::create(action03, action04, nullptr);
	//Spawn* spawn01 = Spawn::create(sequence01, sequence02, nullptr);
	//sprite->runAction(spawn01);


	//6.����Ă݂悤(3)
	//MoveBy* action01 = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(5.0f, Vec2(900.0f, 0));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//sprite->setOpacity(0);
	//FadeTo* action03 = FadeTo::create(5.0f, 255);
	//FadeTo* action04 = FadeTo::create(5.0f, 0);
	//Sequence* sequence02 = Sequence::create(action03, action04, nullptr);
	//Spawn* spawn01 = Spawn::create(sequence01, sequence02, nullptr);
	//Repeat* repear01 = Repeat::create(spawn01, 5);
	//sprite->runAction(repear01);


	//6.����Ă݂悤(4)
	//MoveBy* action01 = MoveBy::create(2.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(2.0f, Vec2(0.0f, -400.0f));
	//MoveBy* action03 = MoveBy::create(2.0f, Vec2(900.0f, 0.0f));
	//MoveBy* action04 = MoveBy::create(2.0f, Vec2(0.0f, 400.0f));
	//Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	//sprite->runAction(sequence01);


	//6.����Ă݂悤(5)
	//MoveBy* action01 = MoveBy::create(1.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(0.5f, Vec2(0.0f, -400.0f));
	//MoveBy* action03 = MoveBy::create(1.0f, Vec2(900.0f, 0.0f));
	//MoveBy* action04 = MoveBy::create(0.5f, Vec2(0.0f, 400.0f));
	//Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//sprite->runAction(repeatForever01);

    //���܂�
	MoveBy* action01 = MoveBy::create(2.0f, Vec2(-900.0f, 0.0f));
	MoveBy* action02 = MoveBy::create(1.0f, Vec2(0.0f, -400.0f));
	MoveBy* action03 = MoveBy::create(2.0f, Vec2(900.0f, 0.0f));
	MoveBy* action04 = MoveBy::create(1.0f, Vec2(0.0f, 400.0f));
	ScaleTo* action05 = ScaleTo::create(1.0f, 8.0f);
	ScaleTo* action06 = ScaleTo::create(1.0f, 3.0f);
	RotateBy* action07 = RotateBy::create(1.0f, 360.0f * 1.0f);
	RotateBy* action08 = RotateBy::create(1.0f, -180.0f * 1.0f);
	Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	Sequence* sequence02 = Sequence::create(action05, action06, nullptr);
	Sequence* sequence03 = Sequence::create(action07, action08, nullptr);
	Spawn* spawn01 = Spawn::create(sequence02, sequence03, nullptr);
	//Repeat* repeat01 = Repeat::create(spawn01, 1000);
	RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	RepeatForever* repeatForever02 = RepeatForever::create(spawn01);
	//sprite->runAction(repeat01);
	sprite->runAction(repeatForever01);
	sprite->runAction(repeatForever02);


	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//�����ɍX�V����������

	//��ʂ����
	//Vec2 pos;
	//pos = sprite->getPosition();
	//switch(state)
	//{
	////���ړ�
	//case 0:
	//	pos += Vec2(-5.0f, 0.0f);
	//	if (pos.x <= 100)
	//	{
	//		state = 1;
	//	}
	//	break;

	//case 1:
	//	pos += Vec2(0.0f, -5.0f);
	//	if (pos.y <= 100)
	//	{
	//		state = 2;
	//	}
	//	break;
	//case 2:
	//	pos += Vec2(5.0f, 0.0f);
	//	if (pos.x >= 1100)
	//	{
	//		state = 3;
	//	}
	//	break;
	//default:
	//	pos += Vec2(0.0f, 5.0f);
	//	if (pos.y >= 550)
	//	{
	//		state = 0;
	//	}
	//	break;
	//}
	//sprite->setPosition(pos);

	//�X�v���C�g�̌��ݍ��W���擾
	//Vec2 pos = sprite->getPosition();
	////���W���ړ�������
	//pos += Vec2(-3.0f, 0.0f);
	////�ړ���̍��W�𔽉f
	//sprite->setPosition(pos);

	//���񂾂񓧖���
	//alpha -= 255.0f / 300.0f;
	//sprite->setOpacity(alpha);
	/*if (alpha < 0)
	{
		alpha = 0;
	}*/



	/*if (sprite->getPositionX() >= 1100 && sprite->getPositionY() < 550)
	{
		pos += Vec2(0.0f, 3.0f);
	}

	else if (sprite->getPositionY() < 130)
	{
		pos += Vec2(3.0f, 0.0f);
	}

	else if (sprite->getPositionX() < 100)
	{
		pos += Vec2(0, -3.0f);
	}

	else if (sprite->getPositionY() >= 550)
	{
		pos += Vec2(-3.0f, 0.0f);
	}

	sprite->setPosition(pos);*/


	//�Ԃ���ɐ���Ԃ�
	//redAlpha += 255.0f / 180.0f;
	//blueAlpha -= 255.0f / 180.0f;
	//sprite->setColor(Color3B(redAlpha, 0, blueAlpha));


	//�L�����̃t�F�[�h�C���t�F�[�h�A�E�g
	/*alpha -= 1.0f;
	if (alpha < 128)
	{
		slimeAlpha += 1.0f;

		if (alpha < 0)
		{
			alpha = 0;
		}
	}
	if (slimeAlpha > 255)
	{
		slimeAlpha = 255;
	}
	sprite->setOpacity(alpha);
	slimeSprite->setOpacity(slimeAlpha);*/


	//�L��������ʒ[�ō��E���]���Ĉړ�
	/*Vec2 pos = slimeSprite->getPosition();
	if (state == 0)
	{
		slimeSprite->setFlippedX(false);
	}
	else
	{
		slimeSprite->setFlippedX(true);
	}
	if (pos.x < 0)
	{
		state = 2;
		velocity *= -1.0f;
	}
	if (pos.x > 1280)
	{
		state = 0;
		velocity *= -1.0f;
	}
	pos += velocity;
	slimeSprite->setPosition(pos);*/

	//�A�j���[�V����
	//if (animeCount > 10 * 3-1)
	//{
	//	animeCount = 10 * 2;
	//	state = 1;
	//}

	//else if (animeCount < 0)
	//{
	//	animeCount = 10;
	//	state = 0;
	//}
	//if (state == 0)
	//{
	//	animeCount += 1;
	//}
	//else
	//{
	//	animeCount -= 1;
	//}
 //   
	//catAnimeCount = animeCount / 10;

	//if (catAnimeCount > 2)
	//{
	//	catAnimeCount = 0;
	//}
	//catRect = Rect(catAnimeCount % 3 * 32, 0 * 32, 32, 32);
	//catSprite->setTextureRect(catRect);

}
