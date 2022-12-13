go:-write('Enter capacity of X jug:'),read(X),write('Enter capacity of Y jug:'),read(Y),jug(X,Y).
jug(X,Y):-X>4,write('Not Valid capacity'),!.
jug(X,Y):-Y>3,write('Not Valid capacity'),!.

jug(0,0):-write('(0,0)'),nl,jug(0,3).
jug(4,3):-write('(4,3)'),nl,jug(4,0).
jug(4,0):-write('(4,0)'),nl,jug(1,3).
jug(1,3):-write('(1,3)'),nl,jug(0,3).
jug(0,3):-write('(0,3)'),nl,jug(3,0).
jug(3,0):-write('(3,0)'),nl,jug(3,3).
jug(3,3):-write('(3,3)'),nl,jug(4,2).
jug(4,2):-write('(4,2)'),nl,jug(0,2).
jug(0,2):-write('(0,2)'),nl,jug(2,0).
jug(2,Z):-write('(2,'),write(Z),write(')').
