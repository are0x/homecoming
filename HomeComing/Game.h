//
//  Game.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Hero.h"
#include "Heroine.h"
#include <vector>

#ifndef HomeComing_Game_h
#define HomeComing_Game_h

class Game{
  void InitHero();
  void GenerateHeroines();
public:
  std::vector<Hero> past_heroes;
  std::vector<Heroine> past_heroines;
  Hero cur_hero;
  std::vector<Heroine> cur_heroines;
  Heroine steady;
  
  Game();
  ~Game();
};

#endif
