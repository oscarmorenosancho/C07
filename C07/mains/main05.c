#include<stdio.h>
char	**ft_split(char *str, char *charset);

void    ft_print_arr(char **arr)
{
    int i;

    if (arr)
    {
        i = 0;
        while (arr[i])
        {
            printf("%s\n", arr[i]);   
            i++;
        }
    }
}

void    ft_free_arr(char **arr)
{
    int i;

    if (arr)
    {
        i = 0;
        while (arr[i] && i < 10)
        {
            free(arr[i]);   
            i++;
        }
        free (arr);
    }
 }


int main(int argc, char *argv[])
{
    char **arr;
    if (argc > 2)
    {
        printf("separadores :%s cadena a separar: %s\n",argv[1], argv[2]);
        arr = ft_split(argv[2], argv[1]);
        if (arr)
        {
            ft_print_arr(arr);
            ft_free_arr(arr);
        }
        else
            printf("array did't mount!\n");
    }
    else
        printf("insufficient arguments!\n");
    return 0;
}
