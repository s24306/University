#include <string>

struct Creature{
	std::string name;
	int hp;

	Creature (std::string creatureName, int creatureHP){
	    name = creatureName;
	    hp = creatureHP;
	}
};

struct Item{
	virtual void use_on(Creature&, int) = 0;
	virtual int strength() const = 0;
};

struct Weapon : Item{
	void use_on(Creature& creature, int dmg) override{
		creature.hp -= dmg;
	}
};

struct Potion : Item{
	void use_on(Creature& creature, int health) override{
		creature.hp += health;
	}

};

struct Sword : Weapon{
	int strength() const override{
		return 666;
	}
};

struct Axe : Weapon{
	int strength() const override{
         return 333;
	}
};

struct Bow : Weapon{
	int strength() const override{
          return 50;
    }
};

int potionUses = 0;

struct Health_potion : Potion{
	int strength() const override{
		potionUses += 1;
		if(potionUses >= 2){
			return 0;
		} else {
            return 1500;
        }
    }
};

void show_monster_hp(Creature& creature)
{
	std::cout << "Monster hp: " << creature.hp << "hp\n";
}
