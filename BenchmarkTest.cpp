#include <benchmark/benchmark.h>
#include <iostream>
#include "./include/skiplist.hpp"

static void benchmark_insert(benchmark::State& state) {
    auto level = state.range(0);
    auto cnt = state.range(1);
    SkipList<int, std::string> skiplist(level);
    for(auto _: state) {
        for(int i = 0; i < cnt; i++) {
            skiplist.insertElement(i, std::string("HouChen"));
        }
        state.PauseTiming();
        skiplist.clearSkiplist();
        state.ResumeTiming();
    }
}
BENCHMARK(benchmark_insert) -> Args({18, 10000}) -> Args({18, 100000}) -> Args({18, 500000});

static void benchmark_search(benchmark::State& state) {
    auto level = state.range(0);
    auto cnt = state.range(1);
    SkipList<int, std::string> skiplist(level);
    for(int i = 0; i < cnt; i++) {
        skiplist.insertElement(i, std::string("HouChen"));
    }
    for(auto _: state) {
        for(int i = 0; i < cnt; i++) {
            skiplist.searchElement(i);
        }
        state.PauseTiming();
        skiplist.clearSkiplist();
        state.ResumeTiming();
    }
}
BENCHMARK(benchmark_search) -> Args({18, 500000}) -> Args({18, 100000}) -> Args({18, 500000});

static void benchmark_delete(benchmark::State& state) {
    auto level = state.range(0);
    auto cnt = state.range(1);
    SkipList<int, std::string> skiplist(level);
    for(int i = 0; i < cnt; i++) {
        skiplist.insertElement(i, std::string("HouChen"));
    }
    for(auto _: state) {
        for(int i = 0; i < cnt; i++) {
            skiplist.deleteElement(i);
        }
        state.PauseTiming();
        skiplist.clearSkiplist();
        state.ResumeTiming();
    }
}
BENCHMARK(benchmark_delete) -> Args({18, 10000}) -> Args({18, 100000}) -> Args({18, 500000});

static void benchmark_update(benchmark::State& state) {
    auto level = state.range(0);
    auto cnt = state.range(1);
    SkipList<int, std::string> skiplist(level);
    for(int i = 0; i < cnt; i++) {
        skiplist.insertElement(i, std::string("HouChen"));
    }
    for(auto _: state) {
        for(int i = 0; i < cnt; i++) {
            skiplist.updateElement(i, std::string("Hello"));
        }
        state.PauseTiming();
        skiplist.clearSkiplist();
        state.ResumeTiming();
    }
}
BENCHMARK(benchmark_update) -> Args({18, 10000})-> Args({18, 100000}) -> Args({18, 500000});

BENCHMARK_MAIN();