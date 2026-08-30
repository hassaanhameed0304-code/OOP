#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}

    void displayCharacter() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << endl;
    }
};

class Warrior : public Character {
protected:
    int strength;

public:
    Warrior(string n, int l, int h, int s)
        : Character(n, l, h), strength(s) {}

    void slash() {
        cout << "Warrior uses Slash!" << endl;
    }

    void displayWarrior() {
        cout << "Strength: " << strength << endl;
    }
};

class Mage : public Character {
protected:
    int intelligence;

public:
    Mage(string n, int l, int h, int i)
        : Character(n, l, h), intelligence(i) {}

    void fireball() {
        cout << "Mage casts Fireball!" << endl;
    }

    void displayMage() {
        cout << "Intelligence: " << intelligence << endl;
    }
};

class Archer : public Character {
protected:
    int dexterity;

public:
    Archer(string n, int l, int h, int d)
        : Character(n, l, h), dexterity(d) {}

    void rapidShot() {
        cout << "Archer uses Rapid Shot!" << endl;
    }

    void displayArcher() {
        cout << "Dexterity: " << dexterity << endl;
    }
};

class NPC : public Character {
public:
    NPC(string n, int l, int h) : Character(n, l, h) {}

    void behave() {
        cout << "NPC follows predefined behavior." << endl;
    }
};

class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int s, int i)
        : Warrior(n, l, h, s), Mage(n, l, h, i) {}

    void display() {
        Warrior::displayCharacter();
        displayWarrior();
        displayMage();
    }
};

int main(void) {
    Mighty m("Homelander", 10, 100, 95, 67);

    m.display();
    m.slash();
    m.fireball();

    return 0;
}