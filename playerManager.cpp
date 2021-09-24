#include "stdafx.h"
#include "playerManager.h"

HRESULT playerManager::init()
{

	//Erik
	//IMAGEMANAGER->addFrameImage("ErikIdle", "LostVikingsimage/Erik/ErikIdle.bmp", 435, 180, 5, 2, true, RGB(255, 0, 255));;
	//IMAGEMANAGER->addFrameImage("ErikRun", "LostVikingsimage/Erik/ErikRun.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikJump", "LostVikingsimage/Erik/ErikJump.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikJumpDouble", "LostVikingsimage/Erik/ErikJumpDouble.bmp", 810, 180, 9, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikLadder", "LostVikingsimage/Erik/ErikLadder.bmp", 435, 90, 6, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikDeath", "LostVikingsimage/Erik/ErikDeath.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikDash", "LostVikingsimage/Erik/ErikDash.bmp", 1344, 180, 14, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikSwimIdle", "LostVikingsimage/Erik/ErikSwimIdle.bmp", 372, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikRope", "LostVikingsimage/Erik/ErikRope.bmp", 372, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikDamageDefault", "LostVikingsimage/Erik/ErikDamageDefault.bmp", 372, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("ErikSwimDash", "LostVikingsimage/Erik/ErikSwimDash.bmp", 930, 180, 4, 2, true, RGB(255, 0, 255));
	//
	////Bealog
	//IMAGEMANAGER->addFrameImage("BaleogIdle", "LostVikingsimage/Bealog/BaleogIdle.bmp", 450, 180, 5, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogRun", "LostVikingsimage/Bealog/BaleogRun.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogfallingIdle", "LostVikingsimage/Bealog/BaleogfallingIdle.bmp", 164, 180, 2, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogRopeIdle", "LostVikingsimage/Bealog/BaleogRopeIdle.bmp", 270, 180, 3, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogRopeMove", "LostVikingsimage/Bealog/BaleogRopeMove.bmp", 540, 180, 6, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogLadder", "LostVikingsimage/Bealog/BaleogLadder.bmp", 540, 90, 6, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogAttackSword", "LostVikingsimage/Bealog/BaleogAttackSword.bmp", 540, 180, 6, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogDeath", "LostVikingsimage/Bealog/BaleogDeath.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogPush", "LostVikingsimage/Bealog/BaleogPush.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogPunch", "LostVikingsimage/Bealog/BaleogPunch.bmp", 360, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogPunchDiagonal", "LostVikingsimage/Bealog/BaleogPunchDiagonal.bmp", 270, 180, 3, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogPunchTop", "LostVikingsimage/Bealog/BaleogPunchTop.bmp", 180, 180, 2, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("BaleogSwing", "LostVikingsimage/Bealog/BaleogSwing.bmp", 720, 180, 8, 2, true, RGB(255, 0, 255));
	//
	////Olaf
	//IMAGEMANAGER->addFrameImage("OlafIDLE", "LostVikingsimage/Olaf/OlafIDLE.bmp", 88, 180, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("OlafTopIdle", "LostVikingsimage/Olaf/OlafTopIdle.bmp", 88, 90, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Olafmove", "LostVikingsimage/Olaf/Olafmove.bmp", 713, 180, 8, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Olafmove2", "LostVikingsimage/Olaf/Olafmove2.bmp", 727, 180, 8, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafPush", "LostVikingsimage/Olaf/OlafPush.bmp", 352, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafDownIDLE", "LostVikingsimage/Olaf/OlafDownIDLE.bmp", 182, 180, 2, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Olafsmall", "LostVikingsimage/Olaf/Olafsmall.bmp", 297, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("SmallOlafmove", "LostVikingsimage/Olaf/SmallOlafmove.bmp", 268, 116, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafDown", "LostVikingsimage/Olaf/OlafDown.bmp", 182, 180, 2, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafDownfast", "LostVikingsimage/Olaf/OlafDownfast.bmp", 455, 180, 5, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafDEAD", "LostVikingsimage/Olaf/OlafDEAD.bmp", 352, 180, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("OlafDamage", "LostVikingsimage/Olaf/OlafDamage.bmp", 87, 180, 1, 2, true, RGB(255, 0, 255));
	//setErik();
	//setBealog();
	//setOlaf();
	//_erik = new Erik;
	//_bealog = new Bealog;
	//_olaf = new Olaf;
	//_erik->init(0, 300, 1149);
	//_bealog->init(1, 200, 1149);
	//_olaf->init(2, 100, 1149);
	//present = 0;

	//_erik->setLinkPixelcollsion(_pix);
	//_bealog->setLinkPixelcollsion1(_pix1);
	//_olaf->setLinkPixelcollsion2(_pix2);
	/*for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); ++_viPlayer)
	{
		(*_viPlayer)->setLinkPixelcollsion(_pix);
	}*/

	return S_OK;
}

void playerManager::release()
{

}

void playerManager::update()
{

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		present++;
		if (present > 2)
			present = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		present--;
		if (present < 0)
			present = 2;
	}
	//for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); ++_viPlayer)
	//{
	//	(*_viPlayer)->update();
	//}
	
	_erik->update();
	_bealog->update();
	_olaf->update();
	//_vPlayer[present]->present=true;
	//_vPlayer[present]->update();
	//CAMERAMANEGER->updateScreen(_erik->getX(), _erik->getY());
}

void playerManager::render()
{
	//for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); ++_viPlayer)
	//{
	//	(*_viPlayer)->render();
	//}
	//_erik->render();
	//_bealog->render();
	//_olaf->render();
}

void playerManager::setErik()
{
	player* _Erik;
	_Erik = new Erik;
	_Erik->init(0, 300, 1149);
	_vPlayer.push_back(_Erik);
}


void playerManager::setBealog()
{
	player* _Bealog;
	_Bealog = new Bealog;
	_Bealog->init(1, 200, 1149);
	_vPlayer.push_back(_Bealog);
}

void playerManager::setOlaf()
{
	player* _Olaf;
	_Olaf = new Olaf;
	_Olaf->init(2, 100, 1149);
	_vPlayer.push_back(_Olaf);
}
