#include "arena.hpp"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Arena arena;
    arena.play();
    return 0;
}