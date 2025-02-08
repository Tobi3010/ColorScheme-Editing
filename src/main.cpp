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

    Image test("test.jpg");
    Image gray_avg = test;
    gray_avg.grayscale_avg();
    gray_avg.write("gray_avg.png");

    return 0;

}