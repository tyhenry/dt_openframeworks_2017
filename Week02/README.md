# Week 2 

## Review:

### using the command line:

 - **cd folder** change directory to a folder inside the current directory
 - **cd ..** go back one directory
 - **ls** list what's in the current directory
 - **ls -a** list everything in the directory, _including hidden files_

further reading:

 - you can do the [Codecademy command line tutorial](https://www.codecademy.com/courses/learn-the-command-line/lessons/navigation/exercises/your-first-command?action=lesson_resume) online (you need a free account)
 - or check out [this Lifehacker article](http://lifehacker.com/5633909/who-needs-a-mouse-learn-to-use-the-command-line-for-almost-anything) with some basics

### pushing to Git: 

 - git add *
 - git commit -m "my commit message"
 - git push origin master

### Object Oriented Programming:

 - we use **classes** to represent _types_ of things, "encapsulated" in neat packages
 - **objects** are the actual things themselves
 - classes can **inherit** from each other
 - we **declare** the class's functions and variables with a header (.h or .hpp) file - this is like a table of contents
 - we **define** the class functions inside a .cpp file

### openFrameworks apps: 

 - use OF Project Generator to create a new OF app
 - OF apps always have a main.cpp, ofApp.h, and ofApp.cpp
 - define your window dimensions in main.cpp
 - in ofApp:
 	- setup() runs once, at start of app
 	- update() loops until you quit - this is where you do calculations, etc.
 	- draw() loops until you quit - this is where you draw things to screen

## Example apps (in this folder):

_To load these apps, use the git command: `git pull` to update your local copy of this repository_

These apps just contain the code.  You need to use OF Project Generator to create the project in your IDE.  
Open OF Project Generator, and click Import.  Then select the app folder (i.e. "bouncingBall").  Then click Update button, and open in IDE.

 - **bouncingBall** demonstrates how to create a Ball class
 - **manyBouncingBalls** demos how to create a vector of Balls 
 - **squareBalls** demos how to create a SquareBall class that _inherits_ from the Ball class

## Homework:

READ the following chapters of the ofBook:

 - [Graphics](http://openframeworks.cc/ofBook/chapters/intro_to_graphics.html)
 - [OOPs!](http://openframeworks.cc/ofBook/chapters/OOPs!.html) <<< this is a deeper explanation of what we did in class
 - [How OF Works](http://openframeworks.cc/ofBook/chapters/how_of_works.html)

USE this knowledge to create a few experimental apps of your own:

1.	Create a simple animation using a class of your own design.  You can use the Ball class as a template for your code.  
	Play with color, shape, size, movement, speed, etc.  
	  	- the class you write should contain both an update() and a draw() function  
		- try to use a vector in your app to contain multiple copies of the class  

2.	**Try** to make an **interactive** application using the mouse or keyboard
	- for example, how would you create a new ball when the user clicks the mouse?
	- Hint: look through the other default functions in ofApp.cpp, especially ofApp::mouseReleased(), and ofApp::keyReleased()

3. 	[Extra] Look through the example "math" or "graphics" apps that came with openFrameworks (inside examples/graphics or examples/math)  
	Choose one example app, and copy the code to a new app you create.  Now modify the code!  Experiment - try "breaking" the code.  Try making the app do something different in subtle or extreme ways.






