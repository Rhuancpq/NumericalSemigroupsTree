#include "MinGenSet.hpp"
#include "GeneratorsUtils.hpp"
#include <set>


MinGenSet::MinGenSet(set<int> gen){
    // Presumes gen is a minimal generating system by itself
    this->ht = removeMultiples(&gen);
    this->generators = gen;
}

bool MinGenSet::insertGenerator(int x){
    if(testMinimality(&this->generators, x, &this->ht)){
        this->generators.insert(x);
        int max = *this->generators.rbegin();
        for (int i = x; i <= max; i += x)                 
            this->ht[i] = true;
        return true;
    }else{
        return false;
    }
}

void MinGenSet::removeGenerator(int x){
    int max = *this->generators.rbegin();
    for (int i = 1; i <= max/x; i++){
        if(this->generators.count(i) != 0)
            continue;
        this->ht[i*x] = false;
    }                 
    this->generators.erase(x);
}

set<int> MinGenSet::getGenerators(){
    return this->generators;
}

MinGenSet::MinGenSet(const MinGenSet *min){
    this->generators = set<int>(min->generators);
    this->ht = unordered_map<int, bool>(min->ht);
}
