//
//  Game.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Hero.h"
#include "Heroine.h"
#include "Action.h"
#include "LowerGradesOfElementary.h"
#include <vector>

#ifndef HomeComing_Game_h
#define HomeComing_Game_h

class Action;

class Game{
  std::vector<Action> action_alldata;
  
  void InitHero();
  void GenerateHeroines();
  std::vector<Heroine> GenerateEnableHeroine();
  std::vector<Action> GenerateEnableAction();
public:
  std::vector<Hero> past_heroes;
  std::vector<Heroine> past_heroines;
  Hero cur_hero;
  GameStateAge age_of_state;
  std::vector<Heroine> cur_heroines;
  Heroine steady;
  
  std::vector<Heroine> enable_heroines;
  std::vector<Action> enable_actions;
  
  Game();
  ~Game();
  void NextState();
};

#endif
