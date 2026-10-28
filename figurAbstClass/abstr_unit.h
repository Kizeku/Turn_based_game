#pragma once

#include <cstdint>
#include <string>

#include "unit_stats.h"

class abstr_unit
{

public:
	explicit abstr_unit(const unit_stats& stats);
	virtual ~abstr_unit() = default;

	virtual void promotion() = 0; // виртульная так у каждого свои тип повышения и свои фишки
	virtual void rest() = 0;

	// Универсальное изменение HP: delta со знаком, кламп в [0, max].
	// Для читаемости есть обёртки heal()/take_damage().
	void change_cur_hp(int delta);
	void heal(uint16_t amount) { change_cur_hp(static_cast<int>(amount)); }
	void take_damage(uint16_t amount) { change_cur_hp(-static_cast<int>(amount)); }

	int atck_dist();

	bool is_alive() const { return c_health > 0; }
	const std::string& get_name() const { return name; }
	uint16_t get_health() const { return c_health; }
	uint16_t get_m_health() const { return stats.max_health; }
	uint8_t get_atk_ch() const { return stats.accuracy; } // порог попадания, больше = хуже
	uint8_t get_count_boyz() const { return stats.count_boyz; }
	const unit_stats& get_stats() const { return stats; }

	// Сид для воспроизводимых боёв - без него баланс не настроить.
	static void set_rng_seed(uint32_t seed);

private:
	unit_stats stats;
	std::string name;  // имя юнита (копия из статов)
	uint16_t c_health; // текущее здоровье

	uint8_t get_random_num(uint8_t lv, uint8_t hv);
	uint8_t atk_try();
};
