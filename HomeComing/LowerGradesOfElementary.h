//
//  LowerGradesOfElementary.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HomeComing_LowerGradesOfElementary_h
#define HomeComing_LowerGradesOfElementary_h

#include "GameStateAge.h"
#include <vector>
#include "Heroine.h"
#include "Action.h"


class LowerGradesOfElementary : public GameStateAge{
public:
  LowerGradesOfElementary();
  GameStateAge *NextAge();
  std::vector<Heroine> GenerateEnableHeroine(Game *game);
  std::vector<Action> GenerateEnableAction(Game *game);
  void SetSchool(School s);
  School GetSchool();
};


#endif
