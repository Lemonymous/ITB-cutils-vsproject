#include "stdafx.h"
#include "lua_pawn.h"
#include "log.h"

size_t ADDR_WEAPON_LIST = 0x4;
size_t ADDR_WEAPON_POWER_BASE = 0x18C;
size_t ADDR_WEAPON_POWER_UPG1 = 0x164;
size_t ADDR_WEAPON_POWER_UPG2 = 0x174;
size_t ADDR_WEAPON_BASE = 0x0;
size_t ADDR_WEAPON_UPG = 0x134;

/*
	Creates an object based on the userdata at
	the given valid index, or the pawn with the id
	at the given valid index; which can be used to
	easily manipulate its associated memory values.
*/
lua_pawn::lua_pawn(lua_State* L, int index) : lua_obj(L) {
	if (!lua_isuserdata(L, index)) {
		luaL_checkint(L, index);
		lua_getglobal(L, "Game");

		if (lua_isnil(L, -1))
			luaL_error(L, "'Game' does not exist");

		lua_getfield(L, -1, "GetPawn");
		lua_insert(L, -2);
		lua_pushvalue(L, index);
		lua_remove(L, index);
		lua_call(L, 2, 1);
		lua_insert(L, index);
	}

	luaL_checktype(L, index, LUA_TUSERDATA);
	userdata = (void***)lua_touserdata(L, index);

	if (userdata == NULL)
		luaL_error(L, "invalid userdata");

	addr = (size_t)userdata[0][2];
}

lua_pawn::~lua_pawn() {}

bool isPowered(lua_State* L, PowerList power) {
	return power == NULL || power->size() == 0 || power->back() != 0;
}

std::vector<Weapon>* lua_pawn::getWeaponList() {
	void* addr_weapons = (void*)(addr + ADDR_WEAPON_LIST);
	return static_cast<std::vector<Weapon>*>(addr_weapons);
}

int lua_pawn::getWeaponCount(lua_State* L) {
	lua_pawn pawn = lua_pawn(L, 1);
	std::vector<Weapon>* weaponList = pawn.getWeaponList();
	lua_pushnumber(L, weaponList->size());

	return 1;
}

int lua_pawn::getWeapon(lua_State* L) {
	lua_pawn pawn = lua_pawn(L, 1);
	size_t weaponId = luaL_checknumber(L, 2);
	std::vector<Weapon>* weaponList = pawn.getWeaponList();

	if (weaponId >= weaponList->size())
		lua_pushnil(L);
	else {
		Weapon weapon = weaponList->at(weaponId);
		std::string* str = static_cast<std::string*>((void*)(weapon.get() + ADDR_WEAPON_BASE));

		lua_pushstring(L, str->c_str());
	}

	return 1;
}

int lua_pawn::getPoweredWeapon(lua_State* L) {
	lua_pawn pawn = lua_pawn(L, 1);
	size_t weaponId = luaL_checknumber(L, 2);
	std::vector<Weapon>* weaponList = pawn.getWeaponList();

	if (weaponId >= weaponList->size())
		lua_pushnil(L);
	else {
		Weapon weapon = weaponList->at(weaponId);
		PowerList power = static_cast<PowerList>((void*)((size_t)weapon.get() + ADDR_WEAPON_POWER_BASE));
		if (!isPowered(L, power))
			lua_pushnil(L);
		else {
			std::string* str = static_cast<std::string*>((void*)((size_t)weapon.get() + ADDR_WEAPON_UPG));
			lua_pushstring(L, str->c_str());
		}
	}

	return 1;
}

template <typename type>
int lua_pawn::get(lua_State* L) {
	return lua_pawn(L, 1).get<type>();
}
template <typename type>
int lua_pawn::set(lua_State* L) {
	return lua_pawn(L, 1).set<type>(2);
}

template int lua_pawn::get<int>(lua_State* L);
template int lua_pawn::get<unsigned int>(lua_State* L);
template int lua_pawn::get<unsigned char>(lua_State* L);
template int lua_pawn::get<double>(lua_State* L);
template int lua_pawn::get<const char*>(lua_State* L);
template int lua_pawn::get<bool>(lua_State* L);

template int lua_pawn::set<int>(lua_State* L);
template int lua_pawn::set<unsigned int>(lua_State* L);
template int lua_pawn::set<unsigned char>(lua_State* L);
template int lua_pawn::set<double>(lua_State* L);
template int lua_pawn::set<const char*>(lua_State* L);
template int lua_pawn::set<bool>(lua_State* L);
