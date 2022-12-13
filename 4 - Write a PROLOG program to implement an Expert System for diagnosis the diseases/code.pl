symtom(jaydeep,fever).

symtom(jaydeep,rashes).

symtom(jaydeep,stomachache).

symtom(jaydeep,running_nose).

symtom(jaydeep,body_ache).

dis(X,malaria):-symtom(X,fever),symtom(X,headache),symtom(X,running_nose).

dis2(X,jaundice):-symtom(X,fever),symtom(X,stomachache),symtom(X,body_ache).
