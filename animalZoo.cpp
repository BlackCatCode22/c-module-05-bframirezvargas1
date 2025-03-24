// animalZoo.cpp
// dh 03/05/2025
// Brenton Ramirez-Vargas
// demo for CIT-66
// below demonstrates class design, data structures, file i/o, control structures and OOP Design

#include <iostream>
#include <vector>
#include <map>
#include <string>


// Base class: Animal
class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    // Constructor
    Animal(std::string n, int a, std::string s) : name(n), age(a), species(s) {}

    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = (a >= 0) ? a : 0; } // Ensuring non-negative age
    void setSpecies(const std::string& s) { species = s; }

    // Virtual function for displaying info (Polymorphism)
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Species: " << species << std::endl;
    }

    // Virtual destructor
    virtual ~Animal() {}
};

// Derived Classes
class Hyena : public Animal {
public:
    Hyena(std::string n, int a) : Animal(n, a, "Hyena") {}

    void displayInfo() const override {
        std::cout << "[Hyena] Name: " << name << ", Age: " << age << std::endl;
    }
};

class Lion : public Animal {
public:
    Lion(std::string n, int a) : Animal(n, a, "Lion") {}

    void displayInfo() const override {
        std::cout << "[Lion] Name: " << name << ", Age: " << age << std::endl;
    }
};

class Tiger : public Animal {
public:
    Tiger(std::string n, int a) : Animal(n, a, "Tiger") {}

    void displayInfo() const override {
        std::cout << "[Tiger] Name: " << name << ", Age: " << age << std::endl;
    }
};

class Bear : public Animal {
public:
    Bear(std::string n, int a) : Animal(n, a, "Bear") {}

    void displayInfo() const override {
        std::cout << "[Bear] Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    std::vector<Animal*> zoo; // Store pointers for polymorphism
    std::map<std::string, int> speciesCount;

    // Creating instances of animals
    zoo.push_back(new Hyena("Shenzi", 4));
    zoo.push_back(new Hyena("Banzai", 5));
    zoo.push_back(new Hyena("Ed", 4));
    zoo.push_back(new Hyena("Zig", 5));
    zoo.push_back(new Hyena("Bud", 4));
    zoo.push_back(new Hyena("Lou", 5));
    zoo.push_back(new Hyena("Kamari", 4));
    zoo.push_back(new Hyena("Wema", 5));
    zoo.push_back(new Hyena("Nne", 4));
    zoo.push_back(new Hyena("Madoa", 5));
    zoo.push_back(new Hyena("Prince Nevarah", 4));


    zoo.push_back(new Tiger("Tony", 6));
    zoo.push_back(new Tiger("Tiger", 6));
    zoo.push_back(new Tiger("Amber", 6));
    zoo.push_back(new Tiger("Cosimia", 6));
    zoo.push_back(new Tiger("Cuddles", 6));
    zoo.push_back(new Tiger("Dave", 6));
    zoo.push_back(new Tiger("Jiba", 6));
    zoo.push_back(new Tiger("Rajah", 6));
    zoo.push_back(new Tiger("Rayas", 6));
    zoo.push_back(new Tiger("Ryker", 6));



    zoo.push_back(new Lion("Scar", 5));
    zoo.push_back(new Lion("Mufasa", 5));
    zoo.push_back(new Lion("Simba", 5));
    zoo.push_back(new Lion("Kiara", 6));
    zoo.push_back(new Lion("King", 5));
    zoo.push_back(new Lion("Drooper", 5));
    zoo.push_back(new Lion("Kimba", 5));
    zoo.push_back(new Lion("Nala", 5));
    zoo.push_back(new Lion("Leo", 5));
    zoo.push_back(new Lion("Samson", 5));
    zoo.push_back(new Lion("Elsa", 5));
    zoo.push_back(new Lion("Cecil", 5));


    zoo.push_back(new Bear("Yogi", 4));
    zoo.push_back(new Bear("Smokey", 4));
    zoo.push_back(new Bear("Paddington", 4));
    zoo.push_back(new Bear("Lippy", 4));
    zoo.push_back(new Bear("Bungle", 4));
    zoo.push_back(new Bear("Baloo", 4));
    zoo.push_back(new Bear("Rupert", 4));
    zoo.push_back(new Bear("Winnie the Pooh", 4));
    zoo.push_back(new Bear("Snuggles", 4));
    zoo.push_back(new Bear("Bert", 4));


    // Display animal details and count species
    std::cout << "Zoo Animal List:\n";
    for (const auto& animal : zoo) {
        animal->displayInfo();
        speciesCount[animal->getSpecies()]++; // Count species
    }

    // Display species count
    std::cout << "\nSpecies Count:\n";
    for (const auto& entry : speciesCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    // Free allocated memory
    for (auto& animal : zoo) {
        delete animal;
    }

    return 0;
}

