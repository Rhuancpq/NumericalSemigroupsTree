#include "NSTree.hpp"
#include "NumericalSemigroup.hpp"
#include <set>
#include <stack>

using namespace std;

NSTree::NSTree(int g){
    this->actual_g = 0;
    this->goal_g = g;
    this->root();
    this->traverse();
}

NSTree::NSTree(const NSTree* t, int g){
    if(t->goal_g > g)
        return;
    this->actual_g = t->goal_g;
    this->goal_g = g;
    for(auto x: t->leafs){
        this->leafs.push_back(new NumericalSemigroup(x));
    }
    this->traverse();
}

void NSTree::root(){
    set<int> s;
    s.insert(1);
    NumericalSemigroup* sn = new NumericalSemigroup(s);
    this->leafs.push_back(sn);
}

NumericalSemigroup * son(const NumericalSemigroup* s, int x){
    NumericalSemigroup * sx = new NumericalSemigroup(s);
    sx->makeSonOf(x);
    return sx;
}

void NSTree::traverse(){
    while(this->actual_g != this->goal_g){
        vector<NumericalSemigroup *> new_leafs;

        for(auto x : this->leafs){
            set<int> gen = x->getMinimalGenerators();
            for(int gi: gen){
                // Tem que adicionar só se for minimal e maior igual ao condutor
                // leafs.push_back(son(s, x, this->actual_g));
                if (gi >= x->getConductor()){
                    new_leafs.push_back(son(x, gi));
                }
            }
        }
        this->actual_g++;
        this->leafs = new_leafs;
    }
}

vector<NumericalSemigroup *> NSTree::getNS(){
    return this->leafs;
}
