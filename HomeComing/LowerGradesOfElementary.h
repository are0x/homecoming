//
//  LowerGradesOfElementary.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "GameStateAge.h"

#ifndef HomeComing_LowerGradesOfElementary_h
#define HomeComing_LowerGradesOfElementary_h

class LowerGradesOfElementary : public GameStateAge{
public:
  void SetUp();
  GameStateAge NextAge();
};


#endif
