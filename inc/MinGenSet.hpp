#ifndef MINGENSET_HPP
#define MINGENSET_HPP

#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class MinGenSet{
private:
    set<int> generators;
    unordered_map<int, bool> ht;
public:
    MinGenSet(set<int> gen);
    MinGenSet(){}
    void insertGenerator();
    set<int> getGenerators();
};

#endif