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
  void SetUp();
  GameStateAge NextAge();
  std::vector<Heroine> GenerateEnableHeroine();
  std::vector<Action> GenerateEnableAction();
};


#endif
