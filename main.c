#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

struct Beam {
    int x;
    int y;
    int width;
    int height;

    // Typ zum Vergleichen
    union {
        int integer;
        char *string;
    };

    Color color;
};


struct Visualizer {

    struct Beam *beam;
    Color background;
    size_t beamCount;

    int (*addBeam)(const struct Beam*);
    void (*removeBeam)(int);
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



bool addBeam(struct Visualizer* visualizer, const struct Beam* newBeam) {

    if (visualizer == NULL || newBeam == NULL) {
        return false;
    }


    struct Beam* tmp = realloc(visualizer->beam, (visualizer->beamCount + 1) * sizeof(struct Beam));

    if (tmp == NULL) {
        perror("addBeam");
        return false;
    }

    visualizer->beam = tmp;
    visualizer->beam[visualizer->beamCount - 1] = *newBeam;
    visualizer->beamCount++;

    return true;

}



struct Visualizer createVisualizer() {
    struct Visualizer visualizer;

    visualizer.beam = NULL;
    visualizer.beamCount = 0;


    return visualizer;
}

int main() {
    InitWindow(800, 450, "viSim");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hallo aus CLion!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}