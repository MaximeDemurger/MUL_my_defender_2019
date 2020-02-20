/*
** EPITECH PROJECT, 2020
** play
** File description:
** pkay
*/

#ifndef PLAY_H_
#define PLAY_H_

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"

typedef struct play_s {
    sfTexture *tower1_text;
    sfSprite *tower1;
    sfTexture *select_tow_text;
    sfSprite *select_tow;
    sfTexture *range_text;
    sfSprite *range;
    sfTexture *missile_text;
    sfSprite *missile;
    sfVector2f pos_missile;
} play_t;

#endif /* !PLAY_H_ */
