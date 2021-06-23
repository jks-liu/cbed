#include "jks-moving-average.h"

void jks_moving_average_update(struct jks_moving_average *self, struct jks_ring_buffer ring, float *buffer, float new_data)
{
    new_data /= ring.element_count;
    self->average += new_data - buffer[ring.index];
    buffer[ring.index] = new_data;
}
