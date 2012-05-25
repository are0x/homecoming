//
//  Hero.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Hero.h"
#include "Utility.h"

using namespace std;

string Hero::ToStr(){
  string ret = "容姿　:"+NumToStr(visual)+"\n";
  ret += "知性　:"+NumToStr(intel)+"\n";
  ret += "資産　:"+NumToStr(property)+"\n";
  ret += "人間性:"+NumToStr(human)+"\n";
  ret += "技術　:"+NumToStr(technicpow)+"\n";
  ret += "生命力:"+NumToStr(lifepow)+"\n";
  ret += "精神力:"+NumToStr(mindpow)+"\n";
  ret += "天運　:"+NumToStr(luck)+"\n";
  ret += "行動力:"+NumToStr(actpow)+"\n";
  ret += "運命力:"+NumToStr(fatalpow)+"\n";
  return ret;
}