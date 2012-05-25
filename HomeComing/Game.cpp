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
    t.appearOK = true;
    t.age = -4+rand()%20;
    cur_heroines.push_back(t);
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
  age_of_state = age_of_state->NextAge();
  enable_actions = GenerateEnableAction();
  enable_heroines = GenerateEnableHeroine();
}