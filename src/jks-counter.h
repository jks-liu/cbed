#pragma once

#include <stdbool.h>

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

/**
 * @brief Increase counter by one
 *
 */
#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_increase(struct jks_counter *counter);

/**
 * @brief Decrease counter by one
 *
 */
#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_decrease(struct jks_counter *counter);

/**
 * @brief Add `value` to counter, `value` can be positive, 0, or negative
 *
 */
#ifdef JKS_COUNTER_CONFIG_RETURN_COUNTER
JKS_COUNTER_T
#else
void
#endif
jks_counter_add(struct jks_counter *counter, int value);

#ifdef __cplusplus
}
#endif
