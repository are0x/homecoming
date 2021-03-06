//
//  Utility.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//



#ifndef HomeComing_Utility_h
#define HomeComing_Utility_h

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

class Action;

enum Stage {NO_STAGE = 0, ELM1 = 1, ELM2 = 2, JHS = 4, HS = 8, UNV1 = 16, UNV2 = 32,
            WOK1 = 64, WOK2 = 128, WOK3 = 256, WOK4 = 512, WOK5 = 1024, WOK6 = 2048, WOK7 = 4096};

static const int STAGE_ALL = (1<<20) - 1;

static Stage toStage(std::string age_name) {
  static const std::string aname[] = {"ELM1", "ELM2", "JHS", "HS", "UNV1", "UNV2",
    "WOK1", "WOK2", "WOK3", "WOK4", "WOK5", "WOK6", "WOK7"};
  for(int i = 0; i < 13; i++) {
    if (aname[i] == age_name) {
      return (Stage)(1<<i);
    }
  }
  return NO_STAGE;
}

struct RangeNumber{
  int low,up;
  RangeNumber(int lb, int ub): low(lb), up(ub){}
  RangeNumber(): low(-INT_MAX / 3), up(INT_MAX / 3) {};
  bool operator<(const RangeNumber &r)const{
    if(r.low != low) return r.low < low;
    return r.up < up; 
  }
  bool operator != (const RangeNumber &r)const{
    return r.low != low || r.up != r.up;
  }
};

static std::string NSStringToString(NSString *str){
  std::string ret = [str UTF8String];
  return ret;
}

static NSString * StringToNSString(std::string str){
  return [[[NSString alloc] initWithCString:str.c_str() encoding:NSUTF8StringEncoding] autorelease];
}

static int StringToNum(std::string &str){
  std::stringstream ss;
  ss<<str;
  int ret;
  ss>>ret;
  return ret;
}

static std::string NumToStr(int n){
  std::stringstream ss;
  ss<<n;
  std::string ret;
  ss>>ret;
  return ret;
}

//期待値　nyu 分散 sigma の正規分布U U(p<=a)を計算する関数の近似式
static double CalcProbability(double a,double nyu,double sigma){
  double x = (a-nyu)/sqrt(sigma);
  return 1/(1+exp(-1.7*x));
}

static std::vector<std::string> loadNameDictionary(const char* path) {
  std::ifstream ifs(path);
  std::vector<std::string> res;
  std::string s;
  while(getline(ifs, s)) res.push_back(s);
  return res;
}

// [low, up] の一様分布
static double uni(const RangeNumber& r) {
  return ((double)rand() / RAND_MAX) * (r.up - r.low) + r.low;
}

/*
static double norm(const RangeNumber& r) {
  double x = ((double) rand() / RAND_MAX);
  double exp = (double)(r.up + r.low) / 2;
  double var = 1;
  return (1. / sqrt(2 * exp * var)) * exp( -(x - exp) * (x - exp) / (2. * var * var));
}*/


class ProgrammingException : public std::domain_error {
public:
  ProgrammingException(const std::string& cause)
  : std::domain_error("cause: " + cause) {}
};

#endif
