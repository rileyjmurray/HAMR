#include <hamr_buffer.h>
#include <hip/hip_runtime.h>

#include <iostream>
#include <memory>

#include "add.h"
#include "write.h"

int main(int, char **)
{
    size_t n_vals = 400;

    // allocate and initialize to 1 on the GPU
    hamr::buffer<float> a0(hamr::buffer_allocator::hip, n_vals, 1.0f);

    // allocate and initialize to 1 on the CPU
    hamr::buffer<float> a1(hamr::buffer_allocator::malloc, n_vals, 1.0f);

    // add the two arrays
    hamr::buffer<float> a2 = add(a0, a1);

    // write the result
    write(std::cerr, a2);

    return 0;
}
