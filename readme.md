# TP en x86_64

## EXPO1

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

## EXPO2

### Q.2.1.1
Seed() met la valeur dans r0

### Q.2.1.2
Les valeurs sont stockés dans le pile

### Q.2.1.3
La fonction n'est même pas appellé. Le programme fait les calculs directement.

### Q.2.2.1
La valeur est mise dans %eax

### Q.2.2.2
Tous les valeurs sont mises dans le pile adjecent de les autres. 

### Q.2.2.3
Les arguments sont toujours dans le pile, mais ils sont tous mises dans des registres differents au debut pour faire les calculs au lieu d'être cherchés dans le pile à chaque besoin.

### Q.2.2.4
Sub01() n'est plus appelé. Au lieu, le fonction main() a été modifié pour faire les calculs directement. 

### Q.2.2.5
Le montant d'operations LEA a augmenté, qui est plus efficace qu'une combination d'additions et multiplications. 

### Q.2.3.1
Les arguments sont même pas mises dans le pile. Ils sont directement mises dans les registres pendant la fonction main() et traites directements du debut de la fonction sub01()

## EXPO3

### Q3.1.1
À partir de l'instruction dans sub01() "return i;", la programme arrete de fonctionner proprement

### Q3.1.2
Dans sub02, on essaye d'écrire dans bb[9] qui n'existe pas, donc on écrit dans le cas après le tableau bb dans le pile, qui est l'addresse de retour. Quand on va faire le retour, on n'a plus la bonne valeur

### Q3.1.3
Parce que la programme n'est pas si optimalisé, elle prend encore plus d'espace de la pile pour avoir suffisament d'espace pour les calculs. Ca permet de avoir un espace "securisé", qui ne pose pas de problème pour l'effacement de l'addresse de retour.

### Q3.2.1
Avec un canarie. Un valeur connue est mis dans le pile pour verifiér que le pile n'a pas été changé / n'a pas de comportement abimé. 

On le voit avec la fonction "__stack_chk_fail_local()"

### Q3.2.2
Oui les valeurs dans les registres sont differents à chaque fois. C'est probablement la valeur de la canarie

### Q3.2.3
Non pas correct. Le programme devie à partir de ligne "return i" dans la fonction sub01() ou il ne plus acceder la memoire. Mais il continue un peu pour executer expose(). 

### Q3.2.4
La cause, c'est que on n'a plus de canarie donc on ne verifie plus que l'integrité du pile est correcte. On essaye de lire un addresse pas valide. On a efface l'addresse de retour donc on recoit un Faute de segmentation. 

### Q3.2.5
On écrit dans l'addresse de retour dans sub01() qui provoque qu'on saute à n'importe où. C'est parce que cette fois on a écrase le cas qui contient l'addresse de retour. 


