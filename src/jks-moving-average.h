#pragma once

/**
 * @file jks-moving-average.h
 * @author https://github.com/jks-liu/cbed
 * @brief 
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "jks-ring-buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

void jks_moving_average_update(float *previous_average, float new_data, struct jks_ring_buffer *ring);
void jks_moving_average_batch_update(float *previous_average, const float *new_data,
        struct jks_ring_buffer **rings, unsigned char batch_size);

#ifdef __cplusplus
}
#endif
