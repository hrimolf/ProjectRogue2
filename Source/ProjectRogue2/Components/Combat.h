// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTROGUE2_API UCombat : public UActorComponent
{
	GENERATED_BODY()

private:
	int CurrentHealth;
	int MaxHealth;
	int CurrentMana;
	int MaxMana;

public:	
	// Sets default values for this component's properties
	UCombat();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(int Amount);
	void Heal(int Amount);

	int GetCurrentHealth() const { return CurrentHealth; }
	int GetMaxHealth() const { return MaxHealth; }
	int GetCurrentMana() const { return CurrentMana; }
	int GetMaxMana() const { return MaxMana; }

	bool IsDead() const { return CurrentHealth == 0; }
};