#ifndef GENERATORSUTILS_HPP
#define GENERATORSUTILS_HPP

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> removeMultiples(set<int> *C);

void findAperry(set<int> *C);

bool testMinimality(set<int> *C, int x, unordered_map<int, bool>* ht);

void findMinimalSet(set<int> *C);

#endif