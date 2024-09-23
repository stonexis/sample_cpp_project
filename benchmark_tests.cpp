#include <benchmark/benchmark.h>
#include "my_add.hpp"

static void Benchmark_my_add(benchmark::State& state) {
    for (auto _ : state) {
        my_add(rand(), rand());  // Вызываем функцию для бенчмаркинга
    }
}

// Регистрируем бенчмарк
BENCHMARK(Benchmark_my_add);

// Главная функция для запуска всех бенчмарков
BENCHMARK_MAIN();
