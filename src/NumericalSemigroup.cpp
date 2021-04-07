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
    updateElements();
}

NumericalSemigroup::NumericalSemigroup(const NumericalSemigroup *x) {
    this->min_generators = new MinGenSet(x->min_generators);
}

NumericalSemigroup::~NumericalSemigroup(){
    delete this->min_generators;
}

void NumericalSemigroup::updateElements(){
    if(this->min_generators->getGenerators().count(1) == 1){
        // raiz <1>
        this->gapset = {};
        this->c = 1;
        // não tem número de frobenius
    }else{
        // TODO lógica para obter gapset, condutor, frobenius do zero
    }
}

bool  NumericalSemigroup::makeSonOf(int x){
    if(this->min_generators->getGenerators().count(x)){
        // TODO Lógica de atualização de SN como filho dele mesmo sem o X
        return true;
    }else
        return false;
}

set<int>  NumericalSemigroup::getApery(){

}

set<int>  NumericalSemigroup::getGapset(){
    return gapset;
}

int NumericalSemigroup::getMultiplicity() const{
    return * this->min_generators->getGenerators().begin();
}

int NumericalSemigroup::getConductor() const{
    return this->c;
}

set<int>  NumericalSemigroup::getMinimalGenerators(){
    return this->min_generators->getGenerators();
}
