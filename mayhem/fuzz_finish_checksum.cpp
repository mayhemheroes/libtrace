#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" uint16_t finish_checksum(uint32_t sum);
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint32_t sum = provider.ConsumeIntegral<uint32_t>();
    finish_checksum(sum);
    return 0;
}