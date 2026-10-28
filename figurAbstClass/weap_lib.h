#pragma once

#include <cstddef>
#include <cstdint>

//
// [id] = {dmg_l, dmg_h, dmg_t, weap_r}
// dmg_l/dmg_h - нижняя/верхняя граница урона за попадание
// dmg_t       - задел: тип урона (сравнивается с armor_* в бою)
// 1 - ближний бой 
// 2 - дальний 
// 3 - магический
// weap_r      - задел: радиус в клетках
typedef enum {
	BOW = 0,
	SWORD,
	GUN,
	RIFLE,
	FIREBALL,
	ICE_ARROR,
	WIND_BLADE,
	WEAP_COUNT
}dist_weap_t;

typedef struct {
	uint8_t dmg_l;
	uint8_t dmg_h;
	uint8_t dmg_t;
	uint8_t weap_r;
}weapon_dist_info_t;

// Доступ к таблице оружия по id.
// Сама таблица лежит в weap_lib.cpp: определение массива в заголовке
// даёт multiple definition, как только файл подключат из двух .cpp.
const weapon_dist_info_t& get_weapon_dist_info(dist_weap_t id);
