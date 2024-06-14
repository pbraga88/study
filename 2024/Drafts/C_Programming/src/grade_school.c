#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grade_school.h"

static bool sg_is_clipped = false;

void set_gen_flag() {
    sg_is_clipped = true;
}

bool get_gen_flag_value() {
    return sg_is_clipped;
}