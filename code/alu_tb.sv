`timescale 1ns / 1ps  

module tb_alu;

//Import Function for ALU
  import "DPI-C" context function void alu_reference_model(input logic [7:0] A, B,
                                                 input logic [3:0] ALU_Sel,
                                                 output logic [7:0] ALU_Out,
                                                 output logic CarryOut
                                                );
  
//Inputs
 logic [7:0] A,B;
 logic [3:0] ALU_Sel;

//Outputs
 logic [7:0] ALU_Out;
 logic  CarryOut;
 
 //Expected Outputs variables
 logic [7:0] exp_result;
 logic exp_carry;
  
 // Verilog code for ALU
 integer i;
 alu test_unit(
            A,B,  // ALU 8-bit Inputs                 
            ALU_Sel,// ALU Selection
            ALU_Out, // ALU 8-bit Output
            CarryOut // Carry Out Flag
     );
    initial begin
    // hold reset state for 100 ns.
      A = 8'h0;
      B = 8'h0;
      ALU_Sel = 4'h0;
      #100;
      
      A = 8'hFA;
      B = 8'hF0;
      ALU_Sel = 4'h0;
      
      for (i=0;i<=15;i=i+1)
      begin
       #1;

       //Call ALU function here and store the result in expected output variables
        alu_reference_model(A, B, ALU_Sel, exp_result, exp_carry);
       
        if (exp_carry != CarryOut && exp_result != ALU_Out)
          $display("test Fail: Expected=%d, Actual=%d", exp_result, ALU_Out);
      else
        $display("test Pass: Expected=%d, Actual=%d", exp_result, ALU_Out);
       #10;
       ALU_Sel = ALU_Sel + 4'h1;
      end;
      
      A = 8'hF6;
      B = 8'h0A;
      
    end
endmodule

