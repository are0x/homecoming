//
//  Game.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//



#ifndef HomeComing_Game_h
#define HomeComing_Game_h

#include "Hero.h"
#include "Heroine.h"
#include <vector>
#include <string>
#include "School.h"

class Action;
class GameStateAge;

class Game{
  std::vector<std::string> firstname_alldata;
  std::vector<std::string> lastname_alldata;
  
  void InitHero();
  void GenerateHeroines();
  std::vector<Heroine> GenerateEnableHeroine();
  std::vector<Action> GenerateEnableAction();
  
  void GrowHeroines();
public:
  std::vector<School> juniorhighschool_alldata;
  std::vector<School> university_alldata;
  std::vector<Action> action_alldata;
  
  std::vector<Hero> past_heroes;
  std::vector<Heroine> past_heroines;
  Hero cur_hero;
  GameStateAge *age_of_state;
  std::vector<Heroine> cur_heroines;
  Heroine steady;
  
  std::vector<Heroine> enable_heroines;
  std::vector<Action> enable_actions;
  
  Game();
  ~Game();
  void NextState();
};

#endif
