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

#include "../engine/engine.h"
#include "scripting.h"

int abyss_lua_get_config(lua_State *l) {
    LCHECK_NUMPARAMS(2)

    LCHECK_STRING(1);
    LCHECK_STRING(2);

    const char *category = lua_tostring(l, 1);
    const char *value = lua_tostring(l, 2);

    if (strcmp(category, "#Abyss") == 0) {
        if (strcmp(value, "BasePath") == 0) {
            lua_pushstring(l, engine_get_base_path(engine_get_global_instance()));
            return 1;
        }

        luaL_error(l, "configuration value '%s' not found in abyss environment", value);
        return 0;
    }

    ini_file *ini = engine_get_ini_configuration(engine_get_global_instance());
    const char *result = init_file_get_value(ini, category, value);

    if (result == NULL) {
        luaL_error(l, "configuration value '%s' not found for category '%s'", value, category);
        return 0;
    }

    lua_pushstring(l, result);
    return 1;
}
