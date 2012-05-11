/***********************************************************************
 * Module:  APlayer.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:17 PM
 * Purpose: Declaration of the class APlayer
 ***********************************************************************/

#if !defined(__Bomberman_APlayer_h)
#define __Bomberman_APlayer_h

#include <AObj.h>

class APlayer : public AObj
{
public:
  APlayer();
  virtual ~APlayer();
  virtual void play(void)=0;
  void takeDamage(Point origin, Pattern pattern);
  virtual void initialize(void);
  virtual void draw(void);
  virtual void update(gdl::GameClock const& clock, gdl::Input& input);
  void		setPv(int);
  int		getPv() const;
  void		setWeapon(eBomb);
  eBomb		getWeapon() const;
  void		setTeam(size_t);
  size_t	getTeam() const;
  void		setId(size_t);
  size_t	getId() const;
  void		setState(eState);
  eState	getState() const;
  void		setName(std::string const&);
  std::string const&	getName() const;
  
protected:
   int _pv;
   eBomb _weapon;
   eSkin _skin;
   size_t _team;
   size_t _id;
   eState _state;
   std::map<eBomb, fBomb> _bombEffect;
   std::map<eBonus, fBonus> _bonusEffect;
   gdl::Model _model;
   std::string _name;

private:
   APlayer(const APlayer& oldAPlayer);


};

#endif
