Jeudi 21 décembre 2017 \n
J'ai formé mon groupe avec Charlène Berteina. Nous n'avions pas d'idées concrètes en ce qui concerne le sujet, nous avons donc profité de cette séance pour faire des recherches sur les différents projets Arduino possibles.
Nous avions retenu 7 projets au départ, puis on a fait le tri pour arriver à 3 idées au final.
Finalement, nous avons choisi le triple sismographe RF.

Mercredi 10 janvier 2018
Nous avons réfléchi sur comment allaient se presenter les trois sismographes et comment récupérer les données détectées. On a donc commencé par faire un schéma des trois sismographes avec le Rover et un récepteur sur le Rover. On a pensé à utiliser le module HC-SR04 pour mesurer la distance entre les émetteurs et le récepteur, pour pouboir "guider" le Rover et le faire arrêter là où sont les émetteurs. Mr Masson est passé nous voir pour nous parler des sismographes et il nous a proposé d'utiliser des géophones pour capter et enregistrer les vibrations détectées. Il nous a aussi dit d'utiliser une horloge RCT que l'on placera sur les 3 géophones pour pouvoir détecter lequel des 3 aura reçu des vibrations en premier et ainsi les distinguer. Pour cela il faudra enlever la différence de temps au temps enregistré pour que les 3 géophones "soient réglés à la même heure". Mr Masson nous a donné une carte SD où l'on stockera toutes les données dessus. Il nous a dit que le sismographe devra avoir une carte arduino et une pile. Pour l'instant nous ne nous soucierons pas du chargement de la pile. Notre objectif maintenant est de réussir à détecter des vibrations en utilisant un piezo (à la place du géophone), d'enregister l'heure excate à laquelle les vibrarions ont commencé, et de sauvegarder tout ça sur la  carte SD.

Mercredi 17 janvier 2018
Séances où tous les groupes faisaient leur présentation, nous avons donc rectifié des choses sur notre diapo et nous nous sommes entraînées à l'oral avant notre passage.

Mardi 6 février 2018
M.Masson a reçu les 3 géophones nous avons donc pu commencer à les tester. Nous avons utilisé le logiciel Serial Port Plotter pour visualiser les courbes que les vibrations ont créé. Nous avons simplement placé un géophone sur le sol puis nous avons sauté. Les courbes avaient toutes des amplitudes différentes et même des fois plutôt faibles même lorsque l'on sautait fort. Cela est dû à un mauvais branchement que l'on avait fait pour le montage. M.Masson l'a arrangé et nous avons visualiser les courbes sur l'oscilloscope. C'était beaucoup plus clair et précis.
Nous avons aussi écrit un programme pour visualiser la tension que le piezo mesurait (et il fonctionnait).

Lundi 19 février
On a eu nos modules RS232 avec leurs antennes séparément, on les a donc soudé. J'ai fait des recherches consernant la carte SD pour pouvoir l'utiliser pour la 1ère fois. 

Lundi 12 mars
J'ai touvé un code fonctionnel pour écrire sur un fichier et l'enregistrer sur la carte SD et un autre code pour lire ce fichier. J'ai ensuite voulu tester avec des valeurs fictives enregistrées sur la carte SD manuellement et ces valeurs sont de la forme 'un caractère par ligne', pour essayer de combiner ces valeurs après l'enregistrement, comme ça on pourra faire des graphes avec des valeurs correctes (et non pas avec "2", ".", "0", "4" pour 2.04 par exemple...). Mais ça n'a pas marché.

Lundi 26 mars
On a commencé à voir en quoi consistait la serial communication entre les deux cartes Arduino. On a trouvé plusieurs programmes et méthodes pour établir une communication mais aucune d'entre elles ne marchaient. On a même essayé de relier les 2 cartes entre elles grâce aux pins RX et TX réservés pour la communication mais aucun résulat produit!

Jeudi 5 avril
On a continué à essayer d'avoir une communication entre nos 2 mmodules RS_232. On a trouvé le programme renommé (par nous) 'RF_avec_masse' et il fonctionnait! Charlène a pu m'envoyer 'Hello' et j'ai bien lu 'Hello' sur mon serial monitor.

Lundi 9 avril
Première tentative de synchronisation avec le PC pour que l'horloge RTC 1702 puisse afficher l'heure exacte de mon PC. Ainsi les 3 horloges seront programmées à la même heure exactement et on aura pas de problèmes de décalage horaire. J'ai donc installé les bibliothèques disponibles de l'horloge 1702 mais c'était très compliqué de trouver un code pour la synchroniser. Il n'existe pas de bibliothèque arduino officielle, donc toutes les bibliothèques que j'ai ont été créées par des personnes, il n'y a donc pas toutes les fonctions utiles... J'ai alors cherché comment on pourrait la synchroniser, j'ai essayé plusieurs tutoriels, installé plusieurs fichiers mais rien ne marchait.

Mercredi 2 mai 2018
J'ai encore essayé de faire marcher la synchronisation de l'horloge RTC 1702 avec les différentes bibiliothèques et différents programmes mais rien ne marchaient. Après plusieurs recherches, j'ai enfin compris que le RTC 1702 ne pouvait pas se synchroniser avec le PC. Nous ne pouvions que régler l'heure manuellement. Il faut donc qu'on prenne un RTC 1302.

Lundi 7 mai 2018
On a finalement changé notre module RTC 1702 pour un RTC 3231 pour pouvoir synchroniser l'horloge. J'ai pu tester le code qui synchronise l'horloge avec l'heure du PC, il a fonctionné. J'ai aussi écrit le code pour afficher l'heure et la date actuelle.
Après on a voulu se concentrer sur le problème des 3 géophones, et de comment localiser l'épicentre. On a fait des recherches et on en est venues à la conclusion que cela faisait partie des traitements de données, partie que l'on ne fera pas. On laisse donc tomber les calculs et les codes pour placer les 3 géophones.

Vendredi 18 mai 2018
Moi et Charlène avons tenté d'écrire plusieurs codes pour que nos RS232 communiquent à une fréquence différente. Après maintes essais, nous n'avons pas réussi... Nos modules ne peuvent communiquer entre eux qu'à une fréquence de 9600 baud.

Mardi 22 mai 2018
Après un petit talk avec M.Masson, on a finalement compris pourquoi nos RS232 ne pouvaient pas communiquer entre eux. Ils sont tous les deux reglés pour communiquer à une fréquence de 9600 baud, ça ne changera pas. Par contre la vitesse de fréquence peut être modifiée, et c'est ça qui permettra au Rover de différenier les 3 modules. Mais il se peut qu'on n'ait pas le temps de programmer la vitesse de fréquence des 3 modules donc on va juste se concentrer sur un seul module. Notre but pour l'instant est d'avoir une communication à une vitesse de fréquence qui marche et d'afficher les valeurs reçues.

Jeudi 24 mai 2018
On a fait des tests pour avoir une communication entre les 2 modules RS232 à une fréquence de 9600 baud. Ca a bien marché. Par contre les valeurs du géophone de la carte SD 1 ne sont pas renvoyé correctement à la carte SD 2. Les valeurs sont vu comme des caractères donc on a un carctère par ligne, ce qui ne nous arrange pas.

Vendredi 25 mai 2018
J'ai cherché des programmes qui pouvaient combiner des caractères entre eux de sorte à former une chaîne de caractère pour que Charlène les teste (vu qu'elle est récéptrice pour l'instant). Tous ne marchaient pas ou bien faisaient que certains caractères étaient 'mangés' lors de l'envoi. J'ai donc cherché un programme qui cette fois créait un tableau de caractères avec 4 caractères dedans (vu que nos valeurs sont de la forme 3.70 par exemple). Après en avoir modifié un pour qu'il colle avec notre programme de base, on a pu envoyer des chaines de caractères. Par contre la vitesse d'envoi est très lente. On a ensuite pu visualiser le graphe fait par le logiciel Arduino directement à partir des valeurs envoyées.

Lundi 28 mai 2018
On a modifié nos delay dans nos programmes d'envoi/réception pour changer la vitesse d'envoi. On a remarqué que c'était au niveau de l'émetteur où ça posait problème. Quand on met un delay trop faible, certains caractères sont mangés donc on se retrouve avec des valeurs incorrectes (mais la vitesse est bonne) et quand on met un delay important, là toutes les valeurs sont correctes mais la vitesse d'envoi reste lente/l'envoie est interminable. Recherche du delay correct pour avoir toutes les valeurs envoyées correcement avec une vitesse plus ou moins rapide. 

Mercredi 30 mai 2018
Recherche d'un delay peut-être meilleur. Il a été mis à 50ms pour l'instant. On a ensuite commencé à regrouper tous les programmes sur un seul fichier à exécuter. Le déclenchement de l'enregistrement des valeurs prises par le géophone et leur écriture sur la carte SD1 se fait sans problèmes. On a ensuite affiché la date et l'heure de l'enregistrement au début et à la fin du fichier enregistré. On a ensuite voulu envoyer le tout sur la carte SD2 mais là on a encore eu le problème de la vitesse d'envoi qui était très faible, de l'ordre d'une seconde par valeur... mais cette fois-ci même pour l'enregistrement! C'est à cause de la fonction qui envoie des données, le delay (ou peut-être autre chose) fait que tout le code prend ce delay là, ce qui est bizarre vu que la fonction est exécutée en dehors de la boucle while de l'enregistrement. On va donc quand même utiliser ce code là pour la suite histoire d'envoyer quelque chose. On espère avoir le temps de tout téléverser et de tester avec la pile pour voir si ça marche de manière 'autonome'.
