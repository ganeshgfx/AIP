len_ls([],0).
len_ls([H|T],L):-len_ls(T,LL),L is LL+1.
