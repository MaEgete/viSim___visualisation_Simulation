

#include "beam_tests.h"

#include <assert.h>
#include "../src/Beam.h"
#include <string.h>


void test_createBeam_with_Float_val() {

    // Test Beam
    struct Beam beam;

    // Test values
    float x = 1;
    float y = 2;
    float width = 3;
    float height = 4;
    Color color = WHITE;
    BeamValue beam_value = {
        .float_number = 5,
    };
    Datatype datatype = TYPE_FLOAT;

    // Test object
    beam = createBeam(x, y, width, height, color, beam_value, datatype);

    // Asserts
    assert(beam.valid == true);

    assert(beam.x == x);
    assert(beam.y == y);

    assert(beam.width == width);
    assert(beam.height == height);

    assert(beam.beamRec.x == x);
    assert(beam.beamRec.y == y);
    assert(beam.beamRec.width == width);
    assert(beam.beamRec.height == height);

    assert(beam.color.r == color.r);
    assert(beam.color.g == color.g);
    assert(beam.color.b == color.b);
    assert(beam.color.a == color.a);

    assert(beam.beamValue.float_number == beam_value.float_number);
    assert(beam.datatype == datatype);

}

void test_createBeam_with_String_val() {

    // Test Beam
    struct Beam beam;

    // Test values
    float x = 1;
    float y = 2;
    float width = 3;
    float height = 4;
    Color color = WHITE;
    BeamValue beam_value = {
        .string = "Teststring",
    };
    Datatype datatype = TYPE_FLOAT;

    // Test object
    beam = createBeam(x, y, width, height, color, beam_value, datatype);

    // Asserts
    assert(beam.valid == true);

    assert(beam.x == x);
    assert(beam.y == y);

    assert(beam.width == width);
    assert(beam.height == height);

    assert(beam.beamRec.x == x);
    assert(beam.beamRec.y == y);
    assert(beam.beamRec.width == width);
    assert(beam.beamRec.height == height);

    assert(beam.color.r == color.r);
    assert(beam.color.g == color.g);
    assert(beam.color.b == color.b);
    assert(beam.color.a == color.a);

    assert(strcmp(beam.beamValue.string, beam_value.string) == 0);
    assert(beam.datatype == datatype);

}

void test_createBeam_with_not_valid_values() {
    struct Beam beam;

    // x
    beam = createBeam(-1, 10, 10, 10, WHITE, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

    // y
    beam = createBeam(10, -1, 10, 10, WHITE, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

    // width
    beam = createBeam(10, 10, 0, 10, WHITE, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

    // height
    beam = createBeam(10, 10, 10, 0, WHITE, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

    // height
    beam = createBeam(10, 10, 10, 0, WHITE, (BeamValue){.string = NULL}, TYPE_STRING);
    assert(beam.valid == false);

}