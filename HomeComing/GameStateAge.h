//
//  GameState.h
//  first
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Action.h"
#include "Heroine.h"

#ifndef first_GameStateAge_h
#define first_GameStateAge_h

class Action;

class GameStateAge
{
public:
  virtual void SetUp();
  virtual GameStateAge NextAge();
  virtual std::vector<Heroine> GenerateEnableHeroine();
  virtual std::vector<Action> GenerateEnableAction();
};

#endif
