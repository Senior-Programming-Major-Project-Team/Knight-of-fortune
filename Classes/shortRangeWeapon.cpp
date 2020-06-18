#include"shortRangeWeapon.h"




ShortRangeWeapon* ShortRangeWeapon::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	ShortRangeWeapon* shortRangeweapon = new(std::nothrow)ShortRangeWeapon;
	shortRangeweapon->init(combatScene, weaponName,hero);
	if (shortRangeweapon->init(combatScene, weaponName,hero))
	{
		shortRangeweapon->autorelease();
		return shortRangeweapon;
	}
	else
	{
		CC_SAFE_DELETE(shortRangeweapon);
		return nullptr;
	}
}

bool ShortRangeWeapon::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	if (!Sprite::init())

	{

		return false;

	}
	_magicPoint = 0;
	_attackPoint = 0;
	_critRate = 0;
	_combatScene = combatScene;
	_weaponName = weaponName;
	return true;

}




