//
// Created by MaEge on 08.05.2026.
//

#ifndef VISIM___VISUALISATION_SIMULATION_VISUALIZER_H
#define VISIM___VISUALISATION_SIMULATION_VISUALIZER_H

#include "raylib.h"
#include "Beam.h"
#include <stddef.h>

// Visualizes the algorithms in the form of a beam
struct Visualizer {

    // Beam struct (defined in Beam.h) type pointer, points to a List of beams
    struct Beam *beam;
    // Size of the beam pointer
    size_t beamCount;

    // Backgroundcolor of the visualizer
    Color background;

    // Functionpointer to add a Beam to the beam pointer of Visualizer
    int (*addBeam)(struct Visualizer*, const struct Beam*);
    void (*removeBeam)(struct Visualizer*, int);
    void (*clearBeams)();
    struct Beam* (*getBeam)(int);
    void (*setBeam)(const struct Beam*);

    int (*getBeamCount)();
    void (*drawBeam)(const struct Beam*);
    void (*drawAllBeams)();

    void (*update)();
    void (*render)();

    void (*setBackgroundColor)(Color);

    void (*setBeamColor)(int, Color);

    void (*setBeamWidth)(int, int);
    void (*setBeamHeight)(int, int);
    void (*setBeamPosition)(int, int, int, int);

    void (*setBeamString)(int, char*);
    void (*setBeamInteger)(int, int);

    void (*destroyVisualizer)();

};


#endif //VISIM___VISUALISATION_SIMULATION_VISUALIZER_H
