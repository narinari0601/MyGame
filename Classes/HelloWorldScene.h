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
    
	//�֐��̐錾
	void update(float delta) override;

	void SpriteActive(cocos2d::Sprite* sprite);

	void SpriteDisActive(cocos2d::Sprite* sprite);

	void PlaySE(string* name);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	//�X�v���C�g
	//cocos2d::Sprite* sprite;
	//cocos2d::Sprite* slimeSprite;
	//cocos2d::Sprite* catSprite;
	cocos2d::Sprite* marioDef;  //�}���I�̃f�t�H�����G
	cocos2d::Sprite* marioJump;  //�W�����v���Ă�}���I
	cocos2d::Sprite* kuppaDef;  //�N�b�p�̃f�t�H
	cocos2d::Sprite* kuriboDef;  //�N���{�[�f�t�H
	cocos2d::Sprite* floor_mineDef;  //�����̏�
	cocos2d::Sprite* floor_yoursDef;  //����̏�
	cocos2d::Sprite* fieldDef;        //�S�̏�
	cocos2d::Sprite* messageWindowDef;  //���b�Z�[�W�E�C���h�E
	cocos2d::Sprite* selectArrow;  //�I����
	cocos2d::Sprite* commandSelect01;  //�R�}���h�Z���N�g1
	cocos2d::Sprite* commandSelect02;  //�R�}���h�Z���N�g2
	cocos2d::Sprite* textBattleStart01;  //�o�g�����߂̃e�L�X�g
	cocos2d::Sprite* textKuriboSummon01;  //�N���{�[���o�����Ƃ��̃e�L�X�g
	cocos2d::Sprite* textKuriboEnd01;  //�N���{�[���|�ꂽ�Ƃ��̃e�L�X�g
	cocos2d::Sprite* textMarioAttack01; //�}���I�̍U�����̃e�L�X�g
	cocos2d::Sprite* textBattleEnd01;  //�o�g���I�����̃e�L�X�g
	cocos2d::Sprite* textKuppaEnd01;  //�N�b�p�̎̂đ䎌�e�L�X�g
	cocos2d::Sprite* ui_Mine;  //������UI
	cocos2d::Sprite* ui_Yours;  //�����UI


	//Sprite�z��
	//cocos2d::Sprite* sprite[100];


	float alpha;
	float redAlpha;
	float blueAlpha;
	float slimeAlpha;

	//�ǂ���Ɉړ����Ȃ̂�
	int state;
	cocos2d::Vec2 velocity;
	cocos2d::Rect catRect;
	int catAnimeCount;
	int animeCount;
};

#endif // __HELLOWORLD_SCENE_H__
