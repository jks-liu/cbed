#pragma once

/**
 * @file jks-moving-standard-deviation.h
 * @author https://github.com/jks-liu/cbed
 * @brief 
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "jks-ring-buffer.h"
#include "jks-moving-average.h"

#ifdef __cplusplus
extern "C" {
#endif

struct jks_moving_std {
    struct jks_ring_buffer ring_average;
    struct jks_ring_buffer ring_variance;
    float previous_average;
    float previous_variance;
};

void jks_moving_std_update(struct jks_moving_std *std, float new_data, float *out);
void jks_moving_std_batch_update(struct jks_moving_std *std, const float *new_data, float *out,
        unsigned char batch_size);

#ifdef __cplusplus
}
#endif
