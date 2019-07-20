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
using namespace CocosDenshion;

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

	hpLength = 531;
	hpRect = Rect(0, 0, hpLength, 720);
	

	//画像(sprite)を追加
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
	hp_red = Sprite::create("HP_red.png");
	hp_yellow = Sprite::create("HP_yellow.png");
	hp_green = Sprite::create("HP_Green.png");



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
	hp_red->setAnchorPoint(Vec2::ZERO);
	hp_yellow->setAnchorPoint(Vec2::ZERO);
	hp_green->setAnchorPoint(Vec2::ZERO);



	//シーングラフにつなぐ
	this->addChild(fieldDef);
	this->addChild(floor_mineDef);
	this->addChild(floor_yoursDef);
	this->addChild(ui_Yours);
	this->addChild(hp_red);
	this->addChild(hp_yellow);
	this->addChild(hp_green);
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
	hp_red->setVisible(false);
	hp_yellow->setVisible(false);
	hp_green->setVisible(false);

	//BGMを鳴らす
	experimental::AudioEngine::play2d("game_maoudamashii_2_boss07.mp3");


	//座標初期設定
	marioDef->setPosition(Vec2(1280, 0));
	kuppaDef->setPosition(Vec2(-1280, 0));
	fieldDef->setPosition(Vec2::ZERO);
	floor_mineDef->setPosition(Vec2(1280, 0));
	floor_yoursDef->setPosition(Vec2(-1280, 0));
	messageWindowDef->setPosition(Vec2::ZERO);
	kuriboDef->setPosition(Vec2(640, 0));


	//updateが呼び出されるようにする
	this->scheduleUpdate();

	//アクションの作成
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
	CallFunc* ui_mineActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, ui_Mine));
	CallFunc* ui_yoursActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, ui_Yours));
	CallFunc* hp_redActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, hp_red));
	CallFunc* hp_yellowActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, hp_yellow));
	CallFunc* hp_greenActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, hp_green));

	Spawn* kuriboSummonSpa = Spawn::create(
		TargetedAction::create(this, textBattleStartDisActive),
		TargetedAction::create(this, textKuriboSummmonActive),
		TargetedAction::create(kuppaDef, kuppaMove02),
		TargetedAction::create(kuriboDef, kuriboMove01),
		nullptr);

	Spawn* uiActive = Spawn::create(
		TargetedAction::create(this, ui_mineActive),
		TargetedAction::create(this, ui_yoursActive),
		TargetedAction::create(this, hp_redActive),
		TargetedAction::create(this, hp_yellowActive),
		TargetedAction::create(this, hp_greenActive),
		nullptr);

	Sequence* kuriboSummon = Sequence::create(kuriboSummonSpa,uiActive, kuriboSummonDelay, nullptr);

	//マリオはどうする？アクション
	CallFunc* textKuriboSummmonDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textKuriboSummon01));
	CallFunc* commandSelect01Active = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, commandSelect01));
	CallFunc* selectArrowActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, selectArrow));
	MoveBy* arrowMove01 = MoveBy::create(0.0f, Vec2(0, -70));
	MoveBy* arrowMove02 = MoveBy::create(0.0f, Vec2(226, 0));
	MoveBy* arrowMove03 = MoveBy::create(0.0f, Vec2(0, 70));
	MoveTo* arrowMove04 = MoveTo::create(0.0f, Vec2::ZERO);
	CallFunc* arrowSE = CallFunc::create(CC_CALLBACK_0(HelloWorld::PlaySE, this, "select02.mp3", 0.5f));
	DelayTime* arrowActionDelay = DelayTime::create(1.5f);
	Sequence* arrowAction = Sequence::create(
		arrowActionDelay,arrowMove01,arrowSE,
		arrowActionDelay, arrowMove02, arrowSE,
		arrowActionDelay, arrowMove03, arrowSE,
		arrowActionDelay, arrowMove04, arrowSE,
		arrowActionDelay, arrowSE, nullptr);

	Spawn* marioCommandSelect01 = Spawn::create(
		TargetedAction::create(this, textKuriboSummmonDisActive),
		TargetedAction::create(this, commandSelect01Active),
		TargetedAction::create(this,selectArrowActive),
		TargetedAction::create(selectArrow, arrowAction),
		nullptr);


	//技選択アクション
	CallFunc* commandSelect01DisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, commandSelect01));
	CallFunc* commandSelect02Active = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, commandSelect02));
	MoveBy* arrowMove05 = MoveBy::create(0.0f, Vec2(-727, 8));

	Spawn* marioCommandSelect02Spa = Spawn::create(
		TargetedAction::create(this, commandSelect01DisActive),
		TargetedAction::create(this, commandSelect02Active),
		TargetedAction::create(selectArrow, arrowMove05),
		nullptr);

	DelayTime* commandSelect02Delay = DelayTime::create(3.0f);
	CallFunc* selectArrowDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, selectArrow));

	Sequence* marioCommandSelect02 = Sequence::create(marioCommandSelect02Spa, commandSelect02Delay, arrowSE, TargetedAction::create(selectArrow, selectArrowDisActive), nullptr);


	//マリオのジャンプアクション
	CallFunc* commandSelect02DisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, commandSelect02));
	CallFunc* textMarioAttack = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textMarioAttack01));
	CallFunc* marioDefDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, marioDef));
	CallFunc* marioJumpActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, marioJump));
	JumpTo* marioJump01 = JumpTo::create(1.2f, Vec2(510, 284), 500, 1);
	JumpTo* marioJump02 = JumpTo::create(1.0f, Vec2::ZERO, 200, 1);
	CallFunc* marioJumpDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, marioJump));
	CallFunc* marioDefActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, marioDef));
	CallFunc* marioJumpSE = CallFunc::create(CC_CALLBACK_0(HelloWorld::PlaySE, this, "jump06.mp3", 1.0f));
	CallFunc* marioJumpHitSE = CallFunc::create(CC_CALLBACK_0(HelloWorld::PlaySE, this, "short_bomb.mp3", 1.0f));
	Sequence* marioJumpSeq = Sequence::create(marioJumpActive, marioJump01, marioJumpHitSE, marioJump02, nullptr);
	Spawn* marioJumpTextActive = Spawn::create(
		TargetedAction::create(this, commandSelect02DisActive),
		TargetedAction::create(this, textMarioAttack),
		nullptr);
	DelayTime* jumpTextDelay = DelayTime::create(1.5f);
	Spawn* marioJumpSpa = Spawn::create(
		TargetedAction::create(marioDef, marioDefDisActive),
		TargetedAction::create(marioJump, marioJumpSeq),
		TargetedAction::create(this,marioJumpSE),
		nullptr);

	Sequence* marioJumpAction = Sequence::create(marioJumpTextActive, jumpTextDelay, marioJumpSpa, TargetedAction::create(marioJump,marioJumpDisActive),TargetedAction::create(marioDef,marioDefActive), nullptr);

	//クリボーがやられるアクション
	CallFunc* kuriboDamage = CallFunc::create(CC_CALLBACK_0(HelloWorld::LifeDamage, this));
	DelayTime* hpDamagedelay = DelayTime::create(6.0f);
	CallFunc* textMarioAttackDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textMarioAttack01));
	CallFunc* textKuriboEndActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textKuriboEnd01));
	MoveBy* kuriboEndMove = MoveBy::create(0.3f, Vec2(0, -100));
	CallFunc* kuriboDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, kuriboDef));
	CallFunc* ui_yoursDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, ui_Yours));
	DelayTime* kuriboEndDelay = DelayTime::create(1.5f);

	Sequence* kuriboEnd = Sequence::create(kuriboDamage, hpDamagedelay, textMarioAttackDisActive, textKuriboEndActive, ui_yoursDisActive,TargetedAction::create(kuriboDef, kuriboEndMove), kuriboDisActive, kuriboEndDelay, nullptr);


	//クッパが最後のセリフを言うアクション
	CallFunc* textKuriboEndDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textKuriboEnd01));
	CallFunc* textBattleEndActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textBattleEnd01));
	DelayTime* kuppaMoveDelay01 = DelayTime::create(1.5f);
	CallFunc* textBattleEndDisActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteDisActive, this, textBattleEnd01));
	CallFunc* textKuppaEndActive = CallFunc::create(CC_CALLBACK_0(HelloWorld::SpriteActive, this, textKuppaEnd01));

	Sequence* kuppaEnd = Sequence::create(textKuriboEndDisActive, textBattleEndActive, kuppaMoveDelay01,TargetedAction::create(kuppaDef, kuppaMove01) , textBattleEndDisActive, textKuppaEndActive, nullptr);


	//全てのアクションをシークエンスで
	Sequence* allAction = Sequence::create(startMove, startTextSeq, kuriboSummon, marioCommandSelect01, marioCommandSelect02, marioJumpAction, kuriboEnd, kuppaEnd, nullptr);
	
	this->runAction(allAction);
	

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

void HelloWorld::PlaySE(string name,float volume)
{
	string* str = &name;
	experimental::AudioEngine::play2d(*str, false, volume);
}


void HelloWorld::LifeDamage()
{
	
	damageFlag = true;
		
}

void HelloWorld::update(float delta)
{
	//ここに更新処理を書く

	if (damageFlag)
	{

		hpLength -= 1;
		hpRect = Rect(0, 0, hpLength, 720);
		hp_green->setTextureRect(hpRect);
		hp_yellow->setTextureRect(hpRect);
		hp_red->setTextureRect(hpRect);
		if (hpLength < 402)
		{
			hp_green->setVisible(false);
		}

		if (hpLength < 337)
		{
			hp_yellow->setVisible(false);
		}

		if (hpLength < 280)
		{
			hp_red->setVisible(false);
			damageFlag = false;
		}

	}
	
}
