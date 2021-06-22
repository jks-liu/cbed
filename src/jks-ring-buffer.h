#pragma once

/**
 * @file jks-ring-buffer.h
 * @author https://github.com/jks-liu/cbed
 * @brief 
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct jks_ring_buffer {
    uint8_t index;
    uint8_t element_count;
    void *buffer;
};

inline
void jks_ring_buffer_update(struct jks_ring_buffer *ring)
{
    if (++ring->index >= ring->element_count)
        ring->index = 0;
}


/**
 * @brief After you stored value to current index,
 * call this function to let index point to next position
 * 
 * Init your index to 0
 * 
 * @param index Index where you have stored the current value to
 * @param element_count How many elements in the ring buffer
 * Allowed max of element_count is 255
 */
inline 
void jks_ring_buffer_update_index(uint8_t *index, uint8_t element_count)
{
    if (++*index >= element_count)
        *index = 0;
}

#ifdef __cplusplus
}
#endif
