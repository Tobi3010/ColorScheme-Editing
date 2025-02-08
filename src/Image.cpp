#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"

Image::Image(const char* filename){
    if(read(filename)) {
        printf("Read %s\n", filename);
        size = w * h * channels;
    }
    else {
        printf("Failed To Read %s\n", filename);
    }
}

Image::Image(int w, int h, int channels) : w(w), h(h), channels(channels){
    size = w * h * channels;
    data = new uint8_t[size];
    memset(data, 0, size);
}

Image::Image(const Image& img) : Image(img.w, img.h, img.channels) {
    memcpy(data, img.data, img.size);
}

Image::~Image(){
    stbi_image_free(data);
}

bool Image::read(const char* filename){
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
}

bool Image::write(const char* filename){
    ImageType type = getFileType(filename);
    int success;
    switch(type){
        case PNG:
            success = stbi_write_png(filename, w, h, channels, data, w * channels);
            break;
        case JPG:
            success = stbi_write_jpg(filename, w, h, channels, data, 100);
            break;
        case BMP:
            success = stbi_write_bmp(filename, w, h, channels, data);
            break;
        case TGA:
            success = stbi_write_tga(filename, w, h, channels, data);
            break;
    }
    return success != 0;
}

ImageType Image::getFileType(const char* filename){
    const char* ext = strrchr(filename, '.');
    if (ext != nullptr) {
        if(strcmp(ext, ".png") == 0) {
            return PNG;
        } 
        else if(strcmp(ext, ".jpg") == 0) {
            return JPG;
        } 
        else if(strcmp(ext, ".bmp") == 0) {
            return BMP;
        } 
        else if(strcmp(ext, ".tga") == 0) {
            return TGA;
        }  
    }
    
    return PNG;
   
}


// Average and luminosity methods for converting image to grayscale, see https://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/
// function to convert image to grayscale, takes a grayscale method function as argument.
Image& Image::grayscale(int (*grayscale_method)(uint8_t*)){
    if(channels < 3) {
        printf("Image %p has less than 3 channels, assumed it is grayscale already", this);
    }
    else {
        for(int i = 0; i < size; i += channels) {
            int gray = grayscale_method(&data[i]);
            memset(data + i, gray, 3);
        }
    }
    return *this;
}

int Image::avg_method(uint8_t* data){
    return (data[0] + data[1] + data[2]) / 3; 
}
int Image::lum_method(uint8_t* data){
    return (0.2126 * data[0] + 0.7152 * data[1] + 0.0722 * data[2]) / 3;
}
int Image::light_method(uint8_t* data){
    return (std::max(data[0], std::max(data[1], data[2]))  + std::min(data[0], std::min(data[1], data[2]))) / 2;
}

// Grayscale by average method
Image& Image::grayscale_avg(){
    return grayscale(&(avg_method));
}
// Grayscale by luminosity method
Image& Image::grayscale_lum(){
    return grayscale(&lum_method);
}
// Grayscale by lighting method
Image& Image::grayscale_light(){
    return grayscale(&light_method);
}




