// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(NUMPAD_4x4)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool NUMPAD_4x4(effect_params_t* params) {
    uint8_t layer = biton32(layer_state);

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (layer == 0) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (i == 3) {
                rgb_matrix_set_color(i, 0, 255, 255); // *
            } else if (i == 4) {
                rgb_matrix_set_color(i, 255, 0, 255); // /
            } else if (i == 11) {
                rgb_matrix_set_color(i, 0, 255, 255); // +
            } else if (i == 12) {
                rgb_matrix_set_color(i, 255, 0, 255);  // -
            } else if (i == 13) {
                rgb_matrix_set_color(i, 255, 255, 0); // .
            } else if (i == 14) {
                rgb_matrix_set_color(i, 255, 0, 0); // enter
            } else {
                rgb_matrix_set_color(i, 0, 0, 255); // numbers
            }
        }
    } else if (layer == 1) {
        for (uint8_t i = led_min; i < led_max; i++) { 
            if (i == 15 || i == 14 || i == 13 || i == 9) {
                rgb_matrix_set_color(i, 0, 0, 255);
            } else if (i == 12) {
                rgb_matrix_set_color(i, 255, 0, 0);
            } else if (i == 2 || i == 3 || i == 4 || i == 5 || i == 11) {
                rgb_matrix_set_color(i, 255, 255, 0);
            } else {
                rgb_matrix_set_color(i, 0, 255, 0);
            }
        }
    }

    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS