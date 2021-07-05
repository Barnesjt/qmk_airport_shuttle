#pragma once

#include "custom_board.h"

#define ENABLE_STARTUP_ADV_NOLIST
#define IS_LEFT_HAND  true

#define ENCODERS_PAD_A { GPIO(0, 22) }
#define ENCODERS_PAD_B { GPIO(1, 00) }
#define ENCODER_RESOLUTION 2