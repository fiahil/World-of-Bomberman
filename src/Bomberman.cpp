/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include "Joystick.hpp"
#include "Sound.hpp"
#include "Bomberman.hpp"

Bomberman::Bomberman()
  : _game(0),
    _menu(0),
    _intro(true),
    _pause(false),
    _capture(0)
{
  this->setContentRoot("./Ressources/");
}

Bomberman::~Bomberman()
{
}

void		Bomberman::initialize(void)
{
  this->window_.setTitle("World of Bomberman");
  this->window_.setHeight(800);
  this->window_.setWidth(1600);
  this->window_.create();
  
  this->_menu = new MenuManager(1600, 800);
  this->_menu->initialize();

  this->_capture = cvCaptureFromAVI("./Ressources/video/intro.avi");
  if (!this->_capture)
    this->_intro = false;
  else
    Sound::getMe()->playBack(Audio::INTRO);
}

void		Bomberman::updateIntro(void)
{
  if (this->input_.isKeyDown(gdl::Keys::Escape))
  {
    cvReleaseCapture(&this->_capture);
    this->_intro = false;
    Sound::getMe()->stopSound(Audio::INTRO);
    Sound::getMe()->playMusic(AudioMode::MENU);
    this->_menu->initCamera();
  }
}

void		Bomberman::updateGame(void)
{
  if (this->_game->isEOG())
    {
      this->_game->unload();
      delete this->_game;
      this->_game = 0;
      this->_menu->setEOG();
      Sound::getMe()->stopMusic();
      Sound::getMe()->playMusic(AudioMode::MENU);
    }
  else if (this->_game->isPause())
    {
      this->_pause = true;
      this->_menu->setPause();
    }
  else
    this->_game->update();
}

void		Bomberman::updateBomberman(void)
{
  MyGame*	tmp;

  if (!this->_game || this->_pause)
    {
      this->_menu->update(this->gameClock_, this->input_);
      if ((tmp = this->_menu->createGame(this->gameClock_, this->input_)))
	{
	  if (this->_game)
	    {
	      this->_pause = false;
	      this->_game->unload();
	      delete this->_game;
	    }
	  Sound::getMe()->stopMusic();
	  Sound::getMe()->playMusic(AudioMode::GAME);
	  this->_game = tmp;
	}
      if (this->_menu->isResume())
	{
	  this->_pause = false;
	  this->_game->resumeGame();
	}
      if (this->_menu->isStopGame())
	{
	  this->_pause = false;
	  this->_game->unload();
	  delete this->_game;
	  this->_game = 0;
	  Sound::getMe()->stopMusic();
	  Sound::getMe()->playMusic(AudioMode::MENU);
	}
    }
}

void		Bomberman::update(void)
{
  sf::Joystick::update();
  Sound::getMe()->updateMusic();
  if (this->_intro)
    this->updateIntro();
  else if (this->_game && !this->_pause)
    this->updateGame();
  else
    this->updateBomberman();
}

void		Bomberman::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  if (this->_intro && cvGrabFrame(this->_capture))
    {
      IplImage*	image = cvRetrieveFrame(this->_capture);
      
      cvCvtColor(image, image, CV_BGR2RGB);
      gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->width,
			image->height, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);
      glEnable(GL_TEXTURE_2D);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, 1600, 800, 0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      
      glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f);
      glVertex2f(0.0f, 0.0f);
      glTexCoord2f(1.0f, 1.0f);
      glVertex2f(1600, 0.0f);
      glTexCoord2f(1.0f, 0.0f);
      glVertex2f(1600, 800);
      glTexCoord2f(0.0f, 0.0f);
      glVertex2f(0.0f, 800);
      glEnd();
    }
  else
    {
      if (this->_intro)
	{
	  cvReleaseCapture(&this->_capture);
	  this->_intro = false;
	  Sound::getMe()->stopSound(Audio::INTRO);
	  Sound::getMe()->playMusic(AudioMode::MENU);
	  this->_menu->initCamera();
	}
      else if (this->_game && !this->_pause)
	this->_game->draw();
      else
	this->_menu->draw();
    }
  this->window_.display();
}

void		Bomberman::unload(void)
{
  this->window_.close();
}