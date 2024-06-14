#include <stdio.h>
#include <stdbool.h>
#include "client.h"
#include "grade_school.h"

static bool clipped_by_pellicle = false;
static bool clipped_by_pwc = false;

double calculation(double a, double b) {

    if (a > b) {
        clipped_by_pellicle = true;
    }
    else if (a == b) {
        clipped_by_pwc = clipped_by_pellicle = true;
    }

    if (clipped_by_pellicle || clipped_by_pwc) {
        set_gen_flag();
    }

    return 0;
}

bool get_value() {
    return get_gen_flag_value();
}