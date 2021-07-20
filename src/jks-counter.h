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
    JKS_COUNTER_T counter;
    JKS_COUNTER_T counter_max;
};

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif 
jks_counter_increase(struct jks_counter *counter);

#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif 
jks_counter_decrease(struct jks_counter *counter);


#ifdef __cplusplus
}
#endif
