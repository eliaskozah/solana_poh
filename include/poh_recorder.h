#ifndef POH_RECORDER_H
#define POH_RECORDER_H

#include "bank.h"
#include <pthread.h>
#include <stdint.h>
#include <stdbool.h>

// Structure to hold PoH record information
typedef struct {
    uint64_t tick_height;       // Current tick height
    uint64_t min_tick_height;   // Minimum tick height for the current bank
    uint64_t max_tick_height;   // Maximum tick height for the current bank
    uint64_t slot;              // Current slot
    char hash[32];              // Current hash in the PoH sequence
    bool is_tick;               // Flag to check if the current entry is a tick
} Entry;

// Structure to manage PoH recording
typedef struct {
    pthread_mutex_t mutex;
    pthread_t tick_thread;      // Thread for ticking
    Bank* working_bank;         // Current working bank
    bool is_exited;             // Flag to control thread execution
    Entry current_entry;        // Current PoH entry
} PohRecorder;

// Function declarations
PohRecorder* poh_recorder_create(Bank* bank);
void poh_recorder_destroy(PohRecorder* recorder);
void poh_recorder_record(PohRecorder* recorder, const char* hash);

#endif // POH_RECORDER_H
