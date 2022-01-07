# include "pushswap.h"
typedef struct index
{
    int value;
    int index;
}    s_index;

int *index_it(int argc, char *argv[])
{
    int i;
    int j;
    int minor;
    int major;
    int *return_it;
    s_index *array;

    array = (s_index *)malloc(sizeof(s_index) * (argc - 1));
    return_it = (int *)malloc(sizeof(int) * (argc - 1));
    major = -2147483648;
    minor = 2147483647;
    i = -1;
    j = 0;

    while(++i < argc - 1)
        array[i].value = atoi(argv[i + 1]);
    i = -1;

    while(j < argc - 1)
    {
        minor = 2147483647;
        while(++i < argc - 1)
            if(array[i].value <= minor && array[i].value > major)
            {
                minor = array[i].value;
                array[i].index = j;
            }
        j++;
        major = minor;
		i = -1;
    }

    while(++i < argc - 1)
        return_it[i] = array[i].index;
    free(array);

    return return_it;
}