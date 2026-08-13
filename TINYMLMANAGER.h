#pragma once

#include <Arduino.h>

#include "GLOBALS.h"
#include "MODEL_DATA.h"


#define ELOQUENT_TFLM

#define TF_OP_FULLYCONNECTED
#define TF_OP_RELU
#define TF_OP_SOFTMAX

#define TF_NUM_OPS 6
#define ARENA_SIZE 16384


#include <tflm_esp32.h>
#include <eloquent_tinyml.h>


class TinyMLManager
{
private:

    Eloquent::TF::Sequential<TF_NUM_OPS, ARENA_SIZE> tf;

    float input[8];

public:

    void begin();
    void predict();
};
