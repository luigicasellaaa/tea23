#include <fmt/chrono.h>
#include <fmt/format.h>

#include <stdio.h>

typedef enum {
    STATE_UP,
    STATE_DOWN,
    STATE_STOP_UP,
    STATE_STOP_DOWN,
    STATE_OPEN,
    STATE_CLOSED
} State_t;

typedef enum {
    EVENT_BUTTON,
    EVENT_LIMIT_TOP,
    EVENT_LIMIT_BOTTOM
} Event_t;

typedef struct {
    State_t current;
    Event_t event;
    State_t next;
} Transition_t;

Transition_t transitions[] = {
    { STATE_UP,        EVENT_BUTTON,       STATE_STOP_UP },
    { STATE_STOP_UP,   EVENT_BUTTON,       STATE_DOWN },
    { STATE_DOWN,      EVENT_LIMIT_BOTTOM, STATE_CLOSED },
    { STATE_CLOSED,    EVENT_BUTTON,       STATE_UP },
    { STATE_UP,        EVENT_LIMIT_TOP,    STATE_OPEN },
    { STATE_OPEN,      EVENT_BUTTON,       STATE_DOWN },
    { STATE_STOP_DOWN, EVENT_BUTTON,       STATE_UP },
    { STATE_DOWN,      EVENT_BUTTON,       STATE_STOP_DOWN },
};

const int NUM_TRANSITIONS = sizeof(transitions)/sizeof(Transition_t);

// ❗ FEHLTE
State_t currentState = STATE_UP;

// ❗ FEHLTE
void handleEvent(Event_t event)
{
    for (int i = 0; i < NUM_TRANSITIONS; i++) {
        if (transitions[i].current == currentState &&
            transitions[i].event == event)
        {
            currentState = transitions[i].next;
            return;
        }
    }
}

auto main(int argc, char** argv) -> int
{
    printf("Start state: %d\n", currentState);

    handleEvent(EVENT_BUTTON);       // Up -> StopUp
    printf("State now: %d\n", currentState);

    handleEvent(EVENT_BUTTON);       // StopUp -> Down
    printf("State now: %d\n", currentState);

    handleEvent(EVENT_LIMIT_BOTTOM); // Down -> Closed
    printf("State now: %d\n", currentState);

    handleEvent(EVENT_BUTTON);       // Closed -> Up
    printf("State now: %d\n", currentState);

    fmt::print("Hello, {}!\n", argv[0]);

    return 0;
}

