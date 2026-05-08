//
// Created by MaEge on 08.05.2026.
//

#ifndef VISIM___VISUALISATION_SIMULATION_BEAM_H
#define VISIM___VISUALISATION_SIMULATION_BEAM_H

#include "raylib.h"

// The specific datatype to compare
typedef enum {
    TYPE_FLOAT,
    TYPE_STRING,
} Datatype;

// The specific value to compare
typedef union {
    int float_number;
    const char *string;
} BeamValue;


// Struct for a beam Object
struct Beam {

    // Coordinates x and y
    float x;
    float y;

    // Sizes for the 2-dimensional Beam
    float width;
    float height;

    // The rectangle which represents the beam
    Rectangle beamRec;


    // The specific value to compare
    BeamValue beamValue;

    // The specific type to compare
    Datatype datatype;

    // The color of the beam
    Color color;

    // all correct with the struct
    bool valid;

    // Set the color of the beam
    void (*setBeamColor)(struct Beam*, Color);

    // Set the sizes of the beam
    void (*setBeamWidth)(struct Beam*, float);
    void (*setBeamHeight)(struct Beam*, float);

    // Set the position of the beam
    void (*setBeamPosition)(struct Beam*, float, float);

    // Set the compare value of the beam and its dataype
    void (*setBeamValue)(struct Beam*, BeamValue, Datatype);

    // Returns true if the struct is valid
    bool (*isValid)(struct Beam*);

};

struct Beam createBeam(float x, float y, float width, float height, Color color, BeamValue beam_value, Datatype datatype);



#endif //VISIM___VISUALISATION_SIMULATION_BEAM_H
