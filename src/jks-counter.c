#include "jks-counter.h"

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_increase(struct jks_counter *counter)
{
    if (counter->counter == counter->counter_max) {
        if (!counter->is_saturate) {
            counter->counter = 0;
        }
    } else {
        ++counter->counter;
    }

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
    return counter->counter;
#endif
}

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_decrease(struct jks_counter *counter)
{
    if (counter->counter == 0) {
        if (!counter->is_saturate) {
            counter->counter = counter->counter_max;
        }
    } else {
        --counter->counter;
    }

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
    return counter->counter;
#endif
}
