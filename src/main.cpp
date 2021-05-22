#include <iostream>
#include "NSTree.hpp"
#include "NumericalSemigroup.hpp"

using namespace std;

int main(){
    NumericalSemigroup * sn = new NumericalSemigroup(set<int>({1}));
    sn->makeSonOf(1);
    sn->makeSonOf(2);
    sn->makeSonOf(3);
    for(auto x : sn->getMinimalGenerators()){
        cout << x << " ";
    }
    cout << endl;
    cout << "Condutor: " << sn->getConductor() << endl; 
    for(auto x : sn->getGapset()){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
