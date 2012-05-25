//
//  UpperGradesOfElementary.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/23.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "UpperGradesOfElementary.h"

using namespace std;

UpperGradesOfElementary::UpperGradesOfElementary()
{
  
}
GameStateAge * UpperGradesOfElementary::NextAge()
{
  GameStateAge *ret;
  return ret;
}

vector<Heroine> UpperGradesOfElementary::GenerateEnableHeroine(Game *game)
{
  vector<Heroine> ret;
  //前同じ学校だった人はアタックしてない限り必ずいる。
  //前学校にいた人は[4,11]
  //まだ卒業してない人は[7,11]
  int n = (int)game->enable_heroines.size();
  for(int i=0;i<n;i++){
    Heroine &h = game->enable_heroines[i];
    if(7<=h.age && h.age<=11 && h.appearOK) ret.push_back(h);
  }
  //[6]と新たにあえる
  n = (int)game->cur_heroines.size();
  for(int i=0;i<n;i++){
    Heroine &h = game->cur_heroines[i];
    if(h.age == 6 && rand()%100+1 <= 5 && h.appearOK) ret.push_back(h);
  }
  return ret;
}

vector<Action> UpperGradesOfElementary::GenerateEnableAction(Game *game)
{
  vector<Action> ret;
  return ret;
}