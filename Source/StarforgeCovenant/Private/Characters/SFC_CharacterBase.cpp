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

UAbilitySystemComponent* ASFC_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASFC_CharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ASFC_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
