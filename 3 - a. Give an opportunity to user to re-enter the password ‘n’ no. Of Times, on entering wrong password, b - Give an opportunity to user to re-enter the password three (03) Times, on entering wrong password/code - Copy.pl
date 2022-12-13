db(ganesh,123).
db(raj,456).

login:-login(0).

login(3):-write('maxx attempt cross'),!.

login(N):-goto(X,Y),db(X,Y),write('login successful');write('wrong uname and pass'),nl,NN is N+1,login(NN).

goto(X,Y):-write('Enter username:'),read(X),write('Enter password:'),read(Y).
