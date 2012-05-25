#ifndef __choro3_ES_h
#define __choro3_ES_h

#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 簡易S式パーサー
// 2012-05-25 choro3

namespace choro3 {

  // 入力ストリーム中の空白を読飛ばす
  void ignore_space(std::istream& in) {
    char c;
    while((c = in.get()) && isspace(c)) ;
    in.putback(c);
  }

  // S式クラス
  class ES {
  private:

    bool is_atom; // 式はアトム（シンボル・文字列・数値）か否か
    std::string value; // アトムの場合の値
    std::vector<ES> child; // S式の要素
    
    ES(std::string v): is_atom(true), value(v) {}
    ES(): is_atom(false) {}

    // ストリームからアトムを一つ読み込む
    static ES get_token(std::istream& in) {
      ignore_space(in);
      std::string atom;
      char c = in.get();      
      if(c == '"') {
        while(in && (c = in.get()) && c != '"') atom += c;
      } else {
        in.putback(c);
        while(in && (c = in.get()) && !isspace(c)) atom += c;        
      }
      // in >> atom;
      while(atom[atom.size() - 1] == ')') {
        in.putback(')');
        atom = atom.substr(0, atom.size() - 1);
      }
      // printf("[%s]\n", atom.c_str());
      return ES(atom);
    }

    // 解析
    static ES parse(std::istream& in) {

      ignore_space(in);

      ES res;

      char c = in.get();
      if(c != '(') in.putback(c);

      while(in && (c = in.get()) != ')') {
        if(c != '(') {
          in.putback(c);
          res.child.push_back(get_token(in));
        } else {
          in.putback(c);
          res.child.push_back(parse(in));
        }
        ignore_space(in);
      }

      return res;
    }

  public:
    
    ES& operator [] (const int idx) const {
      return child[idx];
    }
    
    int length() const {
      return child.size();
    }

    // 入力ストリームからS式を読み込む
    static std::vector<ES> load(std::istream& in) {
      std::vector<ES> res;
      while(in) res.push_back(ES::parse(in));
      return res;
    }

    // S式を整形して出力する
    static void prettify(const ES& es, std::ostream& os = std::cout, int depth = 0) {
      if(es.is_atom) {
        for(int i = 0; i < depth; i++) os << "  ";
        os << es.value << std::endl;
      } else {
        for(int i = 0; i < depth; i++) os << "  ";
        os << "(" << es[0].value << std::endl;
        for(int i = 1; i < es.length(); i++)
          prettify(es[i], os, depth + 1);
        for(int i = 0; i < depth; i++) os << "  ";
        os << ")" << std::endl;
      }
    }
  };  

}

#endif
