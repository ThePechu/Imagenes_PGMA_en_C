
typedef struct Content
{
    FILE *archivo;
    int **valores;

    int x,y,grises;

}cont;


void cleanout()
{
    system("cls");

    // system("clear");   LINUX
}

int abrir_pgm(cont *a1, char *nombre)
{

    a1->archivo = fopen(nombre, "r");

    if(a1->archivo == NULL)
    {
          printf("No se pudo abrir el archivo");
          return 1;
    }
    return 0;
}

int comprobar_pgm(cont *a1)
{
        rewind(a1->archivo);
        char valor[64];


        fscanf(a1->archivo, "%s", valor);

        if(valor[0] == 'P' && valor[1] == '2')
        {
            printf("PGM TIPO P2 (ASCII)\n");
        }
        else
        {
            if(valor[0] == 'P' && valor[1] == '5')
            {
                printf("PGM TIPO P5 (BINARIO). NO SE PUEDE ABRIR FORMATOS BINARIOS\n");
                return 1;
            }
            else
            {
                printf("\nError. Formato desconocido");
                return 2;

            }
        }


    system("pause");
    cleanout();
    return 0;

}



int lectura_pgm(cont *a1, char *nombre)
{
        rewind(a1->archivo);

        printf("\nContenido codigo PGM de %s\n",nombre);
        while( !feof(a1->archivo) )
        {
            printf("%c",getc(a1->archivo));
        }
        printf("\n\n\n");

        system("pause");
        cleanout();

        return 0;

}

int cargar_pgm(cont *a1)
{


        char valor[64];
        rewind(a1->archivo);

        do
        {
             fgets(valor,100,a1->archivo);
        }
        while(valor[0]!='#');

        fscanf(a1->archivo,"%d", &a1->y);


        fscanf(a1->archivo,"%d", &a1->x);



        fscanf(a1->archivo,"%d", &a1->grises);

        return 0;


}

int reservar(cont *a1)
{

        if(a1->archivo == NULL)
        {
            printf(" - - - - Problemas con la lectura de archivo. Compruebe la funcion reservar - - - -\n");
            system("pause");
            exit(-1);
        }

    //    cargar_pgm(a1);


        a1->valores=(int**) malloc(sizeof(int*) * (a1->x));

        if( (a1->valores) == NULL)
        {
            printf(" - - - - Problemas con la asignación de memoria. Compruebe la función reservar - - - - \n");
            system("pause");
            return 1;
        }

        for(int i=0; i<(a1->x); i++ )
        {

            a1->valores[i]=(int*) malloc(sizeof(int) * (a1->y));


            if( ( a1->valores[i] ) == NULL )
            {
                printf("Memoria insuficiente para la fila de la matriz %d!\n", i);
                system("pause");
                return 2;
            }

        }

        return 0;

}

int leer(cont *a1)
{

    int temp;

    for(int i=0; i < (a1->x); i++)
    {
        for(int j=0; j < (a1->y); j++)
        {

            fscanf(a1->archivo, "%d", &temp);

            a1->valores[i][j]=temp;
        }
    }



    return 1;

}
int escribe(cont *a1)
{
    char num[4];
    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            itoa(a1->valores[i][j],num, 10);
            fputs(num,a1->archivo);
            fputs(" ",a1->archivo);
        }
        fputs("\n",a1->archivo);
    }

    return 0;

}
int getFilas(cont *a1)
{
    if(a1->archivo == NULL)
    {
        printf(" - - - - Problemas con la lectura de archivo. Compruebe la funcion reservar - - - -\n");
        return 1;
    }
    else
    {
        cleanout();
        printf("El numero de filas de esta imagen es: %d\n",a1->x);
        return 0;
    }
}

int getColumns(cont *a1)
{
    if(a1->archivo == NULL)
    {
        printf(" - - - - Problemas con la lectura de archivo. Compruebe la funcion reservar - - - -\n");
        return 1;
    }
    else
    {
        cleanout();
        printf("El numero de columnas de esta imagen es: %d\n",a1->y);
        return 0;
    }
}

int getGris(cont *a1)
{
    cleanout();

    int x1,y1;
    //int g;
    printf("Introduzca la coordenada con el que desea obtener el valor gris:\n");

    printf("( X , )  --> ");
    scanf("%d",&x1);
    printf("\n");

    printf("( %d , Y )  --> ", x1);
    scanf("%d",&y1);
    printf("\n");

    cleanout();

    printf("\n\n");
    printf("    COORDENADA DONDE SE VA A MOSTRAR VALOR GRIS: (%d,%d)\n",x1,y1);
    system("pause");

    for(int i=0; i<=x1; i++)
    {
        for (int j=0; j<=y1; j++)
        {
            if(i==x1 && j==y1)
            {
                cleanout();
                printf("    El valor de gris de (%d,%d) es: %d",x1,y1,a1->valores[i][j]);
            }
        }
    }

    return 0;

}



int copiar(cont *a1, char *nombre2)
{
    rewind(a1->archivo);
    FILE *archivo2;
    if((a1->archivo) == NULL)
    {
        printf("Problemas con la lectura del fichero emisor. Compruebe la funcion ""escribe""");
        return 1;
        exit(-1);
    }

    char caract;
    archivo2=fopen(nombre2,"w");
    if (archivo2 == NULL)
    {
        printf("\n\n - - - - - - Error al abrir o generar el nuevo fichero. Compruebe la función escribe - - - - - - \n\n");
        return 2;
        exit(-1);
    }
    else
    {

        caract=fgetc(a1->archivo);
        int cont=0;
        while(!feof(a1->archivo))
        {

            fputc(caract,archivo2);

            caract=fgetc(a1->archivo);
            if(cont==0)
            {
                printf("\n\n");
                printf("- - - - - - - - - - - - - - - \n");
                printf("| Proceso de copia en curso | \n");
                printf("- - - - - - - - - - - - - - - \n");
                cont++;
            }
        }
        cleanout();
        printf("\n\n - - - - - - - -  COPIA FINALIZADA  - - - - - - - - \n\n");
        system("pause");


    }


    int est=fclose(archivo2);
    if(est==0)
    {
        printf("\n\nFichero copiado y cerrado correctamente. Comprueba dicho fichero que este correctamente creado\n\n");
    }
    else
    {
        printf("\n\nProblemas con el cierre de fichero. Compruebe la función ""escribe""\n\n");
    }

    return 0;
}

int rellenar(cont *a1, cont *a2, char *nombre2)
{

    rewind(a1->archivo);
    int valorF;

    if((a1->archivo) == NULL)
    {
        printf("Problemas con la lectura del fichero emisor. Compruebe la funcion ""escribe""");
        exit(-1);
    }


    a2->archivo=fopen(nombre2,"w");
    if (a2->archivo == NULL)
    {
        printf("\n\n - - - - - - Error al abrir o generar el nuevo fichero. Compruebe la función escribe - - - - - - \n\n");
    }
    else
    {

        /*     DEFINICIÓN FILAS, COLUMNAS Y VALOR MAX GRIS     */

        int x,y,g;
        char xC[4],yC[4],gC[4];
        char valorS[4];
        printf("\n\nIntroduzca el numero de columnas que va a contener.\n");
        scanf("%d",&y);
        printf("Introduzca el numero de filas que va a contener.\n");
        scanf("%d",&x);
        printf("Valor maximo de gris(0-255)");
        scanf("%d",&g);

        /*     DEFINICIÓN FILAS, COLUMNAS Y VALOR MAX GRIS     */


        /*   CONVERSION VALORES ENTEROS A VALORES DE UNA CADENA DE CARACTERES    */

        itoa(x,xC, 10);     // xC -> STRING | x -> INT
        itoa(y,yC, 10);     // yC -> STRING | y -> INT
        itoa(g,gC, 10);     // gC -> STRING | g -> INT

        /*   CONVERSION VALORES ENTEROS A VALORES DE UNA CADENA DE CARACTERES    */



        /*  ESTRUCTURA FICHERO P2   */


        fputs("P2\n", a2->archivo);
        fputs("#CREADO POR IMAGENES -> ThePechu\n", a2->archivo);
        fputs(yC, a2->archivo);
        fputs(" ", a2->archivo);
        fputs(xC, a2->archivo);
        fputs("\n",a2->archivo);
        fputs(gC, a2->archivo);
        fputs("\n", a2->archivo);

        int x1[2];
        int y1[2];
        int l=0;
        do
        {

            printf("Introduzca la coordenada principio (x1,y1) \n");

            printf("( X , )  --> ");
            scanf("%d",&x1[0]);
            printf("\n");

            printf("( %d , Y )  --> ", x1[0]);
            scanf("%d",&y1[0]);
            printf("\n");

            printf("PRIMER VECTOR ---> (%d,%d)\n",x1[0],y1[0]);

            if(( x1[0] ) < 0 && ( y1[0] ) < 0 )
            {

                printf("\nVector inicial no correcto. Debe ser un vector operable para filas y columnas\n");

            }
            else
            {
                if( ( x1[0] ) > x && ( y1[0] ) > y )
                {
                    printf("\nVector inicial no correcto. Debe ser un vector operable para filas y columnas\n");
                }
                else
                {

                    printf("Introduzca la coordenada final (x2,y2) ");

                    printf("( X , )  --> ");
                    scanf("%d",&x1[1]);
                    printf("\n");

                    printf("( %d , Y )  --> ",x1[1]);
                    scanf("%d",&y1[1]);
                    printf("\n");

                    printf("SEGUNDO VECTOR ---> (%d,%d)",x1[1],y1[1]);

                    if(( x1[0] ) < 0 && ( y1[0] ) < 0 )
                    {

                        printf("\nVector final no correcto. Debe ser un vector operable para filas y columnas\n");

                    }
                    else
                    {
                        if( ( x1[1] ) > x && ( y1[1] ) > y )
                        {
                            printf("\nVector final no correcto. Debe ser un vector operable para filas y columnas\n");
                        }
                        else
                        {
                            if( ( ( x1[0] ) > ( x1[1] ) ) && ( ( y1[0] ) > ( y1[1] ) ) )
                            {
                                printf("\nVector final debe ser mayor que el vector final tanto X como Y \n");
                            }
                            else
                            {
                                l=1;
                            }
                        }

                    }
                }
            }


        }
        while(l==0);

        cleanout();

        l=0;
        do
        {


            printf("Introduzca el valor de gris que se rellenara automáticamente en la escala de vectores dados:\n");
            scanf("%d",&valorF);
            if(valorF > g )
            {
                cleanout();

                printf("- - - -  Incorrecto. No puede ser mayor que el valor gris máximo (%d)  - - - -\n",g);
            }
            else
            {
                l=1;
                itoa(valorF,valorS, 10);
                printf("%s",valorS);
            }

        }
        while(l==0);

        cleanout();
        printf("\n\n");
        printf("        ------------------------------\n");
        printf("      |                 VECTORES \n");
        printf("      |  VECTOR INICIAL -> (%d,%d)\n", x1[0],y1[0]);
        printf("      |  VECTOR FINAL -> (%d,%d)\n", x1[1],y1[1]);
        printf("        -----------------------------\n");

        printf("\n\n\n\n\n");
        system("pause");


        /*  ESTRUCTURA FICHERO P2   */
        int flg=0;
        for(int i=0; i<x; i++)
        {
            if( i >= ( x1[0] ) && i <= ( x1[1] ) )
            {
                flg=1;
            }
            else
            {
                flg=0;
            }

            for(int j=0; j<y; j++)
            {
                if( j >= ( y1[0] ) &&  j <= ( y1[1] )  && flg==1 )
                {

                    fputs(valorS, a2->archivo);
                    fputs(" ",a2->archivo);

                }
                else
                {
                    fputs("0", a2->archivo);
                    fputs(" ", a2->archivo);
                }
            }

            fputs("\n",a2->archivo);
        }

        fclose(a2->archivo);




    }

    return 0;

}

void conversion(cont *a1)
{
    char xC[10],yC[10],gC[10];

    itoa(a1->x,xC, 10);         // xC -> STRING | x -> INT          // CONVIERTE VALOR INT A STRING (VARIABLES)
    itoa(a1->y,yC, 10);         // yC -> STRING | y -> INT          // CONVIERTE VALOR INT A STRING (VARIABLES)
    itoa(a1->grises,gC, 10);     // gC -> STRING | g -> INT     // CONVIERTE VALOR INT A STRING (VARIABLES)

    fputs(yC, a1->archivo);
    fputs(" ", a1->archivo);
    fputs(xC, a1->archivo);
    fputs("\n",a1->archivo);
    fputs(gC, a1->archivo);
    fputs("\n", a1->archivo);

    system("pause");
}

void conversionReves(cont *a1)
{
    char xC[10],yC[10],gC[10];

    itoa(a1->y,xC, 10);     // xC -> STRING | x -> INT          // CONVIERTE VALOR INT A STRING (VARIABLES)
    itoa(a1->x,yC, 10);     // yC -> STRING | y -> INT          // CONVIERTE VALOR INT A STRING (VARIABLES)
    itoa(a1->grises,gC, 10);     // gC -> STRING | g -> INT     // CONVIERTE VALOR INT A STRING (VARIABLES)

    fputs(yC, a1->archivo);
    fputs(" ", a1->archivo);
    fputs(xC, a1->archivo);
    fputs("\n",a1->archivo);
    fputs(gC, a1->archivo);
    fputs("\n", a1->archivo);

    system("pause");
}

int putValor(cont *a1, char *nombre)
{
    if(a1->archivo == NULL)
    {
        printf("Fichero emisor no se encuentra abierto correctamente");
    }
    else
    {
        char cabec1[200];
        rewind(a1->archivo);

        do
        {
            fgets(cabec1,500,a1->archivo);
        }
        while(cabec1[0]!='#');

        fscanf(a1->archivo, "%d", &a1->y);

        fscanf(a1->archivo, "%d", &a1->x);

        fscanf(a1->archivo, "%d", &a1->grises);






        if( (a1->valores) == NULL)
        {
            printf(" - - - - Problemas con la asignación de memoria. Compruebe la función putValor - - - - \n");
            exit(-1);
        }

        for(int j=0; j<a1->x; j++ )
        {


            if(a1->valores[j]==NULL)
            {
                printf("Memoria insuficiente para la fila de la matriz 1%d!\n", j);
                exit(-1);
            }
        }
            remove(a1->archivo);
            a1->archivo = fopen(nombre, "w");
            fputs("P2", a1->archivo);
            fputs("\n",a1->archivo);

            fputs(cabec1, a1->archivo);

            char grisC[4];
            char temp[4];

            conversion(a1);

            int x1,y1;
            int g;
            int flag=0;
            printf("\nIntroduzca la posicion (x, ) -->");
            scanf("%d",&x1);
            printf("\nIntroduzca la posicion (%d,x) -->",x1);
            scanf("%d",&y1);
            cleanout();
            printf("PUNTO A CAMBIAR ->(%d,%d)\n",x1,y1);

            do
            {


                printf("Introduzca el valor gris que desea poner\n");
                scanf("%d",&g);
                if((a1->grises)<g)
                {
                    cleanout();
                    printf("\n - - - - Valor incorrecto. El valor debe ser menor o igual que el máximo(%d) - - - - \n",a1->grises);
                    system("pause");
                    flag=1;
                }
                else
                {
                    flag=0;
                }


            }
            while(flag!=0);
            itoa(g,grisC, 10);


            for(int i=0; i < (a1->x); i++)
            {
                for(int j=0; j < (a1->y); j++)
                {
                    if(i==x1 && j==y1)
                    {

                        fputs(grisC,a1->archivo);
                        fputs(" ",a1->archivo);

                    }
                    else
                    {


                        itoa(a1->valores[i][j],temp, 10);               // CONVERSIÓN INT A CHAR
                        fputs(temp,a1->archivo);
                        fputs(" ",a1->archivo);


                    }
                }
                fputs("\n",a1->archivo);
            }



    }

    sync(a1,nombre);

    return 0;

}

int putValores(cont *a1, int **valores, int x, int y, int paramConversion,char *nombre)
{



        if(a1->archivo == NULL)
        {
            printf("Fichero emisor no se encuentra abierto correctamente");
        }
        else
        {
            char cabec1[200];
            int gets;
            rewind(a1->archivo);

            do
            {
                fgets(cabec1,500,a1->archivo);
            }
            while(cabec1[0]!='#');

            fscanf(a1->archivo, "%d", &gets);

            fscanf(a1->archivo, "%d", &gets);

            fscanf(a1->archivo, "%d", &gets);






            if( (a1->valores) == NULL)
            {
                printf(" - - - - Problemas con la asignación de memoria. Compruebe la función putValor - - - - \n");
                exit(-1);
            }

            for(int j=0; j<a1->x; j++ )
            {


                if(a1->valores[j]==NULL)
                {
                    printf("Memoria insuficiente para la fila de la matriz 1%d!\n", j);
                    exit(-1);
                }
            }
                remove(a1->archivo);
                a1->archivo = fopen(nombre, "w");
                fputs("P2", a1->archivo);
                fputs(" \n",a1->archivo);
                fputs(cabec1, a1->archivo);


                char grisV[4];
                if(paramConversion==0)
                {

                    conversion(a1);
                }
                else
                {
                    conversionReves(a1);
                }


                for(int i=0; i < x; i++)
                {
                    for(int j=0; j < y; j++)
                    {

                        itoa(valores[i][j],grisV, 10);

                        fputs(grisV,a1->archivo);
                        fputs(" ",a1->archivo);



                    }

                    fputs("\n",a1->archivo);

                }


        }

    return 0;

}



int suma(cont *a1,cont *a2,cont *a3, char *nombre3)
{

    if(a1->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 0;
    }
    if(a2->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 0;
    }



    cargar_pgm(a2);


    //  INSPECCIÓN FICHERO 2
    //   printf("%d %d %d", a1->x,a1->y,a1->grises);
    //   printf("%d | %d", a2->y,a2->x);
    //   system("pause");

    if( (a1->valores) == NULL)
    {
        printf(" - - - - Problemas con la asignación de memoria. Compruebe la función putValor - - - - \n");
        exit(-1);
    }

    reservar(a2);
    leer(a2);



    if(a2->valores == NULL)
    {
        cleanout();
        printf("\n - - - - No se ha reservado correctamente en filas\n - - - -");
    }
    else
    {
        for (int i=0; i<(a2->x); i++)
        {
            if(a2->valores[i] == NULL)
            {
                cleanout();
                printf("\n - - - - No se ha reservado correctamente para columnas\n - - - -");
            }
        }
    }


    if((a1->x)<(a2->x))
    {
        a3->x = a1->x;
    }
    else
    {
        a3->x = a2->x;
    }

    if((a1->y)<(a2->y))
    {
        a3->y = a1->y;
    }
    else
    {
        a3->y = a2->y;
    }

    a3->grises=(a1->grises)+(a2->grises);

    printf("Filas: %d | Columnas: %d | Gris Total: %d\n",a3->x, a3->y, a3->grises);
    system("pause");

    cleanout();


    a3->archivo=fopen(nombre3,"w");

    if(a3->archivo == NULL)
    {
        cleanout();
        printf("\nProblemas con la generación de fichero imagen resultante - - - -\n");
        return 0;
    }

    fputs("P2",a3->archivo);
    fputs("\n",a3->archivo);

    fputs("#Creado por ThePechu - Imagenes.exe", a3->archivo);
    fputs("\n",a3->archivo);

    conversion(a3);

    reservar(a3);

    int temp;
    for(int i=0; i<(a3->x); i++)
    {
        for(int j=0; j<(a3->y); j++)
        {
            temp=(a1->valores)[i][j]+(a2->valores)[i][j];
            if(temp > (a3->grises))
            {
                temp=(a3->grises);
                a3->valores[i][j]=temp;
            }
            else
            {
                a3->valores[i][j]=temp;
            }
        }
    }

    escribe(a3);

    fclose(a3->archivo);

    return 1;

}

int resta(cont *a1,cont *a2,cont *a3, char *nombre3)
{

    if(a1->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 0;
    }
    if(a2->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 0;
    }



    cargar_pgm(a2);


    //  INSPECCIÓN FICHERO 2
    //   printf("%d %d %d", a1->x,a1->y,a1->grises);
    //   printf("%d | %d", a2->y,a2->x);
    //   system("pause");

    if( (a1->valores) == NULL)
    {
        printf(" - - - - Problemas con la asignación de memoria. Compruebe la función putValor - - - - \n");
        exit(-1);
    }

    reservar(a2);
    leer(a2);

    printf("%d | %d", a2->y,a2->x);
    system("pause");

    if(a2->valores == NULL)
    {
        cleanout();
        printf("\n - - - - No se ha reservado correctamente en filas\n - - - -");
    }
    else
    {
        for (int i=0; i<(a2->x); i++)
        {
            if(a2->valores[i] == NULL)
            {
                cleanout();
                printf("\n - - - - No se ha reservado correctamente para columnas\n - - - -");
            }
        }
    }


    if((a1->x)<(a2->x))
    {
        a3->x = a1->x;
    }
    else
    {
        a3->x = a2->x;
    }

    if((a1->y)<(a2->y))
    {
        a3->y = a1->y;
    }
    else
    {
        a3->y = a2->y;
    }

    a3->grises=(a1->grises)-(a2->grises);
    if((a3->grises) < 0)
    {

        cleanout();

        printf("- - - - Gris máximo no puede ser negativo - - - -");
        return 1;

    }
    printf("Filas: %d | Columnas: %d | Gris Total: %d\n",a3->x, a3->y, a3->grises);
    system("pause");

    cleanout();


    a3->archivo=fopen(nombre3,"w");

    if(a3->archivo == NULL)
    {
        cleanout();
        printf("\nProblemas con la generación de fichero imagen resultante - - - -\n");
        return 0;
    }

    fputs("P2",a3->archivo);
    fputs("\n",a3->archivo);

    fputs("#Creado por ThePechu - Imagenes.exe", a3->archivo);
    fputs("\n",a3->archivo);

    conversion(a3);

    reservar(a3);

    int temp;
    for(int i=0; i<(a3->x); i++)
    {
        for(int j=0; j<(a3->y); j++)
        {
            temp=(a1->valores)[i][j]-(a2->valores)[i][j];
            if(temp < 0)
            {
                temp=0;
                a3->valores[i][j]=temp;
            }
            else
            {
                a3->valores[i][j]=temp;
            }
        }
    }

    escribe(a3);

    fclose(a3->archivo);

    return 1;

}

int rotar90(cont *a1, int **valoresCopia, char *nombre)
{
    rewind(a1->archivo);
    int x,y;
    x=(a1->y);
    y=(a1->x);



    if(a1->valores == NULL)
    {
        printf("No se ha recogido correctamente los valores. Compruebe rotar90 o reservar");
        system("pause");
    }

    valoresCopia=(int**) malloc(sizeof(int*) * (x));

    if(valoresCopia == NULL)
    {
        cleanout();
        printf("\n- - - - Problemas con la reserva de memoria. Compruebe rotar90 - - - -\n");
        system("pause");
        exit(-1);
    }
    else
    {

        for(int i=0; i<x; i++)
        {
            valoresCopia[i]=(int**) malloc(sizeof(int*) * (y));

            if( (valoresCopia[i]) == NULL )
            {
                cleanout();
                printf("\n- - - - Problemas con la reserva de memoria[i]. Compruebe rotar90 - - - -");
                system("pause");
                exit(-1);
            }
        }




/*
    //      DEBUG VALORES    //

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=((a1->y)-1); j>0; j--)
        {
            printf("%d ",a1->valores[i][j]);
        }
        printf("\n");
    }
    system("pause");
    system("pause");

    //      DEBUG VALORES    //

*/

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=((a1->y)-1); j>0; j--)
        {

/*
            if(a1->valores[i][j]!=0)
            {
                cleanout();
                printf("%d %d",i,j);
                printf("- - - - Problemas con la obtención de valores. Compruebe rotar90\n");
                system("pause");
                exit(-1);
            }
            else
        {*/
            if(a1->valores[i][j]>a1->grises)
            {
                valoresCopia[(a1->y)-(j+1)][i]=0;
            }
            else
            {
                valoresCopia[((a1->y))-(j+1)][i]=a1->valores[i][j];
            }

          //  }


        }

    }

    putValores(a1,valoresCopia,x,y,1,nombre);
    sync(a1,nombre);

    }

    return 0;

}

int rotar180(cont *a1, int **valoresCopia,char *nombre)
{

    int i=0;
    while(i<2)
    {
        rotar90(a1,valoresCopia,nombre);
        i++;
    }

    return 0;

}


int rotar270(cont *a1, int *valores, char *nombre)
{

    int i=0;
    while(i<3)
    {
        rotar90(a1,valores,nombre);
        i++;
    }

    return 0;

}

int rotar(cont *a1, char *nombre, int rot)
{

    if(a1->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 1;
    }

    if((a1->valores) == NULL)
    {
        cleanout();
        printf("\n - - - - Problemas con la memoria de valores puesto que no esta asignada o ha habido un problema. - - - - \n ");
        return 2;
    }
    else
    {



        for (int i=0; i<(a1->x); i++)
        {
                if(a1->valores[i] == NULL)
                {
                    cleanout();
                    printf("\n - - - - Problemas con la memoria de valores en filas  - - - - \n");
                    printf(" - - - - Error por referencia free[i] - - - - \n");
                    system("pause");
                    i=(a1->x);
                    return 0;
                }
        }


    }

    int **valoresCopia;

    switch(rot)
    {

        case 90:

        case -270:

            rotar90(a1,valoresCopia,nombre);

        break;

        case -90:

        case 270:

            rotar270(a1,valoresCopia,nombre);

        break;

        case 180:

        case -180:

            rotar180(a1,valoresCopia,nombre);

        break;

    }

    return 0;

}

int recortar(cont *a1, cont *a2, char *nombre, int p1[2], int p2[2])
{

    if(a1->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 1;
    }

    if((a1->valores) == NULL)
    {
        cleanout();
        printf("\n - - - - Problemas con la memoria de valores puesto que no esta asignada o ha habido un problema. - - - - \n ");
        return 2;
    }
    else
    {



        for (int i=0; i<(a1->x); i++)
        {
                if(a1->valores[i] == NULL)
                {
                    cleanout();
                    printf("\n - - - - Problemas con la memoria de valores en filas  - - - - \n");
                    printf(" - - - - Error por referencia free[i] - - - - \n");
                    system("pause");

                    i=(a1->x);
                    return 3;
                }
        }


    }

    for(int i=0; i<(a1->x); i++)
    {

        if( ( a1->valores[i] ) == NULL )
        {
            printf("Memoria insuficiente para la fila de la matriz 1%d!\n", i);
            system("pause");
            return 4;
        }

    }

    a2->x=(p2[0]-p1[0])+1;
    a2->y=(p2[1]-p1[1])+1;
    a2->grises=a1->grises;

    reservar(a2);


    int flag5=0;

    // CONTROL PARA RECORTAR INTERVALO DE P1-P2 CON flag5 //

    //  PRIMERA ASIGNACIÓN DE VALORES TEMPORALES PARA SU REEMPLAZO DE FORMA CORRECTA

    for(int i=0; i<a2->x; i++)
    {
        for(int j=0; j<a2->y; j++)
        {
            a2->valores[i][j]=-1;
        }

    }


    //  PRIMERA ASIGNACIÓN DE VALORES TEMPORALES PARA SU REEMPLAZO DE FORMA CORRECTA


    for(int i=0; i<(a1->x); i++)
    {

        for(int j=0; j<(a1->y); j++)
        {
            if( (i>=p1[0]) && (j>=p1[1]) )
            {
                if( (i<=p2[0]) && (j<=p2[1]) )
                {

                    flag5=1;

                }
                else
                {
                    flag5=0;            // CONTROL PARA RECORTAR INTERVALO DE P1-P2 CON flag5//

                }

            }
            else
            {
                flag5=0;            //  DESACTIVACIÓN RESERVA AL NO PERTENECER EN EL RECORTE
            }


            if(flag5==1)
            {
                for(int a=0; a<(a2->x); a++)
                {
                    for(int b=0; b<(a2->y); b++)
                    {
                        if(a2->valores[a][b]==-1)
                        {

                                a2->valores[a][b]=a1->valores[i][j];

                                a=(a2->x);
                                b=(a2->y);
                        }

                    }

                }

            }

        }

    }


    system("pause");

    a1->x=a2->x;
    a1->y=a2->y;
    putValores(a1,a2->valores,a2->x,a2->y,0,nombre);            // PARAM 0 = CONVERSION NORMAL ( NO INVERSA )
    sync(a1,nombre);

/*    printf("\n");
    for(int a=0; a<(a2->x); a++)
    {
        for(int b=0; b<(a2->y); b++)
        {
            printf("%d ",a2->valores[a][b]);
        }
        printf("\n");
    }
    system("pause");
*/

    return 0;

}

int ampliarLienzo(cont *a1, cont *a2, char *nombre, int A)
{

    if(a1->archivo == NULL)
    {
        cleanout();
        printf("- - - - Problemas con la lectura de una de las imagenes. Revise si esta abierto - - - -");
        return 0;
    }

    if((a1->valores) == NULL)
    {
        cleanout();
        printf("\n - - - - Problemas con la memoria de valores puesto que no esta asignada o ha habido un problema. - - - - \n ");
        return 0;
    }
    else
    {



        for (int i=0; i<(a1->x); i++)
        {
                if(a1->valores[i] == NULL)
                {
                    cleanout();
                    printf("\n - - - - Problemas con la memoria de valores en filas  - - - - \n");
                    printf(" - - - - Error por referencia free[i] - - - - \n");
                    system("pause");

                    i=(a1->x);  // FIN DEL BUCLE Y RETORNO 0
                    return 0;
                }
        }


    }

    a2->x=(a1->x)*(2*A);
    a2->y=(a1->y)*(2*A);
    a2->grises=a1->grises;

    reservar(a2);

    int P2[3];              // COORDENADA FINAL DE VALORES  //
    P2[0]=(a1->x)-A;        //   X   //
    P2[1]=(a1->y)-A;        //   Y   //

    int P1[3];              // COORDENADA PRIMERA DE VALORES //

    cleanout();
    do
    {

        printf("Posicion de imagen a partir del primer punto\n");
        printf("X -> ");
        scanf("%d",&P1[0]);                  //   X   //
        printf("\nY -> ");
        scanf("%d",&P1[1]);                  //   Y   //

        if(P1[0]>=P2[0] || P1[1]>=P2[1])
        {
            cleanout();
            printf("- - - - Punto no valido. Intente centrar la imagen - - - - \n");
        }
    }
    while(P1[0]>=P2[0] || P1[1]>=P2[1]);





    //  RELLENO TAMAÑO AMPLIACIÓN //

    int g;

    do
    {
        printf("Introduzca el valor gris a rellenar");
        scanf("%d",&g);
        if(g>a1->grises)
        {
            cleanout();
            printf("- - - - El valor gris no puede ser mayor que el max de gris - - - - \n");
        }
    }
    while(g>a1->grises);


    for(int i=0; i<(a2->x); i++)
    {

        for(int j=0; j<(a2->y); j++)
        {

            a2->valores[i][j]=g;

           /* if(i==P1[0] && j==P1[1])
            {

                break;
            }
            else
            {



            }*/
        }

    }

    //  RELLENO TAMAÑO AMPLIACIÓN //



    int k=0;
    int m=0;
    for(int i=P1[0]; i<(P1[0])+(a1->x); i++)
    {


        for(int j=P1[1]; j<(P1[1])+(a1->y); j++)
        {

            a2->valores[i][j]=a1->valores[m][k];
            k++;
        }
        m+=1;
        k=0;


    }



    liberar(a1);
    a1->x=a2->x;
    a1->y=a2->y;


    reservar(a1);
    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;


}

int zoom(cont *a1, cont *a2, char *nombre)
{
    int opc2;

    do
    {
        printf("Que tipo de zoom desea realizar\n");
        printf("1.- Replicacion (positivo)\n");
        printf("2.- Media (negativo)\n");
        scanf("%d",&opc2);
    }
    while(opc2!=1 && opc2!=2);

    int factor;

    switch(opc2)
    {
        case 1:

            do
            {
                printf("\nIntroduzca el factor positivo para realizar un zoom por replicación\n");
                scanf("%d",&factor);
                if(factor<=0)
                {
                    cleanout();
                    printf("\n  - - - - El factor no puede ser negativo o 0 - - - -\n");
                }
            }
            while(factor<=0);
            printf("%s",nombre);
            system("pause");
            zoom1(a1,a2,nombre,factor);

        break;

        case 2:

            do
            {
                printf("\nIntroduzca el factor negativo para realizar un zoom por media\n");
                scanf("%d",&factor);
                if(factor>=0)
                {
                    cleanout();
                    printf("\n  - - - - El factor no puede ser positivo o 0 - - - -\n");
                }
            }
            while(factor>=0);

            zoom2(a1,a2,nombre,factor);


        break;

    }

    return 0;
}

int zoom1(cont *a1, cont *a2,char *nombre,int factor)
{

    a2->x=(a1->x)*(factor);
    a2->y=(a1->y)*(factor);
    a2->grises=(a1->grises);


    reservar(a2);

    int x0=0;
    int y0=0;

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            for(int x=x0, pas=0; pas<factor; x++, pas++)
            {
                for(int y=y0, pas=0; pas<factor; y++, pas++)
                {
                    a2->valores[x][y]=a1->valores[i][j];
                }
            }

            y0+=factor;

        }
        x0+=factor;
        y0=0;
    }



    liberar(a1);

    a1->x=a2->x;
    a1->y=a2->y;

    reservar(a1);
    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;


}

int zoom2(cont *a1, cont *a2,char *nombre,int factor)
{

    int x0 = 0;
    int y0 = 0;
    int promedio = 0;

    a2->y=(a1->y/(-factor));                // FACTOR ES NEGATIVO || INVERSA PARA OPERAR POR POSITIVO
    a2->x=(a1->x/(-factor));                // FACTOR ES NEGATIVO || INVERSA PARA OPERAR POR POSITIVO
    a2->grises=a1->grises;

    reservar(a2);

    for(int i = 0; i < a2->x; i++)
    {

        for(int j = 0; j < a2->y ; j++)
        {

            for(int x = x0, pas=0 ; pas > factor ; x++, pas--)
            {
                for(int y = y0, pas=0; pas > factor ; y++, pas--)
                {

                    promedio+=a1->valores[x][y];

                }
            }
            promedio/=((-factor)*2);                // FACTOR ES NEGATIVO || INVERSA PARA OPERAR POR POSITIVO
            a2->valores[i][j]=promedio;             // ASIGNACIÓN DEL PROMEDIO
            promedio=0;
            y0-=factor;
        }

        x0-=factor;
        y0=0;
    }

    liberar(a1);

    a1->x=a2->x;
    a1->y=a2->y;

    reservar(a1);
    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int flipV(cont *a1, cont *a2, char *nombre)
{

    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            a2->valores[i][j]=a1->valores[((a1->x)-i)-1][j];
        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int flipH(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            a2->valores[i][j]=a1->valores[i][((a1->y)-j)-1];
        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int histograma(cont *a1, char nombre)
{
    int tot=((a1->x)*(a1->y));

    int rep[tot];
    int vec[tot];
    int temp;
    int muestra=0;


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //

    for(int i=0; i<tot; i++)
    {
        rep[i]=-1;
        vec[i]=-1;
    }


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //



    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            temp=a1->valores[i][j];
            for(int k=0; k<tot; k++)
            {
                if(rep[k]==-1)
                {
                    rep[k]=temp;
                    vec[k]=1;
                    muestra++;

                    k=tot;
                }
                else
                {
                    if(rep[k]==temp)
                    {
                        vec[k]++;

                        k=tot;
                    }
                }

            }

        }
    }
    printf("************\n");
    for(int i=0; i<muestra; i++)
    {
        printf("*  %d -> %d",rep[i],vec[i]);
        printf("\n");
    }
    printf("************\n");

    system("pause");

    return 0;
}

int histogramaCSV(cont *a1, char nombre)
{
    int tot=((a1->x)*(a1->y));

    int rep[tot];
    int vec[tot];
    int temp;
    int muestra=0;


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //

    for(int i=0; i<tot; i++)
    {
        rep[i]=-1;
        vec[i]=-1;
    }


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //



    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            temp=a1->valores[i][j];
            for(int k=0; k<tot; k++)
            {
                if(rep[k]==-1)
                {
                    rep[k]=temp;
                    vec[k]=1;
                    muestra++;

                    k=tot;
                }
                else
                {
                    if(rep[k]==temp)
                    {
                        vec[k]++;

                        k=tot;
                    }
                }

            }

        }
    }

    char *nombreCSV[200];
    printf("Introduzca el nombre del fichero CSV:\n");
    scanf("%s",&nombreCSV);

    strcat(nombreCSV,".csv");   // CONCATENAR PARA EXTENSIÓN .CSV
    FILE *ficheroCSV=fopen(nombreCSV, "w");

    if(ficheroCSV==NULL)
    {
        printf("No se ha podido generar el fichero CSV. Consulte la función histogramaCSV \n");
        return 1;
        system("pause");
    }
    else
    {
        fputs("Valor_Gris,Cantidad", ficheroCSV);
        fputs("\n",ficheroCSV);
        char repC[20], vecC[20];
        for(int i=0; i<muestra; i++)
        {
            itoa(rep[i],repC, 10);
            itoa(vec[i],vecC, 10);
            fputs(repC,ficheroCSV);
            fputs(",", ficheroCSV);
            fputs(vecC,ficheroCSV);
            fputs("\n",ficheroCSV);
        }

        fclose(ficheroCSV);

    }
    return 0;

}

int histogramaXML(cont *a1, char nombre)
{

    int tot=((a1->x)*(a1->y));

    int rep[tot];
    int vec[tot];
    int temp;
    int muestra=0;


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //

    for(int i=0; i<tot; i++)
    {
        rep[i]=-1;
        vec[i]=-1;
    }


    //  INICIALIZACIÓN DE VALORES PARA EVITAR VALORES BASURA  ----->  -1  //



    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            temp=a1->valores[i][j];
            for(int k=0; k<tot; k++)
            {
                if(rep[k]==-1)
                {
                    rep[k]=temp;
                    vec[k]=1;
                    muestra++;

                    k=tot;
                }
                else
                {
                    if(rep[k]==temp)
                    {
                        vec[k]++;

                        k=tot;
                    }
                }

            }

        }
    }

    char **nombreXML[100];
    printf("Introduzca el nombre del fichero XML:\n");
    scanf("%s",&nombreXML);

    strcat(nombreXML,".xml");   // CONCATENAR PARA EXTENSIÓN .CSV
    FILE *ficheroXML=fopen(nombreXML, "w");

    if(ficheroXML==NULL)
    {
        printf("No se ha podido generar el fichero CSV. Consulte la función histogramaCSV \n");
        system("pause");
    }
    else
    {

        escribirXML(ficheroXML, muestra, &rep, &vec);

        fclose(ficheroXML);

    }

    return 0;

}

void escribirXML(FILE *ficheroXML, int muestra, int rep[], int vec[])
{
    char repC[20], vecC[20];

        fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>",ficheroXML);
        fputs("\n",ficheroXML);

        fputs(" <histograma>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("     <Fila>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("         <Celda>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("             <Content>Valor_Gris</Content>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("         </Celda>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("         <Celda>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("             <Content>Cantidad</Content>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("         </Celda>",ficheroXML);
        fputs("\n",ficheroXML);
        fputs("     </Fila>",ficheroXML);
        fputs("\n",ficheroXML);
        for(int i=0; i<muestra; i++)
        {

            itoa(rep[i],repC, 10);
            itoa(vec[i],vecC, 10);

            fputs("     <Fila>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("         <Celda>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("             <Content>",ficheroXML);


            fputs(repC,ficheroXML);
            fputs("</Content>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("         </Celda>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("         <Celda>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("             <Content>",ficheroXML);
            fputs(vecC,ficheroXML);
            fputs("</Content>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("         </Celda>",ficheroXML);
            fputs("\n",ficheroXML);
            fputs("     </Fila>",ficheroXML);
            fputs("\n",ficheroXML);


        }
        fputs("\n",ficheroXML);

        fputs(" </histograma>",ficheroXML);
        //fputs("Valor_Gris,Cantidad", ficheroXML);
        fputs("\n",ficheroXML);

}

int brillo(cont *a1, cont *a2, char *nombre, float valorBrillo)
{

    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int temp=0;
    valorBrillo/=100;
    float diferencia=(float)(a2->grises)*valorBrillo;



    for(int i=0; i<a1->x; i++)
    {
        for(int j=0; j<a1->y; j++)
        {
            temp=(int)((float)(a1->valores[i][j]+diferencia));
            if(temp<0)
            {
                a2->valores[i][j]=0;
            }
            else
            {
                if(temp>(a2->grises))
                {
                    a2->valores[i][j]=a2->grises;
                }
                else
                {
                    a2->valores[i][j]=temp;
                }
            }


        }

    }

  /*  for(int i=0; i<(a2->x); i++)
    {
        for(int j=0; j<(a2->y); j++)
        {
            printf("%d ",a2->valores[i][j]);
        }
        printf("\n");
    }
*/
    liberar(a1);
    reservar(a1);
    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int resaltarBordes(cont *a1, cont *a2, cont *a3, char *nombre)       //A3 ES RESULTADO || A2 ES MATRIZ A OPERAR
{
    a2->x=3;
    a2->y=3;
    /*int **matrizTemp;
    int xTemp=2;
    int yTemp=2;
*/
    reservar(a2);

    for(int i=0; i<a2->x; i++)
    {
        for(int j=0; j<a2->y; j++)
        {
            if(i==1)
            {
                if(j==0)
                {
                    a2->valores[i][j]=-1;
                }
                else
                {
                   if(j==1)
                   {
                       a2->valores[i][j]=1;
                   }
                   else
                   {
                       a2->valores[i][j]=0;
                   }
                }
            }
            else
            {
                a2->valores[i][j]=0;
            }

        }
    }


    a3->x=a1->x;
    a3->y=a1->y;
    a3->grises=a1->grises;

    reservar(a3);

    int temp,ii,jj,kk,ll;
    for(int i=0; i<a3->x; ++i)
    {
        for(int j=0; j<a3->y; ++j)
        {
            temp=0;
            for(int k=0; k<a2->x; ++k)
            {
                for(int l=0; l<a2->y; ++l)
                {

                    temp += a1->valores[i][j] * a2->valores[k][l];

                }


            }
           a3->valores[i][j] = temp;
        }

    }

   /* for(int i=0; i<a3->x; i++)
    {
        for(int j=0; j<a3->y; j++)
        {
            printf("%d ", a3->valores[i][j]);
        }
        printf("\n");
    }
    system("pause");
*/
    putValores(a1,a3->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);
}

int invertir(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            a2->valores[i][j]=(a2->grises)-(a1->valores[i][j]);
        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);


    return 0;

}

int umbral(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int param;
    do
    {
        printf("\nIntroduzca el parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param);
    }
    while(param<0 || param>(a2->grises));

    system("pause");

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            if(a1->valores[i][j]<=param)
            {
                a2->valores[i][j]=0;
            }
            else
            {
                a2->valores[i][j]=a2->grises;
            }

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);


    return 0;

}

int umbralBinario(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int param,param1;
    do
    {
        printf("\nIntroduzca el primer parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param);
        printf("\nIntroduzca el segundo parámetro u1 para determinar el nivel de transicion\n");
        scanf("%d",&param1);
    }
    while((param<0 || param>(a2->grises)) && (param<0 || param>(a2->grises)));

    system("pause");

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            if((a1->valores[i][j]<=param) || (a1->valores[i][j] >= param1))
            {
                a2->valores[i][j]=a2->grises;
            }
            else
            {

                a2->valores[i][j]=0;


            }

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int umbralGris(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int param,param1;
    do
    {
        printf("\nIntroduzca el primer parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param);
        printf("\nIntroduzca el segundo parámetro u1 para determinar el nivel de transicion\n");
        scanf("%d",&param1);
    }
    while((param<0 || param>(a2->grises)) && (param<0 || param>(a2->grises)));

    system("pause");

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            if((a1->valores[i][j]<=param) || (a1->valores[i][j] >= param1))
            {
                a2->valores[i][j]=a2->grises;
            }
            else
            {
                a2->valores[i][j]=a1->valores[i][j];
            }

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int extension(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int param,param1;
    do
    {
        printf("\nIntroduzca el primer parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param);
        printf("\nIntroduzca el segundo parámetro u1 para determinar el nivel de transicion\n");
        scanf("%d",&param1);
    }
    while((param<0 || param>(a2->grises)) && (param<0 || param>(a2->grises)));



    int temp;               // VARIABLE PARA OPERACIÓN RANGO PARAM < VALOR GRIS < PARAM1

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            if((a1->valores[i][j]<=param) || (a1->valores[i][j] >= param1))
            {
                a2->valores[i][j]=0;
            }
            else
            {
                temp=(a1->valores[i][j]-param)*(255/(param1-param));

                a2->valores[i][j]=temp;
            }
            temp=0;

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int reduccion(cont *a1, cont *a2, char *nombre)
{


    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);
    int param,param1,param2;
    do
    {
        printf("\nIntroduzca el primer parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param);
        printf("\nIntroduzca el segundo parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param1);
        printf("\nIntroduzca el tercer parámetro u para determinar el nivel de transicion\n");
        scanf("%d",&param2);
    }
    while((param<0 || param>(a2->grises)) && (param<0 || param>(a2->grises)));



    int temp;               // VARIABLE PARA OPERACIÓN RANGO PARAM < VALOR GRIS < PARAM1

    for(int i=0; i<(a1->x); i++)
    {
        for(int j=0; j<(a1->y); j++)
        {
            if((a1->valores[i][j])<=param)
            {
                a2->valores[i][j]=0;
            }
            else
            {
                temp=(a1->valores[i][j]-param)*(255/(param1-param));

                a2->valores[i][j]=temp;
            }
            temp=0;

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

    return 0;

}

int crearMarco(cont *a1,cont *a2, int grosor, int gris, char *nombre)
{
    a2->x=a1->x;
    a2->y=a1->y;
    a2->grises=a1->grises;

    reservar(a2);

    int flagGrosorX=0;
    int flagGrosorY=0;
    int limitX=(a1->x)-grosor;
    int limitY=(a1->y)-grosor;



    for(int i=0; i<a1->x; i++)
    {
        if(i+1<=grosor)
        {
            flagGrosorX=1;
        }
        else
        {
            if(limitX<=i)
            {
                flagGrosorX=1;
            }
            else
            {

                flagGrosorX=0;

            }
        }
        for(int j=0; j<a1->y; j++)
        {

            if(flagGrosorX==1)
            {
                a2->valores[i][j]=gris;
            }
            else
            {
                if(j<=(grosor-1) || limitY<=j)
                {
                    a2->valores[i][j]=gris;
                    /*a2->valores[i][limit]=gris;
                    a2->valores[i][limit+1]=gris;
                    j=grosor+1;
*/
                }
                else
                {
                    a2->valores[i][j]=a1->valores[i][j];
                }

            }

        }
    }

    putValores(a1,a2->valores,a1->x,a1->y,0,nombre);
    sync(a1,nombre);

 /*   for(int i=0; i<a1->x; i++)
    {

        for(int j=0; j<a1->y; j++)
        {
                printf("%d ",a2->valores[i][j]);
        }
        printf("\n");

    }
*/
    system("pause");



}

int liberar(cont *a1)
{
    if((a1->valores) == NULL)
    {
        printf("\n - - - - No se puede liberar la memoria de valores puesto que ya no esta asignada. - - - - \n ");
    }
    else
    {

        for (int i=0; i<(a1->x); i++)
        {

                free(a1->valores[i]);
                a1->valores[i] = NULL;

                if(a1->valores[i] != NULL)
                {
                    printf("\n - - - - Problemas al liberar memoria de valores. Consulte la funcion liberar - - - - \n");
                    printf(" - - - - Error por referencia free[i] - - - - \n");
                    system("pause");
                    cleanout();
                    return 1;
                }


        }


        free(a1->valores);
        a1->valores = NULL;
        if(a1->valores != NULL)
        {

            printf("\n - - - - Problemas al liberar memoria de valores. Consulte la función liberar - - - - \n");
            printf(" - - - - Error por referencia free - - - - \n");
            system("pause");
            cleanout();
            return 1;
        }
    }



    return 0;
}

void sync(cont *a1,char *nombre)
{
    printf("\nSe va a sincronizar el archivo\n");
    system("pause");

    if(close(a1)!=0)
    {
        cleanout();
        printf("\n- - - - Error al sincronizar fichero. Compruebe funcion sync\n");
    }


    abrir_pgm(a1,nombre);


    int est = comprobar_pgm(a1);

    if(est==0)
    {


        cargar_pgm(a1);

        int est1 = reservar(a1);
        if(est1!=0)
        {
            printf("\n\n - - - - - - Error en la sincronización del nuevo fichero imagen. Revisa la función sync - - - - - - \n\n");
            system("pause");
            exit(-1);
        }
        leer(a1);
        rewind(a1->archivo);
    }
}


int close(cont *a1)
{
    int est3;
    est3=fclose(a1->archivo);
    if(est3==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }


}

