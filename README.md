# CSC Latin America 2026 - HEP Computing Exercises

> High-Performance Computing for Experimental Physics and Data Analysis

[![CI](https://github.com/artfisica/csc2026/actions/workflows/ci.yml/badge.svg)](https://github.com/artfisica/csc2026/actions/workflows/ci.yml)

## Quick Start with GitHub Codespaces

**Recommended**: Click the button below to launch a fully configured development environment:

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/artfisica/csc2026)

The environment includes all tools from the course:
- **Languages**: C++20, Python 3.11
- **HEP Frameworks**: ROOT 6.30
- **Testing**: Catch2, pytest
- **Performance**: Google Benchmark, perf, FlameGraph
- **Parallelism**: OpenMP, oneTBB
- **Debugging**: GDB, ASan, UBSan, TSan

## Repository Structure

```
csc2026/
├── .devcontainer/          # Codespaces/DevContainer configuration
│   ├── devcontainer.json
│   ├── Dockerfile
│   └── post-create.sh
├── .github/workflows/      # CI/CD pipelines
│   └── ci.yml
├── include/                # Header files
├── src/                    # Source files
├── tests/                  # Unit tests
├── benchmarks/             # Performance benchmarks
├── exercises/              # Course exercises
│   ├── E1-debugging/
│   └── E2-optimization/
├── data/                   # Sample data files
└── CMakeLists.txt         # Build configuration
```

## Local Development

### Prerequisites

If not using Codespaces, install:
- CMake ≥ 3.16
- GCC ≥ 11 or Clang ≥ 14
- ROOT ≥ 6.28
- Python ≥ 3.9

### Building

```bash
# Standard build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)

# With sanitizers (for debugging)
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build-debug

# With ThreadSanitizer
cmake -B build-tsan -DCMAKE_BUILD_TYPE=Debug -DENABLE_TSAN=ON
cmake --build build-tsan
```

### Running Tests

```bash
# C++ tests
ctest --test-dir build --output-on-failure

# Python tests
pytest tests/ -v
```

### Running Benchmarks

```bash
./build/benchmarks --benchmark_format=console
```

## Course Exercises

### Exercise E1: Debugging with Sanitizers

Navigate to `exercises/E1-debugging/` and follow the instructions in `README.md`.

**Goals:**
- Find memory bugs using ASan
- Write Catch2 tests to prevent regressions
- Practice atomic commits and CI integration

```bash
cd exercises/E1-debugging
cmake -B build -DENABLE_SANITIZERS=ON
cmake --build build
./build/reconstruction  # Watch for ASan output
```

### Exercise E2: Performance Optimization

**Track A - Algorithmic:**
```bash
cd exercises/E2-optimization/track-a
./build/benchmarks  # Baseline
# Optimize and re-run
```

**Track B - ROOT I/O:**
```bash
cd exercises/E2-optimization/track-b
# Work with ATLAS Open Data
```

## Tools Reference

### Sanitizers

```bash
# Compile with ASan + UBSan
g++ -fsanitize=address,undefined -g program.cpp -o program

# Compile with TSan
g++ -fsanitize=thread -g program.cpp -o program

# Run with environment options
ASAN_OPTIONS=detect_leaks=1 ./program
TSAN_OPTIONS=second_deadlock_stack=1 ./program
```

### Profiling with perf

```bash
# Record profile
perf record -g ./program

# View results
perf report

# Generate flame graph
perf script | stackcollapse-perf.pl | flamegraph.pl > flame.svg
```

### ROOT Quick Reference

```cpp
// Enable multithreading
ROOT::EnableImplicitMT();

// RDataFrame analysis
ROOT::RDataFrame df("Events", "data.root");
auto h = df.Filter("pt > 20.0")
           .Histo1D({"h", "pT", 100, 0, 200}, "pt");
h->Draw();
```

### OpenMP

```cpp
#pragma omp parallel for reduction(+:sum)
for (size_t i = 0; i < data.size(); ++i) {
    sum += data[i];
}
```

### TBB

```cpp
#include <tbb/parallel_for.h>

tbb::parallel_for(
    tbb::blocked_range<size_t>(0, data.size()),
    [&](const auto& r) {
        for (size_t i = r.begin(); i != r.end(); ++i)
            process(data[i]);
    }
);
```

## Resources

- [ATLAS Open Data](https://opendata.atlas.cern/)
- [ROOT Documentation](https://root.cern/doc/master/)
- [HSF Training](https://hepsoftwarefoundation.org/training/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)

## License

Educational materials for CSC Latin America 2026.

## Contact

**Instructor**: Arturo Sánchez Pineda  
- GitHub: [@artfisica](https://github.com/artfisica)
- LinkedIn: [arturo-sanchez-pineda](https://www.linkedin.com/in/arturo-sanchez-pineda/)

---

*CSC Latin America 2026 - Santiago, Chile*  
*INAIT AI | Creative Commons Venezuela & Switzerland*
