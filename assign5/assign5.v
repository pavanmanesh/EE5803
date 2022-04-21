module assign5(
input wire a,
input wire b,
input wire c,

output wire redled,
output wire greenled,
output wire blueled
);


reg out;
always @(*)
begin
out = !(a&!((!b)&c));
if(out == 1)
begin
redled = 1;
end
else
begin
redled = 0;
end
end
endmodule
