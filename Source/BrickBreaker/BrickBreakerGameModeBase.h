// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Paddle.h"
#include "Capsula.h"
#include "BrickBreakerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER_API ABrickBreakerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	ABrickBreakerGameModeBase();

	//limite de creaciones
	int limiteCreate;
	//int limitePoder;
	//int limiteDano;

private:

	UPROPERTY()

	//Paddle
	class APaddle* Paddle;

	//Capsula
	class ACapsula* Capsula;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime);

private:

	// propiedades para la creacion de capsulas
	float StartSpawnCapsule;
	float TopSpawnCapsule;

	float InicioSpawn;
	float TopSpawn;
	

	
};
