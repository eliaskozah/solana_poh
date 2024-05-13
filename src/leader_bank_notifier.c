#include "leader_bank_notifier.h"
#include "../include/bank.h"
#include <stdint.h> // Include for uint64_t definition

void LeaderBankNotifier_init(LeaderBankNotifier* notifier) {
    pthread_mutex_init(&notifier->mutex, NULL);
    pthread_cond_init(&notifier->cond, NULL);
    notifier->state.status = StandBy;
    notifier->state.slot = 0;
    notifier->state.bank = NULL;
}

void LeaderBankNotifier_setInProgress(LeaderBankNotifier* notifier, Bank* bank) {
    pthread_mutex_lock(&notifier->mutex);
    notifier->state.status = InProgress;
    notifier->state.slot = bank->slot;  
    notifier->state.bank = bank;
    pthread_mutex_unlock(&notifier->mutex);
    pthread_cond_broadcast(&notifier->cond);
}

void LeaderBankNotifier_setCompleted(LeaderBankNotifier* notifier, uint64_t slot) {
    pthread_mutex_lock(&notifier->mutex);
    if (notifier->state.status == InProgress && notifier->state.slot == slot) {
        notifier->state.status = StandBy;
        pthread_cond_broadcast(&notifier->cond);
    }
    pthread_mutex_unlock(&notifier->mutex);
}
