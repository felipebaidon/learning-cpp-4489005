// Learning C++ 
// Exercise 03_03
// Using Classes, by Eduardo Corpeño 

#include <iostream>
#include <string>

enum class cow_purpose {dairy, meat, hide, pet};

class cow{
public:
    cow(std::string name_i, int age_i, cow_purpose purpose_i){
        name = name_i;
        age = age_i;
        purpose = purpose_i;
    }
    std::string get_name() const{
        return name;
    }
    int get_age() const{
        return age;
    }
    cow_purpose get_purpose() const{
        return purpose;
    }

    void rename(std::string newName){
        name = newName;
    }

    void increaseAge(int newAge){
        age = newAge;
    }

    void repurpose(cow_purpose newPurpose)
    {
        purpose = newPurpose;
    }
private:
    std::string name;
    int age;
    cow_purpose purpose;
};

int main(){
    cow my_cow("Betsy", 5, cow_purpose::dairy);

    std::cout << my_cow.get_name() << " is a type-" << (int)my_cow.get_purpose() << " cow." << std::endl;
    std::cout << my_cow.get_name() << " is " << my_cow.get_age() << " years old." << std::endl;

    std::cout << my_cow.get_name() << " is now: ";
    my_cow.rename("Juana");
    std::cout << my_cow.get_name() << " and she is now: ";
    my_cow.increaseAge(6);
    std::cout << my_cow.get_age() << " years old" << ", her purpose is just to be a type- ";
    my_cow.repurpose(cow_purpose::pet);

    std::cout << (int)my_cow.get_purpose();
    std::cout << " cow" << std::endl << std::endl;
    return (0);
}
