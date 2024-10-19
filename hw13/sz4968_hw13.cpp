#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int GRID_SIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;
const int ANT_BREED_INTERVAL = 3;
const int DOODLEBUG_BREED_INTERVAL = 8;
const int DOODLEBUG_STARVE_INTERVAL = 3;

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char EMPTY_CELL = '-';

enum Direction { UP, DOWN, LEFT, RIGHT };

class World;

class Organism {
protected:
    int x, y, steps_survived;

public:
    Organism(int x = 0, int y = 0) : x(x), y(y), steps_survived(0) {}
    virtual ~Organism() {}

    virtual void move(World& world) = 0;
    virtual void breed(World& world) = 0;
    virtual bool is_doodlebug() const = 0;
    virtual bool is_ant() const = 0;

    int get_x() const { return x; }
    int get_y() const { return y; }
    void set_position(int new_x, int new_y) { x = new_x; y = new_y; }
    void increment_survival() { steps_survived++; }
    void reset_survival() { steps_survived = 0; }
};

class Doodlebug : public Organism {
    int steps_starved;

public:
    Doodlebug(int x, int y) : Organism(x, y), steps_starved(0) {}
    void increment_starvation() { steps_starved++; }
    void reset_starvation() { steps_starved = 0; }
    void move(World& world) override;
    void breed(World& world) override;
    bool is_doodlebug() const override { return true; }
    bool is_ant() const override { return false; }
    void starve(World& world);
};

class Ant : public Organism {
public:
    Ant(int x, int y) : Organism(x, y) {}
    void move(World& world) override;
    void breed(World& world) override;
    bool is_doodlebug() const override { return false; }
    bool is_ant() const override { return true; }
};

class World {
    Organism* grid[GRID_SIZE][GRID_SIZE];

public:
    World();
    ~World();
    Organism* get_organism(int x, int y) const { return grid[x][y]; }
    void set_organism(int x, int y, Organism* organism);
    void move_organism(int x, int y, int new_x, int new_y);
    void remove_organism(Organism* organism);
    bool is_empty(int x, int y) const { return grid[x][y] == nullptr; }
    void display() const;
    void simulate_step();
};

bool is_valid(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}

void Doodlebug::move(World& world) {
    vector<vector<int>> adjacent_ants;
    for (Direction direction : {UP, DOWN, LEFT, RIGHT}) {
        int new_x = x, new_y = y;
        switch (direction) {
            case UP: new_x = x - 1; break;
            case DOWN: new_x = x + 1; break;
            case LEFT: new_y = y - 1; break;
            case RIGHT: new_y = y + 1; break;
        }
        if (is_valid(new_x, new_y) && world.get_organism(new_x, new_y) && world.get_organism(new_x, new_y)->is_ant()) {
            adjacent_ants.push_back({new_x, new_y});
        }
    }

    if (!adjacent_ants.empty()) {
        int random_index = rand() % adjacent_ants.size();
        int new_x = adjacent_ants[random_index][0];
        int new_y = adjacent_ants[random_index][1];
        world.move_organism(x, y, new_x, new_y);
        reset_starvation();
    } else {
        Direction direction = static_cast<Direction>(rand() % 4);
        int new_x = x, new_y = y;
        switch (direction) {
            case UP: new_x = x - 1; break;
            case DOWN: new_x = x + 1; break;
            case LEFT: new_y = y - 1; break;
            case RIGHT: new_y = y + 1; break;
        }
        if (is_valid(new_x, new_y) && world.is_empty(new_x, new_y)) {
            world.move_organism(x, y, new_x, new_y);
        }
        increment_starvation();
    }
    increment_survival();
}

void Doodlebug::breed(World& world) {

    if (steps_survived >= DOODLEBUG_BREED_INTERVAL) {
        vector<vector<int>> adjacent_empty_cell;
        for (Direction direction : {UP, DOWN, LEFT, RIGHT}) {
            int new_x = x, new_y = y;
            switch (direction) {
                case UP: new_x = x - 1; break;
                case DOWN: new_x = x + 1; break;
                case LEFT: new_y = y - 1; break;
                case RIGHT: new_y = y + 1; break;
            }
            if (is_valid(new_x, new_y) && world.is_empty(new_x, new_y)) {
                adjacent_empty_cell.push_back({new_x, new_y});
            }
        }
        if (!adjacent_empty_cell.empty()) {
            int random_index = rand() % adjacent_empty_cell.size();
            int new_x = adjacent_empty_cell[random_index][0];
            int new_y = adjacent_empty_cell[random_index][1];
            world.set_organism(new_x, new_y, new Doodlebug(new_x, new_y));
            reset_survival();
        }
    }
}

void Doodlebug::starve(World& world) {
    if (steps_starved >= DOODLEBUG_STARVE_INTERVAL) {
        world.remove_organism(this);
    }
}

void Ant::move(World& world) {
    Direction direction = static_cast<Direction>(rand() % 4);
    int new_x = x, new_y = y;
    switch (direction) {
        case UP: new_x = x - 1; break;
        case DOWN: new_x = x + 1; break;
        case LEFT: new_y = y - 1; break;
        case RIGHT: new_y = y + 1; break;
    }
    if (is_valid(new_x, new_y) && world.is_empty(new_x, new_y)) {
        world.move_organism(x, y, new_x, new_y);
    }
    increment_survival();
}

void Ant::breed(World& world) {
    if (steps_survived >= ANT_BREED_INTERVAL) {
        vector<vector<int>> adjacent_empty_cell;
        for (Direction direction : {UP, DOWN, LEFT, RIGHT}) {
            int new_x = x, new_y = y;
            switch (direction) {
                case UP: new_x = x - 1; break;
                case DOWN: new_x = x + 1; break;
                case LEFT: new_y = y - 1; break;
                case RIGHT: new_y = y + 1; break;
            }
            if (is_valid(new_x, new_y) && world.is_empty(new_x, new_y)) {
                adjacent_empty_cell.push_back({new_x, new_y});
            }
        }
        if (!adjacent_empty_cell.empty()) {
            int random_index = rand() % adjacent_empty_cell.size();
            int new_x = adjacent_empty_cell[random_index][0];
            int new_y = adjacent_empty_cell[random_index][1];
            world.set_organism(new_x, new_y, new Ant(new_x, new_y));
            reset_survival();
        }
    }
}

World::World() {
    srand(time(0));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    int ant_count = 0;
    while (ant_count < INITIAL_ANTS) {
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;
        if (!grid[i][j]) {
            grid[i][j] = new Ant(i, j);
            ant_count++;
        }
    }

    int doodlebug_count = 0;
    while (doodlebug_count < INITIAL_DOODLEBUGS) {
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;
        if (!grid[i][j]) {
            grid[i][j] = new Doodlebug(i, j);
            doodlebug_count++;
        }
    }
}

World::~World() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            delete grid[i][j];
        }
    }
}

void World::set_organism(int x, int y, Organism* organism) {
    delete grid[x][y];
    grid[x][y] = organism;
    organism->set_position(x, y);
}

void World::move_organism(int x, int y, int new_x, int new_y) {
    grid[new_x][new_y] = grid[x][y];
    grid[x][y] = nullptr;
    grid[new_x][new_y]->set_position(new_x, new_y);
}

void World::remove_organism(Organism* organism) {
    grid[organism->get_x()][organism->get_y()] = nullptr;
    delete organism;
}

void World::display() const {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                cout << (grid[i][j]->is_doodlebug() ? DOODLEBUG : ANT);
            } else {
                cout << EMPTY_CELL;
            }
            cout << ' ';
        }
        cout << endl;
    }
}

void World::simulate_step() {
    vector<Organism*> organisms;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                organisms.push_back(grid[i][j]);
            }
        }
    }

    for (auto organism : organisms) {
        organism->move(*this);
    }

    for (auto organism : organisms) {
        organism->breed(*this);
    }

    for (auto organism : organisms) {
        if (organism->is_doodlebug()) {
            static_cast<Doodlebug*>(organism)->starve(*this);
        }
    }
}

int main() {
    World world;
    int time = 0;

    while (true) {
        cout << "World at time " << time << "\n\n";
        world.display();
        cout << "\nPress Enter to continue";
        cin.get();
        world.simulate_step();
        time++;
    }

    return 0;
}
