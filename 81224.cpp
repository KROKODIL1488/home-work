#include <iostream>
#include <string>

// 1
struct Rat {
    std::string name;      
    double speed;       
    double x;            
    double y;            
    std::string furColor; 
    int age;             
    bool isTrained;      
};

// 2
Rat createRat(std::string name, double speed, double initialX, double initialY, std::string furColor, int age, bool isTrained) {
    Rat newRat;
    newRat.name = name;
    newRat.speed = speed;
    newRat.x = initialX;
    newRat.y = initialY;
    newRat.furColor = furColor;
    newRat.age = age;
    newRat.isTrained = isTrained;
    return newRat;
}

// 3
void moveRat(Rat& rat, double time) {
    rat.x += rat.speed * time; 
    std::cout << rat.name << " переместилась на x=" << rat.x << std::endl;
}

// 4
void updateRat(Rat& rat, std::string newName, double newSpeed) {
    rat.name = newName;
    rat.speed = newSpeed;
    std::cout << rat.name << "'s name and speed updated." << std::endl;
}

int main() {

    Rat remy = createRat("Remy", 1.5, 0.0, 0.0, "Gray", 6, true); 

    std::cout << remy.name << " is at (" << remy.x << ", " << remy.y << ") and moves with speed " << remy.speed << " m/s." << std::endl;

    moveRat(remy, 2.0);  
    moveRat(remy, 1.0); 

    updateRat(remy, "Master Splinter", 2.0);

    std::cout << remy.name << " is at (" << remy.x << ", " << remy.y << ") and now moves with speed " << remy.speed << " m/s." << std::endl;

    return 0;
}