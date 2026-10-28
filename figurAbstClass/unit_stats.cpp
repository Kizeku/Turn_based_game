#include "unit_stats.h"

#include <array>
#include <cstddef>

namespace {

// Порядок строк соответствует порядку unit_type.
constexpr std::array<unit_stats, static_cast<std::size_t>(unit_type::count)> unit_stats_table = { {
	// name        hp  cnt  acc  arm_m  arm_r  arm_m  move  init  dist_weap
	{ "mage",       8,   8,   4,     0,     1,  2,     2,    5,  FIREBALL },   // unit_type::mage
	{ "warrior",   15,  12,   3,     3,     3,  2,     4,    8,  BOW },   // unit_type::warrior
} };

}

const unit_stats& get_unit_stats(unit_type type)
{
	const std::size_t index = static_cast<std::size_t>(type);
	if (index >= unit_stats_table.size()) return unit_stats_table.front();
	return unit_stats_table[index];
}
