/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Compare two strings
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (-1);
        i++;
    }
    return (0);
}
