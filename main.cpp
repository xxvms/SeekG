#include <iostream>
#include <fstream>                                          //for file stream
class Person
{
protected:
    char name[80];                                          // person name
    short age;                                              // person age
public:
    void getData()                                          // get person data
    {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }
    void showData()
    {
        std::cout << " Name: " << name;
        std::cout << " Age: " << age;
    }
};

int main() {

    Person person;                                              // create person
    std::ifstream inFile;                                       // create input output file
    inFile.open("Group.dat", std::ios::in | std::ios::binary);  // open file
    inFile.seekg(0, std::ios::end);                             // go to 0 bytes from end
    int endposition = inFile.tellg();                           //find where we are
    int n = endposition /sizeof(person);                        // number of persons
    std::cout << "There are " << n << " persons in file";

    std::cout << "Enter person number: ";
    std::cin >> n;
    int position = (n -1) * sizeof(person);                     // number times size
    inFile.seekg(position);                                     // bytes from start

    inFile.read(reinterpret_cast<char*>(&person), sizeof(person)); // read one person
    person.showData();                                           // display the person

    std::cout << std::endl;

    std::cin.get();
    return 0;
}