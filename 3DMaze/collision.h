#pragma once
#include <irrlicht.h>
#include "driverChoice.h"
#include <stdlib.h>
#include <Windows.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MoveAndCollision
{
public:
	MoveAndCollision(ICameraSceneNode* camera, float speed);
	

private:
	ICameraSceneNode* camera;
	float speed;
	bool isCol;
	bool isCol2;
	bool isCol3;
	bool isCol4;
	bool wallCollisions[40][40];
};

