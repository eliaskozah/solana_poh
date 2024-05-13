#ifndef POH_SERVICE_H
#define POH_SERVICE_H

#include "poh_recorder.h"
#include <pthread.h>

// Structure representing the PoH Service
typedef struct {
    PohRecorder* recorder;       
    pthread_t service_thread;   
    bool is_running;             
} PohService;

// Function declarations
PohService* poh_service_create(PohRecorder* recorder);
void poh_service_destroy(PohService* service);
void poh_service_start(PohService* service);
void poh_service_stop(PohService* service);

#endif // POH_SERVICE_H
