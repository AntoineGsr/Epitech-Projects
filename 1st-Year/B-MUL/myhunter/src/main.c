/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

int helper_display(int ac, char **av)
{
    int fd;
    char buffer[546];

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            fd = open("./src/helper.txt", O_RDONLY);
            read(fd, buffer, 546);
            buffer[546] = '\0';
            my_putstr(buffer);
            my_putchar('\n');
            return (1);
        }
    }
    return (0);
}

int nb_of_birds(int ac, char **av)
{
    int i = 0;

    if (ac == 1 || ac > 2) {
        return (6);
    }
    i = my_getnbr(av[1]);
    if (i <= 0)
        return (6);
    return (i);
}

void init_display_all(M_base *song, B_base *bck, S_base *bird, int nb_birds)
{
    init_struct_music(song, "./src/OP_song.ogg");
    init_struct_back(bck, "./src/my_menu.png");
    init_struct_sprite(bird, "./src/black_birdthibs.png", nb_birds);
    exec_struct_back(bck);
    exec_struct_bird(bird, nb_birds);
}

void destroy_all(M_base *song, B_base *bck, S_base *bird, int nb_birds)
{
    sfClock_destroy(bird[0].clock);
    sfMusic_destroy(song->music);
    sfTexture_destroy(bck->texture);
    sfSprite_destroy(bck->sprite);
    for (int i = 0; i < nb_birds; i++) {
        sfTexture_destroy(bird[i].texture);
        sfSprite_destroy(bird[i].sprite);
        sfSprite_destroy(bird[i].sprite_copy);
    }
    free(bck);
    free(bird);
    free(song);
}

int main(int ac, char **av)
{
    int nb_birds = nb_of_birds(ac, av);
    B_base *bck = malloc(sizeof(*bck));
    S_base *bird = malloc(sizeof(S_base) * nb_birds);
    M_base *song = malloc(sizeof(*song));
    S_base *menu = malloc(sizeof(*menu));
    sfRenderWindow *window = createMyWindow(1920, 1080);
    sfEvent event;
    S_base mouse;
    sfMouseMoveEvent move;

    if (helper_display(ac, av) == 1) return (0);
    init_display_all(song, bck, bird, nb_birds);
    bird[0].exit_button = display_menu(window, bck, event, menu);
    bird[0].clock = sfClock_create();
    exec_music(song, 2.03, 10, 0);
    if (bird[0].exit_button == 0)
        exe_game(bird, bck, window, event);
    destroy_all(song, bck, bird, nb_birds);
    sfRenderWindow_destroy(window);
    return (0);
}
