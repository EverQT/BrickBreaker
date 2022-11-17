// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsula.h"
#include "GeneradorCapsulaPoder.h"

// Sets default values
AGeneradorCapsula::AGeneradorCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeneradorCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneradorCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//ACapsula* AGeneradorCapsula::getCapsule(FString TypeCapsule)
//{
//	ACapsula* Capsule = MakeCapsule(TypeCapsule);
//	return Capsule;
//}


void AGeneradorCapsula::ConstruirCapsula(FString TipoCapsula)
{
	bool Value = FabricarCapsula(TipoCapsula);
	if (Value == true)
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Se genero Poder capsula.")));
	else
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("NO se genero capsula.")));

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Fabricando capsula: %s"), *capsula->GetNombre()));
	//capsula->Generar();
}

void AGeneradorCapsula::ConstruirCapsula2(FString TipoCapsula)
{
	bool Value = FabricarCapsula2(TipoCapsula);
	if (Value == true)
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("Se genero Dano capsula.")));
	else
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("NO se genero capsula.")));

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Fabricando capsula: %s"), *capsula->GetNombre()));
	//capsula->Generar();
}