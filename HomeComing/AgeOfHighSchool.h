//
//  AgeOfHighSchool.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HomeComing_AgeOfHighSchool_h
#define HomeComing_AgeOfHighSchool_h

#include "GameStateAge.h"
#include <vector>
#include "Heroine.h"
#include "Action.h"


class AgeOfHighSchool : public GameStateAge{
public:
  AgeOfHighSchool();
  GameStateAge *NextAge();
  std::vector<Heroine> GenerateEnableHeroine(Game *game);
  std::vector<Action> GenerateEnableAction(Game *game);
};


#endif
