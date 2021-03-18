#include "NumericalSemigroup.hpp"
#include "MinGenSet.hpp"
#include "GeneratorsUtils.hpp"
#include <vector>
#include <set>

using namespace std;

NumericalSemigroup::NumericalSemigroup(vector<int> gen){
    NumericalSemigroup(set<int>(gen.begin(), gen.end()));
}

NumericalSemigroup::NumericalSemigroup(int gen[], int size){
    NumericalSemigroup(set<int>(gen, gen+size));
}

NumericalSemigroup::NumericalSemigroup(set<int> gen){
    findMinimalSet(&gen);
    this->min_generators = new MinGenSet(gen);
}

NumericalSemigroup::~NumericalSemigroup(){
    delete this->min_generators;
}

set<int>  NumericalSemigroup::getApery(){

}

set<int>  NumericalSemigroup::getGapset(){

}

set<int>  NumericalSemigroup::getMinimalGenerators(){

}
