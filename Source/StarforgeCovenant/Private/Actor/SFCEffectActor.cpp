// Copyright HeheKrazy


#include "Actor/SFCEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/SFCAttributeSet.h"

// Sets default values
ASFCEffectActor::ASFCEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	
}

void ASFCEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USFCAttributeSet* SFCAttributeSet = Cast<USFCAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USFCAttributeSet::StaticClass()));
		USFCAttributeSet* MutableSFCAttributeSet = const_cast<USFCAttributeSet*>(SFCAttributeSet);
		MutableSFCAttributeSet->SetHealth(SFCAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ASFCEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ASFCEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASFCEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASFCEffectActor::OnEndOverlap);
	
}
