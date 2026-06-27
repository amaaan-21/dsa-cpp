#include <iostream>
#include <string>

class car{
    std::string name;
    std::string color;
public:
    car(std::string name, std::string color){
        this->name= name;
        (*this).color = color;
    
    }
    std::string getName(){
        std::cout<<
        name<<"\n";
        return name;
    }
    std::string getColor(){
        std::cout<< color<<"\n";
        return color;
    }
};
int main(){

    car c1("HONDA","Silver");
    c1.getName();
    c1.getColor();


    return 0;
}