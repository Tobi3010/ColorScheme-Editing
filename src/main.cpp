#include <iostream>
#include "image.h"

int main() {

    /* Tests for initialization
    Image test("test.jpg");
    test.write("new.png");

    Image copy = test;
    for (int i = 0; i < copy.w * copy.channels; i++){
        copy.data[i] = 255;
    }
    copy.write("copy.png");


    Image blank(100, 100, 3);
    blank.write("blank.jpg");
    */

    /* Tests for grayscale
    Image test("test.jpg");

    Image gray_avg = test;
    gray_avg.grayscale_avg();
    gray_avg.write("gray_avg.jpg");

    Image gray_lum = test;
    gray_lum.grayscale_lum();
    gray_lum.write("gray_lum.jpg");

    Image gray_light = test;
    gray_light.grayscale_light();
    gray_light.write("gray_light.jpg");
    */

    Image blue("test.jpg");
    blue.colorMask(0, 0, 1);
    blue.write("blue.png");

    Image green("test.jpg");
    green.colorMask(0, 1, 0);
    green.write("green.png");

    Image red("test.jpg");
    red.colorMask(1, 0, 0);
    red.write("red.png");

    Image redGreen("test.jpg");
    redGreen.colorMask(1, 1, 0);
    redGreen.write("redGreen.png");

    return 0;

}