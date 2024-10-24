# ALU Reference Model Using DPI in SystemVerilog Testbench

This repository contains the implementation of an Arithmetic Logic Unit (ALU) reference model in C, which is called from a SystemVerilog testbench using Direct Programming Interface (DPI). The ALU performs a variety of operations such as addition, subtraction, multiplication, division, and bitwise operations. The outputs from the C-based reference model are compared with the outputs from the Design Under Test (DUT), ensuring correct behavior of the ALU.

## Overview

The project demonstrates the following:

1. **C Reference Model**: A simple ALU model implemented in C, which can handle 8-bit inputs and perform operations based on a 4-bit control signal (`ALU_Sel`).
2. **DPI Integration**: The ALU function in C is imported into the SystemVerilog testbench using DPI.
3. **Testbench**: The testbench compares the expected values from the C model with the actual output from the hardware ALU implemented in SystemVerilog.

### Key Operations Performed by the ALU
- Addition
- Subtraction
- Multiplication
- Division
- Logical Shift (Left/Right)
- Rotate (Left/Right)
- Logical AND, OR, XOR, NAND, NOR, XNOR
- Comparisons (Equal, Greater Than)

## Files in the Repository

- **alu_reference_model.c**:  
   Contains the C implementation of the ALU model. This function is invoked from the SystemVerilog testbench via DPI.

- **alu_tb.sv**:  
   The testbench that tests the ALU operations by calling the C function and comparing its results with the DUT output.

- **alu.sv**:  
   SystemVerilog implementation of the ALU (Design Under Test).

- **Makefile** (optional):  
   A Makefile for compilation and simulation, if applicable.

## How It Works

1. The ALU operations are defined in the C function `alu_reference_model`.
2. This function is imported into the SystemVerilog testbench using DPI.
3. The testbench applies a set of test vectors to both the hardware ALU and the C reference model.
4. It compares the expected output from the C model with the actual output from the hardware ALU.
5. The results (pass/fail) for each test are printed in the simulation output.

## Running the Simulation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/alu-dpi-verification.git
   ```
