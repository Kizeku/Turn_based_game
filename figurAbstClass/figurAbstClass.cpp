#include <iostream>

#include "mage.h"
#include "unit_stats.h"
#include "warrior.h"

int main() {
	// Цифры юнитов теперь в unit_stats.cpp, урон - в weap_lib.cpp.
	mage Mages{ get_unit_stats(unit_type::mage) };
	warrior war{ get_unit_stats(unit_type::warrior) };

	std::cout << war.get_name() << " " << int(war.get_count_boyz()) << " " << war.atck_dist() << std::endl;

	// проверка клампа HP (было: c_health не инициализировался)
	Mages.take_damage(999);
	std::cout << Mages.get_name() << " hp=" << Mages.get_health()
		<< " alive=" << Mages.is_alive() << std::endl;
	Mages.heal(5);
	std::cout << Mages.get_name() << " hp=" << Mages.get_health() << std::endl;

	return 0;
}
