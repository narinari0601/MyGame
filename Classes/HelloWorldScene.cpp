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
#include "AudioEngine.h"

using namespace std;

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

	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	//if (label == nullptr)
	//{
	//	problemLoading("'fonts/Marker Felt.ttf'");
	//}
	//else
	//{
	//	// position the label on the center of the screen
	//	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
	//		origin.y + visibleSize.height - label->getContentSize().height));

	//	// add the label as a child to this layer
	//	this->addChild(label, 1);
	//}

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


	//alpha = 255.0f;
	//redAlpha = 0.0f;
	//blueAlpha = 255.0f;
	//slimeAlpha = 255.0f;

	//Vec2 spritePos = Vec2(1100.0f, 550.0f);
	//Vec2 spritePos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	//animeCount = 0;
	//catAnimeCount = 0;
	//catRect = Rect(0, 0, 32, 32);

	//state = 0;
	//velocity = Vec2(-3.0f, 0.0f);


	//乱数の初期化(C# : Random rnd = new Random() )
	//srand(time(nullptr));

	//テクスチャファイル名を指定して、スプライトを作成
	//Sprite* sprite = Sprite::create("fire01.png");
	//sprite = Sprite::create("sample06.png");

	//画像(sprite)を追加
	//slimeSprite = Sprite::create("slime01.png");
	//catSprite = Sprite::create("sample06.png");
	//Sprite* sprite = Sprite::create("sample06.png");
	marioDef = Sprite::create("mario00.png");
	marioJump = Sprite::create("marioJump01.png");
	kuppaDef = Sprite::create("kuppa00.png");
	kuriboDef = Sprite::create("kuribo00.png");
	fieldDef = Sprite::create("field00.png");
	floor_mineDef = Sprite::create("floor_mine00.png");
	floor_yoursDef = Sprite::create("floor_yours00.png");
	messageWindowDef = Sprite::create("messageWindow00.png");
	selectArrow = Sprite::create("arrow01.png");
	commandSelect01 = Sprite::create("commandSelect01.png");
	commandSelect02 = Sprite::create("commandSelect02.png");
	textBattleStart01 = Sprite::create("text_battleStart.png");
	textKuriboSummon01 = Sprite::create("text_kuribo01.png");
	textKuriboEnd01 = Sprite::create("text_kuribo02.png");
	textMarioAttack01 = Sprite::create("text_attack01.png");
	textBattleEnd01 = Sprite::create("text_battleEnd.png");
	textKuppaEnd01 = Sprite::create("text_endTalk.png");
	ui_Mine = Sprite::create("UI_mine00.png");
	ui_Yours = Sprite::create("UI_yoursDef.png");

	//配列にfor文で追加
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

	//アンカーポイントを左下に設定
	marioDef->setAnchorPoint(Vec2::ZERO);
	marioJump->setAnchorPoint(Vec2::ZERO);
	kuppaDef->setAnchorPoint(Vec2::ZERO);
	kuriboDef->setAnchorPoint(Vec2::ZERO);
	fieldDef->setAnchorPoint(Vec2::ZERO);
	messageWindowDef->setAnchorPoint(Vec2::ZERO);
	selectArrow->setAnchorPoint(Vec2::ZERO);
	floor_mineDef->setAnchorPoint(Vec2::ZERO);
	floor_yoursDef->setAnchorPoint(Vec2::ZERO);
	commandSelect01->setAnchorPoint(Vec2::ZERO);
	commandSelect02->setAnchorPoint(Vec2::ZERO);
	textBattleStart01->setAnchorPoint(Vec2::ZERO);
	textKuriboSummon01->setAnchorPoint(Vec2::ZERO);
	textKuriboEnd01->setAnchorPoint(Vec2::ZERO);
	textMarioAttack01->setAnchorPoint(Vec2::ZERO);
	textBattleEnd01->setAnchorPoint(Vec2::ZERO);
	textKuppaEnd01->setAnchorPoint(Vec2::ZERO);
	ui_Mine->setAnchorPoint(Vec2::ZERO);
	ui_Yours->setAnchorPoint(Vec2::ZERO);



	//シーングラフにつなぐ
	this->addChild(fieldDef);
	this->addChild(floor_mineDef);
	this->addChild(floor_yoursDef);
	this->addChild(ui_Yours);
	this->addChild(kuriboDef);
	this->addChild(kuppaDef);
	this->addChild(marioDef);
	this->addChild(marioJump);
	this->addChild(ui_Mine);
	this->addChild(messageWindowDef);
	this->addChild(textBattleStart01);
	this->addChild(textKuriboSummon01);
	this->addChild(textKuriboEnd01);
	this->addChild(textMarioAttack01);
	this->addChild(textBattleEnd01);
	this->addChild(textKuppaEnd01);
	this->addChild(commandSelect01);
	this->addChild(commandSelect02);
	this->addChild(selectArrow);
	

	//最初に非表示にする画像を非表示に
	ui_Yours->setVisible(false);
	//kuriboDef->setVisible(false);
	marioJump->setVisible(false);
	ui_Mine->setVisible(false);
	textBattleStart01->setVisible(false);
	textKuriboSummon01->setVisible(false);
	textKuriboEnd01->setVisible(false);
	textMarioAttack01->setVisible(false);
	textBattleEnd01->setVisible(false);
	textKuppaEnd01->setVisible(false);
	commandSelect01->setVisible(false);
	commandSelect02->setVisible(false);
	selectArrow->setVisible(false);

	experimental::AudioEngine::play2d("game_maoudamashii_2_boss07.mp3");
	//experimental::AudioEngine::play2d("jump06.mp3");


	//座標初期設定
	//sprite->setPosition(spritePos); //visibleSize.widthで横幅、visibleSize.hightで縦幅
	//slimeSprite->setPosition(spritePos - Vec2(0, 60.0f));
	//catSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	marioDef->setPosition(Vec2(1280, 0));
	kuppaDef->setPosition(Vec2(-1280, 0));
	fieldDef->setPosition(Vec2::ZERO);
	floor_mineDef->setPosition(Vec2(1280, 0));
	floor_yoursDef->setPosition(Vec2(-1280, 0));
	messageWindowDef->setPosition(Vec2::ZERO);
	kuriboDef->setPosition(Vec2(640, 0));

	//回転角を指定
	//sprite->setRotation(45.0f);
	//拡縮を指定
	//sprite->setScale(0.4f, 0.4f);
	//catSprite->setScale(8.0f);
	//sprite->setScale(8.0f);
	//左右反転
	//sprite->setFlippedX(true);
	//上下反転
	//sprite->setFlippedY(true);
	//非表示にする
	//sprite->setVisible(false);
	//slimeSprite->setVisible(false);
	//catSprite->setVisible(false);
	//色合いを設定
	//sprite->setColor(Color3B(128, 255, 255));
	//不透明度を設定
	//sprite->setOpacity(0x00);
	//slimeSprite->setOpacity(slimeAlpha);
	//画像切り取り
	//catSprite->setTextureRect(catRect);
	//sprite->setTextureRect(catRect);

	//アンチエイリアスをカット
	//catSprite->getTexture()->setAliasTexParameters();
	//sprite->getTexture()->setAliasTexParameters();

	//updateが呼び出されるようにする
	//this->scheduleUpdate();

	//アンカーポイントを設定(0～1)
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	//sprite->setRotation(45.0f);
	



	//アクションの作成
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
	
	
	
	

	//CallFunc* kuppaDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, kuppaDef));
	//CallFunc* kuriboActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, kuriboDef));

	
	//Spawn* spawn01 = Spawn::create(kuppaMove02, kuriboAction, nullptr);

	//Sequence* kuppaSeq01 = Sequence::create(kuppaMove01, spawn01, nullptr);

	//マリオ達が現れるアクション
	MoveTo* marioMove01 = MoveTo::create(3.0f, Vec2::ZERO);
	MoveTo* kuppaMove01 = MoveTo::create(3.0f, Vec2::ZERO);
	MoveTo* floor_mineMove01 = MoveTo::create(3.0f, Vec2::ZERO);
	MoveTo* floor_yoursMove01 = MoveTo::create(3.0f, Vec2::ZERO);
	Spawn* startMove = Spawn::create(
		TargetedAction::create(marioDef, marioMove01),
		TargetedAction::create(kuppaDef, kuppaMove01),
		TargetedAction::create(floor_mineDef, floor_mineMove01),
		TargetedAction::create(floor_yoursDef, floor_yoursMove01),
		nullptr);


	//クッパが勝負をしかけてきたテキスト表示アクション
	CallFunc* textBattleStartActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textBattleStart01));
	DelayTime* startTextDelay = DelayTime::create(3.0f);
	Sequence* startTextSeq = Sequence::create(textBattleStartActive, startTextDelay, nullptr);

	//クッパがクリボーを繰り出すアクション
	CallFunc* textBattleStartDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textBattleStart01));
	CallFunc* textKuriboSummmonActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textKuriboSummon01));
	MoveTo* kuppaMove02 = MoveTo::create(1.0f, Vec2(1280, 0));
	MoveTo* kuriboMove01 = MoveTo::create(1.0f, Vec2::ZERO);
	DelayTime* kuriboSummonDelay = DelayTime::create(2.0f);

	Spawn* kuriboSummonSpa = Spawn::create(
		TargetedAction::create(this, textBattleStartDisActive),
		TargetedAction::create(this, textKuriboSummmonActive),
		TargetedAction::create(kuppaDef, kuppaMove02),
		TargetedAction::create(kuriboDef, kuriboMove01),
		nullptr);
	Sequence* kuriboSummon = Sequence::create(kuriboSummonSpa, kuriboSummonDelay, nullptr);

	//マリオはどうする？アクション
	CallFunc* textKuriboSummmonDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textKuriboSummon01));
	CallFunc* commandSelect01Active = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, commandSelect01));
	CallFunc* selectArrowActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, selectArrow));
	MoveBy* arrowMove01 = MoveBy::create(0.0f, Vec2(0, -70));
	MoveBy* arrowMove02 = MoveBy::create(0.0f, Vec2(226, 0));
	MoveBy* arrowMove03 = MoveBy::create(0.0f, Vec2(0, 70));
	MoveTo* arrowMove04 = MoveTo::create(0.0f, Vec2::ZERO);
	DelayTime* arrowActionDelay = DelayTime::create(1.5f);
	Sequence* arrowAction = Sequence::create(arrowActionDelay,arrowMove01, arrowActionDelay, arrowMove02, arrowActionDelay, arrowMove03, arrowActionDelay, arrowMove04, nullptr);

	Spawn* marioCommandSelect01 = Spawn::create(
		TargetedAction::create(this, textKuriboSummmonDisActive),
		TargetedAction::create(this, commandSelect01Active),
		TargetedAction::create(this,selectArrowActive),
		TargetedAction::create(selectArrow, arrowAction),
		nullptr);


	//marioDef->runAction(marioMove01);
	//kuppaDef->runAction(kuppaMove01);
	//kuppaDef->runAction(kuppaSeq01);
	//floor_mineDef->runAction(floor_mineMove01);
	//floor_yoursDef->runAction(floor_yoursMove01);
	Sequence* allAction = Sequence::create(startMove, startTextSeq, kuriboSummon,marioCommandSelect01, nullptr);

	this->runAction(allAction);
	

	//CallFunc* active01 = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, marioDef));
	//this->runAction(active01);

	//CallFunc* se01 = CallFunc::create(CC_CALLBACK_0(HelloWorld::PlaySE, this,"game_maoudamashii_2_boss07.mp3"));


	//ノードに対してアクションを実行
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


	//5_やってみよう(1)
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

	//5_やってみよう(2)
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


	//5_やってみよう(3)
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


	//5_やってみよう(4)
	//sprite[0] = Sprite::create("fire01.png");
	//this->addChild(sprite[0]);
	//sprite[0]->setPosition(Vec2(1100.0f, 550.0f));
	//sprite[0]->setScale(0.3f, 0.3f);
	////MoveBy* action01 = MoveBy::create(5.0f, Vec2(-1000.0f, 0));
	//sprite[0]->setOpacity(255);
	//FadeOut* action01 = FadeOut::create(5.0f);
	//sprite[0]->runAction(action01);


	//6.アクションの連携
	//MoveTo* action01 = MoveTo::create(2.0f, Vec2(400.0f, 100.0f));
	//JumpTo* action02 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//sprite->runAction(sequence01);


	//MoveToのあとにTintToとJumpToを同時発動
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
	//自身を削除するアクション。(必ず最後にやる)
	//RemoveSelf* removeSelf01 = RemoveSelf::create();
	//Sequence* sequence01 = Sequence::create(action01, delayTime01, action02, nullptr);
	//Sequence* sequence01 = Sequence::create(action01, action02, removeSelf01, nullptr);
	//Repeat* repeat01 = Repeat::create(sequence01, 6);
	//sprite->runAction(sequence01);
	//sprite->runAction(repeat01);

	//6.やってみよう(1)
	//MoveBy* action01 = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(5.0f, Vec2(900.0f, 0));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//sprite->runAction(repeatForever01);


	//6.やってみよう(2)
	//MoveBy* action01 = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(5.0f, Vec2(900.0f, 0));
	//Sequence* sequence01 = Sequence::create(action01, action02, nullptr);
	//sprite->setOpacity(0);
	//FadeTo* action03 = FadeTo::create(5.0f, 255);
	//FadeTo* action04 = FadeTo::create(5.0f, 0);
	//Sequence* sequence02 = Sequence::create(action03, action04, nullptr);
	//Spawn* spawn01 = Spawn::create(sequence01, sequence02, nullptr);
	//sprite->runAction(spawn01);


	//6.やってみよう(3)
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


	//6.やってみよう(4)
	//MoveBy* action01 = MoveBy::create(2.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(2.0f, Vec2(0.0f, -400.0f));
	//MoveBy* action03 = MoveBy::create(2.0f, Vec2(900.0f, 0.0f));
	//MoveBy* action04 = MoveBy::create(2.0f, Vec2(0.0f, 400.0f));
	//Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	//sprite->runAction(sequence01);


	//6.やってみよう(5)
	//MoveBy* action01 = MoveBy::create(1.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(0.5f, Vec2(0.0f, -400.0f));
	//MoveBy* action03 = MoveBy::create(1.0f, Vec2(900.0f, 0.0f));
	//MoveBy* action04 = MoveBy::create(0.5f, Vec2(0.0f, 400.0f));
	//Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//sprite->runAction(repeatForever01);

 //   //おまけ
	//MoveBy* action01 = MoveBy::create(2.0f, Vec2(-900.0f, 0.0f));
	//MoveBy* action02 = MoveBy::create(1.0f, Vec2(0.0f, -400.0f));
	//MoveBy* action03 = MoveBy::create(2.0f, Vec2(900.0f, 0.0f));
	//MoveBy* action04 = MoveBy::create(1.0f, Vec2(0.0f, 400.0f));
	//ScaleTo* action05 = ScaleTo::create(1.0f, 8.0f);
	//ScaleTo* action06 = ScaleTo::create(1.0f, 3.0f);
	//RotateBy* action07 = RotateBy::create(1.0f, 360.0f * 1.0f);
	//RotateBy* action08 = RotateBy::create(1.0f, -180.0f * 1.0f);
	//Sequence* sequence01 = Sequence::create(action01, action02, action03, action04, nullptr);
	////RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//Sequence* sequence02 = Sequence::create(action05, action06, nullptr);
	//Sequence* sequence03 = Sequence::create(action07, action08, nullptr);
	//Spawn* spawn01 = Spawn::create(sequence02, sequence03, nullptr);
	////Repeat* repeat01 = Repeat::create(spawn01, 1000);
	//RepeatForever* repeatForever01 = RepeatForever::create(sequence01);
	//RepeatForever* repeatForever02 = RepeatForever::create(spawn01);
	////sprite->runAction(repeat01);
	//sprite->runAction(repeatForever01);
	//sprite->runAction(repeatForever02);


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

void HelloWorld::SpriteActive(cocos2d::Sprite* sprite)
{
	sprite->setVisible(true);;
}

void HelloWorld::SpriteDisActive(cocos2d::Sprite* sprite)
{
	sprite->setVisible(false);
}
void HelloWorld::PlaySE(string* name)
{
	string str = *name;
	experimental::AudioEngine::play2d(str);
}

void HelloWorld::update(float delta)
{
	//ここに更新処理を書く

	//画面を回る
	//Vec2 pos;
	//pos = sprite->getPosition();
	//switch(state)
	//{
	////左移動
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

	//スプライトの現在座標を取得
	//Vec2 pos = sprite->getPosition();
	////座標を移動させる
	//pos += Vec2(-3.0f, 0.0f);
	////移動後の座標を反映
	//sprite->setPosition(pos);

	//だんだん透明に
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


	//赤から青に青から赤に
	//redAlpha += 255.0f / 180.0f;
	//blueAlpha -= 255.0f / 180.0f;
	//sprite->setColor(Color3B(redAlpha, 0, blueAlpha));


	//キャラのフェードインフェードアウト
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


	//キャラが画面端で左右反転して移動
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

	//アニメーション
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
