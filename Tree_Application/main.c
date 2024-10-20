#include "tree.h"


char *(DECIDE[2]) = {"NO", "YES" };

char * transWordYesOrNo(bool ret)
{
    return (DECIDE[ret]);
}


int main(void)
{



    P_BINNODE_T pGod = malloc(sizeof(BINNODE_T));
    pGod->val = "as";
    pGod->elderSon = NULL;
    pGod->elderSon = malloc(sizeof(BINNODE_T));
    PrintfCustomElement(pGod->val);



    char** pStringArray = malloc(sizeof(char*) * 6);
    //char str[] = "/home/user/Documents/../Pictures";
    char str[] = "/a/b/c/d/e/f/g/h/i/j/k/l/m///n/o/p/q/r/s/t/u/v/w/x/y/z/a/b/c/d";
    //char *str2  = str;
    //char*pch = strtok(str, "/");
    //int idx = 0;
    //if (pch != NULL)
    //{
    //    do
    //    {
    //        pStringArray[idx] = pch;
    //        printf("%1d\n", idx++);
    //        printf("%s\n", pch);
    //        pch = strtok(NULL,"/");
    //    } while(pch != NULL);

    //}

    //int idx2 = 0;
    //for (idx2 = 0; idx2 < idx; idx2++)
    //{
    //    printf("%s\n", pStringArray[idx2]);
    //}
    int num = 0;
    char** divArray = ParserString(str, &num);

    printf("%1d\n", num);

    for (int idx = 0; idx < num; idx++)
    {
        printf("%s\n", divArray[idx]);
    }





    return 1;
}
