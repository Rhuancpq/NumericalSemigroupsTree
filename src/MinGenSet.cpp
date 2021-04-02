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
        return true;
    }else{
        return false;
    }
}

set<int> MinGenSet::getGenerators(){
    return this->generators;
}
