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
    sfTexture *tower2_text;
    sfSprite *tower2;
    sfTexture *select2_tow_text;
    sfSprite *select2_tow;
    sfTexture *tower3_text;
    sfSprite *tower3;
    sfTexture *select3_tow_text;
    sfSprite *select3_tow;
    sfTexture *tower4_text;
    sfSprite *tower4;
    sfTexture *select4_tow_text;
    sfSprite *select4_tow;
    sfTexture *range_text;
    sfSprite *range;
    sfTexture *missile_text;
    sfSprite *missile;
    sfTexture *bookclose_text;
    sfSprite *bookclose;
    sfTexture *bookopen_text;
    sfSprite *bookopen;
    sfTexture *menubook_text;
    sfSprite *menubook;
    sfVector2f pos_missile;
} play_t;

#endif /* !PLAY_H_ */
