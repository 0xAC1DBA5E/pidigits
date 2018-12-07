#include "pidigits.hpp"
#include <benchmark/benchmark.h>

static void pi16_benchmark(benchmark::State &state) {
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(pi16(state.range(0)));
  }
}
BENCHMARK(pi16_benchmark)->Range(1 << 8, 1 << 16);

BENCHMARK_MAIN();
