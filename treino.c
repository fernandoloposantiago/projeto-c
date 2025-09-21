#include <stdio.h>
#include <thread>
#include <chrono>

void printHeartlayer(int layer){
    std::string space(layer, ' ');
    str::cout <<"    ***       ***\n"<< space;
    std::cout << "*******     *******\n"<< space;
    std::cout << "********* *********\n" << space;
    std::cout << " ***************\n" << space;
    std::cout << "   *************\n" << space;
    std::cout << "     *********\n" << space;
    std::cout << "       *****\n" << space;
    std::cout << "        ***\n" << space;
    std::cout << "         *\n" << space;

}
int maain(){
    for(inti =10; i>=0; --i){
        printHeartlayer(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\033[H\033[J"; // Clear the console

    }
    return 0;
}