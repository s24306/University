#include <iostream>
#include "../include/s24306/Item.h"

int main(){
    Creature monster("Dziekan", 66666666);
    Sword sword;
    Axe axe;
    Bow bow;
    Health_potion healthPotion;

    show_monster_hp(monster);

    std::cout << "Have my sword" << std::endl;
    sword.use_on(monster, sword.strength());
    show_monster_hp(monster);

    std::cout << "AND MY AXE" << std::endl;
    axe.use_on(monster,axe.strength());
    show_monster_hp(monster);

    std::cout << "Potion 1" << std::endl;
    healthPotion.use_on(monster, healthPotion.strength());
    show_monster_hp(monster);

    std::cout << "And my bow" << std::endl;
    bow.use_on(monster, bow.strength());
    show_monster_hp(monster);

    std::cout << "Potion 2" << std::endl;
    healthPotion.use_on(monster, healthPotion.strength());
    show_monster_hp(monster);

    return 0;
}
