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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace std;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	//関数の宣言
	void update(float delta) override;

	void SpriteActive(cocos2d::Sprite* sprite);

	void SpriteDisActive(cocos2d::Sprite* sprite);

	void PlaySE(string* name);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	//スプライト
	//cocos2d::Sprite* sprite;
	//cocos2d::Sprite* slimeSprite;
	//cocos2d::Sprite* catSprite;
	cocos2d::Sprite* marioDef;  //マリオのデフォ立ち絵
	cocos2d::Sprite* marioJump;  //ジャンプしてるマリオ
	cocos2d::Sprite* kuppaDef;  //クッパのデフォ
	cocos2d::Sprite* kuriboDef;  //クリボーデフォ
	cocos2d::Sprite* floor_mineDef;  //自分の床
	cocos2d::Sprite* floor_yoursDef;  //相手の床
	cocos2d::Sprite* fieldDef;        //全体床
	cocos2d::Sprite* messageWindowDef;  //メッセージウインドウ
	cocos2d::Sprite* selectArrow;  //選択矢印
	cocos2d::Sprite* commandSelect01;  //コマンドセレクト1
	cocos2d::Sprite* commandSelect02;  //コマンドセレクト2
	cocos2d::Sprite* textBattleStart01;  //バトル初めのテキスト
	cocos2d::Sprite* textKuriboSummon01;  //クリボーを出したときのテキスト
	cocos2d::Sprite* textKuriboEnd01;  //クリボーが倒れたときのテキスト
	cocos2d::Sprite* textMarioAttack01; //マリオの攻撃時のテキスト
	cocos2d::Sprite* textBattleEnd01;  //バトル終了時のテキスト
	cocos2d::Sprite* textKuppaEnd01;  //クッパの捨て台詞テキスト
	cocos2d::Sprite* ui_Mine;  //自分のUI
	cocos2d::Sprite* ui_Yours;  //相手のUI


	//Sprite配列
	//cocos2d::Sprite* sprite[100];


	float alpha;
	float redAlpha;
	float blueAlpha;
	float slimeAlpha;

	//どちらに移動中なのか
	int state;
	cocos2d::Vec2 velocity;
	cocos2d::Rect catRect;
	int catAnimeCount;
	int animeCount;
};

#endif // __HELLOWORLD_SCENE_H__
