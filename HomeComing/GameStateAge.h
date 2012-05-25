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
#include "Game.h"

#ifndef first_GameStateAge_h
#define first_GameStateAge_h

class Action;
class Game;

class GameStateAge
{
public:
  GameStateAge(){}
  //virtual void SetUp() = 0;
  virtual GameStateAge *NextAge() = 0;
  virtual std::vector<Heroine> GenerateEnableHeroine(Game *game) = 0;
  virtual std::vector<Action> GenerateEnableAction(Game *game) = 0;
};

#endif
