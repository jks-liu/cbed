#include "jks-moving-standard-deviation.h"

#include <math.h>

void jks_moving_std_update(struct jks_moving_std *self, struct jks_ring_buffer ring, float *buffer, float new_data)
{
    float diff = new_data - self->average.average;
    diff = diff * diff / ring.element_count;
    self->variance += diff - buffer[ring.index];
    // In case of float point error
    self->variance = self->variance >= 0 ? self->variance : 0;
    self->standard_deviation = sqrtf(self->variance);
    buffer[ring.index] = diff;
}
