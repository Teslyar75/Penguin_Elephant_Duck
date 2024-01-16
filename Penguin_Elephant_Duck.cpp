//5) Добавить в код на слайде 5 презентации по Интерфейсам(выслана в Тимс) классы Пингвин, Слон, Утка.


#include <iostream>
#include <memory>
using namespace std;

class Animal
{
protected:
    string name;
    int kg;

public:
    Animal() = default;
    Animal(string n, int k)
    {
        name = n;
        kg = k;
    }

    virtual void Print() = 0;
    virtual ~Animal() = default;
};

struct IAnimal // интерфейс в стиле С++
{
    virtual void Eat() = 0;
    virtual void Move() = 0;
    virtual void Print() = 0;
    virtual ~IAnimal() = default;
};

struct IBird
{
    virtual void Fly() = 0;
    virtual ~IBird() = default;
};

struct ISwim
{
    virtual void Swim() = 0;
    virtual ~ISwim() = default;
};

class Cat : public Animal, public IAnimal
{
    string color;

public:
    Cat(string n, int k, string c) : Animal(n, k), color(c) {}

    void Print() override
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
        cout << "Color: " << color << "\n";
    }

    void Eat() override
    {
        cout << "Cat eats\n";
    }

    void Move() override
    {
        cout << "Cat moves\n";
    }
};

class Parrot : public Animal, public IAnimal, public IBird
{
public:
    Parrot(string n, int k) : Animal(n, k) {}

    void Print() override
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat() override
    {
        cout << "Parrot eats\n";
    }

    void Move() override
    {
        cout << "Parrot moves\n";
    }

    void Fly() override
    {
        cout << "Parrot flies\n";
    }
};


class Penguin : public Animal, public IAnimal, public ISwim
{
public:
    Penguin(string n, int k) : Animal(n, k) {}

    void Print() override
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat() override
    {
        cout << "Penguin eats\n";
    }

    void Move() override
    {
        cout << "Penguin moves\n";
    }

    void Swim() override
    {
        cout << "Penguin swims\n";
    }
};

class Elephant : public Animal, public IAnimal
{
public:
    Elephant(string n, int k) : Animal(n, k) {}

    void Print() override
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat() override
    {
        cout << "Elephant eats\n";
    }

    void Move() override
    {
        cout << "Elephant moves\n";
    }
};

class Duck : public Animal, public IAnimal, public IBird, public ISwim
{
public:
    Duck(string n, int k) : Animal(n, k) {}

    void Print() override
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat() override
    {
        cout << "Duck eats\n";
    }

    void Move() override
    {
        cout << "Duck moves\n";
    }

    void Fly() override
    {
        cout << "Duck flies\n";
    }

    void Swim() override
    {
        cout << "Duck swims\n";
    }
};

int main()
{
    IAnimal* cat = new Cat("Whiskers", 5, "gray");
    IAnimal* parrot = new Parrot("Polly", 2);
    IBird* flyingParrot = new Parrot("Peter", 3);
    ISwim* swimmingPenguin = new Penguin("Waddle", 1);
    IAnimal* elephant = new Elephant("Jumbo", 8000);
    ISwim* swimmingDuck = new Duck("Donald", 3);

    cat->Eat();
    cat->Move();
    cat->Print();

    parrot->Eat();
    parrot->Move();
    parrot->Print();

    flyingParrot->Fly();

    swimmingPenguin->Swim();

    elephant->Eat();
    elephant->Move();
    elephant->Print();

    swimmingDuck->Swim();

    delete cat;
    delete parrot;
    delete flyingParrot;
    delete swimmingPenguin;
    delete elephant;
    delete swimmingDuck;
}