//
//  UpperGradesOfElementary.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/23.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "GameStateAge.h"
#include <vector>
#include "Heroine.h"
#include "Action.h"

#ifndef HomeComing_UpperGradesOfElementary_h
#define HomeComing_UpperGradesOfElementary_h

class UpperGradesOfElementary : public GameStateAge{
public:
  UpperGradesOfElementary();
  void SetUp();
  GameStateAge *NextAge();
  std::vector<Heroine> GenerateEnableHeroine();
  std::vector<Action> GenerateEnableAction();
};



#endif
