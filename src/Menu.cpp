/*
 * lemonn_v
 * 07.05.12
 */

#include <iostream>
#include <GL/gl.h>
#include <cv.h>
#include <highgui.h>
#include "Map.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "AIView.hpp"
#include "MainMenu.hpp"
#include "Menu.hpp"
#include "Sound.hpp"

Menu::Menu()
  : _game(0),
    _menu(0),
    _intro(false),
    _capture(0)
{
  this->setContentRoot("./Ressources/");
}

Menu::~Menu()
{
}

void		Menu::initialize(void)
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.setHeight(800);
  this->window_.setWidth(1600);
  this->window_.create();
  this->_menu = new MenuManager(1600, 800);
  this->_menu->initialize();

  //  this->_capture = cvCaptureFromAVI("./Ressources/video/intro.avi");
  // if (!this->_capture)
    // throw std::runtime_error("Fail to load introduction.");
  this->_intro = false; // TODO
  // Sound::getMe()->playBack(Audio::INTRO);
}

void		Menu::update(void)
{
  if (this->_intro && this->input_.isKeyDown(gdl::Keys::Escape))
  {
    cvReleaseCapture(&this->_capture);
    this->_intro = false;
  }
  else
    if (this->_game)
    {
      if (this->_game->isEOG())
      {
	this->_game->unload();
	delete this->_game;
	this->_game = 0;
      }
      else
	this->_game->update();
    }
    else if (!(this->_game = this->_menu->createGame(this->gameClock_, this->input_)))
      this->_menu->update(this->gameClock_, this->input_);
}

void		Menu::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  if (this->_intro)
  {
    IplImage*	image = cvQueryFrame(this->_capture);

    cvCvtColor(image, image, CV_BGR2RGB);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->width, image->height, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);

    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1600, 800, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1600, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1600, 800);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 800);
    glEnd();
  }
  else
  {
    if (this->_game)
      this->_game->draw();
    else
      this->_menu->draw();
  }
  this->window_.display();
}

void		Menu::unload(void)
{
  this->window_.close();
}

