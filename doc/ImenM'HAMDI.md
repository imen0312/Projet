Séance 1 (Jeudi 21 décembre 2017) :
J'ai formé mon groupe avec Charlène Berteina. Nous n'avions pas d'idées concrètes en ce qui concerne le sujet, nous avons donc profité de cette séance pour faire des recherches sur les différents projets Arduino possibles.
Nous avions retenu 7 projets au départ, puis on a fait le tri pour arriver à 3 idées au final.
Finalement, nous avons choisi le triple sismographe RF.

Séance 2 (Mercredi 10 janvier 2018) :
Nous avons réfléchi sur comment allaient se presenter les trois sismographes et comment récupérer les données détectées. On a donc commencé par faire un schéma des trois sismographes avec le Rover et un récepteur sur le Rover. On a pensé à utiliser le module HC-SR04 pour mesurer la distance entre les émetteurs et le récepteur, pour pouboir "guider" le Rover et le faire arrêter là où sont les émetteurs. Mr Masson est passé nous voir pour nous parler des sismographes et il nous a proposé d'utiliser des géophones pour capter et enregistrer les vibrations détectées. Il nous a aussi dit d'utiliser une horloge RCT que l'on placera sur les 3 géophones pour pouvoir détecter lequel des 3 aura reçu des vibrations en premier et ainsi les distinguer. Pour cela il faudra enlever la différence de temps au temps enregistré pour que les 3 géophones "soient réglés à la même heure". Mr Masson nous a donné une carte SD où l'on stockera toutes les données dessus. Il nous a dit que le sismographe devra avoir une carte arduino et une pile. Pour l'instant nous ne nous soucierons pas du chargement de la pile. Notre objectif maintenant est de réussir à détecter des vibrations en utilisant un piezo (à la place du géophone), d'enregister l'heure excate à laquelle les vibrarions ont commencé, et de sauvegarder tout ça sur la  carte SD.

Séance 3 (Mercredi 17 janvier 2018) :
Séances où tous les groupes faisaient leur présentation, nous avons donc rectifié des choses sur notre diapo et nous nous sommes entraînées à l'oral avant notre passage.

Séance 4 (Mardi 6 février 2018) :
M.Masson a reçu les 3 géophones nous avons donc pu commencer à les tester. Nous avons utilisé le logiciel Serial Port Plotter pour visualiser les courbes que les vibrations ont créé. Nous avons simplement placé un géophone sur le sol puis nous avons sauté. Les courbes avaient toutes des amplitudes différentes et même des fois plutôt faibles même lorsque l'on sautait fort. Cela est sans doute dû au microphone du géophone qui est placé vraiment au centre (seulement la tige touchait le sol). Lorque les géophones seront plantés quelque part, là les microphones pourront capter les différentes vibrations, même les plus faibles on espère.
Nous avons aussi écrit un programme pour visualiser la tension que le piezo mesurait (et il fonctionnait).
