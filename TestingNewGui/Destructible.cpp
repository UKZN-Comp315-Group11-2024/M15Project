#include "Destructible.h"

void Destructible::update() {
	for (int i = 0; i < bullets.Count; i++) {
		Bullet^ currentBullet = bullets[i];
		currentBullet->curX += currentBullet->velX;
		currentBullet->curY += currentBullet->velY;

		currentBullet->object->Location = System::Drawing::Point(currentBullet->curX, currentBullet->curY);

		int bulletCenterX = currentBullet->object->Location.X + currentBullet->object->Size.Width/2;
		int bulletCenterY = currentBullet->object->Location.Y + currentBullet->object->Size.Height/2;

		for (int j = 0; j < destroyables.Count; j++) {
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
				currentDestroyable->destructFunction();
				//Delete an remove items
				currentBullet->object->~Control();
				currentDestroyable->object->~Control();
				destroyables.RemoveAt(j);
				bullets.RemoveAt(i--);
				//Exit the loop as the bullet can only destroy one thing at a time
				break;
			}

		}

	}
}

void Destructible::addBullet(Control^ item, double velocityX, double velocityY) {
	Bullet^ bul = gcnew Bullet;
	bul->object = item;
	bul->curX = item->Location.X;
	bul->curY = item->Location.Y;
	bul->velX = velocityX;
	bul->velY = velocityY;
	bullets.Add(bul);
}

void Destructible::addObject(Control ^ item, DestroyFunction^ functionToCallOnDestroy) {
	Destruct^ des = gcnew Destruct;
	des->object = item;
	des->destructFunction = functionToCallOnDestroy;
	destroyables.Add(des);
};