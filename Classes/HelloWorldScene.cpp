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
    if ( !Scene::init() )
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
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
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
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
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


	//テクスチャファイル名を指定して、スプライトを作成
	sprite = Sprite::create("fire01.png");
	//sprite = Sprite::create("sample06.png");

	//新しい画像
	slimeSprite = Sprite::create("slime01.png");
	catSprite = Sprite::create("sample06.png");
	
	//シーングラフにつなぐ
	this->addChild(sprite);
	this->addChild(slimeSprite);
	this->addChild(catSprite);

	Vec2 spritePos = Vec2(1100.0f, 550.0f);
	animeCount = 0;
	catAnimeCount = 0;
	catRect = Rect(0, 0, 32, 32);

	//表示座標指定
	sprite->setPosition(spritePos); //visibleSize.widthで横幅、visibleSize.hightで縦幅
	slimeSprite->setPosition(spritePos - Vec2(0, 60.0f));
	catSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//回転角を指定
	//sprite->setRotation(45.0f);
	//拡縮を指定
	sprite->setScale(0.5f, 0.5f);
	catSprite->setScale(8.0f);
	//左右反転
	//sprite->setFlippedX(true);
	//上下反転
	//sprite->setFlippedY(true);
	//非表示にする
	sprite->setVisible(false);
	slimeSprite->setVisible(false);
	//色合いを設定
	//sprite->setColor(Color3B(128, 255, 255));
	//不透明度を設定
	//sprite->setOpacity(0x00);
	slimeSprite->setOpacity(slimeAlpha);
	//画像切り取り
	catSprite->setTextureRect(catRect);

	//アンチエイリアスをカット
	catSprite->getTexture()->setAliasTexParameters();

	//updateが呼び出されるようにする
	this->scheduleUpdate();

	//アンカーポイントを設定(0〜1)
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	//sprite->setRotation(45.0f);

	

	state = 0;

	velocity = Vec2(-3.0f, 0.0f);

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
	if (animeCount > 10 * 3-1)
	{
		animeCount = 10 * 2;
		state = 1;
	}

	else if (animeCount < 0)
	{
		animeCount = 10;
		state = 0;
	}
	if (state == 0)
	{
		animeCount += 1;
	}
	else
	{
		animeCount -= 1;
	}
    
	catAnimeCount = animeCount / 10;

	if (catAnimeCount > 2)
	{
		catAnimeCount = 0;
	}
	catRect = Rect(catAnimeCount % 3 * 32, 0 * 32, 32, 32);
	catSprite->setTextureRect(catRect);

}
