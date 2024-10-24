/*
********************************************************************************
* File:        alu_reference_model.c
* Author:      Ahmed Raza
* Date:        October 23, 2024
* Description: This file implements the ALU reference model for the ALU 
*              verification in SystemVerilog testbench through DPI (Direct 
*              Programming Interface). The function performs various ALU 
*              operations based on the ALU selection signal and sets the 
*              expected ALU output and carry-out.
*
* Operations supported:
*   0x0 - Addition
*   0x1 - Subtraction
*   0x2 - Multiplication
*   0x3 - Division
*   0x4 - Logical shift left
*   0x5 - Logical shift right
*   0x6 - Rotate left
*   0x7 - Rotate right
*   0x8 - Logical AND
*   0x9 - Logical OR
*   0xA - Logical XOR
*   0xB - Logical NOR
*   0xC - Logical NAND
*   0xD - Logical XNOR
*   0xE - Greater comparison
*   0xF - Equal comparison
*
* This reference model will be called from the SystemVerilog testbench for 
* comparing the expected results with the DUT output.
********************************************************************************
*/

#include <svdpi.h>

void alu_reference_model(const svLogicVecVal* A, 
                         const svLogicVecVal* B, 
                         const svLogicVecVal* ALU_Sel,
                         svLogicVecVal* ALU_Out,
                         svLogic* Carry_Out) {
    
    unsigned char a = A[0].aval & 0xFF;    // 8-bit input A
    unsigned char b = B[0].aval & 0xFF;    // 8-bit input B
    unsigned char sel = ALU_Sel[0].aval & 0xF; // 4-bit ALU selection
    unsigned char result = 0;            // Result
    unsigned short tmp = 0;              // Temporary for carry calculation
    *Carry_Out = 0;                      // Initialize carry out

    // ALU operations
    if (sel == 0x0) { // Addition
        tmp = a + b;
        result = tmp & 0xFF;
        *Carry_Out = (tmp > 0xFF); // Set carry if overflow
    }
    else if (sel == 0x1) { // Subtraction
        result = a - b;
        *Carry_Out = (a < b); // Set carry if borrow
    }
    else if (sel == 0x2) { // Multiplication
        result = a * b;
    }
    else if (sel == 0x3) { // Division
        result = (b != 0) ? (a / b) : 0; // Handle division by zero
    }
    else if (sel == 0x4) { // Logical shift left
        result = a << 1;
    }
    else if (sel == 0x5) { // Logical shift right
        result = a >> 1;
    }
    else if (sel == 0x6) { // Rotate left
        result = (a << 1) | (a >> 7);
    }
    else if (sel == 0x7) { // Rotate right
        result = (a >> 1) | (a << 7);
    }
    else if (sel == 0x8) { // Logical AND
        result = a & b;
    }
    else if (sel == 0x9) { // Logical OR
        result = a | b;
    }
    else if (sel == 0xA) { // Logical XOR
        result = a ^ b;
    }
    else if (sel == 0xB) { // Logical NOR
        result = ~(a | b);
    }
    else if (sel == 0xC) { // Logical NAND
        result = ~(a & b);
    }
    else if (sel == 0xD) { // Logical XNOR
        result = ~(a ^ b);
    }
    else if (sel == 0xE) { // Greater comparison
        result = (a > b) ? 1 : 0;
    }
    else if (sel == 0xF) { // Equal comparison
        result = (a == b) ? 1 : 0;
    }

    // Set output
    ALU_Out[0].aval = result;
    ALU_Out[0].bval = 0;  // No X or Z states, so set bval to 0
}

