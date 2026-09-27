#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>  // for exit()

// Robot state
struct Robot {
    int x = 0, y = 0;           // position
    std::string direction = "north"; // north, south, east, west
    std::string inventory[5];   // max 5 items
    int invCount = 0;
    int health = 100;
};

void showStatus(const Robot& bot) {
    std::cout << "Position: (" << bot.x << ", " << bot.y 
              << ")  Direction: " << bot.direction 
              << "  Health: " << bot.health << "\nInventory: ";
    if (bot.invCount == 0) std::cout << "empty";
    else for (int i = 0; i < bot.invCount; ++i) 
        std::cout << bot.inventory[i] << " ";
    std::cout << "\n";
}

void moveRobot(Robot& bot, int distance, const std::string& dir) {
    // Use the robot's current direction if dir is empty (from "walk 5")
    std::string actualDir = dir.empty() ? bot.direction : dir;
    int dx = 0, dy = 0;
    if (actualDir == "north") dy = distance;
    else if (actualDir == "south") dy = -distance;
    else if (actualDir == "east") dx = distance;
    else if (actualDir == "west") dx = -distance;
    else {
        std::cout << "Unknown direction '" << actualDir << "'\n";
        return;
    }
    bot.x += dx;
    bot.y += dy;
    std::cout << "Moving " << actualDir << " " << distance << " meters......\n";
}

int main() {
    Robot bot;
    // Array of command examples (just for help)
    const char* examples[] = {
        "walk 10", "walk 5 north", "run 3 east",
        "turn left", "turn right", "turn around",
        "jump", "stop", "look", "grab rock", "drop rock",
        "inventory", "status", "help", "exit"
    };
    int numExamples = 15;

    std::string input;
    std::cout << "===== ROBOT COMMANDER =====\n";
    std::cout << "I understand many commands. Type 'help' to see examples.\n\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input.empty()) continue;

        // Regex patterns (case‑insensitive)
        std::regex walkRunRegex(R"((walk|run)\s+(\d+(?:\.\d+)?)\s*(north|south|east|west|forward|back|left|right)?)", std::regex::icase);
        std::regex turnRegex(R"(turn\s+(left|right|around|north|south|east|west))", std::regex::icase);
        std::regex jumpRegex(R"(jump)", std::regex::icase);
        std::regex stopRegex(R"(stop)", std::regex::icase);
        std::regex lookRegex(R"(look|scan)", std::regex::icase);
        std::regex grabRegex(R"(grab\s+(.+))", std::regex::icase);
        std::regex dropRegex(R"(drop\s+(.+))", std::regex::icase);
        std::regex inventoryRegex(R"(inventory|inv)", std::regex::icase);
        std::regex statusRegex(R"(status|health|pos)", std::regex::icase);
        std::regex helpRegex(R"(help|\?)", std::regex::icase);
        std::regex exitRegex(R"(exit|quit)", std::regex::icase);

        std::smatch matches;

        // 1. Walk / Run (with optional direction)
        if (std::regex_match(input, matches, walkRunRegex)) {
            std::string action = matches[1];
            double dist = std::stod(matches[2]);
            std::string dir;
            if (matches.size() > 3 && matches[3].matched)
                dir = matches[3];
            // Convert "forward/back/left/right" to absolute direction
            if (dir == "forward") dir = bot.direction;
            else if (dir == "back") {
                if (bot.direction == "north") dir = "south";
                else if (bot.direction == "south") dir = "north";
                else if (bot.direction == "east") dir = "west";
                else dir = "east";
            }
            else if (dir == "left") {
                if (bot.direction == "north") dir = "west";
                else if (bot.direction == "south") dir = "east";
                else if (bot.direction == "east") dir = "north";
                else dir = "south";
            }
            else if (dir == "right") {
                if (bot.direction == "north") dir = "east";
                else if (bot.direction == "south") dir = "west";
                else if (bot.direction == "east") dir = "south";
                else dir = "north";
            }
            moveRobot(bot, static_cast<int>(dist), dir);
            if (action == "run") 
                std::cout << "(Running fast!)\n";
        }
        // 2. Turn
        else if (std::regex_match(input, matches, turnRegex)) {
            std::string param = matches[1];
            if (param == "left") {
                if (bot.direction == "north") bot.direction = "west";
                else if (bot.direction == "west") bot.direction = "south";
                else if (bot.direction == "south") bot.direction = "east";
                else bot.direction = "north";
                std::cout << "Turning left...... Now facing " << bot.direction << "\n";
            }
            else if (param == "right") {
                if (bot.direction == "north") bot.direction = "east";
                else if (bot.direction == "east") bot.direction = "south";
                else if (bot.direction == "south") bot.direction = "west";
                else bot.direction = "north";
                std::cout << "Turning right...... Now facing " << bot.direction << "\n";
            }
            else if (param == "around") {
                if (bot.direction == "north") bot.direction = "south";
                else if (bot.direction == "south") bot.direction = "north";
                else if (bot.direction == "east") bot.direction = "west";
                else bot.direction = "east";
                std::cout << "Turning around...... Now facing " << bot.direction << "\n";
            }
            else { // absolute direction: turn north etc.
                bot.direction = param;
                std::cout << "Rotating to face " << param << "......\n";
            }
        }
        // 3. Jump
        else if (std::regex_match(input, jumpRegex)) {
            std::cout << "Jumping......\n";
        }
        // 4. Stop
        else if (std::regex_match(input, stopRegex)) {
            std::cout << "Stopping all movement......\n";
        }
        // 5. Look / Scan
        else if (std::regex_match(input, lookRegex)) {
            std::cout << "Looking around... You see:\n";
            std::cout << "- A path to the " << bot.direction << "\n";
            std::cout << "- Some rocks and debris\n";
            if (bot.x == 0 && bot.y == 0)
                std::cout << "- Your starting point\n";
        }
        // 6. Grab an object
        else if (std::regex_match(input, matches, grabRegex)) {
            std::string item = matches[1];
            if (bot.invCount >= 5) {
                std::cout << "Inventory full! Drop something first.\n";
            } else {
                bot.inventory[bot.invCount++] = item;
                std::cout << "Grabbed " << item << "......\n";
            }
        }
        // 7. Drop an object
        else if (std::regex_match(input, matches, dropRegex)) {
            std::string item = matches[1];
            int index = -1;
            for (int i = 0; i < bot.invCount; ++i) {
                if (bot.inventory[i] == item) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                std::cout << "You don't have " << item << " in inventory.\n";
            } else {
                // shift left
                for (int i = index; i < bot.invCount - 1; ++i)
                    bot.inventory[i] = bot.inventory[i+1];
                bot.invCount--;
                std::cout << "Dropped " << item << "......\n";
            }
        }
        // 8. Show inventory
        else if (std::regex_match(input, inventoryRegex)) {
            std::cout << "Inventory: ";
            if (bot.invCount == 0) std::cout << "empty\n";
            else {
                for (int i = 0; i < bot.invCount; ++i)
                    std::cout << bot.inventory[i] << " ";
                std::cout << "\n";
            }
        }
        // 9. Status / Health / Position
        else if (std::regex_match(input, statusRegex)) {
            showStatus(bot);
        }
        // 10. Help
        else if (std::regex_match(input, helpRegex)) {
            std::cout << "Available commands:\n";
            for (int i = 0; i < numExamples; ++i)
                std::cout << "  " << examples[i] << "\n";
            std::cout << "\nNotes:\n";
            std::cout << " - 'walk 10' moves forward 10m (uses current facing)\n";
            std::cout << " - 'walk 5 north' overrides direction\n";
            std::cout << " - 'grab rock' adds 'rock' to inventory\n";
            std::cout << " - 'drop rock' removes it\n";
        }
        // 11. Exit
        else if (std::regex_match(input, exitRegex)) {
            std::cout << "Shutting down. Goodbye!\n";
            break;
        }
        // Unknown command
        else {
            std::cout << "I don't understand. Type 'help' for examples.\n";
        }
    }
    return 0;
}