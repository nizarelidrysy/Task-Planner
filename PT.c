#include<stdio.h>
#include<string.h>
struct alpha{ // La structure qui définie les détailles de la tâche
	char name[100],description[200],clock_time[2];
	int day,month,year,hour,min;
};
int main(void){
	printf("\nBienvenue a votre Planificateur de Taches!\n"); // Message d'accueil. S'affiche une seule fois, au début
	int n=0,nt=0,ti,jdm,i,choice_del,choice_prnt;
	unsigned choice,reponse;
	struct alpha t[n]; // Tableau qui va contenir les tâches
	main: // S'utilise avec la fonction "goto"
	printf("\n - Nombre de taches : %d\n",nt); // Affiche le nombre total de tâches
	printf("\n1- Ajouter des taches\n\n2- Afficher des taches\n\n3- Supprimer des taches\n\n4- Quitter\n\n-> ");
	scanf("%d",&choice);
	while(choice<1||choice>4){ // Boucle de contrôle de saisie
		printf("\nChoix invalide, veuillez rechoisir : \n");
		printf("\n1- Ajouter des taches\n\n2- Afficher des taches\n\n3- Supprimer des taches\n\n4- Quitter\n\n-> ");
		scanf("%d",&choice);
	}
	switch(choice){ // Boucle des cas
		case 1:{ // Cas d'entrée des tâches
			printf("\nCombien de taches voulez vous introduire ?\n\n-> ");
			scanf("%d",&ti);
			while(ti<1){ // Boucle de contrôle de saisie
				printf("\nNombre invalide, veuillez redire le nombre de taches que vous voulez introduire\n\n-> ");
				scanf("%d",&ti);
			}
			for(i=0;i<ti;i++){ // Répéter selon le nombre de tâches que l'utilisateur veut entrer
				printf("\nEntrez la tache numero %d\n\n-> ",i+1);
				scanf(" %[^\n]",t[n].name);
				printf("\nLa description de cette tache ?\n\n-> ");
				scanf(" %[^\n]",t[n].description);
				printf("\nLa date de cette tache ?\n\n-> ");
				second: // S'utilise avec la fonction "goto"
				scanf("%d%d%d",&t[n].day,&t[n].month,&t[n].year);
				while(t[n].year<2000){ // Contrôle de saisie de l'année
					printf("\nLa date est invalide, veuillez retaper la date de cette tache\n\n-> ");
					goto second;
				}
				while(t[n].month<1||t[n].month>12){ // Contrôle de saisie du mois
					printf("\nLa date est invalide, veuillez retaper la date de cette tache\n\n-> ");
					goto second;
				}
				// Vérification si le nombre de jours est compatible avec le mois donné
				if(t[n].month==4||t[n].month==6||t[n].month==9||t[n].month==11){
					jdm=30;
				}
				// Vérification si l'année est Bissextile pour février
				else if(t[n].month==2){
					if((t[n].year%4==0&&t[n].year%100!=0)||(t[n].year%400==0)){ 
						jdm=29;
					} 
					else{
						jdm=28;
					}
				} 
				else{
					jdm=31;
				}
				if(t[n].day>=1&&t[n].day<=jdm){
					goto third; // <==> Date vérifiée
				}
				else{
					printf("\nLa date est invalide, veuillez retaper la date de cette tache\n\n-> ");
					goto second; // <==> Date incorrecte
				}
				third: // S'utilise avec la fonction "goto"
				printf("\nL'horaire de cette tache ?\n\n-> ");
				scanf("%d%d",&t[n].hour,&t[n].min);
				while(t[n].hour<1||t[n].hour>24||t[n].min<0||t[n].min>59){ // Boucle de contr�le de saisie
					printf("\nL'horaire est invalide, veuillez retaper l'horaire de cette tache\n\n-> ");
					scanf("%d%d",&t[n].hour,&t[n].min);
				}
				if(t[n].hour>=12&&t[n].hour<24){
					strcpy(t[n].clock_time,"PM");
				}
				else{
					strcpy(t[n].clock_time,"AM");
				}
				n++;  // ++La taille du tableau qui contient les tâches
				nt++; // ++Le nombre total des tâches
			}
			break;
		}
		case 2:{ // Cas d'affichage des tâches
			if(nt==0){
				printf("\nAucune tache a afficher, veuillez rechoisir :\n");
				goto main;
			}
			printf("\nVoulez vous afficher toutes les taches ?\n\n-> ");
			scanf("%d",&reponse);
			while(reponse!=0&&reponse!=1){ // Boucle de contrôle de saisie
				printf("\nChoix invalide, veuillez rechoisir entre 0 et 1\n\n-> ");
				scanf("%d",&reponse);
			}
			if(reponse==1){
				for(i=0;i<n;i++){
					printf("\n - Tache numero %d : %s\n\n - Description : %s\n\n - Date et Heure : %d/%d/%d , %d:%d%s.\n",i+1,t[i].name,t[i].description,t[i].day,t[i].month,t[i].year,t[i].hour,t[i].min,t[i].clock_time);
				}
			}
			else{
				printf("\nQuelle tache voulez vous afficher ?\n\n-> ");
				scanf("%d",&choice_prnt);
				while(choice_prnt<1||choice_prnt>nt){ // Boucle de contrôle de saisie
					printf("\nChoix invalide, Veuillez retaper la tache que vous voulez afficher\n\n-> ");
					scanf("%d",&choice_prnt);	
				}
				printf("\n - Tache numero %d : %s\n\n - Description : %s\n\n - Date et Heure : %d/%d/%d , %d:%d%s.\n",choice_prnt,t[choice_prnt-1].name,t[choice_prnt-1].description,t[choice_prnt-1].day,t[choice_prnt-1].month,t[choice_prnt-1].year,t[choice_prnt-1].hour,t[choice_prnt-1].min,t[choice_prnt-1].clock_time);
			}
			break;
		}
		case 3:{ // Cas de la supression des tâches
			if(nt==0){
				printf("\nAucune tache a supprimer, veuillez rechoisir :\n");
				goto main;
			}
			printf("\nVoulez vous supprimer toutes les taches (%d) ?\n\n-> ",nt);
			scanf("%d",&reponse);
			while(reponse!=0&&reponse!=1){ // Boucle de contrôle de saisie
				printf("\nChoix invalide, Veuillez redire si vous voulez supprimer toutes les taches\n\n-> ");
				scanf("%d",&reponse);
			}
			if(reponse==1){
				n=0;
				nt=0;
			}
			else{
				printf("\nVeuillez choisir la tache que vous voulez supprimer\n\n-> ");
				scanf("%d",&choice_del);
				while(choice_del<=0||choice_del>n){ // Boucle de contrôle de saisie
				printf("\nChoix invalide, veuillez retaper la taches que vous voulez supprimer : ");
				scanf("%d",&choice_del);
				}
				for(i=choice_del;i<n-1;i++){ // --la taille du tableau
					t[i-1]=t[i];
				}
				n--;
				nt--;
			}
			break;
			}
		default:{ // Cas de terminaison
			printf("\nDone!\n\n - Code written by : Nizar El Idrysy, 1AP G3 - \n");
			return 1;
		}
	}
	printf("\nDone!\n");
	goto main; // Revenir au début jusqu'a l'utilisateur entre le nombre 4 (cas default)
return 0;}
// Code réalisé par Nizar El Idrysy, 1AP G3
