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
  double appearancep;
  std::string name;
};

class Heroine{
public:
  std::string name;
  int visual,intel,property,human;
  int actpow,lifepow,mindpow,technicpow,luck;
  
  std::vector<HeroineAttr> attrs;  
  int schoolid;
  int age;
  bool appearOK;
  
  std::string ToStr();
};


#endif
