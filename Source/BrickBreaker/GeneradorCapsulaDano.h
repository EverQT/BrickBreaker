// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneradorCapsula.h"
#include "GeneradorCapsulaDano.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBREAKER_API AGeneradorCapsulaDano : public AGeneradorCapsula
{
	GENERATED_BODY()

//public:
//	// metodo para la creacion de capsulas
//	virtual ACapsula* MakeCapsule(FString CapsuleTypeName) override;
//

public:
	virtual bool FabricarCapsula2(FString NombreTipoCapsula) override;

};
