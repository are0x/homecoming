//
//  Action.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "Utility.h"
#include <string>

#ifndef HomeComing_Action_h
#define HomeComing_Action_h

class Action{
public:
  std::string name;
  int consume_actpow;//必要行動力
  //変動の範囲
  RangeNumber visual,intel,human,property;
  RangeNumber actpow,lifepow,mindpow,technicpow,luck;
};

#endif
