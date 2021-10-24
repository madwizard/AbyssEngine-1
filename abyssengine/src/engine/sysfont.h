/**
 * Copyright (C) 2021 Tim Sarbin
 * This file is part of AbyssEngine <https://github.com/AbyssEngine>.
 *
 * AbyssEngine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AbyssEngine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with AbyssEngine.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ABYSS_SYSFONT_H
#define ABYSS_SYSFONT_H

#include <SDL2/SDL.h>
#include <stdint.h>

typedef struct sysfont sysfont;

sysfont *sysfont_create(const void *font_gfx);
void sysfont_destroy(sysfont *source);
void sysfont_draw(sysfont *source, SDL_Renderer *renderer, int x, int y, const char *string);
void sysfont_draw_wrap(sysfont *source, SDL_Renderer *renderer, int x, int y, const char *string, int max_width);
int sysfont_get_character_height(const sysfont *source);
int sysfont_get_character_width(const sysfont *source);

#endif // ABYSS_SYSFONT_H
