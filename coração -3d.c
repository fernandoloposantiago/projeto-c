#include <stdio.h>
#include <windows.h> // Para Sleep (no Windows)
#include <math.h>    // Para pow

int main() {
    float x, y, z;
    for (float t = 0; t < 3.14 * 2; t += 0.05) {
        system("cls");
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                x = (j - 20) / 10.0;
                y = (10 - i) / 10.0;
                z = pow(pow(x * x + y * y - 1, 3) - x * x * y * y * y, 2);

                if (z <= 0.1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        Sleep(100);
    }
    return 0;
}
