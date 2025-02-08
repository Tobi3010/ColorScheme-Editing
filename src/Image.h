#include <stdint.h>
#include <cstdio>

enum ImageType {
    PNG, JPG, BMP, TGA
};

struct Image {
    uint8_t* data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels;                       // How many color values per pixel

    Image(const char* filename);
    Image(int w, int h, int channels);
    Image(const Image& img);
    ~Image();

    bool write(const char* filename);
    bool read(const char* filename);

    ImageType getFileType(const char* filename);

    Image& grayscale_avg();
    Image& grayscale_lum();

    private: 
        Image& grayscale(int (*f)(uint8_t*));
        static int avg_method(uint8_t* data);
        static int lum_method(uint8_t* data);
   
};