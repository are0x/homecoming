//
//  LowerGradesOfElementary.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LowerGradesOfElementary.h"

using namespace std;
LowerGradesOfElementary::LowerGradesOfElementary(){
  
}
GameStateAge *LowerGradesOfElementary::NextAge(){
  GameStateAge *ret;
  return ret;
}

vector<Heroine> LowerGradesOfElementary::GenerateEnableHeroine(vector<Heroine> &heroines)
{
  vector<Heroine> ret;
  int n=(int)heroines.size();
  for(int i=0;i<n;i++){
    cout<<"name:"<<heroines[i].name<<" age:"<<heroines[i].age<<endl;
    if(6 == heroines[i].age && ( rand()%100 )+1 >= 50){
      ret.push_back(heroines[i]);
    }
    else if(4 <= heroines[i].age && heroines[i].age <= 12 && (rand()%100)+1 <= 5){
      ret.push_back(heroines[i]);
    }
  }
  for(int i=0;i<ret.size();i++){
    cout<<"name:"<<ret[i].name<<endl;
  }
  return ret;
}
vector<Action> LowerGradesOfElementary::GenerateEnableAction(vector<Action> &actions)
{
  vector<Action> ret;
  return ret;
}
