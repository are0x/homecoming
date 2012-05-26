//
//  GameState.h
//  first
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#ifndef first_GameStateAge_h
#define first_GameStateAge_h

#include "Action.h"
#include "Heroine.h"
#include <vector>
#include "Game.h"
#include "School.h"

class GameStateAge
{
  School hero_school;
public:
  GameStateAge(){}
  //virtual void SetUp() = 0;
  virtual GameStateAge *NextAge() = 0;
  virtual std::vector<Heroine> GenerateEnableHeroine(Game *game) = 0;
  virtual std::vector<Action> GenerateEnableAction(Game *game) = 0;
  void SetSchool(School s){
    hero_school = s;
  }
  School GetSchool(){
    return hero_school;
  }
};

#endif
