/*
** EPITECH PROJECT, 2023
** STEP_1
** File description:
** count the number step1
*/

char *condition_my_strlowcase(char *str, int i, char *temp)
{
    if (str[i] >= 97 && str[i] < 123) {
        temp[i] = str[i];
    } else if (str[i] >= 65 && str[i] <= 90) {
        temp[i] = str[i] + 32;
        str[i] = temp[i];
    }
    return str;
}

void condition_show_occurences(int count_occurences, char *str_low_av_arg )
{
    if(str_low_av_arg[0] >= 97 && str_low_av_arg[0] < 123) {   
        my_putchar(str_low_av_arg[0]);
        my_putchar(58);
        my_putchar(count_occurences);
        my_putchar(10);
    }
}

char *my_strlowcase(char *str)
{
    int i;
    int len = my_strlen(str);
    char temp[len];

    for (i = 0; i < len; i++) {
        condition_my_strlowcase(str, i, temp);
    }
    return str;
}

int cond_occ(int len_str_low, char *str_arg, char *str_char, int count_occ)
{
    int i;

    for (i = 0; i < len_str_low; i++) {
        if (str_arg[0] == str_char[i]) {
            count_occ += 1;
        }
    }
    condition_show_occurences(count_occ, str_arg);
    return count_occ;
}

int step1(int argc, char **av)
{
    int i;
    int l;
    int count_occ = '0';
    char *str_lowcase;
    char *str_low_av_arg;
    char *str_single_char;
    int len_str_low;

    if (argc < 3) {
        return 84;
    }
    len_str_low = my_strlen(av[1]);
    str_single_char = my_strlowcase(av[1]);
    str_low_av_arg = my_strlowcase(av[2]);
    for (l = 0; l < argc - 2; l++) {
        str_low_av_arg = my_strlowcase(av[l + 2]);
        cond_occ(len_str_low, str_low_av_arg, str_single_char, count_occ);
        count_occ = '0';
    }
    return 0;
}
