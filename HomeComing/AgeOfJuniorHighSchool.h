//
//  AgeOfJuniorHighSchool.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HomeComing_AgeOfJuniorHighSchool_h
#define HomeComing_AgeOfJuniorHighSchool_h

#include "GameStateAge.h"
#include <vector>
#include "Heroine.h"
#include "Action.h"


class AgeOfJuniorHighSchool : public GameStateAge{
public:
  AgeOfJuniorHighSchool();
  GameStateAge *NextAge();
  std::vector<Heroine> GenerateEnableHeroine(Game *game);
  std::vector<Action> GenerateEnableAction(Game *game);
};

#endif
