#ifndef MHCUDA_MINHASHCUDA_H
#define MHCUDA_MINHASHCUDA_H

#include <stdint.h>

extern "C" {

#ifdef __GNUC__
#define MALLOC __attribute__((malloc))
#else
#define MALLOC
#endif

typedef struct MinhashCudaGenerator_ MinhashCudaGenerator;

enum MHCUDAResult {
    mhcudaSuccess,
    mhcudaInvalidArguments,
    mhcudaNoSuchDevice,
    mhcudaMemoryAllocationFailure,
    mhcudaRuntimeError,
    mhcudaMemoryCopyError
};

MinhashCudaGenerator* mhcuda_init(
    uint32_t dim, uint16_t samples, uint32_t seed,
    uint32_t devices, int verbosity, MHCUDAResult *status) MALLOC;

MHCUDAResult mhcuda_calc(
    const MinhashCudaGenerator *gen, const float *weights,
    const uint32_t *cols, const uint32_t *rows, uint32_t length,
    uint32_t *output);

MHCUDAResult mhcuda_fini(MinhashCudaGenerator *gen);

} // extern "C"

#endif // MHCUDA_MINHASHCUDA_H