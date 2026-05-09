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
    test_setBeamColor();
    test_setBeamColor_with_not_valid_values();
    test_setBeamWidth();
    test_setBeamWidth_with_not_valid_values();
    test_setBeamHeight();
    test_setBeamHeight_with_not_valid_values();
    test_setBeamPosition();
    test_setBeamPosition_with_not_valid_values();
    test_setBeamValue();
    test_isValid();
}

void runVisualizerTests() {

}