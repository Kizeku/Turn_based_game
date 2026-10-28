#pragma once

#include <cstdint>
#include <string_view>

#include "weap_lib.h"

// Статы типа юнита: только данные, никакого поведения.
// Таблица в unit_stats.cpp - единственное место, где задаются цифры юнитов,
// поэтому новый тип добавляется строкой в таблицу, а не новым классом.
struct unit_stats
{
	std::string_view name;    // отображаемое имя типа
	uint16_t max_health;      // HP всего отряда (общий пул, а не одной фигуры)
	uint8_t  count_boyz;      // количество бойцов в отряде
	uint8_t  accuracy;        // порог попадания 1..6: попадание при броске > accuracy,
	                          // т.е. больше число = хуже (4 = 2/6, 3 = 3/6)
	uint8_t  armor_melee;     // задел: снижение урона в ближнем бою
	uint8_t  armor_range;     // задел: снижение урона в дальнем бою
	uint8_t  armor_magic;     // задел: снижение урона в магическом бою
	uint8_t  move;            // задел: мобильность, клеток за ход
	uint8_t  initiative;      // задел: порядок хода
	dist_weap_t dist_weap;    // id оружия дальнего боя
};

enum class unit_type : uint8_t
{
	mage = 0,
	warrior,
	count
};

const unit_stats& get_unit_stats(unit_type type);
