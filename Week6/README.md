# Week 6

## Example Code

- **Attraction** - simple attraction force on Movers
- **AttractionRepulsion** - create a grid of Movers, apply attraction and repulsion based on mouse
- **Attractors** - create Attractor class, model gravity (see [Reading](#gravity))
- **Elastic** - create an elastic force, particles spring back to starting point
- **ParticleSystems** - create particle emitters with lifespans

## Homework

### Sketches

1. **Interstellar**

    Create a "space" scene, taking inspiration from the orbital motion of galaxies, stars, planets, moons, comets, asteroids... (... and black holes? :sweat_smile:)  Get creative, and don't feel limited by duplicating the _actual_ laws of physics.  You can modify physics to suit your ideas!
      
    Your objects (e.g. your stars, planets, or asteroids, etc.) should be instances of classes that you design.  They should use **forces** like **_attraction_** and **_repulsion_** (or design your own forces).
    
    Now make it interactive! :innocent:
    
    **Bonus:** Game-ify it!  Think about classic space shooters, like [Asteroids](https://www.kevs3d.co.uk/dev/asteroids/index-debug.html)...

2. **Firework Display** 

    Using **particle systems**, create a sketch that makes colorful firework-like explosions.  The "explosions" should be composed of **_particles_** that _decay_ over time (and probably are affected by gravity, or other forces)...
    
    **Bonus:** Make an interactive firework *launcher* (for example, angle and force of launch is controlled by mouse - think *Angry Birds*...)
    
## Reading

**The Nature of Code**

- <a name=gravity>**[The Nature of Code: Chapter 2 Section 9 "Gravitational Attraction"](http://natureofcode.com/book/chapter-2-forces/#chapter02_section9)**

- **[The Nature of Code: Chapter 4 "Particle Systems"](http://natureofcode.com/book/chapter-4-particle-systems/)**

    Remember that **The Nature of Code** is written in the Processing language (Java), but the concepts of physics-based animation are easily translated to C++/oF.
    
**Extra:**  

- Check out **Lewis Lepton's openFrameworks YouTube series**.  It is designed for beginners, but covers some concepts we haven't yet seen, like _ofxAddons_, video, sound, and GUI controls.

    **[Here's the first episode on creating a GUI using ofxGUI](https://www.youtube.com/watch?v=X_is1x8iVtw&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=20)**

    (Note that the older episodes are ~2 years old, so some things like oF Project Generator will look a little different, but the principles are still relevant)


## Class Review

### Normalizing Vectors

Recall that a vector has both a direction and a magnitude.  
What if we just want to know the direction, but don't care about the magnitude?  

When we **normalize** a vector, we set its magnitude to 1.0, but keep the direction.  
A vector with a magnitude of 1.0 is called a _unit vector_.
   
To **normalize**, we just divide the vector by its magnitude:

```c++
ofVec3f vec = ofVec3f(3,3);
float length = vec.length();
ofVec3f normVec;
if (length != 0) // avoid dividing by 0!!
{
    normVec = vec / length;
}
```

`ofVec3f` has two easy built-in functions for normalizing:

```c++
ofVec3f vec = ofVec3f(3,3);

ofVec3f newVec = vec.getNormalized(); // doesn't affect vec internally

// newVec == (1,1), but vec still == (3,3)

myVec.normalize();      // normalize() alters vec

// now vec == (1,1) also

```

### Forces: Attraction / Repulsion and Damping (a.k.a. drag)

Attraction and repulsion are forces that can describe interaction **between** objects.  
These simple forces allow us to begin to create complex physics systems, where multiple objects affect each other.  

Attraction is a force based on the direction of an object to a target (the "Attractor").  
To get the direction, we **normalize** the vector between the objects:

```c++
ofVec3f dir = target.pos - mover.pos;
ofVec3f attraction = dir.getNormalized() * attractionStrength;
mover.applyForce(attraction);
```

**Repulsion** is simply the inverse:

```c++
ofVec3f dir = target.pos - mover.pos;
ofVec3f repulsion = dir.getNormalized() * -1 * repulsionStrength; // -1 inverts
mover.applyForce(repulsion);
```
    
A **damping** force slows things down.  It's also called "drag".  It creates the feeling of moving through fluid, where objects will eventually come to a stop.

We create a **damping** force by pushing on the object in the inverse-direction of its velocity:

```c++
mover.vel += mover.vel.getNormalized() * -0.01; // 0.01 damping
```



### Particle Systems

We can think of a "particle system" as simply a class that manages a collection of particle objects.  
In our case, this collection is a `vector<Particle>`.
 
The particle system takes care of creating new particles:  

```c++
particles.push_back(Particle());
```  

and removing particles when the vector is getting too large:

```c++
particles.erase(particles.begin()); // erase the first particle from the vector
```

Also note that we can give the particles a "lifespan", so that they decay over time. 




