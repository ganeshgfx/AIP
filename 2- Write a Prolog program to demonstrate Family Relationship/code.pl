male(sumit).
male(lalchandrabhai).
male(kalikaprasad).

female(sangita).
female(sushma).
female(premaben).
female(surajkali).

parent(premaben,sumit).
parent(premaben,sushma).
parent(premaben,sangita).
parent(lalchandrabhai,sumit).
parent(lalchandrabhai,sushma).
parent(lalchandrabhai,sangita).
parent(kalikaprasad,lalchandrabhai).
parent(surajkali,lalchandrabhai).

sister(sangita,sumit).
sister(sangita,sumit).

grandfather(kalikaprasad,sumit).
grandfather(kalikaprasad,sushma).
grandfather(kalikaprasad,sangita).

grandmother(surajkali,sumit).
grandmother(surajkali,sushma).
grandmother(surajkali,sangita).

son(X,Y,Z):-male(Y),female(Z),parent(Y,X),parent(Z,X),male(X),!.
daughter(X,Y,Z):-male(Y),female(Z),parent(Y,X),parent(Z,X),female(X),!.
gfs(X,Y):-male(X),parent(X,Z),parent(Z,Y),male(Y),!.
gfd(X,Y):-male(X),parent(X,Z),parent(Z,Y),female(Y),!.
gms(X,Y):-female(X),parent(X,Z),parent(Z,Y),male(Y),!.
gmd(X,Y):-female(X),parent(X,Z),parent(Z,Y),female(Y),!.
gs(X,Y,Z):-male(X),grandfather(Y,X),grandmother(Z,X),!.
gd(X,Y,Z):-female(X),grandfather(Y,X),grandmother(Z,X),!.
