/*
For compiling this code, you need to build the Halide tree which is available on https://halide-lang.org/
Run these 2 commands to get the required result:
 g++ halide_tile*.cpp -g -I /home/dalviubaid02/Downloads/halide_build/include/ -I /home/dalviubaid02/Downloads/halide_build/distrib/tools/ -L /home/dalviubaid02/Downloads/halide_build/distrib/lib/ -lHalide `libpng-config --cflags --ldflags` -ljpeg -lpthread -ldl -o halide -std=c++17 
 LD_LIBRARY_PATH=/home/dalviubaid02/Downloads/halide_build/distrib/lib/ ./halide

NOTE:
Change the path of the Images before executing these command to the path of the Image in your system"
*/


/*

To generate Performance metrics using perf command execeute the below command:
LD_LIBRARY_PATH=/home/dalviubaid02/Downloads/halide_build/distrib/lib/ perf stat ./halide 
*/


#include <Halide.h>
#include <iostream>
#include <halide_image_io.h>

using namespace Halide::Tools;

using namespace Halide;
using namespace std;

int main() {
    Buffer<uint8_t> input = load_image("/home/dalviubaid02/Downloads/Practice_Halide/Mona_Lisa.jpg");
    Var x, y, c;

    string user_input;
    cout << "Enter a processing choice ('bright', 'gray', 'blur'): ";
    cin >> user_input;
    Buffer<uint8_t> output(input.width(), input.height(), input.channels());

    const int tile_size = 64; 

    if (user_input == "bright") {
        Func brighter;
        brighter(x, y, c) = cast<uint8_t>(min(input(x, y, c) * 2.0f, 255.0f));

        Var xi, yi;
        brighter.tile(x, y, xi, yi, tile_size, tile_size);
        brighter.parallel(y);
        output = brighter.realize({input.width(), input.height(), input.channels()});
        save_image(output, "Mona_Lisa_bright_Halide_tiled.png");
    } else if (user_input == "gray") {
        Func grayscale;
        grayscale(x, y) = cast<uint8_t>(
            0.299f * input(x, y, 0) +
            0.587f * input(x, y, 1) +
            0.114f * input(x, y, 2)
        );

        Var xi, yi;
        grayscale.tile(x, y, xi, yi, tile_size, tile_size);
        grayscale.parallel(y);
        output = grayscale.realize({input.width(), input.height()});
        save_image(output, "Mona_Lisa_gray_Halide_tiled.png");
    } else if (user_input == "blur") {
        Func clamped;
        clamped(x, y, c) = input(clamp(x, 0, input.width() - 1), clamp(y, 0, input.height() - 1), c);

        Func input_16;
        input_16(x, y, c) = cast<uint16_t>(clamped(x, y, c));

        Func blurx;
        blurx(x, y, c) = (input_16(x - 1, y, c) + 2 * input_16(x, y, c) + input_16(x + 1, y, c)) / 4;

        Func blury;
        blury(x, y, c) = (blurx(x, y - 1, c) + 2 * blurx(x, y, c) + blurx(x, y + 1, c)) / 4;

        Func blur;
        blur(x, y, c) = cast<uint8_t>(blury(x, y, c));

        Var xi, yi;
        blur.tile(x, y, xi, yi, tile_size, tile_size);
        blur.parallel(y);
        output = blur.realize({input.width(), input.height(), 3});
        save_image(output, "Mona_Lisa_blur_Halide_tiled.jpg");
    } else {
        cerr << "Invalid processing choice." << endl;
        return 1;
    }

    return 0;
}
