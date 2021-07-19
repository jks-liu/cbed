#pragma once

#include <stdint.h>

#include "jks-cbed-config.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Counter
 * 
 */
struct jks_counter {
    bool is_saturate;
    uint8_t counter;
    uint8_t counter_max;
};

inline
#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
uint8_t
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

inline
#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
uint8_t
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


#ifdef __cplusplus
}
#endif
