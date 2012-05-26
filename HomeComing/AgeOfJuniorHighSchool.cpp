//
//  AgeOfJuniorHighSchool.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "AgeOfJuniorHighSchool.h"
#include <map>

using namespace std;

AgeOfJuniorHighSchool::AgeOfJuniorHighSchool(){
}
GameStateAge *AgeOfJuniorHighSchool::NextAge(){
  GameStateAge *ret;
  return ret;
}
vector<Heroine> AgeOfJuniorHighSchool::GenerateEnableHeroine(Game *game){
  vector<Heroine> ret;
  int n = (int)game->juniorhighschool_alldata.size();
  int m = (int)game->cur_heroines.size();
  map<string,int> schooltoid;
  for(int i=0;i<n;i++){
    schooltoid[game->juniorhighschool_alldata[i].name] = i;
  }
  for(int i=0;i<m;i++){
    Heroine &h = game->cur_heroines[i];
    for(int j=0;j<n;j++){
      School &jh = game->juniorhighschool_alldata[j];
      double p = 1.0;
      int o = jh.paramaters.size();
      for(int k=0;k<o;k++){
        p *= CalcProbability(h.GetParamater(jh.paramaters[k]),jh.nyus[k],jh.sigmas[k]);
      }
      if(p <= (1.0 - 1.0*rand()/RAND_MAX)){
        h.schoolid = schooltoid[jh.name];
      }
    }
    if(h.schoolid == game->cur_hero.schoolid){
      ret.push_back(h);
    }
  }
  return ret;
}
vector<Action> AgeOfJuniorHighSchool::GenerateEnableAction(Game *game){
  vector<Action> ret;
  return ret;
}