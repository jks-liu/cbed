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
};

/**
 * @brief Init ring buffer size
 * 
 * @param ring 
 * @param element_count Buffer length
 */
inline
void jks_ring_buffer_init(struct jks_ring_buffer *ring, uint8_t element_count)
{
    ring->index = 0;
    ring->element_count = element_count;
}

/**
 * @brief After you stored value to current index,
 * call this function to let index point to next position
 * 
 * @param ring
 *    index: Index where you have stored the current value to
 *    element_count: How many elements in the ring buffer
 * Allowed max of element_count is 255
 */
inline
void jks_ring_buffer_update_index(struct jks_ring_buffer *ring)
{
    ring->index = (ring->index + 1) % ring->element_count;
}


inline
uint8_t jks_ring_buffer_previous_index(struct jks_ring_buffer ring)
{
    return ring.index == 0 ? (ring.element_count - 1) : (ring.index - 1);
}

inline
uint8_t jks_ring_buffer_next_index(struct jks_ring_buffer ring)
{
    return (ring.index + 1) % ring.element_count;
}


#ifdef __cplusplus
}
#endif
