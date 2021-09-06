#include "stdafx.h"
#include "address.h"
#include "lua_helpers.h"
#include "lua_board.h"
#include "lua_tile.h"
#include "lua_pawn.h"
#include "lua_game.h"

template <typename type>
std::string getter() {
	return "Get";
}

template <>
std::string getter<bool>() {
	return "Is";
}

template <class obj, typename type>
Address Address::build(std::string id, size_t delta, Access access) {
	return Address{
		id,
		delta,
		access,
		LuaFunction{ getter<type>() + id, obj::template get<type> },
		LuaFunction{ "Set" + id, obj::template set<type> }
	};
}

template Address Address::build<lua_board, int>(std::string, size_t, Access);
template Address Address::build<lua_board, unsigned int>(std::string, size_t, Access);
template Address Address::build<lua_board, unsigned char>(std::string, size_t, Access);
template Address Address::build<lua_board, bool>(std::string, size_t, Access);
template Address Address::build<lua_board, double>(std::string, size_t, Access);
template Address Address::build<lua_board, const char*>(std::string, size_t, Access);

template Address Address::build<lua_tile, int>(std::string, size_t, Access);
template Address Address::build<lua_tile, unsigned int>(std::string, size_t, Access);
template Address Address::build<lua_tile, unsigned char>(std::string, size_t, Access);
template Address Address::build<lua_tile, bool>(std::string, size_t, Access);
template Address Address::build<lua_tile, double>(std::string, size_t, Access);
template Address Address::build<lua_tile, const char*>(std::string, size_t, Access);

template Address Address::build<lua_pawn, int>(std::string, size_t, Access);
template Address Address::build<lua_pawn, unsigned int>(std::string, size_t, Access);
template Address Address::build<lua_pawn, unsigned char>(std::string, size_t, Access);
template Address Address::build<lua_pawn, bool>(std::string, size_t, Access);
template Address Address::build<lua_pawn, double>(std::string, size_t, Access);
template Address Address::build<lua_pawn, const char*>(std::string, size_t, Access);

template Address Address::build<lua_game, int>(std::string, size_t, Access);
template Address Address::build<lua_game, unsigned int>(std::string, size_t, Access);
template Address Address::build<lua_game, unsigned char>(std::string, size_t, Access);
template Address Address::build<lua_game, bool>(std::string, size_t, Access);
template Address Address::build<lua_game, double>(std::string, size_t, Access);
template Address Address::build<lua_game, const char*>(std::string, size_t, Access);

void Address::addLuaFunction(lua_State* L, size_t addr, LuaFunction* function) {
	if (!lua_istable(L, -1))
		luaL_error(L, "addLuaFunction failed: parent table does not exist");

	lua_pushstring(L, function->name.c_str());
	lua_pushinteger(L, addr);
	lua_pushcclosure(L, function->func, 1);
	lua_rawset(L, -3);
}

void Address::addLuaFunctions(lua_State* L, std::vector<Address> addresses) {
	if (!lua_istable(L, -1))
		luaL_error(L, "addLuaFunctions failed: parent table does not exist");

	for (auto address : addresses) {

		bool readAccess = (address.access == R || address.access == RW);
		bool writeAccess = (address.access == W || address.access == RW);

		if (readAccess) {
			std::string status = "";

			if (!GET_FUNCS) {
				address.get.func = LuaFunction::get_default;
				status = " - disabled";
			}
			if (VERBOSE)
				logf(L, ("[0x%X]: " + address.get.name + status).c_str(), address.delta);

			address.addLuaFunction(L, address.delta, &address.get);
		}

		if (writeAccess) {
			std::string status = "";

			if (!SET_FUNCS) {
				address.set.func = LuaFunction::set_default;
				status = " - disabled";
			}
			if (VERBOSE)
				logf(L, ("[0x%X]: " + address.set.name + status).c_str(), address.delta);

			address.addLuaFunction(L, address.delta, &address.set);
		}
	}
}
