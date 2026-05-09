

#include "beam_tests.h"

#include <assert.h>
#include "../src/Beam.h"
#include <string.h>

struct Beam init() {
    return createBeam(10, 10, 10, 10, WHITE, (BeamValue){0}, TYPE_FLOAT);
}

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

    // beamvalue string
    beam = createBeam(10, 10, 10, 10, WHITE, (BeamValue){.string = NULL}, TYPE_STRING);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 10, WHITE, (BeamValue){.string = ""}, TYPE_STRING);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 10, WHITE, (BeamValue){0}, TYPE_STRING);
    assert(beam.valid == false);

    // datatype
    beam = createBeam(10, 10, 10, 10, WHITE, (BeamValue){0}, TYPE_NONE);
    assert(beam.valid == false);

    // color
    beam = createBeam(10, 10, 10, 0, (Color){-1,0,0,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,-1,0,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,0,-1,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,0,0,-1}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

    beam = createBeam(10, 10, 10, 0, (Color){256,0,0,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,256,0,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,0,256,0}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);
    beam = createBeam(10, 10, 10, 0, (Color){0,0,0,256}, (BeamValue){0}, TYPE_FLOAT);
    assert(beam.valid == false);

}

void test_setBeamColor() {
    struct Beam beam = init();
    beam.setBeamColor(&beam, (Color){255,100,100,100});

    assert(beam.color.r == 255);
    assert(beam.color.g == 100);
    assert(beam.color.b == 100);
    assert(beam.color.a == 100);

}

void test_setBeamColor_with_not_valid_values() {

    struct Beam beam = init();
    beam.setBeamColor(&beam, (Color){-1,255,255,255});
    assert(beam.color.r == 255);

    beam.setBeamColor(&beam, (Color){255,-1,255,255});
    assert(beam.color.g == 255);

    beam.setBeamColor(&beam, (Color){255,255,-1,255});
    assert(beam.color.b == 255);

    beam.setBeamColor(&beam, (Color){255,255,255,-1});
    assert(beam.color.a == 255);


}

void test_setBeamWidth() {
    struct Beam beam = init();
    beam.setBeamWidth(&beam, 100);

    assert(beam.width == 100);
}

void test_setBeamWidth_with_not_valid_values() {
    struct Beam beam = init();
    beam.setBeamWidth(&beam, 0);
    assert(beam.width == 1);
}

void test_setBeamHeight() {
    struct Beam beam = init();
    beam.setBeamHeight(&beam, 100);
    assert(beam.height == 100);
}

void test_setBeamHeight_with_not_valid_values() {
    struct Beam beam = init();
    beam.setBeamHeight(&beam, 0);
    assert(beam.height == 1);
}

void test_setBeamPosition() {
    struct Beam beam = init();

    beam.setBeamPosition(&beam, 100, 100);
    assert(beam.x == 100);
    assert(beam.y == 100);

}

void test_setBeamPosition_with_not_valid_values() {
    struct Beam beam = init();

    beam.setBeamPosition(&beam, -1, 0);
    assert(beam.x == 10);
    assert(beam.y = 10);

    beam.setBeamPosition(&beam, 0, -1);
    assert(beam.x == 10);
    assert(beam.y = 10);

}

void test_setBeamValue() {

    // Default: Datatype TYPE_FLOAT, value = 0.0f;
    struct Beam beam = init();

    // change float
    beam.setBeamValue(&beam, (BeamValue){10.0f}, TYPE_FLOAT);
    assert(beam.beamValue.float_number == 10.0f);


    // false type
    beam.setBeamValue(&beam, (BeamValue){100.0f}, TYPE_NONE);
    assert(beam.beamValue.float_number != 100.0f);
    beam.setBeamValue(&beam, (BeamValue){100.0f}, TYPE_STRING);
    assert(beam.beamValue.float_number != 100.0f);

    // !isValid
    beam.valid = !beam.valid;
    beam.setBeamValue(&beam, (BeamValue){100.0f}, TYPE_FLOAT);
    assert(beam.beamValue.float_number != 100.0f);

    // string not NULL or empty
    beam.beamValue.string = "HI";
    beam.datatype = TYPE_STRING;
    beam.valid = !beam.valid;

    beam.setBeamValue(&beam, (BeamValue){.string = NULL}, TYPE_STRING);
    assert(strcmp(beam.beamValue.string, "HI") == 0);

    beam.setBeamValue(&beam, (BeamValue){.string = ""}, TYPE_STRING);
    assert(strcmp(beam.beamValue.string, "HI") == 0);

    // change string
    beam.setBeamValue(&beam, (BeamValue){.string = "WELT"}, TYPE_STRING);
    assert(strcmp(beam.beamValue.string, "WELT") == 0);

}

void test_isValid() {
    struct Beam beam = init();
    assert(beam.valid == beam.isValid(&beam));

    beam.valid = !beam.valid;
    assert(beam.valid == beam.isValid(&beam));

}