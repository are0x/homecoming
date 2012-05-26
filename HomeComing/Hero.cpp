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

int Hero::GetParamater(string str)
{
  int ret = 0;
  if(name == "容姿"){
    ret = visual;
  }
  else if(name == "知性"){
    ret = intel;
  }
  else if(name == "資産"){
    ret = property;
  }
  else if(name == "人間性"){
    ret = human;
  }
  else if(name == "技術"){
    ret = technicpow;
  }
  else if(name == "生命力"){
    ret = lifepow;
  }
  else if(name == "精神力"){
    ret = mindpow;
  }
  else if(name == "天運"){
    ret = luck;
  }
  else if(name == "行動力"){
    ret = actpow;
  }
  else throw ProgrammingException("主人公のパラメーター名がおかしい");
}