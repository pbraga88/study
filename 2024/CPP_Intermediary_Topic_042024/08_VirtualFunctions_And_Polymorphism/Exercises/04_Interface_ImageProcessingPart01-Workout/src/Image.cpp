#include "Image.h"

Image::Image(void)
{
}

Image::~Image(void)
{
}

void Image::setBright() {
    brightness++;
}
void Image::setContrast() {
    contrast++;
}
void Image::setEdge() {
    edgeEnhancement++;
}

int Image::getBright() {
    return brightness;
}
int Image::getContrast() {
    return contrast;
}
int Image::getEdge() {
    return edgeEnhancement;
}
