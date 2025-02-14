#include <iostream>
#include <string>

struct Phone {
    std::string brand;       
    std::string model;       
    float screenSize;       
    int storageCapacity;    
    int cameraResolution;   
    bool hasNFC;            
};

void changeStorageCapacity(Phone& phone, int newCapacity) {
    phone.storageCapacity = newCapacity;
    std::cout << "Объем памяти изменен на " << newCapacity << " ГБ" << std::endl;
}

Phone createPhone(std::string brand, std::string model, float screenSize, int storageCapacity, int cameraResolution, bool hasNFC) {
    Phone newPhone;
    newPhone.brand = brand;
    newPhone.model = model;
    newPhone.screenSize = screenSize;
    newPhone.storageCapacity = storageCapacity;
    newPhone.cameraResolution = cameraResolution;
    newPhone.hasNFC = hasNFC;
    std::cout << "Объект телефона создан" << std::endl;
    return newPhone;
}

int main() {
    Phone myPhone = {"Samsung", "Galaxy S23", 6.1, 256, 50, true};

    std::cout << "Изначальный объем памяти: " << myPhone.storageCapacity << " ГБ" << std::endl;

    changeStorageCapacity(myPhone, 512);

    std::cout << "Новый объем памяти: " << myPhone.storageCapacity << " ГБ" << std::endl;

    Phone anotherPhone = createPhone("Apple", "iPhone 15", 6.1, 128, 48, false);

    std::cout << "Создан телефон: " << anotherPhone.brand << " " << anotherPhone.model << std::endl;

    return 0;
}