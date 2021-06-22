#include "jks-moving-average.h"


void jks_moving_average_update(float *previous_average, float new_data, struct jks_ring_buffer *ring)
{
    float *buffer = ring->buffer;

    new_data /= ring->element_count;
    *previous_average += new_data - buffer[ring->index];
    buffer[ring->index] = new_data;

    jks_ring_buffer_update(ring);
}

void jks_moving_average_batch_update(float *previous_average, const float *new_data,
        struct jks_ring_buffer **rings, unsigned char batch_size)
{
    for (uint8_t i=0; i<batch_size; ++i)
        jks_moving_average_update(previous_average+i, new_data[i], rings+i);
}
