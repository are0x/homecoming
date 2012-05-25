#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct S {
  bool is_atom;
  string value;
  vector<S*> child;
  S() {}
  S(string s): is_atom(true), value(s) {}
};

void prettify(S*, int);

void ignore_space() {
  char c;
  while((c = cin.get()) && (c == ' ' || c == '\n' || c == '\t')) ;
  cin.putback(c);
}

S* get_token() {
  string atom;
  cin >> atom;
  while(atom[atom.size() - 1] == ')') {
    atom = atom.substr(0, atom.size() - 1);
    cin.putback(')');
  }
  // cout << "atom = [" << atom << "]" << endl;
  return new S(atom);
}

S* parse() {

  ignore_space();

  S* res = new S;

  char c = cin.get();
  if(c != '(') throw "invalid file format";

  while(cin && (c = cin.get()) != ')') {
    if(c != '(') {
      cin.putback(c);
      res->child.push_back(get_token());
    } else {
      cin.putback(c);
      res->child.push_back(parse());
    }
    ignore_space();
  }
  //  cout << "[parsed] ----------- " << endl;
  // prettify(res, 0);
  // cout << "[parsed] ----------- " << endl;

  return res;
}

void prettify(S* es, int depth) {
  if(es->is_atom) {
    for(int i = 0; i < depth; i++) cout << "  ";
    cout << es->value << endl;
  } else {
    for(int i = 0; i < depth; i++) cout << "  ";
    cout << "(" << es->child[0]->value << "[" << depth<< "]" << endl;// << endl;
    for(int i = 1; i < (int)es->child.size(); i++) prettify(es->child[i], depth + 1);
    for(int i = 0; i < depth; i++) cout << "  ";
    cout << ")" << endl;
  }
}

int main() {

  ios::sync_with_stdio(false);

  prettify(parse(), 0);

  return 0;
}
