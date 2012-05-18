//
// MyGame.cpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon Apr 23 18:10:08 2012 vincent lemonnier
// Last update Wed May 16 18:18:37 2012 vincent lemonnier
//

#include <stdlib.h>
#include <GL/gl.h>
#include "Camera.hpp"
#include <Image.hpp>
#include "MyGame.hpp"

#define	MAX_PARTICLES	1000		// Number Of Particles To Create
bool	keys[256];					// Array Used For The Keyboard Routine
bool	active=true;				// Window Active Flag Set To TRUE By Default
bool	fullscreen=true;			// Fullscreen Flag Set To Fullscreen Mode By Default
bool	rainbow=true;				// Rainbow Mode?
bool	sp;							// Spacebar Pressed?
bool	rp;							// Enter Key Pressed?

float	slowdown=2.0f;				// Slow Down Particles
float	xspeed;						// Base X Speed (To Allow Keyboard Direction Of Tail)
float	yspeed;						// Base Y Speed (To Allow Keyboard Direction Of Tail)
float	zoom=-40.0f;				// Used To Zoom Out

GLuint	loop;						// Misc Loop Variable
GLuint	col;						// Current Color Selection
GLuint	delay;						// Rainbow Effect Delay
GLuint	texture[1];					// Storage For Our Particle Texture

typedef struct						// Create A Structure For Particle
{
	bool	active;					// Active (Yes/No)
	float	life;					// Particle Life
	float	fade;					// Fade Speed
	float	r;						// Red Value
	float	g;						// Green Value
	float	b;						// Blue Value
	float	x;						// X Position
	float	y;						// Y Position
	float	z;						// Z Position
	float	xi;						// X Direction
	float	yi;						// Y Direction
	float	zi;						// Z Direction
	float	xg;						// X Gravity
	float	yg;						// Y Gravity
	float	zg;						// Z Gravity
}
particles;							// Particles Structure

particles particle[MAX_PARTICLES];	// Particle Array (Room For Particle Info)

static GLfloat colors[12][3]=		// Rainbow Of Colors
{
	{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
	{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
	{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};

MyGame::MyGame() : _camera(800, 600)
{

}

MyGame::~MyGame()
{

}

void	MyGame::initialize()
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
  this->_camera.initialize();
}

void	MyGame::update()
{
  gdl::Image	img = gdl::Image::load("img.bmp");
  this->_camera.update(this->gameClock_, this->input_);
  glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
  glClearColor(0.0f,0.0f,0.0f,0.0f);					// Black Background
  glClearDepth(1.0f);									// Depth Buffer Setup
  glDisable(GL_DEPTH_TEST);							// Disable Depth Testing
  glEnable(GL_BLEND);									// Enable Blending
  glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Type Of Blending To Perform
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);	// Really Nice Perspective Calculations
  glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				// Really Nice Point Smoothing
  glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
  img.bind();// Select Our Texture
  
  for (loop=0;loop<MAX_PARTICLES;loop++)				// Initials All The Textures
    {
      particle[loop].active=true;								// Make All The Particles Active
      particle[loop].life=1.0f;								// Give All The Particles Full Life
      particle[loop].fade=float(random()%100)/1000.0f+0.003f;	// Randomom Fade Speed
      particle[loop].r=colors[loop*(12/MAX_PARTICLES)][0];	// Select Red Rainbow Color
      particle[loop].g=colors[loop*(12/MAX_PARTICLES)][1];	// Select Red Rainbow Color
      particle[loop].b=colors[loop*(12/MAX_PARTICLES)][2];	// Select Red Rainbow Color
      particle[loop].xi=float((random()%50)-26.0f)*10.0f;		// Randomom Speed On X Axis
      particle[loop].yi=float((random()%50)-25.0f)*10.0f;		// Randomom Speed On Y Axis
      particle[loop].zi=float((random()%50)-25.0f)*10.0f;		// Randomom Speed On Z Axis
      particle[loop].xg=0.0f;									// Set Horizontal Pull To Zero
      particle[loop].yg=-0.8f;								// Set Vertical Pull Downward
      particle[loop].zg=0.0f;									// Set Pull On Z Axis To Zero
    }
}

void	MyGame::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  for (loop=0;loop<MAX_PARTICLES;loop++)					// Loop Through All The Particles
    {
      if (particle[loop].active)							// If The Particle Is Active
	{
	  float x=particle[loop].x;						// Grab Our Particle X Position
	  float y=particle[loop].y;						// Grab Our Particle Y Position
	  float z=particle[loop].z+zoom;					// Particle Z Pos + Zoom

	  // Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
	  glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);

	  glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
	  glTexCoord2d(1,1); glVertex3f(x+0.5f,y+0.5f,z); // Top Right
	  glTexCoord2d(0,1); glVertex3f(x-0.5f,y+0.5f,z); // Top Left
	  glTexCoord2d(1,0); glVertex3f(x+0.5f,y-0.5f,z); // Bottom Right
	  glTexCoord2d(0,0); glVertex3f(x-0.5f,y-0.5f,z); // Bottom Left
	  glEnd();										// Done Building Triangle Strip

	  particle[loop].x+=particle[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
	  particle[loop].y+=particle[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
	  particle[loop].z+=particle[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed

	  particle[loop].xi+=particle[loop].xg;			// Take Pull On X Axis Into Account
	  particle[loop].yi+=particle[loop].yg;			// Take Pull On Y Axis Into Account
	  particle[loop].zi+=particle[loop].zg;			// Take Pull On Z Axis Into Account
	  particle[loop].life-=particle[loop].fade;		// Reduce Particles Life By 'Fade'

	  if (particle[loop].life<0.0f)					// If Particle Is Burned Out
	    {
	      particle[loop].life=1.0f;					// Give It New Life
	      particle[loop].fade=float(random()%100)/1000.0f+0.003f;	// Randomom Fade Value
	      particle[loop].x=0.0f;						// Center On X Axis
	      particle[loop].y=0.0f;						// Center On Y Axis
	      particle[loop].z=0.0f;						// Center On Z Axis
	      particle[loop].xi=xspeed+float((random()%60)-32.0f);	// X Axis Speed And Direction
	      particle[loop].yi=yspeed+float((random()%60)-30.0f);	// Y Axis Speed And Direction
	      particle[loop].zi=float((random()%60)-30.0f);	// Z Axis Speed And Direction
	      particle[loop].r=colors[col][0];			// Select Red From Color Table
	      particle[loop].g=colors[col][1];			// Select Green From Color Table
	      particle[loop].b=colors[col][2];			// Select Blue From Color Table
	    }
	}
    }
  this->window_.display();
}
  
  void	MyGame::unload()
  {
    this->window_.close();
  }
