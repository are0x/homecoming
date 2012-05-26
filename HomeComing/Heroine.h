//
//  Heroine.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <string>
#include <vector>

#ifndef HomeComing_Heroine_h
#define HomeComing_Heroine_h

class HeroineAttr{
public:
  double appearancep;
  std::string name;
};

class Heroine{
public:
  std::string name;
  int visual,intel,property,human;
  int actpow,lifepow,mindpow,technicpow,luck;
  
  int talent_visual,talent_intel,talent_property,talent_luck;
  int talent_lifepow,talent_technicpow;
  
  std::vector<HeroineAttr> attrs;  
  int schoolid;
  int age;
  bool appearOK;
  
  std::string ToStr();
  int GetParamater(std::string &name);
  bool HaveAttr(std::string name);
};


#endif
