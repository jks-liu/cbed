# cbed
Frequently used functions, algorithms, data structures ... in embedded C code.

In this repo, below things are taken into consideration.
1. Embedded MCU often has little memory
2. Data processed by MCU are often time series, which means data are feed one by one
3. Embedded data structs are often small, so we use `uint8_t` as the default type
   for counter purpose instead of using `size_t`.  
   If `uint8_t` is too small for you, do not hesitate to copy/paste code and then
   replace the type to what you need.


Code convertions
- C99
- Use `jks_`, `Jks` ... as the name space
- Use `uint8_t` if possible


# Ring buffer

- Header: [jks-ring-buffer.h](src/jks-ring-buffer.h)
- Head only
- Dependency: None

Ring buffer is very commonly used. But I do not think it is good to hardcode index updating.

Example:

```c
#define N_BUFFER 55
uint8_t g_buffer[N_BUFFER] = {0};
struct jks_ring_buffer g_ring = {0};
void jks_ring_buffer_init(&g_ring, N_BUFFER);


uint8_t add_to_buffer(uint8_t new_value)
{
    uint8_t eldest_value = g_buffer[g_ring.index];
    g_buffer[g_ring.index] = new_value;
    jks_ring_buffer_update_index(&g_ring);
    return eldest_value;
}
```

# Moving average

- Header: [jks-moving-average.h](src/jks-moving-average.h)
- Src: [jks-moving-average.c](src/jks-moving-average.c)
- Dependency: Ring buffer


# Moving standard deviation

- Header: [jks-moving-standard-deviation.h](src/jks-moving-standard-deviation.h)
- Src: [jks-moving-standard-deviation.c](src/jks-moving-standard-deviation.c)
- Dependency: Ring buffer, Moving average

