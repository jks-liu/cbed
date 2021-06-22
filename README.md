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
uint8_t g_buffer[N_BUFFER];
uint8_t g_buffer_index = 0;

uint8_t add_to_buffer(uint8_t new_value)
{
    uint8_t eldest_value = g_buffer[g_buffer_index];
    g_buffer[g_buffer_index] = new_value;
    jks_ring_buffer_update_index(&g_buffer_index, N_BUFFER);
    return eldest_value;
}
```

# Moving average

- Header: [jks-moving-average.h](src/jks-moving-average.h)
