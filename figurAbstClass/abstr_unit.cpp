#include "abstr_unit.h"

#include <algorithm>
#include <iostream>
#include <random>

namespace {

// Один генератор на программу: random_device + mt19937 на каждый бросок
// слишком дорого и лишает бой воспроизводимости.
std::mt19937& rng()
{
	static std::mt19937 gen{ std::random_device{}() };
	return gen;
}

}

abstr_unit::abstr_unit(const unit_stats& s)
	: stats{ s }, name{ s.name }, c_health{ s.max_health }
{
}

void abstr_unit::set_rng_seed(uint32_t seed)
{
	rng().seed(seed);
}

void abstr_unit::change_cur_hp(int delta)
{
	const int hp = static_cast<int>(c_health) + delta;
	if (hp < 0) c_health = 0;
	else if (hp > static_cast<int>(stats.max_health)) c_health = stats.max_health;
	else c_health = static_cast<uint16_t>(hp);
}

// универсальная функция получения случайного числа в диапазоне
uint8_t abstr_unit::get_random_num(uint8_t lv, uint8_t hv)
{
	if (lv > hv) std::swap(lv, hv);
	return static_cast<uint8_t>(std::uniform_int_distribution<int>(lv, hv)(rng()));
}

int abstr_unit::atck_dist()
{
	const weapon_dist_info_t& weapon = get_weapon_dist_info(stats.dist_weap);

	// вычисление кол-вы попаданий
	const int attackers = atk_try();

	// вычисление урона: границы берутся из таблицы оружия по id
	int atck_rnd_dmg = 0;
	for (int i = 0; i < attackers; i++) {
		atck_rnd_dmg += get_random_num(weapon.dmg_l, weapon.dmg_h);
	}

	// отладочный вывод
	std::cout << std::endl;
	std::cout << "suc_ atck_dist : " << attackers << std::endl;
	std::cout << "rnd dmg : " << atck_rnd_dmg << std::endl;
	return atck_rnd_dmg;
}

uint8_t abstr_unit::atk_try()
{
	uint8_t suc_atk = 0;
	for (uint8_t i = 0; i < stats.count_boyz; i++)
		suc_atk += get_random_num(1, 6) > stats.accuracy ? 1 : 0;
	return suc_atk;
}
