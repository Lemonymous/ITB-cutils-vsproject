// cutils.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "lua.hpp"
#include "board.h"
#include "pawn.h"
#include "game.h"
#include "misc.h"

#define DLLEXPORT __declspec(dllexport)

bool isModuleLoaded(lua_State* L, const char* name) {
	lua_getglobal(L, name);
	bool result = !lua_isnil(L, -1);
	lua_pop(L, 1);

	return result;
}

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

	if (!isModuleLoaded(L, NAME)){
		lua_newtable(L);
		logd(L, "loading cutils...");
	}
	else {
		lua_getglobal(L, NAME);
		lua_pushnil(L);
		while (lua_next(L, -2) != 0) {
			lua_pop(L, 1);
			lua_pushvalue(L, -1);
			lua_pushnil(L);
			lua_rawset(L, -4);
		}

		logd(L, "Reloading cutils...");
	}

	logd(L, "cutils options:");
	logdf(L, "  name = %s", NAME);
	logdf(L, "  debug = %s", DEBUG_MODE);
	logdf(L, "  hex = %s", HEX);
	logdf(L, "  verbose = %s", VERBOSE);
	logdf(L, "  get = %s", GET_FUNCS);
	logdf(L, "  set = %s", SET_FUNCS);

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

