#pragma once

//Author: Faran Steenkamp

using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

ref struct Bullet;
ref struct Destruct;

/* Description of class and how to use:
*
* This class is meant to handle bullet movement, and bullet interaction with other objects
* Calling the update() method is what moves the bullets and tracks for collision
*
* When you add a bullet, you must give a reference to a Control (GUI) object, as well as velocity
* Giving the initial location is optional, if not given then the current location of the object will be used as the start location
*	Note NB: This class destroys(destructs) objects upon collisions, i.e. it calls the deconstructer
*	This means that if you have stored the handle to the bullet somewhere else, that handle will be invalid when the bullet is destroyed
*	and will point to just random memory, giving undefined behaviour
*	For this reason it is recommened to also use gcnew when giving objects to this class, and to not store their handles anywhere else
*
* When you add a destructible object (such as a door), you must give a reference to a Control (GUI) object, as well as a delegate function
* A delegate function is essentially a pointer to the function, but has the ability to be called in non-global scope (i.e. it can call member functions)
* This function is called when the object gets destroyed, so if you want to add a door, you can link the function answerA() to the door, and when the
* door is destroyed it will call answerA(), and then inside answerA() you can have the logic needed to check if that is the right answer and update
* text fields etc.
*
* Delegate function details:
* Summary: Delegate functions are function pointers that can handle scoped (member) functions
* When you create a delegate function you must pass it an object for scoping, and a method (see line 49 in this file)
* This method will get called with the objects scope when the destructible object is destroyed
* The function getting passed to the delegate must be of the type [void func()] i.e. it returns void, and accepts no parameters
*
* In summary, when using this class, make sure to add objects correctly with the correct functions and parameters
* And then all you need to do is call the update() method on a timer, and this class should handle all the logic needed to move bullets, destroy
* objects, and call necessary functions when an object is destroyed
*/

//Example of how to use this class
/*
*class Myform {
*	public:
*		Destructible^ des; //Declare class
*		MyForm(void)
*		{
*			InitializeComponent();
*			des = gcnew Destructible; //Create class
*			Destructible::DestroyFunction^ destroyFunc = gcnew Destructible::DestroyFunction(this, &MyForm::printDeathMSG); //Create delegate function (basically a function pointer)
*
*			des->addBullet(bulletIcon, 5, 0);
*			des->addObject(destructibleIcon, destroyFunc);
*
*			des->addBullet(bulletLabel, 2, 0.1);
*			des->addObject(pictureBox1, destroyFunc);
*		}
*		... Other Code ...
*	}
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
	/// Adds a bullet object to the list, with optional starting position if you wish to set it here instead of before
	/// </summary>
	/// <param name="item">The Control subclass you want to be treated as a bullet</param>
	/// <param name="velocityX">The horizontal velocity of the bullet</param>
	/// <param name="velocityY">The vertical velocity of the bullet</param>
	/// <param name="x_pos">x start position</param>
	/// <param name="y_pos">y start position</param>
	/// <returns></returns>
	void addBullet(Control^ item, double velocityX, double velocityY, int x_pos, int y_pos);

	/// <summary>
	/// Adds a destructible object to the list
	/// </summary>
	/// <param name="item">The Control subclass you want to be treated as a bullet</param>
	/// <param name="functionToCallOnDestroy">Function to call when the object is destroyed</param>
	void addObject(Control^ item, DestroyFunction^ functionToCallOnDestroy);

	int getBulletCount();
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