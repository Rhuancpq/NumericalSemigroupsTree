#include "NSTree.hpp"
#include "NumericalSemigroup.hpp"
#include "MinGenSet.hpp"
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

NumericalSemigroup * son(const NumericalSemigroup* s, int x, int g){
    NumericalSemigroup * sx = new NumericalSemigroup(s);
    // TODO
}

void NSTree::traverse(){
    while(this->actual_g != this->goal_g){
        stack<NumericalSemigroup *, vector<NumericalSemigroup *>> 
        stack(this->leafs);

        this->leafs.clear();

        while(!stack.empty()){
            NumericalSemigroup* s = stack.top();
            stack.pop();

            set<int> gen = s->getMinimalGenerators();
            for(int x: gen){
                // Tem que adicionar só se for minimal e maior igual ao condutor
                // leafs.push_back(son(s, x, this->actual_g));
            }
        }
        this->actual_g++;
    }
}

vector<NumericalSemigroup *> NSTree::getNS(){
    return this->leafs;
}
