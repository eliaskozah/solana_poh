This repository contains a C-based emulation of Solana's Proof of History component, designed to demonstrate the core functionalities of the POH algorithm as implemented in Solana's blockchain.

Quick Installation and Running Instructions
To download and run the POH emulation, follow these steps:

Prerequisites
GCC compiler
Git
Make
Installation
Clone the Repository:

bash
Copy code
git clone git@github.com:yourusername/solana_poh_emulation.git
cd solana_poh_emulation
Build the Project:

bash
Copy code
make
Run the Simulation:

bash
Copy code
./main
Current Limitations
This emulation is a simplified version and does not encompass all aspects of the original Solana POH implementation in Rust. The key differences and limitations include:

Memory Management: The current implementation does not fully handle memory deallocation, which can lead to memory leaks.
Incomplete Functionality:
The simulation does not include all POH-related features such as more complex consensus mechanisms and complete networking functionality.
Certain cryptographic aspects of POH are simplified or omitted.
