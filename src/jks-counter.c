#include "jks-counter.h"

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_increase(struct jks_counter *self)
{
    if (self->counter == self->counter_max) {
        if (!self->is_saturate) {
            self->counter = 0;
        }
    } else {
        ++self->counter;
    }

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
    return self->counter;
#endif
}

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_decrease(struct jks_counter *self)
{
    if (self->counter == 0) {
        if (!self->is_saturate) {
            self->counter = self->counter_max;
        }
    } else {
        --self->counter;
    }

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
    return self->counter;
#endif
}

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_add(struct jks_counter *self, int value)
{
    value += self->counter;

    if (self->is_saturate) {
        if (value < 0)
            value = 0;

        if(value > self->counter_max)
            value = self->counter_max;
    } else while (value < 0 || value > self->counter_max) {
        if (value < 0)
            value += self->counter_max;

        if (value > self->counter_max)
            value -= self->counter_max;
    }

    self->counter = value;

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
    return self->counter;
#endif
}
