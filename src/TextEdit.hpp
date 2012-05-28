/*
 * lemonn_v
 * 12.05.2012
 */

#ifndef __TEXTEDIT_HPP__
#define __TEXTEDIT_HPP__

#include <map>
#include <vector>
#include <string>
#include <Text.hpp>
#include <GameClock.hpp>
#include <Input.hpp>

class TextEdit
{
private:
  std::string	_str;
  int		_x;
  int		_y;
  int		_size;
  size_t	_sizeMax;
  gdl::Text	_text;
  std::map<gdl::Keys::Key, std::string>	_ref;
  std::vector<double>			_timers;

public:
  TextEdit();
  TextEdit(int, int, std::string const& = "");
  ~TextEdit();

  void	update(gdl::GameClock const&, gdl::Input&);
  void	draw();

  void	setPos(int, int);
  std::string const&	getStr() const;
  void	setStr(std::string const&);
  void	setSize(int);
  int	getSize() const;
  void	setSizeMax(size_t);
};

#else

class TextEdit;

#endif
