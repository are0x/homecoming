//
//  GameState.h
//  first
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Action.h"
#include "Heroine.h"
#include <vector>

#ifndef first_GameStateAge_h
#define first_GameStateAge_h

class Action;

class GameStateAge
{
public:
  GameStateAge(){}
  //virtual void SetUp() = 0;
  virtual GameStateAge *NextAge() = 0;
  virtual std::vector<Heroine> GenerateEnableHeroine(std::vector<Heroine> &heroines) = 0;
  virtual std::vector<Action> GenerateEnableAction(std::vector<Action> &actions) = 0;
};

#endif
