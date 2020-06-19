#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

COORD coord = {0,0}; //coordonee 0, 0 (le coin gauche -haut de l ecran);
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // coordonee X et Y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawRectangle()
{
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 100; i++)
    {
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(100,0);
    printf("%c",187);
    for(i = 1; i < 30; i++)
    {
        gotoxy(100, i);
        if(i == 6)
        {
            printf("%c",185);
        }
        else
        {
            printf("%c",186);
        }
    }
    gotoxy(100, 30);
    printf("%c",188);
    for(i = 99; i > 0; i--)
    {
        gotoxy(i,30);
        if(i == 40)
        {
            printf("%c",202);
        }
        else
        {
            printf("%c",205);
        }
    }
    gotoxy(0,30);
    printf("%c",200);
    for(i = 29; i > 0; i--)
    {
        gotoxy(0,i);
        if(i == 6)
        {
            printf("%c",204);
        }
        else
        {
            printf("%c",186);
        }
    }
    for(i = 1; i < 100; i++)
    {
        gotoxy(i,6);
        if(i == 40)
        {
            printf("%c",203);
        }
        else
        {
            printf("%c",205);
        }
    }
    for(i = 7; i < 30; i++)
    {
        gotoxy(40,i);
        printf("%c",186);
    }

}





struct produit
{
    char ID[20];
    char Desiniation[20];
    char categorie[20];
    char prix[20];
    char qte[20];
};
typedef struct produit produit ;

void mod_product()
{
    struct produit  a;
    FILE *file_stock;
    FILE *file_stock_1;
    char find_id[20];
    int i,j;
    for(i = 42; i < 90; i++)
    {
        for(j = 10; j < 20; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }

    gotoxy(50,12);
    printf("Donner ID for delete : ");
    scanf("%s",&find_id);
    file_stock = fopen("stock.txt", "r");
    file_stock_1 = fopen("stockEffacer.txt", "w");
    if (!file_stock)
    {
        printf("\aERREUR: Impossible d'ouvrir le fichier\n");
        exit(-1);
    }

    if (!file_stock_1)

    {
        printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n");
        exit(-1);
    }

    while (!feof(file_stock))
    {
        fscanf (file_stock,"%s || %s || %s || %s\n",a.ID,a.Desiniation,a.categorie,a.prix,a.qte);
        if((a.ID[0] != find_id[0]) && (a.ID[1] !=find_id[1]) && (a.ID[2] != find_id[2]) )
        {
            fprintf(file_stock_1,"%s || %s || %s || %s\n",a.ID,a.Desiniation,a.categorie,a.prix,a.qte);
        }
    }
    fclose(file_stock);
    fclose(file_stock_1);
    remove("stock.txt");
    rename("stockEffacer.txt", "stock.txt");
     gotoxy(50,13);
    printf(" -> Desiniation ? : ");
    scanf("%s",a.Desiniation);
    gotoxy(50,15);
    printf(" -> Categorie ? : ");
    scanf("%s",a.categorie);
    gotoxy(50,17);
    printf(" -> PRIX ? : ");
    scanf("%s",a.prix);
    gotoxy(50,19);
    printf(" -> Quantite ? : ");
    scanf("%s",a.qte);


    if((file_stock = fopen("stock.txt", "a+")) != NULL)
    {
        fprintf(file_stock,"%s || %s || %s || %s\n",find_id,a.Desiniation,a.categorie,a.prix,a.qte);
        fclose(file_stock);
        gotoxy(45,25);
    gotoxy(45,25);
    printf("Modification  de l'article avec success ID : ' %s ",find_id);
    {



        int i,j;
        for(i = 42; i < 90; i++)
        {
            for(j = 10; j < 20; j++)
            {
                gotoxy(i,j);
                printf(" ");
            }
        }
    }



}
}



void display_product()

{
    produit  a;
    FILE *file_stock;
    int i,j;
    for(i = 42; i < 90; i++)
    {
        for(j = 10; j < 20; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }

    char find_id[20];

    gotoxy(50,9);
    printf("Donner ID Pour Display  ");
    scanf("%s",&find_id);
    file_stock = fopen("stock.txt","r");
    char string[128];

    while (fgets(string,128,file_stock))
    {
        if ((string[0] == find_id[0]) && (string[1] ==find_id[1]) && (string[2] == find_id[2]) )
        {



            gotoxy(50,14);
            printf("%s", string);
            break;
        }
        else
        {
            gotoxy(50,14);
            printf("Mon ami id no trouvé");
        }
        string == " ";
    }
    gotoxy(45,25);
    printf("Article Displayed de l'ID : ' %s ",find_id);
    {




    }


    fclose(file_stock);


}
void delete_product()
{
    struct produit  a;
    FILE *file_stock;
    FILE *file_stock_1;
    char find_id[20];
    int i,j;
    for(i = 42; i < 90; i++)
    {
        for(j = 10; j < 20; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }

    gotoxy(50,12);
    printf("Donner ID for delete : ");
    scanf("%s",&find_id);
    file_stock = fopen("stock.txt", "r");
    file_stock_1 = fopen("stockEffacer.txt", "w");
    if (!file_stock)
    {
        printf("\aERREUR: Impossible d'ouvrir le fichier\n");
        exit(-1);
    }

    if (!file_stock_1)

    {
        printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n");
        exit(-1);
    }

    while (!feof(file_stock))
    {
        fscanf (file_stock,"%s || %s || %s || %s\n",a.ID,a.Desiniation,a.categorie,a.prix,a.qte);
        if((a.ID[0] != find_id[0]) && (a.ID[1] !=find_id[1]) && (a.ID[2] != find_id[2]) )
        {
            fprintf(file_stock_1,"%s || %s || %s || %s\n",a.ID,a.Desiniation,a.categorie,a.prix,a.qte);
        }
    }
    fclose(file_stock);
    fclose(file_stock_1);
    remove("stock.txt");
    rename("stockEffacer.txt", "stock.txt");
    gotoxy(45,25);
    printf("Suppresion de l'article avec success ID : ' %s ",find_id);
    {



        int i,j;
        for(i = 42; i < 90; i++)
        {
            for(j = 10; j < 20; j++)
            {
                gotoxy(i,j);
                printf(" ");
            }
        }
    }



}





void add_product(FILE* file_stock)
{
    char rep;
    drawRectangle();
    produit a;
    gotoxy(50,10);
    printf(" -> ID ? : ");
    scanf("%s",a.ID);
    gotoxy(50,11);
    printf(" -> Desiniation ? : ");
    scanf("%s",a.Desiniation);
    gotoxy(50,12);
    printf(" -> Categorie ? : ");
    scanf("%s",a.categorie);
    gotoxy(50,13);
    printf(" -> PRIX ? : ");
    scanf("%s",a.prix);
    gotoxy(50,14);
    printf(" -> Quantite ? : ");
    scanf("%s",a.qte);


    if((file_stock = fopen("stock.txt", "a+")) != NULL)
    {
        fprintf(file_stock,"%s || %s || %s || %s\n",a.ID,a.Desiniation,a.categorie,a.prix,a.qte);
        fclose(file_stock);
        gotoxy(45,25);
        printf("creation de l'article avec success ID : ' %s ",a.ID);
        {



            int i,j;
            for(i = 42; i < 90; i++)
            {
                for(j = 10; j < 20; j++)
                {
                    gotoxy(i,j);
                    printf(" ");
                }
            }
        }

    }
    else
    {
        gotoxy(50,18);
        printf("Impossible d'ajouter la article  : %s\n", file_stock);


    }
}





void main()
{
    drawRectangle();
    gotoxy(30,2);
    printf("IHEC CARTHAGE");
    gotoxy(25,3);
    printf("Etudiant:SALEM DAHMANI");
    int i,j;
    FILE* file_stock ;
    int retour = 0;
    int choix ;
    do
    {


        gotoxy(4,10) ;
        printf("-------- Menu--------");
        gotoxy(4,12) ;
        printf("1) ADD A PRODUCT  ");
        gotoxy(4,14) ;
        printf("2)  Mod a PRODUCT \n\n");
        gotoxy(4,16) ;
        printf("3)  DELETE A PRODUCT \n\n ");
        gotoxy(4,18) ;
        printf("4)  display a PRODUCT \n\n ");
        gotoxy(4,20) ;
        printf("  Votre choix ? : ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            add_product(file_stock);
            choix = "";
            retour = 1;
            break;
        case 2:
            mod_product();
            retour = 1;
            break;
        case 3:
            delete_product();
            retour = 1;
            break;
        case 4:
            display_product();
            retour = 1;
            break;
        default:
            printf(" >>> Choix Invalide ! <<< ");
            retour = 1;

            break;
        }


    }






    while ((choix<0 && choix>2) || retour==1);

}
