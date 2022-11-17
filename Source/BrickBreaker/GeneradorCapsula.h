// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.h"
#include "GeneradorCapsula.generated.h"

UCLASS()
class BRICKBREAKER_API AGeneradorCapsula : public AActor
{
	GENERATED_BODY()


public:

	// metodo para obtener la capsula
	//ACapsula* getCapsule(FString TypeCapsule);
	
	// ----
	void ConstruirCapsula(FString TipoCapsula);

	void ConstruirCapsula2(FString TipoCapsula);

	virtual bool FabricarCapsula(FString NombreTipoCapsula) PURE_VIRTUAL(APaFM_GeneradorCapsulas::FabricarCapsula, return false;);

	virtual bool FabricarCapsula2(FString NombreTipoCapsula) PURE_VIRTUAL(APaFM_GeneradorCapsulas::FabricarCapsula, return false;);

protected:

	// metodo virtual puro para la creacion de capsulas
	//virtual ACapsula* MakeCapsule(FString CapsuleTypeName) PURE_VIRTUAL(APaFM_CapsuleGenerator::MakeCapsule, return nullptr;);
	
public:	
	// Sets default values for this actor's properties
	AGeneradorCapsula();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
