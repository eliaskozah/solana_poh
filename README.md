# Solana Proof of History (POH) Emulation

This repository contains a C-based emulation of Solana's Proof of History component, tailored to demonstrate the core functionalities of the POH algorithm as implemented in Solana's blockchain.

## Prerequisites

Before you begin, ensure you have the following tools installed on your system:
- GCC compiler
- Git
- Make

## Installation

Follow these steps to get the project set up on your local machine:

1. **Clone the Repository:**
   ```bash
   git clone git@github.com:yourusername/solana_poh_emulation.git
   cd solana_poh_emulation

2. **Building the Project:**
   Compile the project using Make:
   ```bash
   make

3. **Running the Project:**
   Once the project is built, you can run the simulation with:
   ```bash
   ./main

## Current Limitations
This emulation simplifies or omits certain aspects of the original Solana POH implementation in Rust. Key limitations include:

### Memory Management:
Memory deallocation is not fully handled, which might lead to memory leaks.

### Simplified Functionality:
Not all features of the original POH module are implemented. This includes complex consensus mechanisms, complete cryptographic functions and networking capabilities integral to Solana's functionality.
