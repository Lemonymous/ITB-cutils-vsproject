#pragma once
#include "lua.hpp"
#include "lua_obj.h"

typedef std::shared_ptr<void*> Weapon;
typedef std::vector<size_t>* PowerList;
typedef std::vector<Weapon>* WeaponList;

class lua_pawn : public lua_obj {
public:
	lua_pawn(lua_State* L, int index);
	~lua_pawn();

	WeaponList getWeaponList();

	using lua_obj::get;
	using lua_obj::set;

	template <typename type>
	static int get(lua_State* L);
	template <typename type>
	static int set(lua_State* L);

	static int getWeaponCount(lua_State* L);
	static int getWeapon(lua_State* L);
	static int getPoweredWeapon(lua_State* L);
};
