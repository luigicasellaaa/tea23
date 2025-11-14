/*
#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

#define SOULS 100

void cursed() {
    char *soul = (char*)malloc(8);
    strcpy(soul, "boo!");
    fmt::println("{}", soul);
}

int main() {
    for(int i=0; i < SOULS; i++) {
        cursed();
    }
}

#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

int main() {
    char *ghost = (char*)malloc(8);
    strcpy(ghost, "evil");
    free(ghost);
    fmt::println("{}", ghost);
}
#include <cstdlib>

int main() {
    while (1) {
        malloc(1024);
    }
}*/

#include <fmt/format.h>
#include "graveyard.h"

int undead = 7;

int main() {
    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}





