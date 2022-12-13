sum([],0).
sum([H|T],S):-sum(T,Temp),S is Temp+H.
