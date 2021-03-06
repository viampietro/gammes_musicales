UT PROJECT

Description :

Le logiciel UtProject permet à partir d'une grille d'accords de calculer une suite de gammes permettant de jouer sur ces accords.
A chaque accord de la grille est associé une gamme vérifiant que l'ensemble des notes de l'accord se trouvent dans les notes de la gamme.
On peut ainsi aisément profiler un solo, imaginer des mélodies, ou orienter une harmonie vis à vis de notre grille d'accords et de la suite de gammes générée par le logiciel.

Architecture du dépôt :

- assets : fichiers utilisés par les sources (images, fichiers d'import et d'export).
- src : fichiers sources + UtProject.pro, fichier de configuration de l'IDE QtCreator
- stats : fichiers utilisés pour l'affichage des statistiques de performance.
- runnable : contient les executables pour les OS windows et linux.

Execution sur Windows (marche sur Windows 10, Windows 7) :
- Télécharger le dépôt Git (Download ZIP sur la page GitHub) et le décompresser à l'endroit de votre choix.
- Aller dans le dossier '<your_path_to_repo>/runnable/windows/bin/' 
  ou ajouter le chemin '<your_path_to_repo>/runnable/windows/bin' au PATH.
- Lancer le fichier UtProject.exe :
  * ligne de commande : >> START ./UtProject.exe
  * explorer Windows : double-clic sur UtProject.exe
  
Execution sur Linux : 
- Télécharger le dépôt Git (Download ZIP sur la page GitHub) et le décompresser à l'endroit de votre choix.
- Aller dans le dossier '<your_path_to_repo>/runnable/linux/bin/' 
  ou ajouter le chemin vers '<your_path_to_repo>/runnable/linux/bin' au PATH.
- Lancer l'executable :
  * ligne de commande : >> ./Ut  
