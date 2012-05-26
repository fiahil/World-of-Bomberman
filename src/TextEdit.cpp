/*
 * lemonn_v
 * 12.05.2012
 */

#include "TextEdit.hpp"

TextEdit::TextEdit()
  : _str(""), _x(0), _y(0), _size(20)
{
  this->_ref[gdl::Keys::A] = "a";
  this->_ref[gdl::Keys::B] = "b";
  this->_ref[gdl::Keys::C] = "c";
  this->_ref[gdl::Keys::D] = "d";
  this->_ref[gdl::Keys::E] = "e";
  this->_ref[gdl::Keys::F] = "f";
  this->_ref[gdl::Keys::G] = "g";
  this->_ref[gdl::Keys::H] = "h";
  this->_ref[gdl::Keys::I] = "i";
  this->_ref[gdl::Keys::J] = "j";
  this->_ref[gdl::Keys::K] = "k";
  this->_ref[gdl::Keys::L] = "l";
  this->_ref[gdl::Keys::M] = "m";
  this->_ref[gdl::Keys::N] = "n";
  this->_ref[gdl::Keys::O] = "o";
  this->_ref[gdl::Keys::P] = "p";
  this->_ref[gdl::Keys::Q] = "q";
  this->_ref[gdl::Keys::R] = "r";
  this->_ref[gdl::Keys::S] = "s";
  this->_ref[gdl::Keys::T] = "t";
  this->_ref[gdl::Keys::U] = "u";
  this->_ref[gdl::Keys::V] = "v";
  this->_ref[gdl::Keys::W] = "w";
  this->_ref[gdl::Keys::X] = "x";
  this->_ref[gdl::Keys::Y] = "y";
  this->_ref[gdl::Keys::Z] = "z";
  this->_ref[gdl::Keys::Num0] = "0";
  this->_ref[gdl::Keys::Num1] = "1";
  this->_ref[gdl::Keys::Num2] = "2";
  this->_ref[gdl::Keys::Num3] = "3";
  this->_ref[gdl::Keys::Num4] = "4";
  this->_ref[gdl::Keys::Num5] = "5";
  this->_ref[gdl::Keys::Num6] = "6";
  this->_ref[gdl::Keys::Num7] = "7";
  this->_ref[gdl::Keys::Num8] = "8";
  this->_ref[gdl::Keys::Num9] = "9";
  this->_ref[gdl::Keys::Numpad0] = "0";
  this->_ref[gdl::Keys::Numpad1] = "1";
  this->_ref[gdl::Keys::Numpad2] = "2";
  this->_ref[gdl::Keys::Numpad3] = "3";
  this->_ref[gdl::Keys::Numpad4] = "4";
  this->_ref[gdl::Keys::Numpad5] = "5";
  this->_ref[gdl::Keys::Numpad6] = "6";
  this->_ref[gdl::Keys::Numpad7] = "7";
  this->_ref[gdl::Keys::Numpad8] = "8";
  this->_ref[gdl::Keys::Numpad9] = "9";
  this->_ref[gdl::Keys::Space] = " ";
}

TextEdit::TextEdit(int x, int y, std::string const& str)
  : _str(str), _x(x), _y(y), _size(20)
{
  this->_ref[gdl::Keys::A] = "a";
  this->_ref[gdl::Keys::B] = "b";
  this->_ref[gdl::Keys::C] = "c";
  this->_ref[gdl::Keys::D] = "d";
  this->_ref[gdl::Keys::E] = "e";
  this->_ref[gdl::Keys::F] = "f";
  this->_ref[gdl::Keys::G] = "g";
  this->_ref[gdl::Keys::H] = "h";
  this->_ref[gdl::Keys::I] = "i";
  this->_ref[gdl::Keys::J] = "j";
  this->_ref[gdl::Keys::K] = "k";
  this->_ref[gdl::Keys::L] = "l";
  this->_ref[gdl::Keys::M] = "m";
  this->_ref[gdl::Keys::N] = "n";
  this->_ref[gdl::Keys::O] = "o";
  this->_ref[gdl::Keys::P] = "p";
  this->_ref[gdl::Keys::Q] = "q";
  this->_ref[gdl::Keys::R] = "r";
  this->_ref[gdl::Keys::S] = "s";
  this->_ref[gdl::Keys::T] = "t";
  this->_ref[gdl::Keys::U] = "u";
  this->_ref[gdl::Keys::V] = "v";
  this->_ref[gdl::Keys::W] = "w";
  this->_ref[gdl::Keys::X] = "x";
  this->_ref[gdl::Keys::Y] = "y";
  this->_ref[gdl::Keys::Z] = "z";
  this->_ref[gdl::Keys::Num0] = "0";
  this->_ref[gdl::Keys::Num1] = "1";
  this->_ref[gdl::Keys::Num2] = "2";
  this->_ref[gdl::Keys::Num3] = "3";
  this->_ref[gdl::Keys::Num4] = "4";
  this->_ref[gdl::Keys::Num5] = "5";
  this->_ref[gdl::Keys::Num6] = "6";
  this->_ref[gdl::Keys::Num7] = "7";
  this->_ref[gdl::Keys::Num8] = "8";
  this->_ref[gdl::Keys::Num9] = "9";
  this->_ref[gdl::Keys::Numpad0] = "0";
  this->_ref[gdl::Keys::Numpad1] = "1";
  this->_ref[gdl::Keys::Numpad2] = "2";
  this->_ref[gdl::Keys::Numpad3] = "3";
  this->_ref[gdl::Keys::Numpad4] = "4";
  this->_ref[gdl::Keys::Numpad5] = "5";
  this->_ref[gdl::Keys::Numpad6] = "6";
  this->_ref[gdl::Keys::Numpad7] = "7";
  this->_ref[gdl::Keys::Numpad8] = "8";
  this->_ref[gdl::Keys::Numpad9] = "9";
  this->_ref[gdl::Keys::Space] = " ";
}

TextEdit::~TextEdit()
{

}

void	TextEdit::update(gdl::Input& input)
{
  for (std::map<gdl::Keys::Key, std::string>::iterator it = this->_ref.begin(); it != this->_ref.end(); ++it)
    if (input.isKeyDown(it->first))
      this->_str += it->second;
  if (input.isKeyDown(gdl::Keys::Back))
    this->_str.resize(this->_str.size() - 1);
}

void	TextEdit::draw()
{
  this->_text.setText(this->_str);
  this->_text.setSize(this->_size);
  this->_text.setPosition(this->_x, this->_y);
  this->_text.draw();
}

void	TextEdit::setPos(int x, int y)
{
  this->_x = x;
  this->_y = y;
}

std::string const&	TextEdit::getStr() const
{
  return this->_str;
}

void	TextEdit::setStr(std::string const& str)
{
  this->_str = str;
}

void	TextEdit::setSize(int size)
{
  this->_size = size;
}

int	TextEdit::getSize() const
{
  return this->_size;
}
