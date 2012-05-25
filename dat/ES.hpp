#ifndef __choro3_ES_h
#define __choro3_ES_h

#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace choro3 {

  void ignore_space(std::istream& in) {
    char c;
    while((c = in.get()) && isspace(c)) ;
    in.putback(c);
  }

  class ES {
  private:
    bool is_atom;
    std::string value;
    std::vector<ES> child;
    ES(std::string v): is_atom(true), value(v) {}
    ES(): is_atom(false) {}

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

    static std::vector<ES> load(std::istream& in) {
      std::vector<ES> res;
      while(in) res.push_back(ES::parse(in));
      return res;
    }

    static void prettify(const ES& es, std::ostream& os = std::cout, int depth = 0) {
      if(es.is_atom) {
        for(int i = 0; i < depth; i++) os << "  ";
        os << es.value << std::endl;
      } else {
        for(int i = 0; i < depth; i++) os << "  ";
        os << "(" << es.child[0].value << std::endl;
        for(int i = 1; i < (int)es.child.size(); i++)
          prettify(es.child[i], os, depth + 1);
        for(int i = 0; i < depth; i++) os << "  ";
        os << ")" << std::endl;
      }
    }
  };  

}

#endif
