#ifndef NSTREE_HPP
#define NSTREE_HPP

#include <vector>
#include <set>
#include <unordered_map>
#include "NumericalSemigroup.hpp"
using namespace std;

class NSTree{
private:
    vector<NumericalSemigroup *> leafs;
    int goal_g, actual_g;
    void root();
    void traverse();
public:
    NSTree(int g);
    NSTree(const NSTree* t, int g);
    vector<NumericalSemigroup *> getNS();
};

#endif
