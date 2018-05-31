
**Séance 1 : Jeudi 21 Décembre**  
Recherche du projet:  
Nous avons rechercher différentes idées pour notre projet. J'ai notamment retenu les idées suivantes:
- Horloge binaire: http://www.instructables.com/id/Arduino-Powered-Binary-Clock/ 
- Caméra macroscopique: http://www.instructables.com/id/RPi-MacroScope/   
  
Notre choix définitif s'est porté sur le triple sismographe RF qui sera ajouté à l'équipement du Rover R6P4 déjà existant.


**Seance 2 : Mercredi 10 Janvier**   
Détail des objectifs:  
Nous avons rechercher les différentes parties qui composeraient notre projet. Il sera divisé en deux parties majeures:
- l'enregistrement des données sismiques.
- la transmission de ces données au Rover R6P4.  
  
On intégrera sur le Rover, un système RF 232 relié à une carte Arduino. Trois géophones réaliseront l'enregistrement des données.
Chaque géophone sera composé des éléments suivants: un système RF 232, une pile, une horloge RTC, une carte Arduino, une carte SD et un géophone.

**Séance 3 : Mercredi 24 Janvier**  
Présentation du projet.

**Séance 4 : Mercredi 07 Février**  
Nous avons d'abord testé le piézo avec le programme "Géophone" et pu obtenir le sismographe des mouvements détectés. En suite, nous avons tester un des trois géophones définitifs, en observant les secousses mesurées avec le logiciel Serial Port  Plotter. Cependant, le montage que nous avions réalisé ne permettait pas d'obtenir de bons résultats. En testant le géophone sur les oscilloscopes, nous avons eu la confirmation que le problème venait du montage et non du géophone.

**Séance 5 : Lundi 19 Février**  
Nous avons soudé les antennes aux modules RF. Nous avons obtenu les programmes "Mise_a_l_heure" et "Lecture_de_l_heure". J' ai vérifié le bon fonctionnement de ces programmes.

**Séance 6 : Lundi 12 Mars**  
Avec le schéma correct du circuit avec le géophone et un amplificateur, j'ai pu réaliser le bon montage. Ainsi, nous pouvons désormais visualiser un sismogramme correct avec une percision optimale.
  
**Séance 7 : Lundi 26 Mars**  
Nous avons débuté les recherches pour établir une connection sans fil entre nos deux cartes Arduino grâce aux modules RF. Nous avons testé différents programmes et circuits sans succés.
  
**Séance 8 : Jeudi 05 Avril**  
Nous avons continué la recherche pour établir la communication entre les cartes. Finalement, avant la séance 9 nous avons réussit à établir cette connection avec le programme "RF". Ma carte a le rôle de transmetteur ,et celle d'Imen de récepteur.
  
**Séance 9 : Lundi 09 Avril**  
Je développe le programme de déclenchement d'enregistrement des données du géophone sur la carte SD. Je me base sur le programme d'Imen: "SDcard_save".

**Séance 10 : Lundi 07 Mai**  
J'ai terminé le programme de déclenchement de l'enregistrement des données sur la carte SD. Les données sont en Volts.

**Séance 11 : semaine du 14 Mai**
On s'est penchées sur le programme du Rover permettant de communiquer successivement avec les trois géophones. Malheureusement, nous n'avions pas la bonnes méthodes. Cette partie a donc été abandonnées par manque de temps. 

**Séance 12 : semaine du 21 Mai**  
Nous avons réalisé le programme de transfert de fichier de la carte SD du géophone vers le Rover.D'abord, on reçoit les données chractere par charactere, donc pour pouvoir utiliser les données on a testé plusieures codes pour reconstituer les nombres. Exemple: On reoit: 
3  
.  
2  
4  
On affiche sur le moniteur série du Rover (récepteur):3.24  
Cela a été possible à l'aide d'un caractère qui est envoyé à la fin de chaque nombre. Ce charactère est reconnu par le récepteur qui sait alors lorsque le nombre est terminé.
Ainsi, on a pu afficher les données que le Rover reçoit sous forme de graphique.
  
Nous avons aussi voulu crée un pogramme pour le Rover qui demande au géophone de lui envoyer ses données. Cependant, le double échange entre les deux Arduinos n'a pas fonctionné. Une cause possible a cela: pour que le RF232 débute sa transmission Imen est obligée de déconnecter puis reconnecter l'alimentation du RF. Il en va de même pour déclencher la demande du Rover vers le géophone. Ce problème empèche l'autonomie du géophone.
  
**Séance 13 : semainde du 28 Mai**  
On a ressemblé tous les programmes du géohones sur une seule carte Arduino. Pour cela, nous avons fusionné plusieurs programmes: lecteure de l'heure, déclenchement de l'enregistrement du séisme et envoi du fichier précedemment enregistré.
