#include "Beam.h"
#include <string.h>


void setBeamColor(struct Beam* beam, Color color);
void setBeamWidth(struct Beam* beam, float width);
void setBeamHeight(struct Beam* beam, float height);
void setBeamPosition(struct Beam* beam, float x, float y);
void setBeamValue(struct Beam* beam, BeamValue value, Datatype datatype);
bool isValid(const struct Beam* beam);


// Create the Beam
// Returns empty Beam with flag 'valid' = false if the function parameters are not valid
// otherwise it returns a full struct Beam

// Datatype and beam_value must be the same
struct Beam createBeam(float x, float y, float width, float height, Color color, BeamValue beam_value, Datatype datatype) {

    // Check if the input string is NULL
    if (datatype == TYPE_STRING) {
        if (beam_value.string == NULL || strlen(beam_value.string) == 0) {
            return (struct Beam){
                .valid = false,
            };
        }
    }



    // check conditions
    if (x < 0 || y < 0 || width <= 0 || height <= 0 ||
        color.r < 0 || color.g < 0 || color.b < 0 || color.a < 0 ||
        color.r > 255 || color.g > 255 || color.b > 255 || color.a > 255 ||
        datatype == TYPE_NONE) {
        // if the parameters are not valid
        return (struct Beam){
            // set valid flag to false
            .valid = false,
        };
    }

    // create Beam
    struct Beam beam = {0};

    // set all Values
    beam.x = x;
    beam.y = y;
    beam.width = width;
    beam.height = height;
    beam.color = color;

    beam.beamRec = (Rectangle){x, y, width, height};

    beam.beamValue = beam_value;
    beam.datatype = datatype;

    // Beam is valid
    beam.valid = true;

    // Functionpointers

    beam.setBeamColor = setBeamColor;

    beam.setBeamWidth = setBeamWidth;
    beam.setBeamHeight = setBeamHeight;

    beam.setBeamPosition = setBeamPosition;

    beam.setBeamValue = setBeamValue;

    beam.isValid = isValid;

    return beam;
}



// Set the color of the beam
void setBeamColor(struct Beam* beam, Color color) {
    beam->color = color;
}


// Set the width of the beam
void setBeamWidth(struct Beam* beam, float width) {

    // if the width parameter is smaller than 1, it will be set to 1
    if (width <= 0) {
        width = 1;
    }

    // Set the width variable from visualizer to the new width value
    beam->width = width;
}


// Set the height of the beam
void setBeamHeight(struct Beam* beam, float height) {

    // if the height parameter is smaller than 1, it will be set to 1
    if (height <= 0) {
        height = 1;
    }

    // Set the height variable from visualizer to the new height value
    beam->height = height;
}


// Set the position of the beam
void setBeamPosition(struct Beam* beam, float x, float y) {

    // if x or y are smaller than 0 than nothing will happen
    if (x < 0 || y < 0) {
        return;
    }

    // otherwise x and y from visualizer are set to their new values
    beam->x = x;
    beam->y = y;
}

// Set the beamValue of the beam
void setBeamValue(struct Beam* beam, BeamValue value, Datatype datatype) {
    beam->datatype = datatype;
    beam->beamValue = value;
}

// Returns true if the beam is in a valid state
bool isValid(const struct Beam* beam) {
    return beam->valid;
}