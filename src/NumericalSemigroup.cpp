#include "NumericalSemigroup.hpp"
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
    this->min_gen = gen;
    updateElements();
}

NumericalSemigroup::NumericalSemigroup(const NumericalSemigroup *x) {
    this->min_gen = set<int>(x->min_gen);
    this->ds = x->ds;
    this->c = x->c;
    this->gapset = x->gapset;
}

NumericalSemigroup::~NumericalSemigroup(){
    
}

void NumericalSemigroup::growDs(int start, int end){
    for (int i = start; i < end; i++){
        if(min_gen.count(i) == 1){
            this->ds[i] = 1;
            continue;
        }

        for (int j = 1; j <= i/2; j++){
            if(this->ds[j] and this->ds[i-j])
                this->ds[i]++;
        }

        if(this->ds[i] != 0){
            this->ds[i]++;
        }
    }
}

void NumericalSemigroup::updateDs(int x){
    int max_n = this->c + *min_gen.begin();
    unordered_map<int, int> new_ds(this->ds);
    for (int i = x; i < max_n; i++){
        if(this->ds[i-x]){
            new_ds[i]--;
            if(new_ds[i] == 1)
                this->min_gen.insert(i);
        }
    }
    this->ds = new_ds;
}

void NumericalSemigroup::createDs(){
    this->ds[0] = 1;
    for(auto x : this->min_gen)
        this->ds[x] = 1;

    // TODO find better upper limit
    int max_n = 3 * *min_gen.rbegin();
    for (int i = 1; i <= max_n; i++){
        if(this->min_gen.count(i) == 1){
            continue;
        }

        for (int j = 1; j <= i/2; j++){
            if(this->ds[j] and this->ds[i-j])
                this->ds[i]++;
        }

        if(this->ds[i] != 0){
            this->ds[i]++;
        }else {
            this->gapset.insert(i);
        }
    }
}

void NumericalSemigroup::updateElements(){
    if(this->min_gen.count(1) == 1){
        this->gapset = {};
        this->c = 0;
        this->ds[0] = 1;
        this->ds[1] = 1;
    }else{
        // TODO lógica para obter gapset, condutor, frobenius do zero
        this->createDs();
        this->c = *this->gapset.rbegin() + 1;
    }
}

bool  NumericalSemigroup::makeSonOf(int x){
    if(this->min_gen.count(x) and x >= this->c){
        int mult = *this->min_gen.begin();
        int start = this->c + mult;
        this->c = x+1;
        int end = x+1 + (x <= mult ? mult+1 : mult);
        this->growDs(start, end);
        if(x <= mult)
            this->min_gen.insert(mult+1);
        this->min_gen.erase(x);
        this->gapset.insert(x);
        this->updateDs(x);
        return true;
    }else
        return false;
}

set<int>  NumericalSemigroup::getApery(){
    return set<int>({});
}

set<int>  NumericalSemigroup::getGapset(){
    return gapset;
}

int NumericalSemigroup::getMultiplicity() const{
    return * this->min_gen.begin();
}

int NumericalSemigroup::getConductor() const{
    return this->c;
}

int NumericalSemigroup::getFrobenius() const{
    return this->c-1;
}

set<int>  NumericalSemigroup::getMinimalGenerators(){
    return this->min_gen;
}
