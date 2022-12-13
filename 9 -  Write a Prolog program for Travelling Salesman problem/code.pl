read('surat','valsad',100).
read('valsad','pune',150).
read('pune','mumbai',100).
read('silvassa','masat',500).
find:-write('Source center:'),read(City1),write('Dest center:'),read(City2),route(City1,City2,Dist). 

route(City1,City2,Dist):-read(City1,City2,Dist),write('Distance bet. '),write(City1),write(' and '),write(City2),write(' is '),write(Dist),nl,nl. 
route(City1,City2,Dist):-read(City1,X,Dist1),route(X,City2,Dist2),Dist=Dist1+Dist2, write('Distance bet. '),write(City1),write(' and '),write(City2),write(' is '),write(Dist),nl.
