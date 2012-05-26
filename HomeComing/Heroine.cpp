//
//  Heroine.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Heroine.h"
#include "Utility.h"

using namespace std;

string Heroine::ToStr()
{
  string ret = "容姿　:"+NumToStr(visual)+"\n";
  ret += "知性　:"+NumToStr(intel)+"\n";
  ret += "資産　:"+NumToStr(property)+"\n";
  ret += "人間性:"+NumToStr(human)+"\n";
  ret += "技術　:"+NumToStr(technicpow)+"\n";
  ret += "生命力:"+NumToStr(lifepow)+"\n";
  ret += "精神力:"+NumToStr(mindpow)+"\n";
  ret += "天運　:"+NumToStr(luck)+"\n";
  ret += "行動力:"+NumToStr(actpow)+"\n";
  ret += "年齢　:"+NumToStr(age);
  return ret;
}

int Heroine::GetParamater(string &name){
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
  else throw ProgrammingException("ヒロインのパラメーター名がおかしい");
  return ret;
}
bool Heroine::HaveAttr(string name){
  int n = attrs.size();
  for(int i=0;i<n;i++){
    if(attrs[i].name == name){
      return true;
    }
  }
  return false;
}