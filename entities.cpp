#include <iostream>
#include <time.h>
using namespace std;

class Ancestor
{ // class to create the ancestor of the avatar and the creatures
    int x, y;

public:
    Ancestor();
    Ancestor(int new_x, int new_y);
    ~Ancestor();
    void set_pos(int new_x, int new_y);
    int get_x() const;
    int get_y() const;
};

Ancestor::Ancestor()
{
}
Ancestor::Ancestor(int new_x, int new_y) : x(new_x), y(new_y)
{
}
Ancestor::~Ancestor() {}
void Ancestor::set_pos(int new_x, int new_y)
{
    this->x = new_x;
    this->y = new_y;
}
int Ancestor::get_x() const
{
    return x;
}
int Ancestor::get_y() const
{
    return y;
}

class Avatar : virtual public Ancestor
{
    int healing;
    char side;

public:
    Avatar();
    Avatar(int new_x, int new_y, char new_side);
    ~Avatar();
    void set_side(char new_side);
    char get_side() const;
    void set_healing(int new_healing);
    int get_healing() const;
};
Avatar::Avatar() : Ancestor()
{
    this->healing = 1;
}
Avatar::Avatar(int new_x, int new_y, char new_side) : Ancestor(new_x, new_y), side(new_side)
{
}
Avatar::~Avatar() {}

void Avatar::set_side(char new_side)
{ // function to set the side of the avatar
    this->side = new_side;
}
char Avatar::get_side() const
{ // function to get the side of the avatar
    return this->side;
}

void Avatar::set_healing(int new_healing)
{ // function to set the healing of the avatar
    this->healing = new_healing;
}
int Avatar::get_healing() const
{ // function to get the healing of the avatar
    return this->healing;
}

class Creatures : virtual public Ancestor
{ // class to create the creatures
    int health;
    int medical;
    int power;
    int defense;

public:
    Creatures();
    Creatures(int new_x, int new_y, int new_medical, int new_power, int new_defense);
    virtual ~Creatures();
    virtual void move(int rows, int columns);
    void set_health(int new_health);
    void set_medical(int new_medical);
    int get_health() const;
    int get_medical() const;
    int get_power() const;
    int get_defense() const;
};

Creatures::Creatures() : Ancestor()
{

    this->health = 3;
    this->medical = rand() % 3;   // random number between 0 and 2
    this->power = rand() % 3 + 1; // random number between 1 and 3

    this->defense = rand() % 2 + 1; // random number between 1 and 2
}

Creatures::Creatures(int new_x, int new_y, int new_medical, int new_power, int new_defense) : Ancestor(new_x, new_y), medical(new_medical), power(new_power), defense(new_defense)
{ // constructor with parameters
}

Creatures::~Creatures()
{
}

void Creatures::move(int rows, int columns)
{ // function to move the creatures
    int direction;

    int x = Creatures::get_x();
    int y = Creatures::get_y();
    if (x == 0)
    {
        if (y == 0)
        {
            direction = rand() % 2;
            if (direction == 0)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else
            {
                Creatures::set_pos(x + 1, y); // down
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 2;
            if (direction == 0)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else
            {
                Creatures::set_pos(x + 1, y); // down
            }
        }
        else
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else
            {
                Creatures::set_pos(x, y - 1); // left
            }
        }
    }
    else if (x == rows - 1)
    {
        if (y == 0)
        {
            direction = rand() % 2;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else
            {
                Creatures::set_pos(x, y + 1); // right
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 2;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else
            {
                Creatures::set_pos(x, y - 1); // left
            }
        }
        else
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else
            {
                Creatures::set_pos(x, y - 1); // left
            }
        }
    }
    else
    {
        if (y == 0)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else
            {
                Creatures::set_pos(x + 1, y); // down
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else
            {
                Creatures::set_pos(x, y - 1); // left
            }
        }
        else
        {
            direction = rand() % 4;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else
            {
                Creatures::set_pos(x, y - 1); // left
            }
        }
    }
}

void Creatures::set_health(int new_health)
{
    this->health = new_health;
}

void Creatures::set_medical(int new_medical)
{
    this->medical = new_medical;
}

int Creatures::get_health() const
{
    return this->health;
}
int Creatures::get_medical() const
{
    return this->medical;
}

int Creatures::get_power() const
{
    return this->power;
}

int Creatures::get_defense() const
{
    return this->defense;
}

class Werewolf : virtual public Ancestor, public Creatures
{ // class werewolf
public:
    static int w_population;
    Werewolf();
    Werewolf(int new_x, int new_y, int new_medical, int new_power, int new_defense);
    ~Werewolf();
    void move(int rows, int columns);
};

int Werewolf::w_population = 0;

Werewolf::Werewolf() : Creatures()
{
    w_population++;
}

Werewolf::Werewolf(int new_x, int new_y, int new_medical, int new_power, int new_defense) : Creatures(new_x, new_y, new_medical, new_power, new_defense)
{ // constructor
}
Werewolf::~Werewolf()
{
    w_population--;
}

void Werewolf::move(int rows, int columns)
{
    Creatures::move(rows, columns);
}

class Vampire : virtual public Ancestor, public Creatures
{ // class vampire
public:
    static int v_population;
    Vampire();
    Vampire(int new_x, int new_y, int new_medical, int new_power, int new_defense);
    ~Vampire();
    void move(int rows, int columns);
};
int Vampire::v_population = 0;
Vampire::Vampire() : Creatures()
{
    v_population++;
}
Vampire::Vampire(int new_x, int new_y, int new_medical, int new_power, int new_defense) : Creatures(new_x, new_y, new_medical, new_power, new_defense)
{ // constructor
}

Vampire::~Vampire()
{
    v_population--;
}

void Vampire::move(int rows, int columns)
{ // vampire move function
    int direction;

    int x = Creatures::get_x();
    int y = Creatures::get_y();
    if (x == 0)
    {
        if (y == 0)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else
            {
                Creatures::set_pos(x + 1, y + 1); // right down diagonal
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else
            {
                Creatures::set_pos(x + 1, y - 1); // left down  diagonal
            }
        }
        else
        {
            direction = rand() % 5;
            if (direction == 0)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else if (direction == 3)
            {
                Creatures::set_pos(x + 1, y + 1); // right down diagonal
            }
            else
            {
                Creatures::set_pos(x + 1, y - 1); // left down diagonal
            }
        }
    }
    else if (x == rows - 1)
    {
        if (y == 0)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else
            {
                Creatures::set_pos(x - 1, y + 1); // right up diagonal
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 3;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else
            {
                Creatures::set_pos(x - 1, y - 1); // left up diagonal
            }
        }
        else
        {
            direction = rand() % 5;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else if (direction == 3)
            {
                Creatures::set_pos(x - 1, y + 1); // right up diagonal
            }
            else
            {
                Creatures::set_pos(x - 1, y - 1); // left up diagonal
            }
        }
    }
    else
    {
        if (y == 0)
        {
            direction = rand() % 5;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else if (direction == 3)
            {
                Creatures::set_pos(x - 1, y + 1); // right up diagonal
            }
            else
            {
                Creatures::set_pos(x + 1, y + 1); // right down diagonal
            }
        }
        else if (y == columns - 1)
        {
            direction = rand() % 5;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else if (direction == 3)
            {
                Creatures::set_pos(x - 1, y - 1); // left up diagonal
            }
            else
            {
                Creatures::set_pos(x + 1, y - 1); // left down diagonal
            }
        }
        else
        {
            direction = rand() % 8;
            if (direction == 0)
            {
                Creatures::set_pos(x - 1, y); // up
            }
            else if (direction == 1)
            {
                Creatures::set_pos(x, y + 1); // right
            }
            else if (direction == 2)
            {
                Creatures::set_pos(x + 1, y); // down
            }
            else if (direction == 3)
            {
                Creatures::set_pos(x, y - 1); // left
            }
            else if (direction == 4)
            {
                Creatures::set_pos(x - 1, y + 1); // right up diagonal
            }
            else if (direction == 5)
            {
                Creatures::set_pos(x + 1, y + 1); // right down diagonal
            }
            else if (direction == 6)
            {
                Creatures::set_pos(x - 1, y - 1); // left up diagonal
            }
            else
            {
                Creatures::set_pos(x + 1, y - 1); // left down diagonal
            }
        }
    }
}