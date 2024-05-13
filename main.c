#include "include/bank.h"
#include "include/poh_recorder.h"
#include "include/poh_service.h"
#include "include/leader_bank_notifier.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>  // For string manipulation functions like strcpy

int main() {
    // Create a new bank
    Bank* bank = bank_create();

    // Create accounts for Alice and Bob with initial balances
    Account* alice = bank_create_account(bank, 1000);
    Account* bob = bank_create_account(bank, 500);

    // Setup the PoH Recorder and Service
    PohRecorder* poh_recorder = poh_recorder_create(bank);
    PohService* poh_service = poh_service_create(poh_recorder);

    // Start the PoH service to simulate the passage of time
    poh_service_start(poh_service);

    // Simulate receiving transaction hashes and mixing them into the PoH chain
    char transaction_hash[32];
    strcpy(transaction_hash, "abc123");  // Example hash
    poh_recorder_record(poh_recorder, transaction_hash);

    // Process some transactions
    printf("Initial balance - Alice: %d, Bob: %d\n", bank_get_balance(alice), bank_get_balance(bob));
    bank_transfer(bank, alice, bob, 200);
    printf("After transfer - Alice: %d, Bob: %d\n", bank_get_balance(alice), bank_get_balance(bob));

    // Let the service run for a short time to simulate continuous operation
    sleep(2);

    // Stop the PoH service
    poh_service_stop(poh_service);

    // Cleanup resources
    poh_service_destroy(poh_service);
    poh_recorder_destroy(poh_recorder);
    bank_delete_account(bank, alice);
    bank_delete_account(bank, bob);
    bank_destroy(bank);

    return 0;
}
