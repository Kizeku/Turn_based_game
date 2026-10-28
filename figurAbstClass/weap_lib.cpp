#include "weap_lib.h"

#include <array>

namespace {

// Порядок строк соответствует порядку dist_weap_t.
// Пока заглушки: реальные цифры урона вписываются здесь, юниты их не знают.
constexpr std::array<weapon_dist_info_t, WEAP_COUNT> weapon_dist_info_table = { {
	{ 1, 2, 2, 3 }, // BOW
	{ 1, 2, 1, 1 }, // SWORD
	{ 1, 2, 2, 3 }, // GUN
	{ 1, 2, 2, 3 }, // RIFLE
	{ 2, 3, 3, 2 }, // FIREBALL
	{ 1, 2, 3, 3 }, // ICE_ARROR
	{ 1, 1, 3, 4 }, // WIND_BLADE

} };

}

const weapon_dist_info_t& get_weapon_dist_info(dist_weap_t id)
{
	const std::size_t index = static_cast<std::size_t>(id);
	if (index >= weapon_dist_info_table.size()) return weapon_dist_info_table.front();
	return weapon_dist_info_table[index];
}
