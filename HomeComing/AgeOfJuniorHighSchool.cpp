//
//  AgeOfJuniorHighSchool.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "AgeOfJuniorHighSchool.h"

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
  for(int i=0;i<n;i++){
    
  }
  return ret;
}
vector<Action> AgeOfJuniorHighSchool::GenerateEnableAction(Game *game){
  vector<Action> ret;
  return ret;
}