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

/**
 * @brief Init member to 0
 * 
 */
struct jks_moving_std {
    struct jks_moving_average average;
    float variance;
    float standard_deviation;
};

/**
 * @brief Calculate moving standard deviation with new data
 * 
 * @param self 
 * @param ring 
 *      ring.element_count is used as the moving window
 * @param buffer Ring buffer to store history info
 *      Its size should be ring.element_count
 * @param new_data The value to calculate the standard deviation
 */
void jks_moving_std_update(struct jks_moving_std *self, struct jks_ring_buffer ring, float *buffer, float new_data);

/**
 * @brief Helper macro to calculate multi moving standard deviation
 * 
 */
#define jks_moving_std_batch_update(self, ring, buffer, new_data, batch_size) do { \
    for (uint8_t jks_i_=0; jks_i_<(batch_size); ++jks_i_) { \
        jks_moving_std_update(self+jks_i_, ring, buffer[jks_i_], new_data[jks_i_]); \
    } \
} while (0)

#ifdef __cplusplus
}
#endif
