#include "MinGenSet.hpp"
#include "GeneratorsUtils.hpp"
#include <set>


MinGenSet::MinGenSet(set<int> gen){
    // Presumes gen is a minimal generating system by itself
    this->ht = removeMultiples(&gen);
    this->generators = gen;
}

void MinGenSet::insertGenerator(){

}

set<int> MinGenSet::getGenerators(){

}
