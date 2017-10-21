# Week 8

## Example Projects 

- **flowField** - particles flow over a 2D grid of forces / terrain
- **grid** - prototype an LED array on screen
- **screenGrabGrid** - demo of capturing the screen and reading colors

## Inspiration

- **[Thomas Wilfred](https://www.google.com/search?tbm=isch&q=Thomas+Wilfred)**
- **[Jim Campbell](https://www.vice.com/en_us/article/av43jz/jim-campbells-sculptural-led-light-installations)**


## Midterm app presentations: Thurs. Oct. 26th at 7pm

**Your project ideas are great** - thanks for sharing them!

If you have any questions about your project, please send me an e-mail  -
(and to those of you who have emailed, I'll respond Sat. Oct 21)

## Midterm project goals

- **Code an app in C++/openFrameworks that produces an interactive animation**, and which speaks to your own artistic or design interests!

 Feel free to explore generative design, physics simulation, games, abstract composition, color, images, drawing, data or math visualizations, motion graphics, or any aesthetic direction you wish.  You should show off your own skills and unique interests.

 You are welcome to combine this project with other classwork or outside work - but you must use openFrameworks, and there must be animation and interaction elements to your application.
 
- **Be ready to demo the app on the big screen in class on Thursday.**

- You should organize your code using classes, objects, `vector`, and any of the C++ programming techniques we've learned so far.
  
### Animation techniques you can use:

+ interpolation, `ofMap()`, `ofVec3f()`, angles, scale...
+ `sin(), cos(), atan2()`...
+ `ofColor(), ofNoise(), ofGetElapsedTimef()`...
+ velocity, forces, attraction, particles, particle systems...
+ 3D? _beware the extra code, focus on 2D first_  
+ flow fields :) _(see this week's example)_

+ or feel free to explore techniques of your own choosing and interpretation!
  
To load and draw images, check out [`ofImage()`](http://openframeworks.cc/documentation/graphics/ofImage/) in the openFrameworks docs 
    
    
### Interaction 

Focus on mouse and keyboard!  Keep it simple first...

```c++
    ofGetMouseX(); ofGetMouseY(); ofGetPreviousMouseX(); ofGetPreviousMouseY();
    
    // ofApp functions
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
```

- **GUIs: If you're interested in creating a quick UI, check out [Lewis Lepton's YouTube channel](https://www.youtube.com/watch?v=X_is1x8iVtw&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=20)**, where he goes through using ofxGUI for animation.  


I encourage you to focus on the animation aspects - try to figure out how to create the motion and the colors, shapes, and images that you envision.  Be sure you achieve that core animation before you get too caught up in addons, or extra technologies for fancy interactions. Your effort should be primarily on the look and feel of your animated "world".

We can always add those cool interactions in the coming weeks!  

