#ifndef LEADER_BANK_NOTIFIER_H
#define LEADER_BANK_NOTIFIER_H

#include "bank.h"  // Ensure this is included before any usage of Bank
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

typedef enum {
    StandBy,
    InProgress
} Status;

typedef struct {
    Status status;
    uint64_t slot;  // Slot number
    Bank* bank;     // Pointer to Bank, ensure Bank is a complete type here
} SlotAndBankWithStatus;

typedef struct {
    SlotAndBankWithStatus state;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} LeaderBankNotifier;

void LeaderBankNotifier_init(LeaderBankNotifier* notifier);
void LeaderBankNotifier_setInProgress(LeaderBankNotifier* notifier, Bank* bank);
void LeaderBankNotifier_setCompleted(LeaderBankNotifier* notifier, uint64_t slot);
Bank* LeaderBankNotifier_getOrWaitForInProgress(LeaderBankNotifier* notifier, int timeout_ms);

#endif // LEADER_BANK_NOTIFIER_H
