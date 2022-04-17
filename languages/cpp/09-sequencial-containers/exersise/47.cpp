#include <iostream>
#include <string>

int main() {
    std::string numbers{"0123456789"};
    std::string characters{"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
    std::string str{"ab2c3d7R4E6"};

    auto pos_num = str.find_first_of(numbers);
    while ((pos_num = str.find_first_of(numbers, pos_num)) != std::string::npos) {
        std::cout << str[pos_num++] << " ";
    }
    std::cout << std::endl;

    auto pos_char = str.find_first_of(characters);
    while ((pos_char = str.find_first_of(characters, pos_char)) != std::string::npos) {
        std::cout << str[pos_char++] << " ";
    }
    std::cout << std::endl;
}
