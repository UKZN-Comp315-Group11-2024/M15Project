#include "pch.h"
#include "Destructible.h"

//Author: Faran Steenkamp

void Destructible::update() {
	for (int i = 0; i < bullets.Count; i++) {
		//Handle for the current Bullet
		Bullet^ currentBullet = bullets[i];

		//Update bullet position then move
		currentBullet->curX += currentBullet->velX;
		currentBullet->curY += currentBullet->velY;
		currentBullet->object->Location = System::Drawing::Point((int)(currentBullet->curX), (int)(currentBullet->curY));

		//Calculate center of Bullet for bounds checking
		int bulletCenterX = currentBullet->object->Location.X + currentBullet->object->Size.Width/2;
		int bulletCenterY = currentBullet->object->Location.Y + currentBullet->object->Size.Height/2;

		for (int j = 0; j < destroyables.Count; j++) {
			//Handle for the current destroyable objects
			Destruct^ currentDestroyable = destroyables[j];

			//Checks if the bullet's center is contained in the horizontal bounds of the destroyable icon
			bool xInside =
				currentDestroyable->object->Location.X <= bulletCenterX
				&& bulletCenterX <= (currentDestroyable->object->Location.X + currentDestroyable->object->Size.Width);

			//Checks if the bullet's center is contained in the vertical bounds of the destroyable icon
			bool yInside =
				currentDestroyable->object->Location.Y <= bulletCenterY
				&& bulletCenterY <= (currentDestroyable->object->Location.Y + currentDestroyable->object->Size.Height);

			if (xInside && yInside) {
				//Call delegate function
				currentDestroyable->destructFunction();
				//Delete Controls and remove items from queue
				currentBullet->object->~Control();
				currentDestroyable->object->~Control();
				destroyables.RemoveAt(j);
				bullets.RemoveAt(i--);
				//Exit the loop as the bullet can only destroy one thing at a time
				//This break will return us back to the i-for loop
				break;
			}

		}

	}
}

void Destructible::addBullet(Control^ item, double velocityX, double velocityY, int x_pos, int y_pos) {
	//Initialise struct and add to queue
	Bullet^ bul = gcnew Bullet;
	bul->object = item;
	bul->object->Location = System::Drawing::Point(x_pos, y_pos);
	bul->curX = item->Location.X;
	bul->curY = item->Location.Y;
	bul->velX = velocityX;
	bul->velY = velocityY;
	bullets.Add(bul);
}

void Destructible::addObject(Control ^ item, DestroyFunction^ functionToCallOnDestroy) {
	//Initialise struct and add to queue
	Destruct^ des = gcnew Destruct;
	des->object = item;
	des->destructFunction = functionToCallOnDestroy;
	destroyables.Add(des);
};