//
//  LowerGradesOfElementary.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LowerGradesOfElementary.h"
#include "UpperGradesOfElementary.h"

using namespace std;
LowerGradesOfElementary::LowerGradesOfElementary(){
  
}
GameStateAge *LowerGradesOfElementary::NextAge(){
  GameStateAge *ret;
  ret = new UpperGradesOfElementary();
  return ret;
}

vector<Heroine> LowerGradesOfElementary::GenerateEnableHeroine(Game *game)
{
  vector<Heroine> ret;
  int n=(int)game->cur_heroines.size();
  for(int i=0;i<n;i++){
    Heroine &h = game->cur_heroines[i];
    if(6 == h.age && ( rand()%100 )+1 >= 50){
      ret.push_back(h);
    }
    else if(4 <= h.age && h.age <= 11 && (rand()%100)+1 <= 5){
      ret.push_back(h);
    }
  }
  return ret;
}
vector<Action> LowerGradesOfElementary::GenerateEnableAction(Game *game)
{
  vector<Action> ret;
  int n = (int)game->action_alldata.size();
  for(int i=0;i<n;i++){
    Action &a = game->action_alldata[i];
    if(a.IsEnable(ELM1,game)) ret.push_back(a);
  }
  for(int i=0;i<ret.size();i++){
    print_act( ret[i] );
  }
  return ret;
}

