
#include "collision.h"

MoveAndCollision::MoveAndCollision(ICameraSceneNode* camera, float speed)
	{

	
	vector2df Position = vector2df(camera->getPosition().X, camera->getPosition().Z);
	int minX = (int)(Position.X - .1f - speed);
	int maxX = (int)(Position.X + 1.f + speed);
	int minY = (int)(Position.Y - .1f);
	int maxY = (int)(Position.Y + 1.f);

	for (int x = minX; x <= maxX; ++x)
	{
		for (int y = minY; y <= maxY; ++y)
		{

			if (wallCollisions[x][y])
			{
				if (y >= camera->getPosition().Y)
				{
					printf("\n\nCollision BBBB");


					isCol = true;

				}

				if (y <= camera->getPosition().Y)
				{
					printf("\n\nCollision BBBB");


					isCol2 = true;

				}
				if (x >= camera->getPosition().X)
				{
					printf("\n\nCollision BBBB");


					isCol3 = true;
				}
				if (x <= camera->getPosition().X)
				{
					printf("\n\nCollision BBBB");


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
				camera->setPosition(vector3df(camera->getPosition().X, camera->getPosition().Y, camera->getPosition().Z - 0.005f));
				isCol = false;

			}
			while (isCol2)
			{
				camera->setPosition(vector3df(camera->getPosition().X, camera->getPosition().Y, camera->getPosition().Z + 0.005f));
				isCol2 = false;

			}
			while (isCol3)
			{
				camera->setPosition(vector3df(camera->getPosition().X - 0.005f, camera->getPosition().Y, camera->getPosition().Z + 0.001f));
				isCol3 = false;

			}
			while (isCol4)
			{
				camera->setPosition(vector3df(camera->getPosition().X + 0.005f, camera->getPosition().Y, camera->getPosition().Z + 0.001f));
				isCol4 = false;

			}
		}
	}
}