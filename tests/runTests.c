#include "runTests.h"

#include "beam_tests.h"

void runAllTests() {
    runBeamTests();
    runVisualizerTests();
}

void runBeamTests() {
    test_createBeam_with_Float_val();
    test_createBeam_with_String_val();
    test_createBeam_with_not_valid_values();
}

void runVisualizerTests() {

}