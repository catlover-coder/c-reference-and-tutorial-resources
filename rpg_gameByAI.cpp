#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// A simple structure to hold item data
struct Item {
    std::string name;
    std::string type; // "Heal" or "Weapon"
    int value;        // Healing power or bonus damage
};

// Base class using standard variables and methods
class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int baseDamage;

public:
    Character(std::string n, int hp, int dmg) {
        name = n;
        health = hp;
        maxHealth = hp;
        baseDamage = dmg;
    }

    std::string getName() { return name; }
    int getHealth() { return health; }
    bool isAlive() { return health > 0; }

    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
        std::cout << name << " takes " << dmg << " damage! (HP: " << health << "/" << maxHealth << ")\n";
    }

    void heal(int amount) {
        health += amount;
        if (health > maxHealth) health = maxHealth;
        std::cout << name << " heals for " << amount << "! (HP: " << health << "/" << maxHealth << ")\n";
    }

    int attack() {
        int damage = baseDamage + (std::rand() % 5);
        std::cout << name << " attacks and deals " << damage << " damage.\n";
        return damage;
    }
};

// Player class managing its own inventory array via vector
class Player : public Character {
private:
    int gold;
    std::vector<Item> inventory;

public:
    Player(std::string n) : Character(n, 100, 10) {
        gold = 50;
        
        // Add starting equipment
        Item potion = {"Minor Health Potion", "Heal", 30};
        Item sword = {"Rusty Iron Sword", "Weapon", 5};
        inventory.push_back(potion);
        inventory.push_back(sword);
    }

    void showStatus() {
        std::cout << "\n==============================\n";
        std::cout << " PLAYER STATUS: " << name << "\n";
        std::cout << " HP: " << health << "/" << maxHealth << "\n";
        std::cout << " Gold: " << gold << "g\n";
        std::cout << "==============================\n";
    }

    void showInventory() {
        std::cout << "\n--- Inventory ---\n";
        if (inventory.size() == 0) {
            std::cout << "Your inventory is empty.\n";
            return;
        }
        for (int i = 0; i < inventory.size(); ++i) {
            std::cout << i + 1 << ". " << inventory[i].name 
                      << " (" << inventory[i].type << ": +" << inventory[i].value << ")\n";
        }
    }

    void addItem(Item item) {
        inventory.push_back(item);
        std::cout << "You found a " << item.name << "!\n";
    }

    void addGold(int amount) {
        gold += amount;
        std::cout << "You gained " << amount << " gold!\n";
    }

    // Player specific attack calculation using loops
    int calculateCustomAttack() {
        int bonus = 0;
        for (int i = 0; i < inventory.size(); ++i) {
            if (inventory[i].type == "Weapon") {
                if (inventory[i].value > bonus) {
                    bonus = inventory[i].value; 
                }
            }
        }
        int totalDmg = baseDamage + bonus + (std::rand() % 6);
        std::cout << name << " swings with weapon bonus! Dealing " << totalDmg << " damage.\n";
        return totalDmg;
    }

    void useItemAction() {
        showInventory();
        if (inventory.size() == 0) return;

        std::cout << "Choose an item number to use (0 to cancel): ";
        int choice;
        std::cin >> choice;

        if (choice <= 0 || choice > inventory.size()) {
            std::cout << "Action canceled.\n";
            return;
        }

        Item chosen = inventory[choice - 1];
        if (chosen.type == "Heal") {
            heal(chosen.value);
            inventory.erase(inventory.begin() + (choice - 1)); 
        } else if (chosen.type == "Weapon") {
            std::cout << "You equip " << chosen.name << " automatically during fights.\n";
        }
    }
};

// Enemy class tracking separate reward pools
class Enemy : public Character {
private:
    int goldReward;

public:
    Enemy(std::string n, int hp, int dmg, int reward) 
        : Character(n, hp, dmg) {
        goldReward = reward;
    }

    int getGoldReward() { return goldReward; }
};

// GameManager class linking user inputs to combat outcomes
class GameManager {
private:
    Player player;
    std::vector<std::string> enemyNames;

public:
    GameManager(std::string playerName) : player(playerName) {
        enemyNames.push_back("Goblin");
        enemyNames.push_back("Orc Thief");
        enemyNames.push_back("Dark Skeleton");
        enemyNames.push_back("Feral Wolf");
    }

    Enemy spawnEnemy() {
        int index = std::rand() % enemyNames.size();
        int hp = 40 + (std::rand() % 31);   
        int dmg = 5 + (std::rand() % 6);     
        int gold = 15 + (std::rand() % 21);  
        return Enemy(enemyNames[index], hp, dmg, gold);
    }

    void combat(Enemy& enemy) {
        std::cout << "\nAn angry " << enemy.getName() << " blocks your path!\n";

        while (player.isAlive() && enemy.isAlive()) {
            player.showStatus();
            std::cout << "\nWhat will you do?\n1. Attack\n2. Use Item\n3. Run\nChoice: ";
            int action;
            std::cin >> action;

            if (action == 1) {
                enemy.takeDamage(player.calculateCustomAttack());
            } else if (action == 2) {
                player.useItemAction();
            } else if (action == 3) {
                if (std::rand() % 2 == 0) {
                    std::cout << "You successfully escaped the fight!\n";
                    return;
                } else {
                    std::cout << "Failed to escape! The monster blocks you.\n";
                }
            } else {
                std::cout << "Invalid input! You stumble around.\n";
            }

            if (enemy.isAlive()) {
                std::cout << "\n--- Enemy's Turn ---\n";
                player.takeDamage(enemy.attack());
            }
        }

        if (!player.isAlive()) {
            std::cout << "\nYou were defeated by the " << enemy.getName() << "... Game Over.\n";
        } else if (!enemy.isAlive()) {
            std::cout << "\nYou defeated the " << enemy.getName() << "!\n";
            player.addGold(enemy.getGoldReward());
            
            if ((std::rand() % 10) < 4) {
                Item superPotion = {"Super Potion", "Heal", 50};
                player.addItem(superPotion);
            }
        }
    }

    void gameLoop() {
        std::cout << "Welcome, " << player.getName() << ", to the Endless Dungeon!\n";
        
        while (player.isAlive()) {
            std::cout << "\n1. Venture Deeper\n2. Rest & Check Status\n3. Quit Game\nChoice: ";
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                Enemy currentEnemy = spawnEnemy();
                combat(currentEnemy);
            } else if (choice == 2) {
                player.showStatus();
                player.showInventory();
            } else if (choice == 3) {
                std::cout << "Thanks for playing! Goodbye.\n";
                break;
            } else {
                std::cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    std::srand(time(0));

    std::cout << "Enter your hero's name: ";
    std::string name;
    std::getline(std::cin, name);
    if (name.size() == 0) {
        name = "Unknown Hero";
    }

    GameManager game(name);
    game.gameLoop();

    return 0;
}
