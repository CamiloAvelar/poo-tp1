#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Util {
  public:
    static const vector<string> explode(const string&, const char&);
    static const string toLowerCase(const string&);
    static const int waitForAction(const int);
    static const int displayAction();
    static const int getAction();
};

#endif