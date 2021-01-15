#include <irrlicht.h>
#include "driverChoice.h"
#include <stdlib.h>
#include <Windows.h>
#include "collision.h"
#include "maze.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;











int main()
{


	

	////////Create device
	IrrlichtDevice* device = createDevice(video::EDT_OPENGL, dimension2d<u32>(1280, 720), 16, false, false, false);
	if (!device)
		return 1;
	device->setWindowCaption(L"3D Maze");

	bool isRunning = true;
	bool wallCollisions[40][40];

	float speed;

	




	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();





	ICameraSceneNode* finalCamera = smgr->addCameraSceneNodeFPS();
	finalCamera->setPosition(vector3df(20.f, 40.f, 20.f));
	finalCamera->setTarget(vector3df(20.f, 0.f, 20.f));
	


	IMeshSceneNode* cube = smgr->addCubeSceneNode(1, nullptr, 0, vector3df(20.0f, -1.f, 20.f), vector3df(0.f, 0.f, 0.f), vector3df(40.0f, 0.5f, 40.f));

	cube->setMaterialFlag(E_MATERIAL_FLAG::EMF_LIGHTING, false);


	










	/////////////////////////////////////////////////////













	////////creation de la camera
	

	SKeyMap keyMap[10];
	keyMap[0].Action = EKA_MOVE_FORWARD;  
	keyMap[0].KeyCode = KEY_UP;
	keyMap[1].Action = EKA_MOVE_FORWARD;
	keyMap[1].KeyCode = KEY_KEY_Z;

	keyMap[2].Action = EKA_MOVE_BACKWARD;
	keyMap[2].KeyCode = KEY_DOWN;
	keyMap[3].Action = EKA_MOVE_BACKWARD;
	keyMap[3].KeyCode = KEY_KEY_S;

	keyMap[4].Action = EKA_STRAFE_LEFT;
	keyMap[4].KeyCode = KEY_LEFT;
	keyMap[5].Action = EKA_STRAFE_LEFT;
	keyMap[5].KeyCode = KEY_KEY_Q;

	keyMap[6].Action = EKA_STRAFE_RIGHT;
	keyMap[6].KeyCode = KEY_RIGHT;
	keyMap[7].Action = EKA_STRAFE_RIGHT;
	keyMap[7].KeyCode = KEY_KEY_D;

	keyMap[8].Action = EKA_JUMP_UP;
	keyMap[8].KeyCode = KEY_SPACE;
	keyMap[9].Action = EKA_CROUCH;
	keyMap[9].KeyCode = KEY_CONTROL;



	

	vector3df newpos = vector3df(2.5f, 0.f, 1.5f);

	ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS(0, 60.0f, 0.005f, -1, keyMap, 10, true, 0.f, false);
	device->getCursorControl()->setVisible(false);
	camera->setFOV(PI / 4.5f);
	camera->setNearValue(0.5f);
	camera->setPosition(newpos);

	vector3df camRot = camera->getRotation();

	camera->setTarget(vector3df(40.f, .0f, 4.0f));





	////////labyrinthe

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			wallCollisions[i][j] = false;

			if (maze[i][j] == 0)
			{
				
			}
			else if (maze[i][j] == 1)
			{
				IMeshSceneNode* wall = smgr->addCubeSceneNode(1, nullptr, 0, vector3df((i), 0.f, (j)), vector3df(0.f, 0.f, 0.f), vector3df(1.0f, 2.f, 1.f));
				wall->setMaterialTexture(0, driver->getTexture("iron.jpg"));
				wall->setMaterialFlag(E_MATERIAL_FLAG::EMF_LIGHTING, false);
				wallCollisions[i][j] = true;
				printf("Created");
				
			}

			
		}
	}






	
	




	
	


	int lastFPS = -1;

	
	u32 then = device->getTimer()->getTime();
	
	
	

	bool isCol = false;
	bool isCol2 = false;
	bool isCol3 = false;
	bool isCol4 = false;

	while (device->run() && isRunning)
	{
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;
	    speed = .003f;
		
		bool isEnd = false;


		if (camera->getPosition().X >= 38)
			isEnd = true;
	
		if (GetKeyState(VK_ESCAPE) & 0x8000)
			{
				isRunning = false;
				printf("\n Fin Du Programme \n");
			}
	
		if (isEnd)
			smgr->setActiveCamera(finalCamera);


		
	
		
		//MoveAndCollision(camera, speed);
	
		
		
		vector2df Position = vector2df(camera->getPosition().X , camera->getPosition().Z  );
		int minX = (int)(Position.X - .1f - speed);
		int maxX = (int)(Position.X + 1.f + speed );
		int minY = (int)(Position.Y - .1f );
		int maxY = (int)(Position.Y + 1.f );

		for (int x = minX; x <= maxX; ++x)
		{
			for (int y = minY; y <= maxY; ++y)
			{
				
				if (wallCollisions[x][y])
				{
					if( y >= camera->getPosition().Y )
					{ 
						printf("\n\nCollision");
					
						
						isCol = true;
					
					}

					if (y <= camera->getPosition().Y)
					{
						printf("\n\nCollision ");

						
						isCol2 = true;
						
					}
					if (x >= camera->getPosition().X)
					{
						printf("\n\nCollision ");

						
						isCol3 = true;
					}
					if (x <= camera->getPosition().X)
					{
						printf("\n\nCollision ");

						
						isCol4 = true;
					}

					

					
					
				}
				else if (!wallCollisions[x][y])
				{
					//printf("NO COLLISION");
					isCol = false;
					isCol2 = false;
					isCol3 = false;
					isCol4 = false;

				}
			
				
				while (isCol)
				{
					camera->setPosition(vector3df(camera->getPosition().X, camera->getPosition().Y, camera->getPosition().Z-0.005f));
					isCol = false;
				
				}
				while (isCol2)
				{
					camera->setPosition(vector3df(camera->getPosition().X, camera->getPosition().Y, camera->getPosition().Z + 0.005f));
					isCol2 = false; 

				}
				while (isCol3)
				{
					camera->setPosition(vector3df(camera->getPosition().X-0.005f, camera->getPosition().Y, camera->getPosition().Z +0.001f  ));
					isCol3 = false;

				}
				while (isCol4)
				{
					camera->setPosition(vector3df(camera->getPosition().X + 0.005f, camera->getPosition().Y, camera->getPosition().Z +0.001f));
					isCol4 = false;

				}
			}
		}
		


		driver->beginScene(true, true, SColor(255, 25, 25, 25));

		smgr->drawAll();
		
		
		

			
		driver->endScene();
		int fps = driver->getFPS();

        if (lastFPS != fps)
        {
            core::stringw tmp(L"3D maze /");
         
            tmp += " fps: ";
            tmp += fps;

            device->setWindowCaption(tmp.c_str());
            lastFPS = fps;
        }
		
	}


	device->drop();

	return 0;
}






//lecteur depuis fichier
/*
fopen(filename, "r", ptr);
unsigned int info[? ];
fread(info, sizeof(unsigned int), ?, f )
*/