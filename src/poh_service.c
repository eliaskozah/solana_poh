#include "poh_service.h"
#include <unistd.h>

void* service_function(void* arg) {
    PohService* service = (PohService*) arg;
    while (service->is_running) {
        poh_recorder_record(service->recorder, "hash_from_service");
        usleep(500000);  // Sleep for 500ms to simulate work
    }
    return NULL;
}

PohService* poh_service_create(PohRecorder* recorder) {
    PohService* service = malloc(sizeof(PohService));
    if (service != NULL) {
        service->recorder = recorder;
        service->is_running = false;
    }
    return service;
}

void poh_service_destroy(PohService* service) {
    if (service != NULL) {
        poh_service_stop(service);
        free(service);
    }
}

void poh_service_start(PohService* service) {
    if (!service->is_running) {
        service->is_running = true;
        pthread_create(&service->service_thread, NULL, service_function, service);
    }
}

void poh_service_stop(PohService* service) {
    if (service->is_running) {
        service->is_running = false;
        pthread_join(service->service_thread, NULL);
    }
}
