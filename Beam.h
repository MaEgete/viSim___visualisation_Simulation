//
// Created by MaEge on 08.05.2026.
//

#ifndef VISIM___VISUALISATION_SIMULATION_BEAM_H
#define VISIM___VISUALISATION_SIMULATION_BEAM_H

#include "raylib.h"

typedef enum {
    TYPE_INT,
    TYPE_STRING,
} Datatype;


// Struct for a beam Object
struct Beam {

    // Coordinates x and y
    int x;
    int y;

    // Sizes for the 2-dimensional Beam
    int width;
    int height;

    // The rectangle which represents the beam
    Rectangle beamRec;


    // The specific value to compare
    union {
        int integer;
        const char *string;
    };

    // The specific type to compare
    Datatype datatype;


    // The color of the beam
    Color color;

    // Set the color of the beam
    void (*setBeamColor)(struct Beam*, Color);

    // Set the sizes of the beam
    void (*setBeamWidth)(struct Beam*, int);
    void (*setBeamHeight)(struct Beam*, int);

    // Set the position of the beam
    void (*setBeamPosition)(struct Beam*, int, int);

    // Set the compare value of the beam and its dataype
    void (*setBeamString)(struct Beam*, const char*);
    void (*setBeamInteger)(struct Beam*, int);

};

#endif //VISIM___VISUALISATION_SIMULATION_BEAM_H
