#include <iostream>
using namespace std;

class Weapons{
public:
    void WeaponsDescription(){
        cout << "Weapons are tools designed for combat or defense.\n";
    }
};

class HotWeapons : public Weapons{
public:
    void HotWeaponsDescription(){
        cout << "Hot Weapons use explosive materials or combustion to function.\n";
    }
};

class Bombs : public HotWeapons{
public:
    void BombsDescription(){
        cout << "Bombs explodes.\n";
    }
};

class NuclearBombs : public Bombs{
public:
    void NuclearBombsDescription(){
        cout << "Nuclear Bombs explode and use nuclear fission and fusion.\n";
    }
};

int main(void){
    NuclearBombs nb;

    cout << "Weapons Description:\n";
    nb.WeaponsDescription();
    cout << "\nHot Weapons Description:\n";
    nb.HotWeaponsDescription();
    cout << "\nBombs Description:\n";
    nb.BombsDescription();
    cout << "\nNuclear Bombs Description:\n";
    nb.NuclearBombsDescription();

    return 0;
}
