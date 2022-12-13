db(ganesh,890).

go(X,Y):-write('Enter Username : '),read(X), write('Enter Password : '),read(Y).

login:-go(X,Y),db(X,Y),nl, write('Your username & password are : '),write(X),write(Y).

login:-write('Incorrect Password try again....'),login.
