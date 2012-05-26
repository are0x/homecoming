//
//  Hero.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include<string>

#ifndef HomeComing_Hero_h
#define HomeComing_Hero_h


class Hero{
public:
  int visual,intel,property,human;
  int actpow,lifepow,mindpow,technicpow,luck;
  int fatalpow;
  int toku;
  int talent_visual,talent_intel,talent_property,talent_luck;
  int talent_lifepow,talent_technicpow;
  std::string name;
  int schoolid;
  
  std::string ToStr();
  int GetParamater(std::string str);
};

#endif
