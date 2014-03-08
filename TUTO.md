Sur Windows:

	Télécharger GitHub:

			http://windows.github.com

	Ouvrir Git Shell (même commandes que sur linux après)

Sur Linux:
	
	Ouvrir terminal:

		sudo apt-get install git-core gitk





À faire une fois:

	git config --global user.name "pseudo"
	git config --global user.email adresseMailDeGithub

À faire une fois, pour chaque projet:

	- Créer un dossier n'importe où
	- Aller dedans avec le terminal puis

		git clone https://github.com/MatrixOrganization/Matrix.git





À chaque fois pour coder:

	- Aller dans le dossier
	
		git pull 

		(télécharge les modifications de autres personnes)

	- Pendant le Code:

		git commit -a -m "message"

		Il faut faire un commit à chaque fois qu'on modifie un petit bout, par ex. une fonction. 
		Mettez dans le "message" un description de la modification:
			par ex: "-ajout de la fonction addition"
		C'est conseillé pour qu'on sache qui à modifié quoi.

	- À la fin:
		Dès que vous avez fini et que vous allez rien faire de plus:

			git push




!!! 
	C'est conseillé de faire le git push qu'un seule fois par "session de code".
	En gros:
		- Dès que vous faites sauvegarder sur l'éditeur, faites un 'git commit'
		- Dès que vous fermez l'éditeur et que vous vous barrez, faites un 'git push'
!!!

Fonctions avancées:

-	Pour des couleurs:

		git config --global color.diff auto
		git config --global color.status auto
		git config --global color.branch auto







