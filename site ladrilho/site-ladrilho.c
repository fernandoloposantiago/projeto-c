#include <iostream>
#include <cmath>
#include <windows.h> // Para Sleep()

using namespace std;

int main() {
    float x, y;
    const float pi = 3.1416;

    system("cls");

    for (y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (x = -1.5f; x < 1.5f; x += 0.05f) {
            float z = x * x + y * y - 1;
            if ((z * z * z - x * x * y * y * y) <= 0.0f)
                cout << "\033[1;31m♥\033[0m"; // vermelho (♥)
            else
                cout << " ";
        }
        cout << endl;
    }

    Sleep(500);
    cout << "\n\n\033[1;35m  TE AMO PARA SEMPRE! 💘\033[0m\n\n";

    return 0;
}
