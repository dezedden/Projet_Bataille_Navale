#include<stdlib.h>
#include<stdio.h>
void affiche_tab();
int placer_bateau();


int Tab[10][10];


int placer_bateau()
{
  int j;//colonne
  int l;//longueur bateau
  int k;
  int i;//ligne
  int a;//alignement vertical ou horizontal
  int u,h,n;
  int bon;
  char c;
  for (u=0;u<3;u++)//placer tous les baateaux d'un coup
  {
  	do
    { printf("Entre la ligne (de A a J): ");
	  scanf("%c",&c);
	  i=(c|32)-'a';
    } while(i<0 || i>9);
	do
	{ printf("entre la cordonnee de j : ");
	  while (scanf("%d",&n)!=1) fflush(stdin);
	  j=n-1;
	}while(j<0 || j>9);//tant que j n'est pas inf à 0 et sup a dix, on applique l instruct
	do
    { printf("tape 1 pour alignement vertical ou 0 pour horizontal\n");
      while(scanf("%d",&a)!=1) fflush(stdin);
	}while(a<0 || a>1);
	do
	{ printf("entrer la longueur du bateau: ");
      while(scanf("%d",&l)!=1) fflush(stdin);
	}while(l>5 || l>9-i+1 || l>9-j+1);
    if(a==1)
    { bon=1;
      for (h=0;h<l;h++) // Ici on parcourt d'abord la colonne pour savoir s'il n'y a pas d'autres valeurs"0"
      {
        if(Tab[i+h][j]==0) bon=0;
      }
      if(bon) for (k=0;k<l;k++) Tab[i+k][j]=0;
      else u--;
    }
    if(a==0)
    { bon=1;
      for (h=0;h<l;h++)
      {
        if(Tab[i][j+h]==0) bon=0;
      }
      if(bon) for (k=0;k<l;k++) Tab[i][j+k]=0;
      else u--;
    }
    affiche_tab();
   }


}
 int intialiser_tableau()
 {
 	int i;
 	int j;

    	for(i=0;i<10;i++)
    	{
    		for(j=0;j<10;j++)
    		{
    			Tab[i][j]=1;
    		}
 		}
}

void affiche_tab()
{
	int i,j;
	printf("   1     2     3     4     5     6     7     8     9    10\n");
	for(i=0;i<10;i++){
		for(printf("%c",'A'+i),j=0;j<10;j++){

			printf( "  %d   ",Tab[i][j]);

		}
		printf("\n");
	}

}

int main ()
{
	int i,j;
	 intialiser_tableau();
	 placer_bateau();
	 printf("b");

}
