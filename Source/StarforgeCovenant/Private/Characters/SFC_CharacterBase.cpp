// Copyright HeheKrazy


#include "Characters/SFC_CharacterBase.h"

ASFC_CharacterBase::ASFC_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	//Create Weapon
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	//Attach Weapon to Socket on Mesh
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocketRight"));
	//Disable Weapon Collision
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	Shield = CreateDefaultSubobject<USkeletalMeshComponent>("Shield");
	Shield->SetupAttachment(GetMesh(), FName("ShieldHandSocketLeft"));
	Shield->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

void ASFC_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}