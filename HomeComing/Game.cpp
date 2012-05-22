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

Game::Game()
{
  //主人公初期化
  InitHero();
  //ヒロイン生成
  GenerateHeroines();
  
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
  cur_hero.fatalpow = 50 + cur_hero.luck/10-5;
}
void Game::GenerateHeroines()
{
  cur_heroines.clear();
  int n = 100000;
  int cnt = 0;
  for(int i=0;i<n;i++){
    double p = rand()*1.0/RAND_MAX;
    Heroine t;
    t.human = rand()%100+1;
    t.intel = rand()%10+1;
    t.property = rand()%100+1;
    t.visual = rand()%10+1;
    t.actpow = rand()%10+1;
    t.luck = rand()%100+1;
    t.lifepow = rand()%10+1;
    t.technicpow = rand()%10+1;
    if (cnt < cur_hero.fatalpow && p >= 1.0*cur_hero.fatalpow/n){
      cnt++;
      t.appearOK = true;
    }
    else t.appearOK = false;
  }
}