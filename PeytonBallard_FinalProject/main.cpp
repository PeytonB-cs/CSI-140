// The Rotting Chamber - starter framework
// Commands: go, look, examine, take, drop, inventory, use, help, quit

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

// ---------------------------------------------------------------
// DATA
// ---------------------------------------------------------------

struct Item {
    string name;         // what the player types: "lighter"
    string description;  // shown when examined
    string hintText;     // shown in the room while hidden
    string roomText;     // shown in the room once revealed
    bool hidden;         // true = player can't take it yet
    string revealedBy;   // feature that reveals it, e.g. "drain"
};

struct Room {
    string name;
    string description;
    map<string, int> exits;               // direction -> room index
    map<string, string> lockedExits;      // direction -> item needed to unlock
    vector<Item> items;
    map<string, string> features;         // examinable scenery: name -> text
};

string toLower(string s) {
    for (char& c : s) c = tolower(static_cast<unsigned char>(c));
    return s;
}

// ---------------------------------------------------------------
// GAME
// ---------------------------------------------------------------

class Game {
public:
    Game() { setup(); }
    void run();

private:
    vector<Room> rooms;
    vector<Item> inventory;
    int current = 0;

    // Checkpoint: a full copy of the world, taken on entering each room
    vector<Room> savedRooms;
    vector<Item> savedInventory;
    int savedCurrent = 0;

    bool running = true;

    void setup();
    void saveCheckpoint();
    void die(const string& message);

    void handle(const string& verb, const string& rest);
    void help();
    void look();
    void go(const string& dir);
    void examine(const string& target);
    void take(const string& name);
    void drop(const string& name);
    void showInventory();
    void use(const string& rest);

    int findItem(const vector<Item>& list, const string& name, bool allowHidden);
};

// ---------------------------------------------------------------
// WORLD SETUP - add your rooms, items, and features here
// ---------------------------------------------------------------

void Game::setup() {
    // Room 0: the starting cell
    Room cell;
    cell.name = "Cell";
    cell.description =
        "You wake on a damp concrete floor, head pounding. A narrow cot sits "
        "against one wall and a rusted door stands to the north.";
    cell.features["drain"] = "A clogged iron drain, slick with grime.";
    cell.features["cot"] = "A thin, stained mattress on a bent frame.";
    cell.features["door"] = "A heavy iron door. There's a keyhole but no handle.";

    cell.items.push_back({ "lighter",
        "A dented brass lighter. It still has fuel.",
        "Something small glints near the drain.",
        "A brass lighter sits beside the drain.",
        true, "drain" });
    cell.items.push_back({ "key",
        "A small iron key, cold to the touch.",
        "Something is wedged under the cot.",
        "An iron key lies on the floor by the cot.",
        true, "cot" });

    cell.exits["north"] = 1;
    cell.exits["east"] = 2;
    cell.lockedExits["north"] = "key";   // needs the key to pass

    // Room 1A: the gas room
    Room gas;
    gas.name = "Gas Room";
    gas.description =
        "A sweet, rotten smell fills the air. Your head swims and the dark "
        "presses in on all sides.";
    gas.features["shelf"] = "Your fingers find a slick metal shelf bolted to the wall.";
    gas.items.push_back({ "note",
        "Scratched into the paper: 'He wants you to burn.'",
        "Something rustles on the shelf.",
        "A crumpled note sits on the shelf.",
        true, "shelf" });
    gas.exits["south"] = 0;

    // Room 1B: the bathroom
    Room bathroom;
    bathroom.name = "Bathroom";
    bathroom.description =
        "You step into the tiny bathroom nook and see a toilet directly in front of you filled to the brim clogged."
        "The floor drain surrounded with sediment from the toilets overflow."
        "a small vent on the ground by the toilet sits with a single screw.";
    bathroom.features["toilet"] = "you slowly reach out your arm and plunge it to bottom of the toilet... you find nothing... why did you do that?";
    bathroom.features["drain"] = "the drain is empty, but smells foul.";
    bathroom.features["vent"] = "the sinlge screw could easily be removed by a screwdriver... or even a coin";
    bathroom.items.push_back({ "flashlight",
        "A flashlight with 2 batteries" });
    bathroom.exits["west"] = 0;


    rooms.push_back(cell);
    rooms.push_back(gas);
    rooms.push_back(bathroom);

    current = 0;
    saveCheckpoint();
}

// ---------------------------------------------------------------
// CHECKPOINT + DEATH
// ---------------------------------------------------------------

void Game::saveCheckpoint() {
    savedRooms = rooms;
    savedInventory = inventory;
    savedCurrent = current;
}

void Game::die(const string& message) {
    cout << "\n" << message << "\n";
    cout << "\n... You wake up again.\n\n";
    rooms = savedRooms;
    inventory = savedInventory;
    current = savedCurrent;
    look();
}

// ---------------------------------------------------------------
// MAIN LOOP + PARSER
// ---------------------------------------------------------------

void Game::run() {
    cout << "=== THE ROTTING CHAMBER ===\n";
    cout << "(type 'help' for commands)\n\n";
    look();

    string line;
    while (running && (cout << "\n> ", getline(cin, line))) {
        line = toLower(line);
        istringstream iss(line);
        string verb, rest;
        iss >> verb;
        getline(iss >> ws, rest);   // everything after the verb
        if (verb.empty()) continue;
        handle(verb, rest);
    }
}

void Game::handle(const string& verb, const string& rest) {
    if (verb == "look" || verb == "l") look();
    else if (verb == "go" || verb == "walk") go(rest);
    else if (verb == "north" || verb == "south" || verb == "east" || verb == "west") go(verb);
    else if (verb == "n") go("north");
    else if (verb == "s") go("south");
    else if (verb == "e") go("east");
    else if (verb == "w") go("west");
    else if (verb == "examine" || verb == "x" || verb == "search") examine(rest);
    else if (verb == "take" || verb == "get" || verb == "grab") take(rest);
    else if (verb == "drop") drop(rest);
    else if (verb == "inventory" || verb == "i") showInventory();
    else if (verb == "use") use(rest);
    else if (verb == "help") help();
    else if (verb == "quit") running = false;
    else cout << "I don't understand that.\n";
}

void Game::help() {
    cout << "Commands:\n"
        << "  look                 - describe the room again\n"
        << "  examine [thing]      - inspect an item or feature (alone = closer look at room)\n"
        << "  take <item>          - pick something up\n"
        << "  drop <item>          - put something down\n"
        << "  inventory            - list what you're carrying\n"
        << "  use <item>           - use an item on its own\n"
        << "  use <item> on <thing> - use an item on something\n"
        << "  go <direction>       - move (or just type north/south/east/west)\n"
        << "  quit                 - exit the game\n";
}

// ---------------------------------------------------------------
// COMMANDS
// ---------------------------------------------------------------

int Game::findItem(const vector<Item>& list, const string& name, bool allowHidden) {
    for (size_t i = 0; i < list.size(); i++)
        if (list[i].name == name && (allowHidden || !list[i].hidden))
            return static_cast<int>(i);
    return -1;
}

void Game::look() {
    Room& r = rooms[current];
    cout << "[" << r.name << "]\n" << r.description;
    for (const Item& item : r.items)
        cout << " " << (item.hidden ? item.hintText : item.roomText);
    cout << "\nExits:";
    for (const auto& e : r.exits) cout << " " << e.first;
    cout << "\n";
}

void Game::go(const string& dir) {
    Room& r = rooms[current];
    auto exit = r.exits.find(dir);
    if (dir.empty()) { cout << "Go where?\n"; return; }
    if (exit == r.exits.end()) { cout << "You can't go that way.\n"; return; }

    if (r.lockedExits.count(dir)) {
        cout << "The way " << dir << " is locked.\n";
        return;
    }

    current = exit->second;
    saveCheckpoint();   // new room = new respawn point
    look();
}

void Game::examine(const string& target) {
    Room& r = rooms[current];

    // No target: closer look at the room
    if (target.empty()) {
        cout << r.description << "\nLooking closer, you could examine:";
        for (const auto& f : r.features) cout << " " << f.first;
        cout << "\n";
        return;
    }

    // A feature of the room (this is how hidden items get revealed)
    auto f = r.features.find(target);
    if (f != r.features.end()) {
        cout << f->second;
        for (Item& item : r.items) {
            if (item.hidden && item.revealedBy == target) {
                item.hidden = false;
                cout << " You find a " << item.name << ".";
            }
        }
        cout << "\n";
        return;
    }

    // A visible item in the room, then one in the inventory
    int idx = findItem(r.items, target, false);
    if (idx != -1) { cout << r.items[idx].description << "\n"; return; }
    idx = findItem(inventory, target, false);
    if (idx != -1) { cout << inventory[idx].description << "\n"; return; }

    cout << "You don't see anything like that.\n";
}

void Game::take(const string& name) {
    if (name.empty()) { cout << "Take what?\n"; return; }
    Room& r = rooms[current];
    int idx = findItem(r.items, name, false);   // hidden items can't be taken
    if (idx == -1) { cout << "You don't see that here.\n"; return; }

    inventory.push_back(r.items[idx]);
    r.items.erase(r.items.begin() + idx);
    cout << "You pick up the " << name << ".\n";
}

void Game::drop(const string& name) {
    if (name.empty()) { cout << "Drop what?\n"; return; }
    int idx = findItem(inventory, name, false);
    if (idx == -1) { cout << "You aren't carrying that.\n"; return; }

    Item item = inventory[idx];
    inventory.erase(inventory.begin() + idx);
    item.roomText = "A " + item.name + " lies on the floor.";   // generic text
    item.hidden = false;
    rooms[current].items.push_back(item);
    cout << "You drop the " << name << ".\n";
}

void Game::showInventory() {
    if (inventory.empty()) { cout << "You're carrying nothing.\n"; return; }
    cout << "You are carrying:\n";
    for (const Item& i : inventory) cout << "  - " << i.name << "\n";
}

// "use <item>" or "use <item> on <target>"
void Game::use(const string& rest) {
    if (rest.empty()) { cout << "Use what?\n"; return; }

    string itemName = rest, target;
    size_t pos = rest.find(" on ");
    if (pos != string::npos) {
        itemName = rest.substr(0, pos);
        target = rest.substr(pos + 4);
    }

    if (findItem(inventory, itemName, false) == -1) {
        cout << "You aren't carrying that.\n";
        return;
    }

    Room& r = rooms[current];

    // ---- PUZZLE LOGIC LIVES HERE: check item + room (+ target) ----

    // Key opens any locked exit that asks for a key
    if (itemName == "key") {
        if (target == "door" || target.empty()) {
            for (auto it = r.lockedExits.begin(); it != r.lockedExits.end(); ++it) {
                if (it->second == "key") {
                    cout << "The key turns with a heavy clunk. The way " << it->first << " is open.\n";
                    r.lockedExits.erase(it);
                    return;
                }
            }
        }
        cout << "Nothing to unlock here.\n";
        return;
    }

    // Lighter: harmless in the cell, deadly in the gas room (no warning)
    if (itemName == "lighter") {
        if (r.name == "Gas Room") {
            die("The lighter sparks. The air ignites. The last thing you feel is heat.");
        }
        else {
            cout << "The flame flickers, showing you every crack in the walls. You snuff it out.\n";
        }
        return;
    }

    cout << "Nothing happens.\n";
}

// ---------------------------------------------------------------

int main() {
    Game game;
    game.run();
    return 0;
}