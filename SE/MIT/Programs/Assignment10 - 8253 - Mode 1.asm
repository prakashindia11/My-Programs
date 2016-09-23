mov al, 33h     ;CWR
out 33h,al

mov al,05       ;LSB
out 30h,al

mov al,00       ;MSB
out 30h,al

int 3
