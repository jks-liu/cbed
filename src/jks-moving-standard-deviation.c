#include "jks-moving-standard-deviation.h"

#include <math.h>

void jks_moving_std_update(struct jks_moving_std *std, float new_data, float *out)
{
    float *buffer = std->ring_variance.buffer;
    jks_moving_average_update(&std->previous_average, new_data, &std->ring_average);

    float diff = new_data - std->previous_average;
    diff = diff * diff / std->ring_variance.element_count;
    std->previous_variance += diff - buffer[std->ring_variance.index];
    buffer[std->ring_variance.index] = diff;

    jks_ring_buffer_update(&std->previous_variance);
    *out = sqrtf(std->previous_variance);
}

void jks_moving_std_batch_update(struct jks_moving_std *std, const float *new_data, float *out,
        unsigned char batch_size)
{
    for (uint8_t i=0; i<batch_size; ++i)
        jks_moving_std_update(std+i, new_data[i], out+i);
}
