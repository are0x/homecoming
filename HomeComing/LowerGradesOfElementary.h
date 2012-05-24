//
//  LowerGradesOfElementary.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "GameStateAge.h"
#include <vector>
#include "Heroine.h"
#include "Action.h"

#ifndef HomeComing_LowerGradesOfElementary_h
#define HomeComing_LowerGradesOfElementary_h

class LowerGradesOfElementary : public GameStateAge{
public:
  LowerGradesOfElementary();
  GameStateAge *NextAge();
  std::vector<Heroine> GenerateEnableHeroine(std::vector<Heroine> &heroines);
  std::vector<Action> GenerateEnableAction(std::vector<Action> &actions);
};


#endif
