#include "Visualizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Create the Visualizer -- constructor
struct Visualizer createVisualizer() {
    struct Visualizer visualizer;

    visualizer.beam = NULL;
    visualizer.beamCount = 0;
    visualizer.background = GRAY;


    return visualizer;
}




// Returns true if 'newBeam' was successfully added otherwise false
bool addBeam(struct Visualizer* visualizer, const struct Beam* newBeam) {

    // If the input parameters are NULL then return false
    if (visualizer == NULL || newBeam == NULL) {
        return false;
    }

    // Resize Memory for the new entry and safe it in a new variable for safety
    // If not and realloc fails then the Beam list is forgotten
    struct Beam* tmp = realloc(visualizer->beam, (visualizer->beamCount + 1) * sizeof(struct Beam));

    // Safety check
    if (tmp == NULL) {
        perror("addBeam");
        return false;
    }

    // Set beam variable to tmp
    visualizer->beam = tmp;
    // Add the new Beam to the list
    visualizer->beam[visualizer->beamCount - 1] = *newBeam;
    // increment the beamCount variable
    visualizer->beamCount++;

    // All good
    return true;

}


void removeBeam(struct Visualizer* visualizer, int index) {

    // if one of function parameters is not valid then nothing will happen
    if (visualizer == NULL || index < 0 || index >= visualizer->beamCount) {
        return;
    }


    // remove the last beam item
    if (index == visualizer->beamCount - 1) {

        struct Beam* tmp = realloc(visualizer->beam, (visualizer->beamCount - 1) * sizeof(struct Beam));

        if (tmp == NULL) {
            perror("removeBeam");
            return;
        }

        visualizer->beamCount--;
        visualizer->beam = tmp;

        return;
    }


    // Alle Beams nach index
    //struct Beam* tmp = malloc(visualizer->be)

    //&visualizer->beam[index];

}




