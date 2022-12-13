go:-write('Enter term number: '),
read(N),
fibo(1,1,0,N).
fibo(_,_,_,0).
fibo(X,B,C,N):-AA is B,
BB is C,
CC is AA+BB,
write(CC),
write(','),
NN is N-1,
fibo(AA,BB,CC,NN).
