#pragma once

#include <vector>

namespace csc2026 {

struct Particle {
    double px{};
    double py{};
    double pz{};
    double mass{};

    double energy() const;
};

struct Event {
    int id{};
    std::vector<Particle> particles{};
};

} // namespace csc2026

