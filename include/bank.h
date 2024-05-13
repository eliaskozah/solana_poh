#ifndef BANK_H
#define BANK_H

#include <stdint.h>
#include <stddef.h>

typedef struct Account Account;
typedef struct Bank Bank;

struct Account {
    int balance;
};

struct Bank {
    uint64_t slot;
    Account *accounts;  // This is a simplification
    int num_accounts;
};

// Bank functions
Bank* bank_create();
void bank_destroy(Bank* bank);

// Account functions
Account* bank_create_account(Bank* bank, int initial_balance);
void bank_delete_account(Bank* bank, Account* account);
int bank_get_balance(Account* account);
void bank_transfer(Bank* bank, Account* from, Account* to, int amount);

#endif // BANK_H
