#include <raylib.h>

#include <iostream>
#include <complex>

bool is_inf(std::complex<double> c) {
    std::complex<double> z{};
    for (int i=0 ; i<100 ; ++i) {
        std::complex<double> prev = std::pow(z,2) + c;
        z = std::pow(z,2) + c;
        if (std::abs(z) > 2) {
            return false;
        }
//        if (std::real(z) - std::real(prev) < 0.00001 && std::imag(z) - std::imag(prev) < 0.00001) {
//            return false;
//        }
    }
    return true;
}

int main() {

    int WIDTH = 160;
    double x_min = -1.0;
    double x_max = 1.0;

    int HEIGHT = 160;
    double y_min = -1.3;
    double y_max = 1.3;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "xor");
    SetTargetFPS(2);

    #define BACKGROUND CLITERAL(Color) { 0x77, 0x45, 0x45, 0xFF }
    #define FOREGROUND CLITERAL(Color) { 0xc7, 0x45, 0x45, 0xFF }

    while (!WindowShouldClose()) {
        BeginDrawing();
        //if (IsKeyPressed(KEY_SPACE)) {
        if (true) {
            ClearBackground(BACKGROUND);
            int w = GetRenderWidth();
            int h = GetRenderHeight();
            for (int j{}; j<h; ++j) {
                for (int k{}; k<w; ++k) {
                    double re = (x_min + (k/(w/(x_max-x_min))));
                    double im = (y_min + (j/(h/(y_max-y_min))));
                    using namespace std::complex_literals;
                    std::complex<double> z = re + (im)*1i;
                    if (is_inf(z)) {
                        DrawPixel(k, j, BACKGROUND);
                    } else {
                        DrawPixel(k, j, FOREGROUND);
                    }
                }
            }
        }
        x_max -= 0.01;
        EndDrawing();
    }
/*
*/

}
