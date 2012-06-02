/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __LOADING_HPP__
#define __LOADING_HPP__

#include "AMenu.hpp"

class Loading : public AMenu
{
private:
  double	_timer;
  std::vector<gdl::Model>       _model;
  
public:
  Loading(GameManager&);
  virtual ~Loading();
  
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void          initialize();
  virtual void          draw();
};

#else

class Loading;

#endif
