#ifndef NUMERICALSGPS_HPP
#define NUMERICALSGPS_HPP

#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class NumericalSemigroup{
private:
    set<int> gapset, apery, min_gen;
    int c;
    unordered_map<int,int> ds;
    void updateElements();
    void updateDs(int x);
    void growDs(int start, int end);
    void createDs();
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
    int getFrobenius() const;
    set<int> getGapset();
    set<int> getMinimalGenerators();
};

#endif
