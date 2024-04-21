#pragma once
#include <list>

//Author: Faran Steenkamp

using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

ref struct Bullet;
ref struct Destruct;

//Example of how to use this class
/*
class Myform { 
	public:
		Destructible^ des; //Declare class
		MyForm(void)
		{
			InitializeComponent();
			des = gcnew Destructible; //Create class
			Destructible::DestroyFunction^ destroyFunc = gcnew Destructible::DestroyFunction(this, &MyForm::printDeathMSG); //Create delegate function (basically a function pointer)

			des->addBullet(bulletIcon, 5, 0);
			des->addObject(dickheadIcon, destroyFunc);

			des->addBullet(bulletLabel, 2, 0.1);
			des->addObject(pictureBox1, destroyFunc);
		}
		... Other Code ...
	}
*/

public ref class Destructible {
private:
	List<Bullet^> bullets;
	List<Destruct^> destroyables;
public:
	//Updates bullet positions and checks for collisions
	void update();

	//Definition of delegate function
	delegate void DestroyFunction();

	/// <summary>
	/// Adds a bullet object to the list
	/// </summary>
	/// <param name="item">The Control subclass you want to be treated as a bullet</param>
	/// <param name="velocityX">The horizontal velocity of the bullet</param>
	/// <param name="velocityY">The vertical velocity of the bullet</param>
	/// <returns></returns>
	void addBullet(Control^ item, double velocityX, double velocityY);

	/// <summary>
	/// Adds a destructible object to the list
	/// </summary>
	/// <param name="item">The Control subclass you want to be treated as a bullet</param>
	/// <param name="functionToCallOnDestroy">Function to call when the object is destroyed</param>
	void addObject(Control^ item, DestroyFunction^ functionToCallOnDestroy);
};

ref struct Bullet {
	Control^ object;
	double curX, curY, velX, velY;
};

ref struct Destruct {
	Control^ object;
	Destructible::DestroyFunction^ destructFunction;
};