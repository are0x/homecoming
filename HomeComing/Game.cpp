//
//  Game.cpp
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <vector>
#include "Utility.h"

using namespace std;

Game::Game()
{
  //全行動ロード
  //名前辞書ロード
  firstname_alldata = loadNameDictionary("../../../../../dat/firstname_dic");
  lastname_alldata = loadNameDictionary("../../../../../dat/lastname_dic");
  //主人公初期化
  InitHero();
  //ヒロイン生成
  GenerateHeroines();
  //最初は小学校
  age_of_state = new LowerGradesOfElementary();
  enable_heroines = GenerateEnableHeroine();
  enable_actions = GenerateEnableAction();
}

Game::~Game()
{
}
void Game::InitHero(){
  cur_hero.human = rand()%100+1;
  cur_hero.intel = rand()%10+1;
  cur_hero.property = rand()%100+1;
  cur_hero.visual = rand()%10+1;
  cur_hero.actpow = rand()%10+1;
  cur_hero.luck = rand()%100+1;
  cur_hero.lifepow = rand()%10+1;
  cur_hero.technicpow = rand()%10+1;
  cur_hero.mindpow = 20+rand()%30;
  cur_hero.fatalpow = 50 + cur_hero.luck/10-5;
  
  cur_hero.talent_intel = rand()%100+1;
  cur_hero.talent_lifepow = rand()%100+1;
  cur_hero.talent_luck = rand()%100+1;
  cur_hero.talent_property = rand()%100+1;
  cur_hero.talent_technicpow = rand()%100+1;
  cur_hero.talent_visual = rand()%100+1;
}
void Game::GenerateHeroines()
{
  cur_heroines.clear();
  for(int i=0;i<cur_hero.fatalpow;i++){
    Heroine t;
    t.name = lastname_alldata[rand()%lastname_alldata.size()];
    t.name += " "+firstname_alldata[rand()%firstname_alldata.size()];
    t.human = rand()%100+1;
    t.intel = rand()%10+1;
    t.property = rand()%100+1;
    t.visual = rand()%10+1;
    t.actpow = rand()%10+1;
    t.luck = rand()%100+1;
    t.lifepow = rand()%10+1;
    t.technicpow = rand()%10+1;
    t.mindpow = 20+rand()%30;
    
    t.talent_intel = rand()%100+1;
    t.talent_lifepow = rand()%100+1;
    t.talent_luck = rand()%100+1;
    t.talent_property = rand()%100+1;
    t.talent_technicpow = rand()%100+1;
    t.talent_visual = rand()%100+1;
    
    t.appearOK = true;
    t.age = -4+rand()%20;
    cur_heroines.push_back(t);
  }
}
void Game::GrowHeroines()
{
  int n = (int)cur_heroines.size();
  for(int i=0;i<n;i++){
    Heroine &t = cur_heroines[i];
    t.intel += 3+(int)(1.0*t.talent_intel/100*5)+ (int)(-1+1.0*2*(rand()%100)/100);
    t.visual += 3+(int)(1.0*t.talent_visual/100*5)+ (int)(-1+1.0*2*(rand()%100)/100);
    if(rand()%100<=0) t.human = rand()%100;
    else if(rand()%100 <= 2) t.human += 10;
    else if(rand()%100 <= 2) t.human -= 10;
    if(rand()%100<=0) t.property = 0;
    else if(rand()%100 <= 2) t.property += 20;
    else if(rand()%100 <= 2) t.property -= 20;
    else if(rand()%100 > 50) t.property += 1;
    else if(rand()%100 < 25) t.property -= 1;
  }
}
vector<Heroine> Game::GenerateEnableHeroine()
{
 return age_of_state->GenerateEnableHeroine(cur_heroines);
}
vector<Action> Game::GenerateEnableAction()
{
 return age_of_state->GenerateEnableAction(action_alldata); 
}
void Game::NextState(){
  GrowHeroines();
  age_of_state = age_of_state->NextAge();
  enable_actions = GenerateEnableAction();
  enable_heroines = GenerateEnableHeroine();
}