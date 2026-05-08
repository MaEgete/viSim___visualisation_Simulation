#include "Beam.h"
#include <string.h>

// Set the color of the beam
void setBeamColor(struct Beam* beam, Color color) {
    beam->color = color;
}


// Set the width of the beam
void setBeamWidth(struct Beam* beam, int width) {

    // if the width parameter is smaller than 1, it will be set to 1
    if (width <= 0) {
        width = 1;
    }

    // Set the width variable from visualizer to the new width value
    beam->width = width;
}


// Set the height of the beam
void setBeamHeight(struct Beam* beam, int height) {

    // if the height parameter is smaller than 1, it will be set to 1
    if (height <= 0) {
        height = 1;
    }

    // Set the height variable from visualizer to the new height value
    beam->height = height;
}


// Set the position of the beam
void setBeamPosition(struct Beam* beam, int x, int y) {

    // if x or y are smaller than 0 than nothing will happen
    if (x < 0 || y < 0) {
        return;
    }

    // otherwise x and y from visualizer are set to their new values
    beam->x = x;
    beam->y = y;
}

// Set the string of the beam
void setBeamString(struct Beam* beam, const char* string_val) {
    beam->datatype = TYPE_STRING;
    beam->string = string_val;
}

void setBeamInteger(struct Beam* beam, int integer_val) {
    beam->datatype = TYPE_INT;
    beam->integer = integer_val;
}