// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneradorCapsula.h"
#include "GeneradorCapsulaPoder.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER_API AGeneradorCapsulaPoder : public AGeneradorCapsula
{
	GENERATED_BODY()

public:
	// metodo para la creacion de capsulas
	//virtual ACapsula* MakeCapsule(FString CapsuleTypeName) override;

public:
	virtual bool FabricarCapsula(FString NombreTipoCapsula) override;
	
};
