# SD-E2: Benchmark and Optimise

**Timetable slot:** Software Design **E2** (60 minutes)

This exercise is a constrained optimisation loop: measure first, change one thing, measure again.

## Learning objectives

By the end you can:

- Run Google Benchmark and interpret basic results
- Use a baseline to avoid “optimising blind”
- Apply one targeted optimisation (layout or loop) without breaking correctness

## Timebox plan (60 min)

- 0–10: build and run the baseline benchmark
- 10–25: choose one optimisation lever (layout or loop)
- 25–45: implement the change and re-run benchmark
- 45–55: validate correctness (same numeric results)
- 55–60: write down baseline vs improved results + commit

## Success criteria

- `bench_layout` runs
- You capture baseline and improved numbers
- Correctness is preserved within tolerance

## Where to work

Start in:

- `starter/`

## Commands

```bash
cd exercises/SD-E2-benchmark-and-optimize/starter

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"

./build/bench_layout --benchmark_format=console
```

## Stretch (only if you finish early)

* Add a second benchmark case (different particle count)
* Add a lightweight correctness check inside the benchmark code path





BM_AoS_SumEnergy/1000_mean           1350 ns         1350 ns            3
BM_AoS_SumEnergy/1000_median         1380 ns         1380 ns            3
BM_AoS_SumEnergy/1000_stddev         55.2 ns         55.1 ns            3
BM_AoS_SumEnergy/1000_cv             4.09 %          4.08 %             3
BM_AoS_SumEnergy/10000_mean         15267 ns        15265 ns            3
BM_AoS_SumEnergy/10000_median       14815 ns        14813 ns            3
BM_AoS_SumEnergy/10000_stddev         995 ns          995 ns            3
BM_AoS_SumEnergy/10000_cv            6.51 %          6.52 %             3
BM_AoS_SumEnergy/100000_mean       160547 ns       160532 ns            3
BM_AoS_SumEnergy/100000_median     159712 ns       159703 ns            3
BM_AoS_SumEnergy/100000_stddev       2768 ns         2767 ns            3
BM_AoS_SumEnergy/100000_cv           1.72 %          1.72 %             3
BM_SoA_SumEnergy/1000_mean          66903 ns        66897 ns            3
BM_SoA_SumEnergy/1000_median        66922 ns        66915 ns            3
BM_SoA_SumEnergy/1000_stddev         85.1 ns         84.7 ns            3
BM_SoA_SumEnergy/1000_cv             0.13 %          0.13 %             3
BM_SoA_SumEnergy/10000_mean        679057 ns       678992 ns            3
BM_SoA_SumEnergy/10000_median      674916 ns       674850 ns            3
BM_SoA_SumEnergy/10000_stddev       12934 ns        12902 ns            3
BM_SoA_SumEnergy/10000_cv            1.90 %          1.90 %             3
BM_SoA_SumEnergy/100000_mean      6711689 ns      6711067 ns            3
BM_SoA_SumEnergy/100000_median    6709201 ns      6708703 ns            3
BM_SoA_SumEnergy/100000_stddev      12625 ns        12790 ns            3
BM_SoA_SumEnergy/100000_cv           0.19 %          0.19 %             3



---
Load Average: 1.62, 1.45, 1.37
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_AoS_SumEnergy/1000_mean           1530 ns         1530 ns            3
BM_AoS_SumEnergy/1000_median         1525 ns         1525 ns            3
BM_AoS_SumEnergy/1000_stddev         19.6 ns         19.6 ns            3
BM_AoS_SumEnergy/1000_cv             1.28 %          1.28 %             3
BM_AoS_SumEnergy/10000_mean         16079 ns        16078 ns            3
BM_AoS_SumEnergy/10000_median       16096 ns        16095 ns            3
BM_AoS_SumEnergy/10000_stddev        35.3 ns         35.7 ns            3
BM_AoS_SumEnergy/10000_cv            0.22 %          0.22 %             3
BM_AoS_SumEnergy/100000_mean       168743 ns       168719 ns            3
BM_AoS_SumEnergy/100000_median     168445 ns       168425 ns            3
BM_AoS_SumEnergy/100000_stddev       1001 ns          993 ns            3
BM_AoS_SumEnergy/100000_cv           0.59 %          0.59 %             3
BM_SoA_SumEnergy/1000_mean           1207 ns         1207 ns            3
BM_SoA_SumEnergy/1000_median         1201 ns         1201 ns            3
BM_SoA_SumEnergy/1000_stddev         16.4 ns         16.4 ns            3
BM_SoA_SumEnergy/1000_cv             1.36 %          1.36 %             3
BM_SoA_SumEnergy/10000_mean         11966 ns        11966 ns            3
BM_SoA_SumEnergy/10000_median       11945 ns        11945 ns            3
BM_SoA_SumEnergy/10000_stddev        55.8 ns         55.8 ns            3
BM_SoA_SumEnergy/10000_cv            0.47 %          0.47 %             3
BM_SoA_SumEnergy/100000_mean       125464 ns       125459 ns            3
BM_SoA_SumEnergy/100000_median     125457 ns       125452 ns            3
BM_SoA_SumEnergy/100000_stddev        259 ns          258 ns            3
BM_SoA_SumEnergy/100000_cv           0.21 %          0.21 %             3