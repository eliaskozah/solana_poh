#include "bank.h"
#include <stdlib.h>


// Create a new bank
Bank* bank_create() {
    Bank *bank = malloc(sizeof(Bank));
    if (bank) {
        bank->accounts = NULL;
        bank->num_accounts = 0;
    }
    return bank;
}

// Destroy a bank
void bank_destroy(Bank* bank) {
    // Free all accounts
    for (int i = 0; i < bank->num_accounts; i++) {
        free(&bank->accounts[i]);
    }
    free(bank->accounts);
    free(bank);
}

// Create a new account with an initial balance
Account* bank_create_account(Bank* bank, int initial_balance) {
    // Simplification: just reallocating each time (not efficient)
    bank->accounts = realloc(bank->accounts, (bank->num_accounts + 1) * sizeof(Account));
    bank->accounts[bank->num_accounts].balance = initial_balance;
    bank->num_accounts++;
    return &bank->accounts[bank->num_accounts - 1];
}

// Delete an account
void bank_delete_account(Bank* bank, Account* account) {
    // Simplified: we're not actually removing the account in a real sense
}

// Get the balance of an account
int bank_get_balance(Account* account) {
    return account->balance;
}

// Transfer amount from one account to another
void bank_transfer(Bank* bank, Account* from, Account* to, int amount) {
    if (from->balance >= amount) {
        from->balance -= amount;
        to->balance += amount;
    }
}

