#include "poh_recorder.h"
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to simulate hash generation and PoH ticking
void* tick_function(void* arg) {
    PohRecorder* recorder = (PohRecorder*) arg;
    while (!recorder->is_exited) {
        pthread_mutex_lock(&recorder->mutex);
        if (recorder->working_bank != NULL) {
            // Simulate the PoH hashing process
            snprintf(recorder->current_entry.hash, sizeof(recorder->current_entry.hash), "%ld", time(NULL));
            recorder->current_entry.tick_height++;
            recorder->current_entry.is_tick = true;
        }
        pthread_mutex_unlock(&recorder->mutex);
        usleep(100000);  // Sleep for 100ms
    }
    return NULL;
}

// Create a new PoH Recorder
PohRecorder* poh_recorder_create(Bank* bank) {
    PohRecorder* recorder = malloc(sizeof(PohRecorder));
    if (recorder != NULL) {
        pthread_mutex_init(&recorder->mutex, NULL);
        recorder->working_bank = bank;
        recorder->is_exited = false;
        pthread_create(&recorder->tick_thread, NULL, tick_function, recorder);
    }
    return recorder;
}

// Destroy the PoH Recorder
void poh_recorder_destroy(PohRecorder* recorder) {
    if (recorder != NULL) {
        recorder->is_exited = true;
        pthread_join(recorder->tick_thread, NULL);
        pthread_mutex_destroy(&recorder->mutex);
        free(recorder);
    }
}

// Record a new hash in the PoH sequence
void poh_recorder_record(PohRecorder* recorder, const char* hash) {
    pthread_mutex_lock(&recorder->mutex);
    if (recorder->working_bank != NULL) {
        strncpy(recorder->current_entry.hash, hash, sizeof(recorder->current_entry.hash) - 1);
        recorder->current_entry.is_tick = false;
    }
    pthread_mutex_unlock(&recorder->mutex);
}
