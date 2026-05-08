#include "runTests.h"

#include "beam_tests.h"

void runAllTests() {
    runBeamTests();
    runVisualizerTests();
}

void runBeamTests() {
    test_createBeam_with_Float_val();
}

void runVisualizerTests() {

}