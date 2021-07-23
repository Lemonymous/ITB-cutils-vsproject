// cutils.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "lua.hpp"
#include "board.h"
#include "pawn.h"
#include "game.h"
#include "misc.h"

#define DLLEXPORT __declspec(dllexport)

extern "C" DLLEXPORT int luaopen_inspect(lua_State* L) {
	if (lua_gettop(L) > 0) {
		luaL_checktype(L, 1, LUA_TTABLE);
		NAME = Options::get(L, "name", "cutils");
		DEBUG_MODE = Options::get(L, "debug", false);
		HEX = Options::get(L, "hex", true);
		VERBOSE = Options::get(L, "verbose", DEBUG_MODE);
		GET_FUNCS = Options::get(L, "get", !DEBUG_MODE);
		SET_FUNCS = Options::get(L, "set", !DEBUG_MODE);
		lua_pop(L, lua_gettop(L));
	}

	lua_newtable(L);

	if (DEBUG_MODE) {
		lua_pushstring(L, "Debug");
		lua_newtable(L);
		add_debug_functions(L);
		lua_rawset(L, -3);
	}

	lua_pushstring(L, "Misc");
	lua_newtable(L);
	add_misc_functions(L);
	lua_rawset(L, -3);

	lua_pushstring(L, "Board");
	lua_newtable(L);
	add_board_functions(L);
	lua_rawset(L, -3);

	lua_pushstring(L, "Pawn");
	lua_newtable(L);
	add_pawn_functions(L);
	lua_rawset(L, -3);

	lua_pushstring(L, "Game");
	lua_newtable(L);
	add_game_functions(L);
	lua_rawset(L, -3);

	lua_setglobal(L, NAME);

	return 1;
}

