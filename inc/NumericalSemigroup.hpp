#ifndef NUMERICALSGPS_HPP
#define NUMERICALSGPS_HPP

#include "MinGenSet.hpp"
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class NumericalSemigroup{
private:
    set<int> gapset, apery;
    int f, c;
    MinGenSet* min_generators;
    void updateElements();
public:
    NumericalSemigroup(vector<int> gen);
    NumericalSemigroup(set<int> gen);
    NumericalSemigroup(int gen[], int size);
    NumericalSemigroup(const NumericalSemigroup *x);
    ~NumericalSemigroup();
    bool makeSonOf(int x);
    set<int> getApery();
    int getMultiplicity() const;
    int getConductor() const;
    set<int> getGapset();
    set<int> getMinimalGenerators();
};

#endif
