/*
 * pin_assign.h
 */

#pragma once

#include "custom_board.h"

#define THIS_DEVICE_ROWS 4
#define THIS_DEVICE_COLS 12

#define MATRIX_ROW_PINS { GPIO(0, 20), GPIO(0, 17), GPIO(0, 15), GPIO(0, 13) }
#define MATRIX_COL_PINS { GPIO(1, 11), GPIO(0, 03), GPIO(0, 28), GPIO(1, 13), GPIO(0, 26), GPIO(0, 02), GPIO(0, 29), GPIO(0, 30), GPIO(0, 31), GPIO(0, 00), GPIO(0, 01), GPIO(0, 06) }
