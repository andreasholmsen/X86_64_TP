# TP en x86_64

### Q1.1.1
a,b,c,d,e sont stockés dans l'addresse contenue dans R7 avec les offsets suivants: 20,16,12,8,4. Donc:
- a -> [R7, #20]
- b -> [R7, #16]
- c -> [R7, #12]
- d -> [R7, #8]
- e -> [R7, #4]

avec R7 = SP. Donc **dans le pile**

### Q.1.1.2
Au debut de sub01(), on soustrait 24 bytes pour le SP, pour allouer suffisament d'espace.
Pour le liberer, on ajoute simplement les 24 bytes pour rendre le zone "cache".

### Q1.1.3
On ne stocke plus tous les variables, mais on calculs directement nos resultats avec les registres. Donc pas d'utilisation de SP/ la pile.

### Q1.2.1
a,b,c,d,e sont stockés dans l'addresse contenue dans %ebp avec les offsets suivants: -0x1c, -0x18, -0x14, -0x10, -0x0c  Donc:
- a -> -0x1c(%ebp)
- b -> -0x18(%ebp)
- c -> -0x14(%ebp)
- d -> -0x10(%ebp)
- e -> -0x0c(%ebp)

avec %ebp = %esp. Donc dans le pile (comme prévu)

### Q1.2.2
Pareil, on alloue de l'espace dans le pile avec SUB et après on le retire avec ADD. Le numero de bytes ajoutés et retirés sont pas pareils parce que au début on utilise "push %rbp" et "mov %rsp, %rbp", et vers le fin, on utilise leave, qui fait l'inverse.

### Q1.2.3
Maintenant, on ne garde plus les résultats dans le pile. Au lieu, on stocke les résultats dans les registres. Le compilateur sait qu'on n'a pas d'interet dans stocker les valeurs - on ne les utilisent pas plus tard.

### Q1.2.4
Au lieu de utiliser add, on fait LEA  (Load Effective Address) pour l'arithmetique qui est plus efficace que mov et add/sub.

### Q1.3.1
On utilise les registres R-- au lieu de E-- (registres de taille 64 bit au lieu de 32 bit).
La taille des registres sont differents

### Q1.3.2
Les instructions sont les mêmes mais les registres sont plus grands (64 bit au lieu de 32 bit).


