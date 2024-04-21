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

//Class that contains functions which allow you to make Control objects move and possibly destroy eachother
public ref class Destructible {
private:
	//List of 'bullet' Control objects
	List<Bullet^> bullets;
	//List of destroyable Control objects
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

//Structure storing the Control object and other necessary details needed for moving bullets
ref struct Bullet {
	//The actual Control object that represents the bullet
	Control^ object;

	//Positions/velocity numbers
	//Doubles are used to store position and then type-cast to int when drawing, allows more fine control over speed and angle of bullet
	double curX, curY, velX, velY;
};

//Structure storing the Control object and other necessary details needed for destroyable objects
ref struct Destruct {
	//The actual Control object that represents the destroyable object
	Control^ object;
	Destructible::DestroyFunction^ destructFunction;
};