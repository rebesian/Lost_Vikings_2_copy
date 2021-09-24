#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);
	
	imageset();
	
	background = IMAGEMANAGER->findImage("배경");
	pixel = IMAGEMANAGER->findImage("픽셀배경");

	_pix = new pixelCollision;
	_pix1 = new pixelCollision;
	_pix2 = new pixelCollision;
	
	_erik = new player;
	_bealog = new player;
	_olaf = new player;
	
	_pirate = new pirate;
	_cannonbullet1 = new cannonbullet;
	_cannonbullet2 = new cannonbullet;

	_erikhud = new HUD;
	_bealoghud = new HUD;
	_olafhud = new HUD;
	_trashhud = new HUD;

	_key = new key;
	_clear1 = new clearobject1;
	_clear2 = new clearobject2;

	_object = new objectManager;


	_erikhud->init(IMAGEMANAGER->findImage("HUDone"), 0, 0);
	_bealoghud->init(IMAGEMANAGER->findImage("HUDtwo"), 304, 0);
	_olafhud->init(IMAGEMANAGER->findImage("HUDThree"), 584, 0);
	_trashhud->init(IMAGEMANAGER->findImage("trash"), 864, 0);

	_pix->init(0);
	_pix1->init(1);
	_pix2->init(2);

	_erik->init(0, 300, 1149);
	_bealog->init(1, 200, 1149);
	_olaf->init(2, 100, 1149);
	
	_key->init();
	// 2712,2002;
	_clear1->init(2712, 2002,1);
	//2560 ,452
	_clear2->init(2560, 452, 2);

	_erik->setpresent(true);
	_bealog->setpresent(false); 
	_olaf->setpresent(false);
	
	_object->init();

	_pirate->init();

	_cannonbullet1->init(1063, 1188, 439, 90, 1213, 1188  , 1);
	_cannonbullet2->init(1300, 1523, 534, 102, 1503, 1523 , 2);
	 
	_pix->setLinkPlayer(_erik);
	_pix1->setLinkPlayer(_bealog);
	_pix2->setLinkPlayer(_olaf);

	_erik->setLinkPixelcollsion(_pix);
	_bealog->setLinkPixelcollsion(_pix1);
	_olaf->setLinkPixelcollsion(_pix2);
	 
	_erikhud->setLinkPlayer(_erik);
	_bealoghud->setLinkPlayer(_bealog);
	_olafhud->setLinkPlayer(_olaf);

	present = 0;
	hudMode = false;

	return S_OK;

}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

}


void playGround::update()
{
	gameNode::update();
	

	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		present++;
		if (present > 2)
			present = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		present--;
		if (present < 0)
			present = 2;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (hudMode)
			hudMode = false;
		else
			hudMode = true;
	}

	_pix->update();
	_pix1->update();
	_pix2->update();
	

	switch (present)
	{
	case 0 :
		_bealog->setpresent(false);
		_olaf->setpresent(false);
		_erik->setpresent(true);

		_bealoghud->setpresent(false);
		_olafhud->setpresent(false);
		_erikhud->setpresent(true);

		_bealoghud->update(IMAGEMANAGER->findImage("NoneBealog"));
		_olafhud->update(IMAGEMANAGER->findImage("NoneOlaf"));
		_erikhud->update(IMAGEMANAGER->findImage("Erik"));

		CAMERAMANEGER->updateScreen(_erik->getX(), _erik->getY());
		break;

	case 1 :

		_erik->setpresent(false);
		_olaf->setpresent(false);
		_bealog->setpresent(true);

		_erikhud->setpresent(false);
		_olafhud->setpresent(false);
		_bealoghud->setpresent(true);

		_erikhud->update(IMAGEMANAGER->findImage("NoneErik"));
		_olafhud->update(IMAGEMANAGER->findImage("NoneOlaf"));
		_bealoghud->update(IMAGEMANAGER->findImage("Bealog"));

		CAMERAMANEGER->updateScreen(_bealog->getX(), _bealog->getY());
		break;

	case 2 : 

		_erik->setpresent(false);
		_bealog->setpresent(false);
		_olaf->setpresent(true);

		_erikhud->setpresent(false);
		_bealoghud->setpresent(false);
		_olafhud->setpresent(true);

		_erikhud->update(IMAGEMANAGER->findImage("NoneErik"));
		_bealoghud->update(IMAGEMANAGER->findImage("NoneBealog"));
		_olafhud->update(IMAGEMANAGER->findImage("Olaf"));

		CAMERAMANEGER->updateScreen(_olaf->getX(), _olaf->getY());
		break;
	}

	ErikCollision();
	BealogCollision();
	OlafCollision();

	if (_erik->key || _bealog->key || _olaf->key)
	{
		_key->update();
	}
	if (_erik->clear1 || _bealog->clear1 || _olaf->clear1)
	{
		_clear1->update();
	}
	if (_erik->clear2 || _bealog->clear2 || _olaf->clear2)
	{
		_clear2->update();
	}

	if (!hudMode) {
		
		_pirate->playerdamage(_erik);
		_pirate->playerdamage(_bealog);
		_pirate->playerdamage(_olaf);

		_erik->update();
		_bealog->update();
		_olaf->update();

		_pirate->attackdamage(_bealog);

		ErikPlay();
		BealogPlay();
		OlafPlay();

		_pirate->update();
		_cannonbullet1->update();
		_cannonbullet2->update();
		_object->update();

		_erikhud->sethudMode(false);
		_bealoghud->sethudMode(false);
		_olafhud->sethudMode(false);
	}
	else
	{
		_erikhud->sethudMode(true);
		_bealoghud->sethudMode(true);
		_olafhud->sethudMode(true);
	}
	_trashhud->update(nullptr);
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		this->init();
	}
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	if (hudMode)
	{
		background->alphaRender(getMemDC(), 0, 0 , 10);
	}
	else
	{
		background->render(getMemDC());
	}

	//if (KEYMANAGER->isToggleKey(VK_TAB))
	//{
	//	pixel->render(getMemDC(), 0, 0);
	//}

	_object->render();
	_pirate->render();
	_cannonbullet1->render();
	_cannonbullet2->render();
	_erik->render(hudMode);
	_bealog->render(hudMode);
	_olaf->render(hudMode);
	
	_key->render();
	_clear1->render();
	_clear2->render();

	_erikhud->render();
	_bealoghud->render();
	_olafhud->render();
	_trashhud->render();

	if (hudMode&&_erikhud->getpresent()) {
		_bealoghud->render();
		_olafhud->render();
		_trashhud->render();
		_erikhud->render();
	}
	if (hudMode&&_bealoghud->getpresent()) {
		_olafhud->render();
		_trashhud->render();
		_erikhud->render();
		_bealoghud->render();
	}
	if (hudMode&&_olafhud->getpresent()) {
		_bealoghud->render();
		_trashhud->render();
		_erikhud->render();
		_olafhud->render();
	}

	if (_object->clear)
	{

		IMAGEMANAGER->findImage("TheLostVikings")->render(getMemDC(),CAMERAMANEGER->getX(),CAMERAMANEGER->getY());
	}
	//==================================================
	//여기도 건들지마라

	CAMERAMANEGER->render(getHDC(), 0 , 0 , getBackBuffer()->getMemDC(), 1.0f);
}

void playGround::imageset()
{
	//배경
	IMAGEMANAGER->addImage("픽셀배경", "픽셀충돌maps.bmp", 3168, 2298, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경", "maps.bmp", 3168, 2298, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TheLostVikings","LostVikingsimage/backGround/LostVikings.bmp", 1024, 800, true, RGB(255, 0, 255));


	//허드
	IMAGEMANAGER->addImage("HUDone", "LostVikingsimage/HUD/HUDone.bmp", 304, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HUDtwo", "LostVikingsimage/HUD/HUDtwo.bmp", 280, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HUDThree", "LostVikingsimage/HUD/HUDThree.bmp", 280, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("trash", "LostVikingsimage/HUD/trash.bmp", 160, 186, true, RGB(255, 0, 255));
	//초상화
	IMAGEMANAGER->addImage("Erik", "LostVikingsimage/HUD/Erik.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Bealog", "LostVikingsimage/HUD/Bealog.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Olaf", "LostVikingsimage/HUD/Olaf.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("NoneErik", "LostVikingsimage/HUD/NoneErik.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("NoneBealog", "LostVikingsimage/HUD/NoneBealog.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("NoneOlaf", "LostVikingsimage/HUD/NoneOlaf.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DeadErik", "LostVikingsimage/HUD/DeadErik.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DeadBealog", "LostVikingsimage/HUD/DeadBealog.bmp", 121, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DeadOlaf", "LostVikingsimage/HUD/DeadOlaf.bmp", 121, 94, true, RGB(255, 0, 255));
	
	//hp
	IMAGEMANAGER->addImage("hp", "LostVikingsimage/HUD/hp.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hp1", "LostVikingsimage/HUD/hp.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hp2", "LostVikingsimage/HUD/hp.bmp", 16, 16, true, RGB(255, 0, 255));
	
	//itempoint
	IMAGEMANAGER->addImage("itempoint", "LostVikingsimage/HUD/itempoint.bmp", 61, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("itempoint1", "LostVikingsimage/HUD/itempoint.bmp", 61, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("itempoint2", "LostVikingsimage/HUD/itempoint.bmp", 61, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("trashpoint", "LostVikingsimage/HUD/trashpoint.bmp", 81, 61, true, RGB(255, 0, 255));

	//Erik
	IMAGEMANAGER->addFrameImage("ErikIdle", "LostVikingsimage/Erik/ErikIdle.bmp", 435, 180, 5, 2, true, RGB(255, 0, 255));;
	IMAGEMANAGER->addFrameImage("ErikRun", "LostVikingsimage/Erik/ErikRun.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikJump", "LostVikingsimage/Erik/ErikJump.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikJumpDouble", "LostVikingsimage/Erik/ErikJumpDouble.bmp", 810, 180, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikLadder", "LostVikingsimage/Erik/ErikLadder.bmp", 435, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikDeath", "LostVikingsimage/Erik/ErikDeath.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikSwimIdle", "LostVikingsimage/Erik/ErikSwimIdle.bmp", 372, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikRope", "LostVikingsimage/Erik/ErikRope.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikDamageDefault", "LostVikingsimage/Erik/ErikDamageDefault.bmp", 180, 90, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikSwimDash", "LostVikingsimage/Erik/ErikSwimDash.bmp", 930, 180, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ErikDeath", "LostVikingsimage/Erik/ErikDeath.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));

	////Bealog
	IMAGEMANAGER->addFrameImage("BaleogIdle", "LostVikingsimage/Bealog/BaleogIdle.bmp", 450, 180, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogRun", "LostVikingsimage/Bealog/BaleogRun.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogfallingIdle", "LostVikingsimage/Bealog/BaleogfallingIdle.bmp", 164, 180, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogRopeMove", "LostVikingsimage/Bealog/BaleogRopeMove.bmp", 540, 180, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogLadder", "LostVikingsimage/Bealog/BaleogLadder.bmp", 540, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogAttackSword", "LostVikingsimage/Bealog/BaleogAttackSword.bmp", 540, 180, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogDeath", "LostVikingsimage/Bealog/BaleogDeath.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogPush", "LostVikingsimage/Bealog/BaleogPush.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogPunch", "LostVikingsimage/Bealog/BaleogPunch.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogPunchDiagonal", "LostVikingsimage/Bealog/BaleogPunchDiagonal.bmp", 270, 180, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogPunchTop", "LostVikingsimage/Bealog/BaleogPunchTop.bmp", 180, 180, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogSwing", "LostVikingsimage/Bealog/BaleogSwing.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BaleogDamageDefault", "LostVikingsimage/Bealog/BaleogDamageDefault.bmp", 180, 90, 2, 1, true, RGB(255, 0, 255));

	//gargolee
	IMAGEMANAGER->addImage("gargolee1", "LostVikingsimage/Bealog/gargolee1.bmp", 38, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargolee2", "LostVikingsimage/Bealog/gargolee2.bmp", 38, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargolee3", "LostVikingsimage/Bealog/gargolee3.bmp", 38, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargolee4", "LostVikingsimage/Bealog/gargolee4.bmp", 38, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargolee5", "LostVikingsimage/Bealog/gargolee5.bmp", 38, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargoleebody", "LostVikingsimage/Bealog/gargoleebody.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargoleebody1", "LostVikingsimage/Bealog/gargoleebody.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gargoleebody2", "LostVikingsimage/Bealog/gargoleebody.bmp", 32, 32, true, RGB(255, 0, 255));

	////Olaf
	IMAGEMANAGER->addFrameImage("OlafIDLE", "LostVikingsimage/Olaf/OlafIDLE.bmp", 88, 180, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafTopIdle", "LostVikingsimage/Olaf/OlafTopIdle.bmp", 88, 180, 1,2,true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Olafmove", "LostVikingsimage/Olaf/Olafmove.bmp", 713, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Olafmove2", "LostVikingsimage/Olaf/Olafmove2.bmp", 727, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafPush", "LostVikingsimage/Olaf/OlafPush.bmp", 352, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafDownIdle", "LostVikingsimage/Olaf/OlafDownIdle.bmp", 182, 180, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Olafsmall", "LostVikingsimage/Olaf/Olafsmall.bmp", 297, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SmallOlafmove", "LostVikingsimage/Olaf/SmallOlafmove.bmp", 268, 116, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafDown", "LostVikingsimage/Olaf/OlafDown.bmp", 182, 180, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafDownfast", "LostVikingsimage/Olaf/OlafDownfast.bmp", 455, 180, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Olafladder", "LostVikingsimage/Olaf/Olafladder.bmp", 477, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafDEAD", "LostVikingsimage/Olaf/OlafDEAD.bmp", 352, 180, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OlafDamage", "LostVikingsimage/Olaf/OlafDamage.bmp", 87, 180, 1, 2, true, RGB(255, 0, 255));
}

void playGround::ErikCollision()
{
	//int값
	_erik->rope = _object->ropecheck(_erik);
	_erik->labber = _object->labbercheck(_erik);
	_erik->thorn = _object->thorncheck(_erik);
	_erik->elevator = _object->elevatorcheck(_erik);
	_erik->pushbotten = _object->pushbottencheck(_erik);

	//bool값
	_erik->keyhome = _object->keyhomecheck(_erik);
	_erik->door = _object->doorcheck(_erik);
	_erik->wall = _object->wallcheck(_erik);
	_erik->water = _object->watercheck(_erik);
	_erik->fire = _object->firecheck(_erik);
	_erik->bottenbox = _object->bottenboxcheck(_erik);
	_erik->npc = _object->npccheck(_erik);
	_erik->key = _key->keycheck(_erik);
	_erik->clear1 = _clear1->clearcheck1(_erik);
	_erik->clear2 = _clear2->clearcheck2(_erik);
	//에너미충돌
	_pirate->rangeplayer(_erik);
	_cannonbullet1->rangeplayer(_erik);
	_cannonbullet2->rangeplayer(_erik);
	_erik->damage = _pirate->playerdamage(_erik);
	_erik->bullet1 = _cannonbullet1->bulletdamage(_erik);
	_erik->bullet2 = _cannonbullet2->bulletdamage(_erik);
}
void playGround::BealogCollision()
{
	//int값
	_bealog->rope = _object->ropecheck(_bealog);
	_bealog->labber = _object->labbercheck(_bealog);
	_bealog->thorn = _object->thorncheck(_bealog);
	_bealog->elevator = _object->elevatorcheck(_bealog);
	_bealog->pushbotten = _object->pushbottencheck(_bealog);
	_bealog->bealogaction = _object->bealogactioncheck(_bealog);

	//bool값
	_bealog->keyhome = _object->keyhomecheck(_bealog);
	_bealog->door = _object->doorcheck(_bealog);
	_bealog->wall = _object->wallcheck(_bealog);
	_bealog->water = _object->watercheck(_bealog);
	_bealog->fire = _object->firecheck(_bealog);
	_bealog->bottenbox = _object->bottenboxcheck(_bealog);
	_bealog->npc = _object->npccheck(_bealog);
	_bealog->key = _key->keycheck(_bealog);
	_bealog->clear1 = _clear1->clearcheck1(_bealog);
	_bealog->clear2 = _clear2->clearcheck2(_bealog);

	//에너미충돌
	_pirate->rangeplayer(_bealog);
	_cannonbullet1->rangeplayer(_bealog);
	_cannonbullet2->rangeplayer(_bealog);
	_bealog->damage = _pirate->playerdamage(_bealog);
	_bealog->bullet1 = _cannonbullet1->bulletdamage(_bealog);
	_bealog->bullet2 = _cannonbullet2->bulletdamage(_bealog);

}

void playGround::OlafCollision()
{
	//int값
	_olaf->rope = _object->ropecheck(_olaf);
	_olaf->labber = _object->labbercheck(_olaf);
	_olaf->thorn = _object->thorncheck(_olaf);
	_olaf->elevator = _object->elevatorcheck(_olaf);
	_olaf->pushbotten = _object->pushbottencheck(_olaf);

	//bool값
	_olaf->keyhome = _object->keyhomecheck(_olaf);
	_olaf->door = _object->doorcheck(_olaf);
	_olaf->wall = _object->wallcheck(_olaf);
	_olaf->water = _object->watercheck(_olaf);
	_olaf->fire = _object->firecheck(_olaf);
	_olaf->bottenbox = _object->bottenboxcheck(_olaf);
	_olaf->npc = _object->npccheck(_olaf);
	_olaf->key = _key->keycheck(_olaf);
	_olaf->clear1 = _clear1->clearcheck1(_olaf);
	_olaf->clear2 = _clear2->clearcheck2(_olaf);

	//에너미충돌
	_pirate->rangeplayer(_olaf);
	_cannonbullet1->rangeplayer(_olaf);
	_cannonbullet2->rangeplayer(_olaf);
	_olaf->damage = _pirate->playerdamage(_olaf);
	_olaf->bullet1 = _cannonbullet1->bulletdamage(_olaf);
	_olaf->bullet2 = _cannonbullet2->bulletdamage(_olaf);
}

void playGround::ErikPlay()
{
	if (_erik->wall)
	{
		_object->setwall(_erik);
	}
	if (_erik->elevator != 255)
	{
		_object->setelevtor(_erik);
	}
}

void playGround::BealogPlay()
{
	if (_bealog->wall)
	{
		_object->setwall(_bealog);
	}
	if (_bealog->elevator != 255)
	{
		_object->setelevtor(_bealog);
	}
}

void playGround::OlafPlay()
{
	if (_olaf->wall)
	{
		_object->setwall(_olaf);
	}
	if (_olaf->elevator != 255)
	{
		_object->setelevtor(_olaf);
	}
}

