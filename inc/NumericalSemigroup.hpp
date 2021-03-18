#ifndef NUMERICALSGPS_HPP
#define NUMERICALSGPS_HPP

#include "MinGenSet.hpp"
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class NumericalSemigroup{
private:
    set<int> gapset;
    MinGenSet* min_generators;
    unordered_map<int, int> apery;
public:
    NumericalSemigroup(vector<int> gen);
    NumericalSemigroup(set<int> gen);
    NumericalSemigroup(int gen[], int size);
    ~NumericalSemigroup();
    set<int> getApery();
    set<int> getGapset();
    set<int> getMinimalGenerators();
};

#endif