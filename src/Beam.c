#include "Beam.h"
#include <string.h>



// Create the Visualizer
// Returns empty Beam with flag 'valid' = false if the function parameters are not valid
// otherwise it returns a full struct Beam
struct Beam createBeam(float x, float y, float width, float height, Color color, BeamValue beam_value, Datatype datatype) {

    // check conditions
    if (x < 0 || y < 0 || width <= 0 || height <= 0) {
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